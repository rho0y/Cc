#include <stdio.h>
#include <string.h>
#include "funciones.h"

int menu() {
    int opc;
    printf("GESTION DE VENTAS \n");
    printf("1. Ingresar productos \n");
    printf("2. Hacer venta\n");
    printf("3. Buscar venta\n");
    printf("4. Imprimir ventas \n");
    printf("5. SALIR \n");
    printf("Seleccione una opcion: ");
    scanf("%d", &opc);
    return opc;
}

void leercadena(char *cadena, int num ){
    fflush(stdin);
    fgets(cadena,num,stdin);
    int len=strlen (cadena)-1;
    cadena[len]='\0';
}

void Ingresar_productos(struct productos product[3],int cont){
    printf("INGRESO DE PRODUCTOS(MAXIMO 3)");
    printf("Ingrese el nombre del producto %d:",cont+1);
    leercadena(product[cont].nombre_pro ,30);
    printf("Ingrese el precio %d:",cont+1);
    scanf("%d",&product[cont].precio);
}

void lista_productos(struct productos product[3], int cont){
    printf("LISTA DE PRODUCTOS \n");
    for (int i = 0; i < cont; i++)
    {
        printf("Producto %d: %s, Precio: %d\n", i+1, product[i].nombre_pro, product[i].precio);
    }
}

void hacer_venta(struct ventas venta[10], struct productos product[3], int cont, int total_productos) {
    printf("INGRESO DE VENTAS (MAXIMO 10)\n");
    printf("Ingrese el nombre del cliente %d:", cont + 1);
    leercadena(venta[cont].nombre_cliente, 30);
    printf("Ingrese la cedula del cliente %d:", cont + 1);
    scanf("%d", &venta[cont].cedula);

    printf("Seleccione los productos que desea comprar:\n");
    float total_venta = 0.0;
    for (int i = 0; i < total_productos; i++) {
        printf("%d. %s - Precio: %d\n", i + 1, product[i].nombre_pro, product[i].precio);
    }

    int opcion;
    char continuar;
    do {
        printf("Ingrese el numero del producto que desea comprar: ");
        scanf("%d", &opcion);
        if (opcion > 0 && opcion <= total_productos) {
            total_venta += product[opcion - 1].precio;
            printf("Producto agregado: %s\n", product[opcion - 1].nombre_pro);
        } else {
            printf("Opcion invalida. Intente nuevamente.\n");
        }
        printf("Desea agregar otro producto? (s/n): ");
        fflush(stdin);
        scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');

    venta[cont].Total_ventas = total_venta;
    printf("Total de la venta %d: %.2f\n", cont + 1, total_venta);
}
