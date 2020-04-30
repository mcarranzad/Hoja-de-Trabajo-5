/*
Una persona desea comprar entradas para un concierto que
se realizará en la explanada de cierto lugar de la ciudad. 
El precio de la entrada varía según la zona elegida, así 
tenemos que la lista de precios es la siguiente:

Zona Identificación Precio
VIP V 350.00
Platea P 130.00
Popular E 50.00

Adicionalmente los precios tendrán un descuento en función
del número de entradas que se compran, así como si la persona 
que las adquiere es socio o no. 

Se le pide elaborar un programa 
en C++ que solicite la zona elegida, el número de entradas a
comprar y consulte si es socio o no y nos determine y muestre
el monto a pagar por la compra de las entradas. Todas las ventas
deben de ser grabadas un archivo de datos, así mismo el programa
de ser capaz de mostrar el monto total de lo vendido globalmente
y por tipo de entrada mostrando también el porcentaje respecto al 
total global vendido. 

*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

struct zonas{
  string descripcion;
  string codigo;
  float precio;
  int cantidad;
  float grantotal;
} zona[3];

struct compras{
  string zona;
  int cantidad;
  bool miembro;
  float total;
};

//vector<compras> boletos;

void inicio_variables(){
  //Precios por zona
  zona[0]={"VIP","V",350.00,0,0};
  zona[1]={"PLATEA","P",130.00,0,0};
  zona[2]={"POPULAR","E",50.00,0,0};
};

float calculo(string codigo, int cantidad, bool miembro){
  float total=0, descuento;
  int intzona=0;

  // Comprobamos la zona
  if ((codigo=="V") || (codigo=="v" )){
    intzona=0;
  } else if ((codigo=="P") || (codigo=="p")) {
    intzona=1;
  } else if ((codigo=="E") || (codigo=="e")) {
    intzona=2;
  } else {
    cout << "no hay nada" << endl;
  }

  // hacemos el calculo de precio en base a la zona
  total=cantidad*zona[intzona].precio;
  
  if ((cantidad>=3) and (cantidad<=6)){
    descuento=0.05;
  } else if ((cantidad>=7) and (cantidad<=9)){
    descuento=0.075;
  } else if (cantidad>9){
    descuento=0.10;
  } else {
    descuento=0;
  }
  // Aplicamos el descuento según la cantidad comprada
  total=total-(total*descuento);

  // Verificamos si es miembro para hacer un descuento
  // del 8% adicional
  if (miembro==true) {
    total=total-(total*0.08);
  }

  // devolvemos el calculo
  return total;
};

void ingreso(){
  // Estructura de compras
  compras x;
  string var1;

  cout << "Ingrese la zona selecionada: ";
  cin >> x.zona;

  cout << "Ingrese la cantidad de boletas a comprar: ";
  cin >> x.cantidad;

  cout << "Es miembro honorario: ";
  cin >> var1;

  // si es si, manda un true, de lo contrario un false.
  if ((var1=="si") or (var1=="SI")) {
    x.miembro=true;
  } else {
    x.miembro=false;
  }

  // llamamos la función para realizar el calculo.
  x.total=calculo(x.zona, x.cantidad, x.miembro);

  string miem;
  if (x.miembro==true) {
    miem="s";
  } else {
    miem="n";
  }
  //abrimos el archivo.
  ofstream archivo("venta_boletos.txt", ios::app);

  // Escribimos en el archivo
  archivo<<x.zona<< "\t" << x.cantidad << "\t" <<  miem << "\t" << x.total << "\n";

  // Cerramos el archivo
  archivo.close();

};

void leer(){
    //Iniciamos varibles para la cuenta de la lectura del archivo.
    inicio_variables();

    float grantotal=0;
    int grancantidad=0;
    string miem;

    //declaramos la clase de lectura de archivo
    ifstream archivo;
    
    compras x;
  
    	
	  try{
      archivo.open("venta_boletos.txt",ios::in);
		
  		while(archivo >> x.zona >> x.cantidad >> miem >> x.total){
        if ((x.zona=="V") || (x.zona=="v")){
          zona[0].cantidad=zona[0].cantidad+x.cantidad;
          zona[0].grantotal=zona[0].grantotal+x.total;
        } else if ((x.zona=="P") || (x.zona=="p")){
          zona[1].cantidad=zona[1].cantidad+x.cantidad;
          zona[1].grantotal=zona[1].grantotal+x.total;
        } else if ((x.zona=="E") || (x.zona=="e")) {
          zona[2].cantidad=zona[2].cantidad+x.cantidad;
          zona[2].grantotal=zona[2].grantotal+x.total;
        }

        // sumamos el total de los boletos vendidos
        grantotal=grantotal+x.total;
        //Contamos la cantidad de boletos vendidos
        grancantidad=grancantidad+x.cantidad;
      }

		  archivo.close();

      for (int x=0; x<3; x++){
        float porcentaje=0;
        cout << "El total vendido por zona "<< zona[x].descripcion << ": " << zona[x].cantidad << endl;
        cout << "Con un monto total de: "<< zona[x].grantotal << endl;
        porcentaje=(zona[x].cantidad*100)/grancantidad;
        cout << "El porcentaje total de venta es de " << porcentaje <<"%" << "\n" << endl;
      }
      cout << "El gran total de venta es de: "<< grantotal << endl;

      // hacemos una pausa
      string empty;
      getchar();
      getline(cin, empty);
      return;
    }
	  catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;			
      
			exit(1);
	  }
};


void menu(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Venta de boletos" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Vender Boletos" <<endl;
        cout << "\t2 .- Mostrar Venta Global" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        //mostrar();
        ingreso();
        break;
 
			case '2':
        system("clear");
        leer();
        break;
      
      case '3':
				bandera=true;
				//exit(1);
				break;
 
			default:
				system("clear");
				cout << "Opcion no valida.\a\n";
				getchar();
        getline(cin, empty);
				break;
		}
    }while(bandera!=true);
}



int main(){
  inicio_variables();
  menu();
  return 0;
}


