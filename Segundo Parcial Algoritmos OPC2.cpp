/*Autor: Josué Godoy
  Facultad: Ingenieria En Ciencias Y Sistemas
  Programa: Base De Datos
  Descripción: Programa para crear una base de datos
  Fecha: 16-09-21
  Sede: La Florida
  Seccion: "A"
  Licenciado: Agusto Armando Cardona*/
#include <iostream>
#include <locale.h>
#include <string.h>
#include <fstream>
#include <cstdlib> 
#include <windows.h>
using namespace std;
int menu(){
	setlocale(LC_ALL, "Spanish");
	int Base_Empleados = 0;
	int x;
	system("cls");
	cout << "\n\t------BIENVENIDOS A LA BASE DE DATOS DE EMPLEADOS------" << endl;
	cout << "\n\t---------Menú---------" << endl;
	cout<<"\n\t1. Ingresar Empleado: "<<endl;
	cout<<"\n\t2. Empleado a Verificar: "<<endl;
	cout<<"\n\t3. Empleado a Buscar: "<<endl;
	cout<<"\n\t4. Modificar Empleado: "<<endl;
	cout<<"\n\t5. Eliminar a un Empleado: "<<endl;
	cout<<"\n\t6. Salir Del Menú"<<endl;
	cout<<"\n\t-----------------------"<<endl;
	cout<<"\n\tSelecione la Opcion a Utilizar: ";
	cin>>x;
	return x;
}

bool verificacion(string ID){
 ifstream leer ("Base.dat", ios::in);
 string Cod;
 string Nom;
 string Ape;
 string pues;
 int suel;
 int boni;
 int suma;
 leer>>Cod;
 while(!leer.eof()){
  leer>>Nom;
  leer>>Ape;
  leer>>pues;
  leer>>suel;
  leer>>boni;
  leer>>suma;
  if(Cod == Cod){
   cout<<"\n\n\tError: El Registro Ingresado se Encuentra Duplicado.\n\n";
   system("pause");
   leer.close();
   return false;
  }
  leer>>Cod;
 }
   leer.close();
   return true; 
}

void Ingresar_Dato(ofstream &es) {
	system("cls");
	string Cod;
	string Nom;
	string Ape;
	string pues;
	int suel;
	int boni;
	int suma;
	es.open("Base.dat", ios::out| ios::app);
	cout<<"Codigo: ";
	cin>>Cod;
	cout<<"Nombre: ";
	cin>>Nom;
	cout<<"Apellido: ";
	cin>>Ape;
	cout<<"Puesto: ";
	cin>>pues;
	cout<<"Sueldo: ";
	cin>>suel;
	cout<<"Bonificacion: ";
	cin>>boni;
	suma = suel + boni;
	cout<<"La totalidad del sueldo es:  "<<suma<<endl;
	if(verificacion(Cod))
		es<<Cod<<" "<<Nom<<" "<<Ape<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";
	es.close();
	}
	
void Verificar_Registros(ifstream &Lec){
	system("cls");
	string Cod;
 	string Nom;
 	string Ape;
 	string pues;
 	int suel;
 	int boni;
 	int suma;
 	Lec.open("Base.dat", ios::in);
 	if(Lec.is_open()){
	 	cout<<"-------Registro De Base-------"<<endl<<endl;
	 	Lec>>Cod;
	 	while(!Lec.eof()){
			Lec>>Nom;
			Lec>>Ape;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			Lec>>suma;
			cout<<"-Codigo: "<<Cod<<endl;
			cout<<"-Nombre: "<<Nom<<endl;
			cout<<"-Apellido: "<<Ape<<endl;
			cout<<"-Puesto: "<<pues<<endl;
			cout<<"-Sueldo: "<<suel<<endl;
			cout<<"-Bonificacion: "<<boni<<endl;
			cout<<"-Sueldo a Recibir: "<<suma<<endl;
			cout<<"----------------------"<<endl;
			Lec>>Cod;
		 }
		 Lec.close();
	}else
		cout<<"Error"<<endl;
	 system("pause");
}

void Buscar_El_Dato(ifstream &Lec){
	system("cls");
	Lec.open("registro.dat", ios::in);
	string Cod, Nom, Ape, pues, Codaux;
	int suel, boni, suma;
	bool encontrado = false;
	cout<<"Digite El Codigo Del Usuario: ";
	cin>>Codaux;
	Lec>>Cod;
	while(! Lec.eof() && !encontrado){	
		Lec>>Cod;
		Lec>>Nom;
		Lec>>Ape;
		Lec>>pues;
		Lec>>suel;
		Lec>>boni;
		Lec>>suma;
		if(Cod == Codaux){
			cout<<"Codigo: "<<Cod<<endl;
			cout<<"Nombre: "<<Nom<<endl;
			cout<<"Apellido: "<<Ape<<endl;
			cout<<"Puesto: "<<pues<<endl;
			cout<<"Sueldo: "<<suel<<endl;
			cout<<"Bonificacin: "<<boni<<endl;
			cout<<"Sueldo Total: "<<suma<<endl;
			cout<<"----------------------"<<endl;
			encontrado = true;
		}	
		Lec>>Cod;
	}
	Lec.close();
	
	if(!encontrado)
		cout<<"No Existe"<<endl<<endl;
	system("pause");
}

void Modificar_Texto(ifstream &Lec){
	system("cls");
 	string Cod;
	string Nom;
 	string Ape;
	string pues;
	int suel;
	int boni;
	int suma;
	string Codaux;
	string Nomaux;
	string Apeaux;
	string puesaux;
	int suelaux;
	int boniaux;
	int sumaux;
	Lec.open("Base.dat", ios::in);
	ofstream aux("auxiliar.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Datos a Modificar--------------------"<<endl;
		cout<<"Ingrese dato Codigo:  ";
		cin>>Codaux;
		Lec>>Cod;
		while(!Lec.eof()){
			Lec>>Nom;
		  	Lec>>Ape;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			if(Cod == Codaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese Nombre: ";
				cin>>Nomaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese apellido: ";
				cin>>Apeaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingres el Puesto que posee: ";
				cin>>puesaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese el Sueldo: ";
				cin>>suelaux;
				cout<<"--------------------------------------"<<endl;
				cout<<"Ingrese la bonificacion: ";
				cin>>boniaux;
			
				sumaux = suelaux + boniaux;
				aux<<Cod<<" "<<Nomaux<<" "<<Apeaux<<" "<<puesaux<<" "<<suelaux<<" "<<boniaux<<" "<<sumaux<<"\n";
				cout<<"--------------------------------------"<<endl;
			}else{
				suma = suel + boni;
				aux<<Cod<<" "<<Nom<<" "<<Ape<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";
			}
			Lec>>Cod;
			Lec>>Nom;
		}
		Lec.close();
		aux.close();
		
	}else 
		cout<<"Error"<<endl;
	remove ("Base.dat");
	rename("auxiliar.dat", "Base.dat");
}

void Eliminar_Registro(ifstream &Lec){
	system("cls");
 	string Cod;
	string Nom;
 	string Ape;
	string pues;
	int suel;
	int boni;
	int suma;
	string Codaux;
	string Nomaux;
	string Apeaux;
	string puesaux;
	int suelaux;
	int boniaux;
	int sumaux;
	Lec.open("Base.dat", ios::in);
	ofstream aux("Base.dat", ios::out);
	if(Lec.is_open()){
		cout<<"--------------Codigo a Modificar--------------------"<<endl;
		cout<<"Ingrese Codigo:  ";
		cin>>Codaux;
		Lec>>Cod;
		while(!Lec.eof()){
			Lec>>Nom;
		  	Lec>>Ape;
			Lec>>pues;
			Lec>>suel;
			Lec>>boni;
			Lec>>suma;
			if(Cod == Codaux){
				cout<<"--------------------------------------"<<endl;
				cout<<"------Existosamente ha Sido Eliminado-----"<<endl;
				Sleep(1500);
				cout<<"--------------------------------------"<<endl;
			}else{
				aux<<Cod<<" "<<Nom<<" "<<Ape<<" "<<pues<<" "<<suel<<" "<<boni<<" "<<suma<<"\n";	
			}
			Lec>>Cod;
			Lec>>Nom;
		}
		Lec.close();
		aux.close();
	}else 
		cout<<"Error"<<endl;
	remove ("Base.dat");
	rename("auxiliar.dat", "Base.dat");	
}

int main(){
	ofstream Esc;
	ifstream Lec;
	int op;
	do{
		system("cls");
		op = menu();
		switch(op){
			case 1:
				Ingresar_Dato(Esc);
			break;
			case 2:
				Verificar_Registros(Lec);
			break;
			case 3:
				Buscar_El_Dato(Lec);
			break;
			case 4:
				Modificar_Texto(Lec);
			break;
			case 5:
				Eliminar_Registro(Lec);
			break;	
		}	
	}while(op != 6);
	return 0;
}
