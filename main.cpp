#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <time.h>
#include <string>
using namespace std;
#include "fecha.h"
#include "clases.h"
#include "Menus.h"
#include "Actividades.h"
#include "clientes.h"
#include "pagos.h"
void copy_file(string, string);
void HacerBackup();
void Recuperar();
void Configuracion();
bool existeArchivo(int);


int main()
{
    textcolor(15,4);
   int op;
   while(true){
        textcolor(15,4);
       Borrar();


    MenuPrincipal();


op=Mouse(26,56,8,22);///llama a la funcion mouse, esta compara si el mouse hizo click dentro de un recuadro que abarca todo el menu
            /// si lo hizo retorna la posicion de Y en la que se hizo click, esta se guarda en "op" para usarla en el switch
///cout<<"op::::::"<<op<<endl;pause();  /// Este cout muestra la posicion de Y que devolvio la funcion anterior (solo usar como guia, borrar al finalizar)

/// los case siempre son 3 menos en el primero, esto es para que al hacer click en la linea superior o inferior del recuadro cuente como click en el centro
/// esos case son posicion central + - 1 (ej: posicion central = 4, los case seran 3 - 4 - 5 )
   switch(op){

       case 8:
       case 9:
        case 10:textcolor(15,4);
           Borrar();







            if(existeArchivo(1))
            Cliente();
            else{break;}
            break;
       case 11:
        case 12:
        case 13:textcolor(15,4);
            Borrar();
               Actividades();
            break;
       case 14:
        case 15:
        case 16:textcolor(15,4);
            Borrar();
            if(existeArchivo(2))
              Pagos();
            else{break;}
            break;
        case 17:
        case 18:
        case 19:textcolor(15,4);
        Borrar();
            MenuConfiguraciones();
            Configuracion();
            break;
        case 20:
        case 21:
        case 22:cout<<"\n"<<"\n";exit(0);
            break;
   }///SWITCH

   }///While


    return 0;
}



void Configuracion(){
int op;
            op=Mouse(26,56,9,16);
            switch(op){
        case 8:
        case 9:
        case 10:
                 HacerBackup();
            break;
        case 11:
        case 12:
        case 13:
                Recuperar();
            break;
         case 14:
        case 15:
        case 16:

            break;
            }/// switch
            Borrar();

}

void copy_file(string ruta, string destino)
{
 FILE * archivo;
 string cadena;
 if (archivo = fopen(ruta.c_str(), "r"))
 {
  cadena = "copy " + ruta + " " + destino;
  system(cadena.c_str());
  fclose(archivo);
 }
 else
 {
   cout << "ARCHIVO INEXISTENTE" << endl;
 }
}

void HacerBackup()
{
    int opcion;
  /// "Ruta del archivo: ";
  string ruta;
  ///getline(cin, ruta);
  ///"Destino: ";
  string destino;
  ///getline(cin, destino);
  Borrar();
    MenuBKP();
    opcion=Mouse(20,64,8,28);
    ///cout<<"op::::::"<<opcion<<endl;pause();
    switch(opcion){
    case 8:
    case 9:
    case 10:
        ///actividad
        ruta="actividades.dat";
        destino="actividades.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        ///actividad por cliente
        ruta="actividadesClientes.dat";
        destino="actividadesClientes.bkp";
        gotoxy(30,31);
        copy_file(ruta, destino);
         ///actividad Horario
        ruta="HorariosActividades.dat";
        destino="HorariosActividades.bkp";
        gotoxy(30,32);
        copy_file(ruta, destino);
         ///Clientes
        ruta="clientes.dat";
        destino="clientes.bkp";
        gotoxy(30,33);
        copy_file(ruta, destino);

        ///Pagos
        ruta="pagos.dat";
        destino="pagos.bkp";
        gotoxy(30,34);
        copy_file(ruta, destino);
        gotoxy(30,35);
        Pausa();
        return;
        break;
    case 11:
    case 12:
    case 13:
        ///actividad
        ruta="actividades.dat";
        destino="actividades.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 14:
    case 15:
    case 16:
         ///Clientes
        ruta="clientes.dat";
        destino="clientes.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 17:
    case 18:
    case 19:
        ///actividad por cliente
        ruta="actividadesClientes.dat";
        destino="actividadesClientes.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 20:
    case 21:
    case 22:
         ///actividad Horario
        ruta="HorariosActividades.dat";
        destino="HorariosActividades.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 23:
    case 24:
    case 25:
         ///Pagos
        ruta="pagos.dat";
        destino="pagos.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        ruta="yaPago.dat";
        destino="yaPago.bkp";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 26:
    case 27:
    case 28:
        return;
        break;

    }///switch
return;
}

void Recuperar()
{
   int opcion;
  /// "Ruta del archivo: ";
  string ruta;
  ///getline(cin, ruta);
  ///"Destino: ";
  string destino;
  ///getline(cin, destino);
  Borrar();
    MenuRecuperar();
    opcion=Mouse(20,64,8,28);
    ///cout<<"op::::::"<<opcion<<endl;pause();
    switch(opcion){
    case 8:
    case 9:
    case 10:
        ///actividad
        ruta="actividades.bkp";
        destino="actividades.dat";
        gotoxy(30,30);
        copy_file(ruta, destino);
        ///actividad por cliente
        ruta="actividadesClientes.bkp";
        destino="actividadesClientes.dat";
        gotoxy(30,31);
        copy_file(ruta, destino);
         ///actividad Horario
        ruta="HorariosActividades.bkp";
        destino="HorariosActividades.dat";
        gotoxy(30,32);
        copy_file(ruta, destino);
         ///Clientes
        ruta="clientes.bkp";
        destino="clientes.dat";
        gotoxy(30,33);
        copy_file(ruta, destino);

        ///Pagos
        ruta="pagos.bkp";
        destino="pagos.dat";
        gotoxy(30,34);
        copy_file(ruta, destino);
        gotoxy(30,35);
        Pausa();
        break;
    case 11:
    case 12:
    case 13:
        ///actividad
        ruta="actividades.bkp";
        destino="actividades.dat";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 14:
    case 15:
    case 16:
         ///Clientes
        ruta="clientes.bkp";
        destino="clientes.dat";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 17:
    case 18:
    case 19:
        ///actividad por cliente
        ruta="actividadesClientes.bkp";
        destino="actividadesClientes.dat";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 20:
    case 21:
    case 22:
         ///actividad Horario
        ruta="HorariosActividades.bkp";
        destino="HorariosActividades.dat";
        gotoxy(30,30);
        copy_file(ruta, destino);
        Pausa();
        break;
    case 23:
    case 24:
    case 25:
         ///Pagos
        ruta="pagos.bkp";
        destino="pagos.dat";
        copy_file(ruta, destino);
         ruta="yaPago.bkp";
        destino="yaPago.dat";
        copy_file(ruta, destino);
        gotoxy(30,30);
        Pausa();
        break;
    case 26:
    case 27:
    case 28:
        return;
        break;

    }///switch
return;
}///funcion




bool existeArchivo(int IdArchivo){
int x;
	FILE *p;
	p=fopen("actividades.dat","rb");
	if(p==NULL)
		{
        Borrar();
		switch(IdArchivo){
    case 1:
        cout<<"NO HAY ACTIVIDADES CARGADAS"<<endl;
		cout<<"INGRESE ACTIVIDAD NUEVA PARA DAR ALTA A USUARIOS"<<endl<<endl;
        break;
    case 2:
        cout<<"NO HAY CLIENTES CARGADOS"<<endl;
		cout<<"INGRESE UN NUEVO CLIENTE  PARA GESTIONAR PAGOS"<<endl<<endl;
        break;
    default:
       cout<<"NO DEBERIA ENTRAR EN DEFAULT"<<endl;
        break;


		}

        system("pause");
		return false;
		}
	fclose(p);
	return true;
	}


