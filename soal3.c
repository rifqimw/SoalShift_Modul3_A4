#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int stat_k=100, stat_l=100, status;

void *menu (void *arg)
{
}

void* l_kurang(void *arg)
{
	
}

void *k_kurang(void *arg)
{
}

void *l_tambah(void *arg)
{
}

void *k_tambah(void *arg)
{
}

int main()
{
	pthread_t thr1, thr2, thr3, thr4, thr5;

	pthread_create(&thr1, NULL, &l_kurang, NULL); 	
	pthread_create(&thr2, NULL, &k_kurang, NULL);
	pthread_create(&thr3, NULL, &l_tambah, NULL); 	
	pthread_create(&thr4, NULL, &k_tambah, NULL);
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
}
