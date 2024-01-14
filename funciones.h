void ingresarProducto(char nombres[][100], int *cantidades, float *precios, int *numProductos);
void editarProducto(char nombres[][100], int *cantidades, float *precios, int numProductos);
void eliminarProducto(char nombres[][100], int *cantidades, float *precios, int *numProductos);
void mostrarInventario(char nombres[][100], int *cantidades, float *precios, int numProductos);
void guardarDatosEnArchivo(char nombres[][100], int *cantidades, float *precios, int numProductos);
void leerDatosDesdeArchivo(char nombres[][100], int *cantidades, float *precios, int *numProductos);
void ingresarCliente(char nombresClientes[][100], char cedulasClientes[][20], int *numClientes);
void editarCliente(char nombresClientes[][100], char cedulasClientes[][20], int numClientes);
void mostrarClientes(char nombresClientes[][100], char cedulasClientes[][20], int numClientes);
void facturar(char nombres[][100], int *cantidades, float *precios, int *numProductos, char nombresClientes[][100], char cedulasClientes[][20], int numClientes, char fechaFactura[][20], int *numFacturas, int cantidadesFactura[], float preciosFactura[], int *numItemsFactura, float *totalFactura);


