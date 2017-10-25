#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int stat_k=100, stat_l=100, status=0, opsi;

void* menu(void *arg)
{
}

void* l_kurang(void *arg)
{
	stat_l-=15;
	sleep(10);		
}

void *k_kurang(void *arg)
{
	stat_k-=10;
	sleep(20);
}

void *l_tambah(void *arg)
{
	while(status==0) {}	
	if(opsi==1)
	{
		stat_l += 10;
	}
	if(opsi==2)
	{
		stat_k += 10;
	}
}

int main()
{
	pthread_t thr1, thr2, thr3, thr4, thr5;

	pthread_create(&thr1, NULL, &l_kurang, NULL); 	
	pthread_create(&thr2, NULL, &k_kurang, NULL);
	pthread_create(&thr3, NULL, &tambah, NULL); 	
	pthread_create(&thr5, NULL, &menu, NULL); 	 	

	while(1)
	{
		if(stat_k <= 0 || stat_l <= 0 || stat_k > 100 || stat_l > 100) break;
		else {
			pthread_join(thr1, NULL);
			pthread_join(thr2, NULL);
			pthread_join(thr3, NULL);
			pthread_join(thr4, NULL);
			pthread_join(thr5, NULL);
		}
	}
	return 0;
}
