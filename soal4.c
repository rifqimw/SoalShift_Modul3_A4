#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
pthread_t tid3;
int status;
 

void* tulis(void *arg)
{
	status = 0;
	do
	{
	  scanf("%d%c", &arr[i], &temp);
	  i++;
	} while(temp!='\n');
	status = 1;
	return  NULL;
}

void* sort(void *arg)
{
	
}
void* faktorial(void *arg)
{
	
}
int main(void)
{
	pthread_create(&(tid1), NULL, &tulis, NULL);
	pthread_join(tid1, NULL);
	pthread_create(&(tid2), NULL, &sort, NULL);
	pthread_join(tid2,NULL);
	pthread_create(&(tid3), NULL, &faktorial, NULL);
	pthread_join(tid3, NULL);
	return 0;
}
