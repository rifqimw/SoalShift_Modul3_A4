#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

int main()
{
	char nama[15]; int beli, menu;

	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	int *value = shmat(shmid, NULL, 0);

	printf("=== PEMBELI SENJATA ===\n");
	while(1) {
	printf("Silahkan pilih menu yang ingin diakses dengan input nomor urut!\n");
	printf("1.Lihat stock senjata\n2.Beli senjata\n3.Exit\n");
	scanf("%d", &menu);
	if(menu==1)
	{
		printf("Stock MP4A1 : %d\n", value[0]);
		printf("Stock PM2-V1 : %d\n", value[1]);
		printf("Stock SPR-3 : %d\n", value[2]);
		printf("Stock SS2-V5 : %d\n", value[3]);
		printf("Stock SPG1-V3 : %d\n", value[4]);
		printf("Stock MINE : %d\n", value[5]);
	}
	else if(menu==2)
	{
		printf("Silahkan input senjata yg ingin ditambah dengan format [nama_barang] [jumlah_barang]\n");
		scanf("%s", &nama);
		scanf("%d", &beli);		

		if(strcmp(nama,"MP4A1")==0 && value[0]>beli) value[0] -= beli;	
		else if(strcmp(nama,"PM2-V1")==0 && value[1]>beli) value[1] -= beli;	
		else if(strcmp(nama,"SPR-3")==0 && value[2]>beli) value[2] -= beli;	
		else if(strcmp(nama,"SS2-V5")==0 && value[3]>beli) value[3] -= beli;	
		else if(strcmp(nama,"SPG1-V3")==0 && value[4]>beli) value[4] -= beli;	
		else if(strcmp(nama,"MINE")==0 && value[5]>beli) value[5] -= beli;		
		
	}
	else if(menu==3) break;
	
	}
	shmdt(value);	
	shmctl(shmid, IPC_RMID, NULL);	
	
	return 0;
}
