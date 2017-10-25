#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int stat_k=100, stat_l=100, status=0;

void* l_kurang(void *arg)
{	
	while(status==0) {
	if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) break;
	sleep(10);	
	stat_l-=15; }
}

void* k_kurang(void *arg)
{	
	while(status==0) {
	if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) break;
	sleep(20);
	stat_k-=10; }
}

void* menu(void *arg)
{
	int opsi;
	while(status==0)
	{
		printf("\nGAME AQUARIUM -- Lohan dan Kepiting\n");
		printf("Input sesuai pilihan yang Anda inginkan:\n");
		printf("1.Beri makan lohan\n2.Beri makan kepiting\n");
		printf("Status kepiting : %d dan Status lohan : %d\n", stat_k, stat_l);
		scanf("%d", &opsi);
		if(opsi==1) stat_l+=10;
		else if(opsi==2) stat_k+=10;	
		else printf("Input error!");

		if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) status=1;
	}
}

int main()
{
	pthread_t thr1, thr2, thr3, thr4, thr5;

	system("clear");
	pthread_create(&thr1, NULL, &l_kurang, NULL); 	
	pthread_create(&thr2, NULL, &k_kurang, NULL); 
	pthread_create(&thr3, NULL, &menu, NULL);

	//if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) status=1;

	pthread_join(thr3, NULL);
	pthread_join(thr1, NULL);
	pthread_join(thr2, NULL);

	printf("GAME AQUARIUM SELESAI! Terima kasih sudah bermain :)\n");
	return 0;
}
