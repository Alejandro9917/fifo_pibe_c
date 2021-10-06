#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
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

    mkfifo("/home/proyecto/fifo2", 0666);
    fd = open("/home/proyecto/fifo2", O_WRONLY);

    srand(time(NULL));

    printf("Números pares:-\n");
    for(a=1; a<=20; a++) {
        char str[10] = {0};

        N=rand() % 451 *2 + 100;   /* numero aleatorio PAR entre 100 y 1000 */

        my_itoa(N, str);
        char space[] = "    ";
        strcat(str, space);
        strcat(dest, str);
    }
    
    write(fd, dest, sizeof(dest));
    close(fd);
    printf("%s \n",dest);
}
