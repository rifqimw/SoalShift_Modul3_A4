#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	char nama[15]; int beli, menu, j_MP4A1=0, j_PM2_V1=0, j_SPR_3=0, j_SS2_V5=0, j_SPG1_V3=0, j_MINE=0;

	key_t key = 1234;
	int *value1, *value2, *value3, *value4, *value5, *value6;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0_666);
	value1 = shmat(shmid, NULL, 0);	
	value2 = shmat(shmid, NULL, 0);	
	value3 = shmat(shmid, NULL, 0);	
	value4 = shmat(shmid, NULL, 0);	
	value5 = shmat(shmid, NULL, 0);	
	value6 = shmat(shmid, NULL, 0);	

	printf("=== PEMBELI SENJATA ===\n");
	while(1) {
	printf("Silahkan pilih menu yang ingin diakses dengan input nomor urut!\n");
	printf("1.Lihat stock senjata\n2.Beli senjata\n");
	scanf("%d", &menu);
	if(menu==1)
	{
		printf("Stock MP4A1 : %d\n", j_MP4A1);
		printf("Stock PM2-V1 : %d\n", j_PM2_V1);
		printf("Stock SPR-3 : %d\n", j_SPR_3);
		printf("Stock SS2-V5 : %d\n", j_SS2_V5);
		printf("Stock SPG1-V3 : %d\n", j_SPG1_V3);
		printf("Stock MINE : %d\n", j_MINE);
	}
	else if(menu==2)
	{
		printf("Silahkan input senjata yg ingin ditambah dengan format [nama_barang] [jumlah_barang]\n");
		scanf("%s", &nama);
		scanf("%d", &tambah);
		if(strcmp(nama,"MP4A1")==0) j_MP4A1 += tambah;	
		else if(strcmp(nama,"PM2_V1")==0) j_PM2_V1 += tambah;	
		else if(strcmp(nama,"SPR_3")==0) j_SPR_3 += tambah;	
		else if(strcmp(nama,"SS2_V5")==0) j_SS2_V5 += tambah;	
		else if(strcmp(nama,"SPG1_V3")==0) j_SPG1_V3 += tambah;	
		else if(strcmp(nama,"MINE")==0) j_MINE += tambah;		
		
	} 	*value1 = j_MP4A1;
		*value2 = j_PM2_V1;
		*value3 = j_SPR_3;
		*value4 = j_SS2_V5;
		*value5 = j_SPG1_V3;
		*value6 = MINE;
	}

	shmdt(value1, value2, value3, value4, value5, value6);
	shmctl(shmid, IPC_RMID, NULL);	
	
	return 0;
}
