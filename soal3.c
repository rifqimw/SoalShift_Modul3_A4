#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int stat_k=100, stat_l=100, opsi;

void* l_kurang(void *arg)
{
	sleep(10);	
	stat_l-=15;	
}

void* k_kurang(void *arg)
{
	sleep(20);
	stat_k-=10;
}

int main()
{
	pthread_t thr1, thr2, thr3, thr4, thr5;

	pthread_create(&thr1, NULL, &l_kurang, NULL); 	
	pthread_create(&thr2, NULL, &k_kurang, NULL); 

	while(1)
	{
		if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) break;
		else {
		printf("\nGAME AQUARIUM -- Lohan dan Kepiting\n");
		printf("Input sesuai pilihan yang Anda inginkan:\n");
		printf("1.Beri makan lohan\n2.Beri makan kepiting\n3.Cek status\n");
		scanf("%d", &opsi);
		if(opsi==1) stat_l+=10;
		else if(opsi==2) stat_k+=10;	
		else if(opsi==3) printf("Status lohan : %d. Status kepiting : %d\n", stat_l, stat_k);
		else printf("Input error!");
		}
	}
	return 0;
}
