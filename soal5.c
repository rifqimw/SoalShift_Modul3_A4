#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>


void* open(void *argv)
{
    int hasil=0;
    char* x;
    x = (char*) argv;
	char cari[25];
    char text[1500];
    FILE *f;
    f = fopen("Novel.txt", "r");
    strcpy(cari, x);
       
    while(fscanf(f,"%s",text) != EOF)
    {
        if(strstr(text,cari) != NULL)hasil++;
    }
    fclose(f);
    printf("Jumlah kata %s : %d kata\n", cari, hasil);
}
int main(int argc, char *argv[])
{
    pthread_t tid[argc];
	int i=0;
	char input[1000];
	while(scanf("%c",&input[i])!=EOF)
	{
		pthread_create(&(tid[i]), NULL, &open,(void*) input[i]); 
		i++;
	}
	return 0;
}
