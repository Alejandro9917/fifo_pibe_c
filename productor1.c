#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>
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

int IsPrime(int num)
{
    if (num <= 1) return 0;
    if (num % 2 == 0 && num > 2) return 0;
    for(int i = 3; i < num / 2; i+= 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(void)
{
    int fd;
    int i = 100, c = 0;

    char dest[1024];

    mkfifo("/home/proyecto/fifo1", 0666);
    fd = open("/home/proyecto/fifo1", O_WRONLY);

    srand(time(NULL));
    printf("Prime numbers are:-\n");
    while(i--)
    {
        int n = rand() % 451 *2 + 101;
        if(IsPrime(n) == 1)
        {
            //printf("%d\n",n);
            char str[10] = {0};

            my_itoa(n, str);
            char space[] = "    ";
            strcat(str, space);
            strcat(dest, str);
            c++;
        }

        if(c == 20){
            break;
        }
    }

    write(fd, dest, sizeof(dest));
    close(fd);
    printf("%s \n",dest);
    return 0;
}