#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int board1[16], board2[16];
int status = 0; 
int poin1 = 0, poin2 = 0;

void* thr1(void *arg) //giliran pemain1
{
	int tempat;
	printf("Pasang ranjau untuk pemain 1, masukkan -1 jika ingin selesai : ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tempat);
		if(tempat==-1) break;
		board1[tempat] = 1;
	}
	printf("\nSilahkan pemain 2 tebak empat ranjau : ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tempat);
		if(board1[tempat]==1) poin2+=1;
		else poin1+=1;
	}
	status = 1;
}

void* thr2(void *arg) //giliran pemain2
{
	while(status==0) {}
	printf("Cuma nyoba mutex");
}

int main()
{
	memset(board1, 0, sizeof(board1));
	memset(board2, 0, sizeof(board2));
	pthread_t tid1, tid2;
	pthread_create(&(tid1), NULL, &thr1, NULL);
	pthread_create(&(tid2), NULL, &thr2, NULL);
	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
}
