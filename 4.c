#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[2];

int length=90;
void* count(void *arg)
{
	unsigned long i=0;
	pthread_t id=pthread_self();
	int iter;
	if(pthread_equal(id,tid[0]))
	{
		
	}
	else if(pthread_equal(id,tid[1]))
	{
		
	}
	return NULL;
}
int main(void)
{
	int l=0;
	int err;
	int i=0;
   	int size;
   	int arr[6];
   	char temp;
   	do
	{
          scanf("%d%c", &arr[i], &temp);
          i++;
        } while(temp!='\n');

	while(l<2)
	{
		err=pthread_create(&(tid[0]),NULL,&count,(void*)argument);
		if(err!=0)
		{
		  
		}
		else
		{
		  
		}
		i++;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
