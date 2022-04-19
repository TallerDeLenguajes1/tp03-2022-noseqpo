#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};
struct Producto
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
struct Cliente
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable "CantidadProductosAPedir"
} typedef Cliente;

int pedirClientes();
Cliente cargarCliente(int id);
void cargarProductos(Producto *productos, int tam);
int costoProducto(Producto *temp);
void mostrarTodo(Cliente *listado, int tam);
void imprimirProductos(Producto **listado, int tam);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int clientes = pedirClientes();
    Cliente listado[clientes];
    for (int i = 0; i < clientes-1; i++)
    {
        listado[i] = cargarCliente(i); 
    }
    mostrarTodo(listado, clientes);
    return 0;
}

int pedirClientes()
{
    // Peventista necesita la cantidad de clientes
    int clientes;
    printf("\nIngrese la cantidad de clientes: ");
    scanf("%d", &clientes);
    return clientes;
}

Cliente cargarCliente(int id)
{
    Cliente temp;
    temp.ClienteID = id+1;
    char *bufalo = malloc(sizeof(char) * 100);
    fflush(stdin);
    printf("\nIngrese el nombre del cliente %d: ", id+1);
    gets(bufalo);
    temp.NombreCliente = malloc(sizeof(char) * (strlen(bufalo) + 1));
    strcpy(temp.NombreCliente, bufalo);
    free(bufalo); // proceso caro
    // hasta acá anda bien
    temp.CantidadProductosAPedir = 1 + rand() % 5;
    printf("cantidad: %d", temp.CantidadProductosAPedir);

    Producto productos[temp.CantidadProductosAPedir]; // hacer malloc ??
    cargarProductos(productos, temp.CantidadProductosAPedir);
    // imprimir productos acá
    return temp;
}

void cargarProductos(Producto *productos, int tam)
{
    // acá hay problemas
    for (int i = 0; i < tam - 1; i++)
    {
        Producto *temp = (productos + i);
        temp->ProductoID = i;
        temp->Cantidad = 1 + rand() % 10;
        temp->TipoProducto = *(TiposProductos + (rand() % 5)); // puede acceder a los nombres???
        temp->PrecioUnitario = 10 + rand() % 100;
    }
}

int costoProducto(Producto *temp)
{
    return temp->Cantidad * temp->PrecioUnitario;
}

void mostrarTodo(Cliente *listado, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        Cliente temp = listado[i];
        printf("\n\n\n --------------  Cliente ID %d: ", temp.ClienteID);
        printf("\n Nombre del Cliente: %s", temp.NombreCliente);
        printf("\n Cantidad de productos pedidos: %d", temp.CantidadProductosAPedir);
        int tamP = temp.CantidadProductosAPedir - 1;
        imprimirProductos(&(temp.Productos), tamP);
    }
}

void imprimirProductos(Producto **listado, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("entraaaaaaaaaaa");
        Producto *temp = *(listado + i);
        printf("\n Producto ID: %d", temp->ProductoID);
        printf("\n      Producto '%s': ", temp->TipoProducto);
        printf("\n              %d unidades pedidas", temp->Cantidad);
        printf("\n              %d precio por unidad", temp->PrecioUnitario);
        printf("\n              %d costo total del pedido", costoProducto(temp));
    }
}