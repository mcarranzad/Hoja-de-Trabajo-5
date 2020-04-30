/*
Realice un programa que genere la venta de compra de un terreno/casa/departamento. Este programa
debe realizar los cálculos de acuerdo con la tabla abajo listada:


Dada la categoría, zona, tipo y el área del terreno o inmueble determine a cuánto asciende el monto que
deberá pagar para comprar el inmueble. 

El programa desarrollado deberá de ser capaz de generar un
reporte de el total vendido por categoría, zona y tipo de inmueble. */

#include <iostream>
#include <string>
using namespace std;

string categoria[2]={"Comercial","Residencial"}; 
string zona[3]={"A","B","C"};
string tipo[3]={"Terreno     ","Casa \t \t","Departamento"};

int categoria_cuenta[2]={0,0}; 
int zona_cuenta[3]={0,0,0};
int tipo_cuenta[3]={0,0,0};
float grantotal=0;



struct inmuebles{
  int categoria;
  int  zona;
  int  tipo;
  float precio;
} inmueble[15], cuenta[15];

void inicio_variables(){
  inmueble[0]={0,0,0,2200.00};
  inmueble[1]={0,0,1,2500};
  inmueble[2]={0,0,2,2100};

  inmueble[3]={0,1,0,1300};
  inmueble[4]={0,1,1,1500};
  inmueble[5]={0,1,2,1200};

  inmueble[6]={1,0,0,2100};
  inmueble[7]={1,0,1,2500};
  inmueble[8]={1,0,2,2100};

  inmueble[9]={1,1,0,1500};
  inmueble[10]={1,1,1,1600};
  inmueble[11]={1,1,2,1300};
  
  inmueble[12]={1,2,0,1100};
  inmueble[13]={1,2,1,1300};
  inmueble[14]={1,2,2,1000};

  cuenta[0]={0,0,0,0};
  cuenta[1]={0,0,1,0};
  cuenta[2]={0,0,2,0};

  cuenta[3]={0,1,0,0};
  cuenta[4]={0,1,1,0};
  cuenta[5]={0,1,2,0};

  cuenta[6]={1,0,0,0};
  cuenta[7]={1,0,1,0};
  cuenta[8]={1,0,2,0};

  cuenta[9]={1,1,0,0};
  cuenta[10]={1,1,1,0};
  cuenta[11]={1,1,2,0};
  
  cuenta[12]={1,2,0,0};
  cuenta[13]={1,2,1,0};
  cuenta[14]={1,2,2,0};
};


void mostrar(){
  for (int i=0; i<15; i++){
    //cout << inmueble[i].categoria << "\n";
      cout << i+1 << ") ";
      cout << categoria[inmueble[i].categoria] << "\t";
      cout << zona[inmueble[i].zona] << "\t";
      cout << tipo[inmueble[i].tipo] << "\t";
      cout << inmueble[i].precio << "\n";
  }
};

// Calcula el metro cuadrado por la opcion selecionada
float calculo(int opcion, float metros){
  float total;

  total=inmueble[opcion].precio*metros;

  return total;
}

void ingreso(){
  int var;
  float metr, total;

  cout << "Ingrese la opcion a elegir: ";
  cin >> var;
  cout << "Ingrese los metros cuadrados a comprar: ";
  cin >> metr;
  var=var-1;

  // Contamos la categoria, zona y tipo
  cuenta[var].precio=cuenta[var].precio=+1;

  // Aca indicamos cuantos hay en Categoria, Zona y Tipo, los aderimos a la cuenta
  // respectiva.
  categoria_cuenta[cuenta[var].categoria]=categoria_cuenta[cuenta[var].categoria]+1;
  zona_cuenta[cuenta[var].zona]=zona_cuenta[cuenta[var].zona]+1;
  tipo_cuenta[cuenta[var].tipo]=tipo_cuenta[cuenta[var].tipo]+1;

  total=calculo(var,metr);

  //El monto total a pagar
  grantotal=grantotal+total;

  
  // Es un presione para continuar
  getchar();
  string empty;
  getline(cin, empty);

}

void reporte(){
  
  cout << "El total de categorias son: " << "\n";
  for (int x=0; x<2; x++){
    cout << categoria[x] << ": " << categoria_cuenta[x] << endl;  
  }
  cout << "\n";

  cout << "El total de zonas  son: " << "\n";
  for (int x=0; x<3; x++){
    cout << zona[x] << ": " << zona_cuenta[x] << endl;
  }
  cout << "\n";  

  cout << "El total de tipos son: " << "\n";
  for (int x=0; x<3; x++){
    cout << tipo[x] << ": " << tipo_cuenta[x] << endl;
  }
  cout << "\n \n";

  cout << "El monto total a pagar es de :" << grantotal << endl;
  // Es un presione para continuar
  getchar();
  string empty;
  getline(cin, empty);
};


void menu(){
  char tecla;
  string empty;
  bool bandera=false;
  
  do
    {
        system("clear");
        cin.clear();
        cout << "Venta Inmobiliaria" << endl;
        cout << "-----------" << endl << endl;
        cout << "\t1 .- Comprar Activo" <<endl;
        cout << "\t2 .- Mostrar Reporte" <<endl;
        cout << "\t3 .- Salir" << endl << endl;
        cout << "Elije una opcion: ";
 
        cin >> tecla;
 
		switch(tecla)
    		{
			case '1':
				system("clear");
        mostrar();
        ingreso();
        break;
 
			case '2':
        system("clear");
        reporte();
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