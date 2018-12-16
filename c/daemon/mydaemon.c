#include<stdio.h>
#include<signal.h> 
#include<unistd.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<sys/stat.h> 
void mydaemon(void) 
{ 
    umask(0);//调用umask将文件模式创建屏蔽字设置为0. 
    pid_t id=fork();//调用fork，创建子进程 
    if(id<0) { 
        perror("fork()"); 
    } else if (id>0) { //father 
        exit(0); 
    } 
    setsid();//调用setsid函数创建一个会话 
    signal(SIGCHLD,SIG_IGN);//忽略SIGCHLD信号，子进程退出时不再给父进程发信号。 
    if(chdir("/")<0) {       //将当前工作目录更改为根目录
        printf("child dir error\n"); 
        return; 
    } 
    close(0); 
    close(1);//关闭不需要的文件描述符 
    close(2); 
} 
int main() 
{ 
    mydaemon(); 
    while(1)
    { 
        sleep(1); 
    } 
    return 0; 
}

