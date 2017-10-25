#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	char nama1[10]; int a; int menu, MP4A1, PM2_V1, SPR_3, SS2_V5, SPG1_V3, MINE;
	printf("=== PENJUAL SENJATA ===\n");
	printf("Silahkan pilih menu yang ingin diakses dengan input nomor urut!\n");
	printf("1.Lihat stock senjata\n2.Tambah stock senjata\n");
	scanf("%d", &menu);
	if(menu==1)
	{
		if(MP4A1>0) printf("Stock MP4A1 : %d", MP4A1);
		if(PM2_V1>0) printf("Stock PM2-V1 : %d", PM2_V1);
		if(SPR_3>0) printf("Stock SPR-3 : %d", SPR_3);
		if(SS2_V5>0) printf("Stock SS2-V5 : %d", SS2_V5);
		if(SPG1_V3>0) printf("Stock SPG1-V3 : %d", SPG1_V3);
		if(MINE>0) printf("Stock MINE : %d", MINE);
	}
	//scanf("%s", &nama1);
	//scanf("%d", &a);

}
