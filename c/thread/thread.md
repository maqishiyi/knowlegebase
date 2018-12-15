1. C语言在linux系统下如何实现并发编程
pthread_t pthread_mutex_t 定义线程和互斥锁
pthread_create 创建线程
pthread_join 等待线程结束
example: demo1.c

2. 互斥锁的使用

3. C语言如何使用读写锁
同一时刻只能有一个线程获得写锁，同一时刻可以有多个线程获得读锁。
pthread_rwlock_init
pthread_rwlock_wrlock
pthread_rwlock_rdlock

4. C语言如何使用自旋锁


5. C语言线程属性如何运用
pthread_attr_t   以分离状态创建线程，主线程不需要等待结束，线程自行结束
另外可以设置线程的调度属性

6. C语言线程同步属性
pthread_mutexattr_t

7. 线程和信号如何一起使用

8. 守护进程