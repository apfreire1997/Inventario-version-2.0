#include <stdio.h>
#include <string.h>
#include "funciones.h"
#include <ctype.h>

void ingresarProducto(char nombres[][100], int *cantidades, float *precios, int *numProductos) {
    int numProductosAgregar;

    printf("¿Cuántos productos desea ingresar? \n");
    scanf("%d", &numProductosAgregar);

    if (*numProductos + numProductosAgregar <= 100) {
        for (int i = 0; i < numProductosAgregar; i++) {
            printf("Ingrese el nombre del producto: ");
            scanf("%s", nombres[*numProductos]);

            printf("Ingrese la cantidad del producto: ");
            scanf("%d", &cantidades[*numProductos]);

            printf("Ingrese el precio del producto: ");
            scanf("%f", &precios[*numProductos]);

            (*numProductos)++;
        }

        printf("Productos ingresados exitosamente.\n");

        guardarDatosEnArchivo(nombres, cantidades, precios, *numProductos);
    } else {
        printf("No se pueden ingresar más productos, límite alcanzado.\n");
    }
}

void editarProducto(char nombres[][100], int *cantidades, float *precios, int numProductos) {
    if (numProductos > 0) {
        char nombreBuscado[100];
        printf("Ingrese el nombre del producto que desea editar: ");
        scanf("%s", nombreBuscado);

        int encontrado = 0;
        for (int i = 0; i < numProductos; i++) {
            if (strcmp(nombres[i], nombreBuscado) == 0) {
                printf("Ingrese la nueva cantidad del producto: ");
                scanf("%d", &cantidades[i]);

                printf("Ingrese el nuevo precio del producto: ");
                scanf("%f", &precios[i]);


                guardarDatosEnArchivo(nombres, cantidades, precios, numProductos);

                printf("Producto editado exitosamente.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
    } else {
        printf("No hay productos para editar.\n");
    }
}

void eliminarProducto(char nombres[][100], int *cantidades, float *precios, int *numProductos) {
    if (*numProductos > 0) {
        char nombreBuscado[100];
        printf("Ingrese el nombre del producto que desea eliminar: ");
        scanf("%s", nombreBuscado);

        int encontrado = 0;
        for (int i = 0; i < *numProductos; i++) {
            if (strcmp(nombres[i], nombreBuscado) == 0) {

                for (int j = i; j < *numProductos - 1; j++) {
                    strcpy(nombres[j], nombres[j + 1]);
                    cantidades[j] = cantidades[j + 1];
                    precios[j] = precios[j + 1];
                }

                (*numProductos)--;


                guardarDatosEnArchivo(nombres, cantidades, precios, *numProductos);

                printf("Producto eliminado exitosamente.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Producto no encontrado.\n");
        }
    } else {
        printf("No hay productos para eliminar.\n");
    }
}

void mostrarInventario(char nombres[][100], int *cantidades, float *precios, int numProductos) {
    if (numProductos > 0) {
        printf("-------------------------------------------------------\n");
        printf("|                     Inventario                      | \n");
        printf("-------------------------------------------------------\n");
        printf("%-20s %-10s %-10s\n", "Nombre", "Cantidad", "Precio");
        printf("-------------------------------------------------------\n");
        for (int i = 0; i < numProductos; i++) {
            printf("%-20s %-10d %-10.2f\n", nombres[i], cantidades[i], precios[i]);
        }
        printf("-------------------------------------------------------\n");
    } else {
        printf("El inventario está vacío.\n");
    }
}

void guardarDatosEnArchivo(char nombres[][100], int *cantidades, float *precios, int numProductos) {
    FILE *archivo = fopen("datos.txt", "w");
    if (archivo != NULL) {
        for (int i = 0; i < numProductos; i++) {
            fprintf(archivo, "%s %d %.2f\n", nombres[i], cantidades[i], precios[i]);
        }
        fclose(archivo);
        printf("Datos guardados exitosamente en el archivo.\n");
    } else {
        printf("No se pudo abrir el archivo para escritura.\n");
    }
}

void leerDatosDesdeArchivo(char nombres[][100], int *cantidades, float *precios, int *numProductos) {
    FILE *archivo = fopen("datos.txt", "r");
    if (archivo != NULL) {
        *numProductos = 0;
        while (fscanf(archivo, "%s %d %f", nombres[*numProductos], &cantidades[*numProductos], &precios[*numProductos]) == 3) {
            (*numProductos)++;
        }
        fclose(archivo);
        printf("Datos cargados exitosamente desde el archivo.\n");
    } else {
        printf("No se pudo abrir el archivo para lectura.\n");
    }
}

int validarCedula(char cedula[]) {

    if (strlen(cedula) != 10) {
        return 0;  
    }

    for (int i = 0; i < 10; i++) {
        if (!isdigit(cedula[i])) {
            return 0;  
        }
    }

    return 1;  
}

void ingresarCliente(char nombresClientes[][100], char cedulasClientes[][20], int *numClientes) {
    if (*numClientes < 100) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", nombresClientes[*numClientes]);

        char cedula[20];
        do {
            printf("Ingrese el numero de cedula del cliente: ");
            scanf("%s", cedula);

            if (!validarCedula(cedula)) {
                printf("Cedula invalida. Por favor, ingrese una cedula valida.\n");
            }
        } while (!validarCedula(cedula));

        strcpy(cedulasClientes[*numClientes], cedula);

        (*numClientes)++;
        printf("Cliente ingresado exitosamente.\n");
    } else {
        printf("No se pueden ingresar más clientes, límite alcanzado.\n");
    }
}


void editarCliente(char nombresClientes[][100], char cedulasClientes[][20], int numClientes) {
    if (numClientes > 0) {
        char cedulaBuscada[20];
        printf("Ingrese el numero de cedula del cliente que desea editar: ");
        scanf("%s", cedulaBuscada);

        int encontrado = 0;
        for (int i = 0; i < numClientes; i++) {
            if (strcmp(cedulasClientes[i], cedulaBuscada) == 0) {
                printf("Ingrese el nuevo nombre del cliente: ");
                scanf("%s", nombresClientes[i]);

                printf("Cliente editado exitosamente.\n");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("Cliente no encontrado.\n");
        }
    } else {
        printf("No hay clientes para editar.\n");
    }
}

void mostrarClientes(char nombresClientes[][100], char cedulasClientes[][20], int numClientes) {
    if (numClientes > 0) {
        printf("-------------------------------------------------------\n");
        printf("|                     Lista de Clientes               | \n");
        printf("-------------------------------------------------------\n");
        printf("%-20s %-20s\n", "Nombre", "Cedula");
        printf("-------------------------------------------------------\n");
        for (int i = 0; i < numClientes; i++) {
            printf("%-20s %-20s\n", nombresClientes[i], cedulasClientes[i]);
        }
        printf("-------------------------------------------------------\n");
    } else {
        printf("La lista de clientes está vacía.\n");
    }
}

void facturar(char nombres[][100], int *cantidades, float *precios, int *numProductos, char nombresClientes[][100], char cedulasClientes[][20], int numClientes, char fechaFactura[][20], int *numFacturas, int cantidadesFactura[], float preciosFactura[], int *numItemsFactura, float *totalFactura) {
    if (*numProductos > 0 && numClientes > 0) {
       
        char cedulaBuscada[20];
        printf("Ingrese el numero de cedula del cliente que realiza la compra: ");
        scanf("%s", cedulaBuscada);

        int clienteEncontrado = 0;
        int indiceCliente;
        for (int i = 0; i < numClientes; i++) {
            if (strcmp(cedulasClientes[i], cedulaBuscada) == 0) {
                clienteEncontrado = 1;
                indiceCliente = i;
                break;
            }
        }

        if (clienteEncontrado) {
       
            printf("Ingrese la fecha de la factura: ");
            scanf("%s", fechaFactura[*numFacturas]);

            char nombreProductoBuscado[100];
            do {
                printf("Ingrese el nombre del producto a agregar a la factura (o 'fin' para finalizar): ");
                scanf("%s", nombreProductoBuscado);

                if (strcmp(nombreProductoBuscado, "fin") != 0) {
                    for (int i = 0; i < *numProductos; i++) {
                        if (strcmp(nombres[i], nombreProductoBuscado) == 0) {
                            printf("Ingrese la cantidad de %s comprada: ", nombreProductoBuscado);
                            scanf("%d", &cantidadesFactura[*numItemsFactura]);

                            if (cantidadesFactura[*numItemsFactura] <= cantidades[i]) {
                                preciosFactura[*numItemsFactura] = precios[i];
                                *totalFactura += cantidadesFactura[*numItemsFactura] * preciosFactura[*numItemsFactura];

                              
                                cantidades[i] -= cantidadesFactura[*numItemsFactura];

                                (*numItemsFactura)++;
                            } else {
                                printf("No hay suficiente cantidad en el inventario para %s.\n", nombreProductoBuscado);
                            }

                            break;
                        }
                    }
                }
            } while (strcmp(nombreProductoBuscado, "fin") != 0);

         
            printf("-------------------------------------------------------\n");
            printf("|                     Factura                         | \n");
            printf("-------------------------------------------------------\n");
            printf("Cliente: %s\n", nombresClientes[indiceCliente]);
            printf("Cedula: %s\n", cedulasClientes[indiceCliente]);
            printf("Fecha: %s\n", fechaFactura[*numFacturas]);
            printf("-------------------------------------------------------\n");
            printf("%-20s %-10s %-10s %-10s\n", "Nombre", "Cantidad", "Precio Unit.", "Subtotal");
            printf("-------------------------------------------------------\n");
            for (int i = 0; i < *numItemsFactura; i++) {
                printf("%-20s %-10d %-10.2f %-10.2f\n", nombres[i], cantidadesFactura[i], preciosFactura[i], cantidadesFactura[i] * preciosFactura[i]);
            }
            printf("-------------------------------------------------------\n");
            printf("Total: %.2f\n", *totalFactura);

            (*numFacturas)++;

          
            guardarDatosEnArchivo(nombres, cantidades, precios, *numProductos);

            printf("Factura generada exitosamente.\n");
        } else {
            printf("Cliente no encontrado. Por favor, ingrese un cliente válido.\n");
        }
    } else {
        printf("No hay productos o clientes para generar una factura.\n");
    }
}
