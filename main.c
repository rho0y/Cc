#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    struct productos product[3];
    struct ventas venta[10];
    int total_productos = 0, total_ventas = 0;

    while (1) {
        int opc = menu();
        switch (opc) {
            case 1:
                if (total_productos < 3) {
                    Ingresar_productos(product, total_productos);
                    total_productos++;
                } else {
                    printf("No se pueden ingresar mas productos.\n");
                }
                break;
            case 2:
                if (total_ventas < 10) {
                    hacer_venta(venta, product, total_ventas, total_productos);
                    total_ventas++;
                } else {
                    printf("No se pueden realizar mas ventas.\n");
                }
                break;
            case 3:
                printf("Funcionalidad de buscar venta no implementada.\n");
                break;
            case 4:
                printf("Funcionalidad de imprimir ventas no implementada.\n");
                break;
            case 5:
                printf("Saliendo del programa.\n");
                return 0;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    }
}
