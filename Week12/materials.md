+ 전역변수. 전역변수인데, parent 와 child 값이 공유가 안된다.  
+ parent 와 child는 메모리 공간이 다르기때문에, 둘의 전역변수의 공간도 다르다. 두 프로세스의 data segment가 현재 다른 메모리 영역임.  
+ fork() 하는순간. 달라짐.  


+ 부모 프로세스와 자식 프로세스 전역변수 읽기 => 공유하지 않는다. (1번과졔)      
+ 그럼 프로세스 간에 데이터를 어떻게공유??    
+ => signal, 메모리맵핑, PIPE, Message Queue, ...  여러가지가 있음.  

+ 여러가지 방법중, 9장의 **메모리 맵핑**을 이용한 데이터 공유를 이번 실강때 진행함.(9장 18페이지 - 예제 9-5번 )  
    
+ 2번째 과제)  


#### 4. 8장 시그널, 프로세스간의 전송&수신 (지난번엔 전송만함)  

+ 15페이지. 시그널 헨들러.   
+ 시그널을 보내는게 kill 수신하는게 헨들러.  

시그널<신호>  
+ 8장 8페이지에 시그널들 확인.  
+ 코어덤프, 무시, 17번시그널(SIGCHID : 자식이 부모에게 보내는 시그널. 기본액션이 무시.지만 우리가 바꿔줄수있다)  
+  > 단, SIGKILL 이라는 시그널은 절대 변경 불가하다.  
+ 시그널을 보내려면 PID를 알아야한다.
+ 시그널은 비동기.
+ 12페이지. 시그널 헨들러 함수. 14페이지에 코드있음.  
+ 시그널 전송 프로그램 SIGINT sendSIGINT.c

<br><br>

## 시그널 핸들러

```c
void sig_handler(int signo) {
	//do it. 
	printf("parent received signal %d \n", signo);
	printf(" not exit~~~~~~"); -> if, SIGINT 시그널인 경우, SIGINT는 프로세스 강제종료이나, 이 기본동작대신 sig_handler 실행. 
	return;
}

int main(int argc, char* argv[]) {
	signal(SIGCHLD, sig_handler); //SIGCHLD 시그널 수신시 -> sig_handler 실행
    signal(SIGINT, sig_handler); //SIGINT 시그널 수신시 -> sig_handler 실행
```

<br>

signal(시그널번호 및 시그널 상수, sig_handler); 이 코드는 SIGCHLD, SIGINT 등등 시그널이 발생했을 때, 운영체제가 기본적으로 설정된 동작을 하는 대신 sig_handler 함수를 실행하도록 지정하는 역할.  

마치 특정 상황에 대한 "예외 처리"를 등록하는 것과 같다고 볼 수 있음.  

일반적으로 SIGCHLD 시그널은 자식 프로세스가 종료되었을 때 부모 프로세스에게 전달되는데, 운영체제가 정의해둔 이 기본 동작 대신에, 시그널 헨들러 함수를 수행하도록 한다.  

위 코드처럼 signal() 함수를 사용하면 SIGCHLD 시그널을 받았을 때 sig_handler 함수가 실행되어, 부모 프로세스가 자식 프로세스의 종료를 인지하고 필요한 작업을 수행할 수 있도록 해줌.  

이처럼 signal() 함수 & 헨들러를 사용하면 시그널에 대한 처리 방식을 직접 정의하여 프로그램의 동작을 제어할 수 있다.

<br><br>

