#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

char *my_itoa(int num, char *str)
{
        if(str == NULL)
        {
                return NULL;
        }
        sprintf(str, "%d", num);
        return str;
}

int main() {
    int N, a, fd;

    char dest[1024];

    mkfifo("/home/proyecto/fifo3", 0666);
    fd = open("/home/proyecto/fifo3", O_WRONLY);

    srand(time(NULL));
    printf("Números impares:-\n");
    for(a=1; a<=20; a++) {
        char str[10] = {0};

        N=rand() % 451 *2 + 101; 

        my_itoa(N, str);
        char space[] = "    ";
        strcat(str, space);
        strcat(dest, str);
    }

    write(fd, dest, sizeof(dest));
    close(fd);
    printf("%s \n",dest);
}
