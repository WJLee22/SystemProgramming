
**만일 부모 프로세스가 자식 프로세스보다 일찍 종료되는 경우 자식 프로세스는 고아 프로세스가 되어 PPID로 init process의 PID를 가지게 된다.**

<br>

#### `고아 프로세스`:  부모 프로세스가 자식 프로세스보다 먼저 종료되면 -> 자식 프로세스가 고아가 됨. 자식 프로세스의 ppid가 변경됨.

####  `좀비 프로세스`:  고아의 경우와는 반대로, 자식 프로세스가 부모 프로세스보다 먼저 종료되는 지극히 정상적인 흐름이긴하나, 자식 프로세스가 실행을 종료하고나서 자원까지 다 반납했음에도 자식의 종료 상태 정보를 받지 못한 경우에는, 자식 프로세스는 좀비 프로세스가 된다.  

#### 즉, 자식 프로세스가 종료했음을 부모 프로세스가 전달받지 못해서 일어난 일.
> 프로세스 동기화 문제때문에 발생한 문제이다.
> 부모 프로세스가 자식 프로세스의 종료 시그널을 받지못해서 테이블에서 제거하지않고 그대로 남아있는 상태.  
> 부모가 종료되고나서야 자식 프로세스가 테이블에서 사라지면서 좀비해제.

<br>

**시그널**: 커널(리눅스)이 프로세스(메모리에 로드된 프로그램)한테 보내는 신호 or 프로세스 -> 프로세스.  
주로, 커널 -> 프로세스로 보내는 시그널이 일반적.  

1. 시그널
+ **커널 -> 프로세스**
+ 프로세스 -> 프로세스

#### 시그널은 비동기적.  
> 언제 날라올지모른다. 마치 민방위 소방훈련처럼.  
> 시그널의 갯수(총 256개의 시그널이 있음) ->  쉘에서 `kill -l` 입력으로 유저의 시그널 갯수 확인  

#### `kill(pid, signal num)` : 프로세스 `1개`에게 시그널을 보내는 함수.  
> kill 이외에도 raise 등등 시그널 전송 시스템 호출함수들 있음.  
> **중요한건 시그널을 보낼 대상 프로세스의 pid를 알아야 보낼수있음**  


