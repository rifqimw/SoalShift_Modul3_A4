#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

char board1[16], board2[16];
int status = 0; 

void* thr1(void *arg) //giliran pemain1
{
}

void* thr2(void *arg) //giliran pemain2
{
}

int main()
{
	pthread_t thread1, thread2;
	pthread_create(&(tid1), NULL, &thr1, NULL);
	pthread_create(&(tid2), NULL, &thr2, NULL);
	
	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);
}
