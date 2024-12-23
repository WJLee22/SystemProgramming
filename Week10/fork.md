프로세스가 2개가 되었기때문에 printf 2번이 출력됨.  
> 프로그램은 하난데, 메인메모리에는 2개의 프로세스.

fid가 하나는 0으로 출력됨. 부모한테는 자식 프로세스의 id, fork로 만들어진 자식한테는 0이 반환됨.  

<br>

**fork()**: 현재 프로세스와 똑같은 프로세스를, 현재 프로세스의 자식프로세스로써 메모리에 생성.  

> fork()를 호출한 프로세스가 부모 프로세스. fork()로 생성된 프로세스가 자식 프로세스.

```
fid=fork(); 로 자식 프로세스 생성후 -> child process는 fork를 수행하지 않는다.
왜냐하면 child 프로세스는 parent부터 동일한 pc(program counter) 레지스터 값을
그대로 복사받았기때문에 parent 프로세스의 코드 실행지점과 동일하다.

현재 parent 프로세스가 fork()를 호출하고나서 자식 프로세스가 생성되어진 것이니,  
fork() 호출 다음 코드 구문들이 실행되어진다.
fork() 호출 후, 부모 프로세스의 pc 레지스터 값은 fork() 호출 구문 +1 되어졌을테니깐.

즉, fork() 호출문 이후부터 자식은 부모와 동일한 코드로 쭉 실행되는 것.
```
> 여기서 pc(program counter) 레지스터 값은 프로세스의 PCB에 저장되어있음.
> 
> PCB는 운영체제가 프로세스를 관리하기 위해 프로세스마다 유지하는 정보들을 담고 있는 커널 내의 자료구조.
> 
> PCB에는 프로세스의 상태, PID, PC 레지스터 값, CPU 레지스터 값, 메모리 할당 정보 등 다양한 정보가 저장  
> fork() 시스템 콜을 통해 프로세스를 복제할 때, 운영체제는 부모 프로세스의 PCB를 복사하여 자식 프로세스의 PCB가 생성됨.
> 
> so, 이때 PC 레지스터 값을 포함한 모든 부모 프로세스의 PCB 정보가 자식 프로세스의 PCB로써 복사됨.
> 따라서 자식 프로세스는 부모 프로세스와 동일한 위치에서 실행을 시작하게 되는 것임.
<br>

### fork() return 값  

+ **fid == 0** : 자식 프로세스한테 전달되는 값. fork 함수는 자식 프로세스에게는 0을 반환함.
+ **fid > 0** : 부모 프로세스한테 전달되는 값. fork 함수는 부모 프로세스에게는 자식프로세스의 PID를 반환하기에 무조건 양수임.
+ **fid == -1** : fork() 함수 실패, 에러시 fork 함수는 부모 프로세스에게 -1을 반환. fork()가 실패했으니 자식 프로세스는 존재x.  

<br>

child 의 ppid = parent 의 pid.  
=> 부모 자식 관계.  

부모는 자식의 pid를 어떻게 아나? -> **fork() 의 return value. fId.**  


<br>

### 개념 정리

+ #### PID  
PID(Process ID)는 운영체제에서 프로세스를 식별하기 위해 프로세스에 부여하는 번호를 의미한다.  

+ #### PPID
PPID(Parent Process ID)는 부모 프로세스의 PID를 의미한다.  

```
./fork1.out 입력하면, 하드디스크에 있는 fork1.out 이라는 컴파일 링크된 실행파일 프로그램이  
메모리를 할당받아 로드되고 프로세스로써 실행된다.
이때, 코드, 데이터, 스택 등 프로그램 실행에 필요한 모든 정보가 메모리에 적재된다.  
그리고 fork()로 생성된 자식 프로세스도 메모리의 별도의 공간에 로드되고 실행.  
```




