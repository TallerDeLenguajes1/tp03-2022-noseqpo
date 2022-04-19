#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cargarNombre(char **p)
{
    char buff[50];
    printf("\nIngrese un name:");
    gets(buff);
    *p = (char *)malloc((strlen(buff) + 1) * sizeof(char));
    strcpy(*p,buff);
    // free nada?? nada, porque buff es de la funcion y si libero *p lo pierdo
}

int main(int argc, char const *argv[])
{
    /*char *temp; // no tiene memoria
    cargarNombre(&temp); // tenemos que enviar la direccion de nuestro puntero
    puts(temp); // hay que hacer de cuenta que acepta **strings** directamente
    */

    char *V[5]; // arreglo de 5 punteros tipo char

    for (int i = 0; i < 5; i++)
    {
        cargarNombre(&V[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        puts(V[i]); 
        free(V[i]); // uno por uno si o si
    } // se podria mostrar y liberar en el mismo momento que se carga? posiblemente

    // perfecto!!
    
    return 0;
}
