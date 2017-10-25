#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int i;
pthread_t tid[1000];

void* sort(void *arg)
{
	while(status != 1)
	{
	}
	int temp[6];
	for(int j = 0; j < i-1; j++)
	{
	  for(int k = 0; k < i-j-1; k++)
	  {
	    if(arr[k] > arr[k+1])
	    {
	 	temp[1] = arr[k+1];
	 	arr[k+1] = arr[k];
	 	arr[k] = temp[1];
	    }
	  }
	}
	status = 2;
}*/
void* faktorial(void *argv)
{
	//while(status != 2)
	//{
	//}
	int *x;
	x = (int*)argv;
	long long faktorial = 1;
	for (int j = 1; j <= x; j++)
	{
		faktorial *= j;
	}
	printf("Hasil %d! = %lld", x, faktorial);
	printf("\n");
}
int main()
{
	int i=0;
	int input[1000];
	while(scanf("%d",&input[i])!=EOF)
	{
		pthread_create(&(tid[i]), NULL, &faktorial,(void*) input[i]); 
		i++;
	}
	//pthread_create(&(tid1), NULL, &tulis, NULL);
	//pthread_join(tid1, NULL);
	//pthread_create(&(tid2), NULL, &sort, NULL);
	//pthread_join(tid2,NULL);
	//pthread_create(&(tid3), NULL, &faktorial, NULL);
	//pthread_join(tid3, NULL);
	return 0;
}
