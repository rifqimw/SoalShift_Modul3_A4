#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int board1[16], board2[16], temp1[16], temp2[16];
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
		else if(board1[tempat]==1 || board1[tempat]==-1)
		{
			while(1) {
			printf("Lubang ini sudah terisi! Silahkan isi lubang lain!\n");
			scanf("%d", &tempat); 
			if(board1[tempat]==0) break;}
		}
		board1[tempat] = 1;
	}
	system("clear");
	printf("\nSilahkan pemain 2 tebak empat ranjau : ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tempat);
		if(board1[tempat]==1) { poin2+=1; board1[tempat]=-1;}
		else poin1+=1;
	}
	system("clear");
	
	printf("\nPoin1: %d, Poin2: %d\n", poin1, poin2);
	
	status = 1;
}

void* thr2(void *arg) //giliran pemain2
{
	while(status==0) {}
	int tempat;
	printf("Pasang ranjau untuk pemain 2, masukkan -1 jika ingin selesai : ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tempat);
		if(tempat==-1) break;
		else if(board2[tempat]==1 || board2[tempat]==-1)
		{
			while(1) {
			printf("Lubang ini sudah terisi! Silahkan isi lubang lain!\n");
			scanf("%d", &tempat); 
			if(board2[tempat]==0) break;}
		}
		board2[tempat] = 1;
	}
	system("clear");
	printf("\nSilahkan pemain 1 tebak empat ranjau : ");
	for(int i=0; i<4; i++)
	{
		scanf("%d", &tempat);
		if(board2[tempat]==1) { poin1+=1; board2[tempat]=-1;}
		else poin2+=1;
	}
	system("clear");
	printf("\nPoin1: %d, Poin2: %d\n", poin1, poin2);
	status = 0;
	
}

int main()
{
	char start;
	printf("\nIngin memainkan permainan MINE? Y/N? ");
	scanf("%c", &start);
	if(start=='Y') {
	system("clear");
	memset(board1, 0, sizeof(board1));
	memset(board2, 0, sizeof(board2));
	
	while(1){
	pthread_t tid1, tid2;
	
	pthread_create(&(tid1), NULL, &thr1, NULL);
	pthread_create(&(tid2), NULL, &thr2, NULL);
		
	if(poin1==10 || poin2==10) break;
	else {	
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);}
	}
	
	system("clear");
	printf("PERMAINAN SELESAI!\n");
	if(poin1==10) printf("Pemain 1 memenangkan permainan! YAY!\n");
	else if(poin2==10) printf("Pemain 2 memenangkan permainan! YEAH!\n");
	printf("Terima kasih sudah bermain :)\n");
	
	}
	else if(start=='N') printf("\nYaaah, oke deh!\n");
	return 0;
}
