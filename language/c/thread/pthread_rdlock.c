#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 
struct share{
	pthread_rwlock_t rwlock;
	int product;
};	//把共享数据和它们的同步变量集合到一个结构中，这往往是一个较好的编程技巧。
 
struct share *shareData;
void *produce(void *);
void *consume1(void *);
void *consume2(void *);
 
int main(void)
{
	pthread_t pid,cid1,cid2;
	int res;
	void *ret;
 
	srand(time(NULL));
	shareData = malloc(sizeof(struct share));
	if(shareData == NULL)
	{
		perror("shareData malloc fail");
		exit(1);
	}
	res = pthread_rwlock_init(&shareData->rwlock,NULL);
	if(res != 0)
	{
		perror("rwlock init fail");
		exit(1);
	}
	res = pthread_create(&pid,NULL,produce,NULL);
	if(res != 0)
	{
		perror("pthread produce create fail");
		exit(1);
	}
	res = pthread_create(&cid1,NULL,consume1,NULL);
	if(res != 0)
	{
		perror("pthread consume1 create fail");
		exit(1);
	}
	res = pthread_create(&cid2,NULL,consume2,NULL);
	if(res != 0)
	{
		perror("pthread consume2 create fail");
		exit(1);
	}
 
	res = pthread_join(pid,&ret);
	if(res == 0)
		printf("producer exit\n");
	res = pthread_join(cid1,&ret);
	if(res == 0)
		printf("consumer1 exit\n");
	res = pthread_join(cid2,&ret);
	if(res == 0)
		printf("consumer2 exit\n");
	pthread_rwlock_destroy(&shareData->rwlock);
	exit(0);
}
 
void *produce(void *arg)
{
	int i;
	for(i=0;i<6;i++)
	{
		pthread_rwlock_wrlock(&shareData->rwlock);
		shareData->product = rand()%100+1;
		printf("produce:%d\n",shareData->product);
		pthread_rwlock_unlock(&shareData->rwlock);
		sleep(1);
	}
	pthread_exit(NULL);
}
 
void *consume1(void *arg)
{
	int i;
	for(i=0;i<6;i++)
	{
		pthread_rwlock_rdlock(&shareData->rwlock);
		printf("consume1:%d\n",shareData->product);
		//pthread_rwlock_unlock(&shareData->rwlock);
		sleep(1);
	}
	pthread_exit(NULL);
}
 
void *consume2(void *arg)
{
	int i;
	for(i=0;i<6;i++)
	{
		pthread_rwlock_rdlock(&shareData->rwlock);
		printf("consume2:%d\n",shareData->product);
		pthread_rwlock_unlock(&shareData->rwlock);
		sleep(1);
	}
	pthread_exit(NULL);
}
