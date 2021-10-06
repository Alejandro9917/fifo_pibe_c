#include <unistd.h>
#include <fcntl.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int c, char** s){
    int i, N, fd;

    char dest[1024];

    mkfifo("/home/proyecto/fifo4", 0666);
    fd = open("/home/proyecto/fifo4", O_WRONLY);

    srand(time(NULL));
    printf("Letras random:-\n");
    for(i = 1; i <= 20; i++){
        char str[10] = {0};

	    N=rand() % (('z' - 'a') + 1);	

        str[0] = 'a' + N;
        char space[] = " ";
        strcat(str, space);
        strcat(dest, str);
        //printf("%d.- '%c' \n", i,'a' + N);
    }

    write(fd, dest, sizeof(dest));
    close(fd);
    printf("%s \n",dest);
    return 0;
}
