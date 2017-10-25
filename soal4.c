#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int i;
pthread_t tid[1000];

void* faktorial(void *argv)
{
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
int main(int argc, char** argv[])
{
	int i=0;
	int input[1000];
	//for(int k=0; k<argc; k++)
	while(scanf("%d",&input[i])!=EOF)
	{
		pthread_create(&(tid[i]), NULL, &faktorial,(void*) input[i]); 
		i++;
	}
	return 0;
}
