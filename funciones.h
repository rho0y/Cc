#define funciones_h

struct ventas{

    char nombre_cliente [30];
    int cedula ;
    float Total_ventas;


};
struct productos {

    char nombre_pro [30];
    int precio;
    
};

int menu();
void leercadena (char *cadena, int num);
void Ingresar_productos(struct productos product[3],int cont);
void lista_productos (struct productos product[3], int cont);
void hacer_venta(struct ventas venta[10], struct productos product[3], int cont, int total_productos);
struct ventas*buscarventa(struct ventas venta [10],int cont,char ventaAbuscar[50]);
