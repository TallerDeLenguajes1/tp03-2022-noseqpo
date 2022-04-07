#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char *array[5];
    char temp[10]; // cual es el punto de usar malloc acá? 
    for (int i = 0; i < 5; i++)
    {
        printf("\nIngrese un nombre: ");
        gets(temp);

        *(array + i) = (char *)malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(*(array + i), temp);
    }

    for (int i = 0; i < 5; i++)
    {
        puts(*(array+i));
        free(array[i]);
    }

    return 0;
}
