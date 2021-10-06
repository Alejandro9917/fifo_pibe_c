#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

int main(void)
{
    int fd1, fd2, fd3, fd4; 
    char buf1[1024], buf2[1024], buf3[1024], buf4[1024];

    fd1 = open("/home/proyecto/fifo1", O_RDONLY);
    read(fd1, buf1, sizeof(buf1));

    fd2 = open("/home/proyecto/fifo2", O_RDONLY);
    read(fd2, buf2, sizeof(buf2));

    fd3 = open("/home/proyecto/fifo3", O_RDONLY);
    read(fd3, buf3, sizeof(buf3));

    fd4 = open("/home/proyecto/fifo4", O_RDONLY);
    read(fd4, buf4, sizeof(buf4));

    printf("Números Primos: %s \n", buf1);
    printf("Números Pares: %s \n", buf2);
    printf("Números Impares: %s \n", buf3);
    printf("Caracteres: %s \n", buf4);

    return 0;
}