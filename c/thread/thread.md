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
