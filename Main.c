#include <stdio.h>
#include "menu.h"
#include "funciones.h"

int main() {
    char nombres[100][100];
    int cantidades[100];
    float precios[100];
    int numProductos = 0;

    char nombresClientes[100][100];
    char cedulasClientes[100][20];
    int numClientes = 0;

    char fechaFactura[100][20];
    int numFacturas = 0;
    int cantidadesFactura[100];
    float preciosFactura[100];
    int numItemsFactura = 0;
    float totalFactura = 0.0;

    leerDatosDesdeArchivo(nombres, cantidades, precios, &numProductos);

    int opcion;
    do {
        mostrarMenu();
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 2:
                editarProducto(nombres, cantidades, precios, numProductos);
                break;
            case 3:
                eliminarProducto(nombres, cantidades, precios, &numProductos);
                break;
            case 4:
                mostrarInventario(nombres, cantidades, precios, numProductos);
                break;
            case 5:
                ingresarCliente(nombresClientes, cedulasClientes, &numClientes);
                break;
            case 6:
                editarCliente(nombresClientes, cedulasClientes, numClientes);
                break;
            case 7:
                mostrarClientes(nombresClientes, cedulasClientes, numClientes);
                break;
            case 8:
                facturar(nombres, cantidades, precios, &numProductos, nombresClientes, cedulasClientes, numClientes, fechaFactura, &numFacturas, cantidadesFactura, preciosFactura, &numItemsFactura, &totalFactura);
                break;
            case 9:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opcion no valida. Por favor, ingrese una opcion valida.\n");
        }
    } while (opcion != 9);

    return 0;
}
