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
void cargarCliente(Cliente **lista, int tam);
void cargarProductos(Producto **listado, int tam);
float costoProducto(Producto *temp);
void mostrarTodo(Cliente *listado, int tam);
void imprimirProductos(Producto *listado, int tam);

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int clientes = pedirClientes();
    Cliente *listado; // intentar trabajar todo con dinamica
    listado = (Cliente *)malloc(sizeof(Cliente) * clientes);
    cargarCliente(&listado, clientes);
    mostrarTodo(listado, clientes ); // no anda nada
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

void cargarCliente(Cliente **lista, int tam)
{
    Cliente *temp = *lista;
    for (int i = 0; i < tam; i++)
    {
        temp->ClienteID = i;
        char *bufalo = malloc(sizeof(char) * 100);
        fflush(stdin);
        printf("\nIngrese el nombre del cliente %d: ", temp->ClienteID);
        gets(bufalo);
        temp->NombreCliente = malloc(sizeof(char) * (strlen(bufalo) + 1));
        strcpy(temp->NombreCliente, bufalo);
        free(bufalo);
        temp->CantidadProductosAPedir = 1 + rand() % 5;
        temp->Productos = (Producto *)malloc(sizeof(Producto) * temp->CantidadProductosAPedir);
        cargarProductos(&(temp->Productos), temp->CantidadProductosAPedir);
        temp++;
    }
}

void cargarProductos(Producto **listado, int tam)
{
    Producto *temp = *listado;
    for (int i = 0; i < tam; i++)
    {
        temp->ProductoID = i;
        temp->Cantidad = 1 + rand() % 10;
        int rando = rand() % 5;
        temp->TipoProducto = malloc(sizeof(char) * (strlen(TiposProductos[rando]) + 1));
        strcpy(temp->TipoProducto, TiposProductos[rando]);
        temp->PrecioUnitario = 10 + rand() % 100;
        temp++;
    }
}

float costoProducto(Producto *temp) // no en uso
{
    return temp->Cantidad * temp->PrecioUnitario;
}

void mostrarTodo(Cliente *listado, int tam)
{
    Cliente *temp = listado;
    for (int i = 0; i < tam ; i++)
    {
        printf("\n\n\n --------------  Cliente ID %d: ", temp->ClienteID);
        printf("\n Nombre del Cliente: %s", temp->NombreCliente);
        printf("\n Cantidad de productos pedidos: %d", temp->CantidadProductosAPedir);
        imprimirProductos(temp->Productos, temp->CantidadProductosAPedir);
        temp++;
    }
}

void imprimirProductos(Producto *listado, int tam)
{
    Producto *temp = listado;
    for (int i = 0; i < tam ; i++)
    {
        printf("\n        Producto numero: %d", temp->ProductoID);
        printf("\n        Tipo: %s", temp->TipoProducto);
        printf("\n        Cantidad: %d", temp->Cantidad);
        printf("\n        Precio unitario: %.2f", temp->PrecioUnitario);
        printf("\n          Precio de la compra: %.2f", costoProducto(temp));
        printf("\n");
        temp++;
    }
}