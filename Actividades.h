#ifndef ACTIVIDADES_H_INCLUDED
#define ACTIVIDADES_H_INCLUDED
#include "clases.h"
#include <ctype.h>///<--funcion toUpper y toLower


/**
*********************************************************************************
**                                                                             **
**                            MENU ACTIVIDADES A MOSTRAR                       **
**                                                                             **
*********************************************************************************
**                                                                             **
**  Actividad **   Hora Inicio **   Hora Fin  ** Precio ** Cantidad Inscriptos **
**            **               **             **        **                     **
**    box     **    20:00      **    22:00    **  $450  **        13           **
**            **               **             **        **                     **
*********************************************************************************

*/


//****************************
//Prototipos funciones externas
int buscar_Actividad_activa(int);
void alta_Actividad();
void modifica_nombre();
void modifica_precio();
void baja_alta_logica_ACT();
void listar_Actividades();
bool PrimeraActividad();
bool primerAcClie();
int contarActividades();
//****************************



void Actividad::Cargar()
	{
	if(PrimeraActividad()==true){
	setID(1);
	 }///si es primero asigna ID 1
    else{setID(contarActividades()+1);}
    recuadro(2,1,55,2,cBLANCO,cROJO);
    gotoxy(6,2);
    cout<<"INGRESE EL NOMBRE:  ";
    cin.ignore();///necesario para usar getline
    cin.getline(Nombre, 30);///necesario para guardar espacios entre nombres
    setNombre(Nombre);
    recuadro(2,4,47,2,cBLANCO,cROJO);
    gotoxy(6,5);
    bool ver=false;
    while(ver==false){
    cout<<"INGRESE EL PRECIO:  ";///validar precio ( >0 )
    cin>>precio;
    if(precio>0){setPrecio(precio);ver=true;}
    else{Borrar();cout<<"PRECIO INVALIDO";Borrar();}
    }
	}

void Actividad::Mostrar(int pos)
	{int y;
        if (pos==0){y=7;}
        else{y=pos+4;}

	gotoxy(1,y);
	cout<<" | "<<getID()<<" | "<<endl;
	gotoxy(13,y);
	cout<<" | "<<getNombre()<<endl;
	gotoxy(44,y);
	cout<<" | "<<"$ "<<getPrecio()<<endl;

	}

void Actividad::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("actividades.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Actividad::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("actividades.dat","rb");
	if(p==NULL)
		{
        Borrar();
		cout<<"No existe el archivo"<<endl;
        system("pause");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Actividad::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("actividades.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}





bool repetido(int acti,int clie){
Actividades_x_Cliente reg;


int pos=0;
    while (reg.Leer_de_disco(pos++)==1){
        if(reg.getID_ACT()==acti && reg.getID_Cli()==clie){return true;}
    }
return false;
}


void Actividades_x_Cliente::Cargar(int idCli)
	{

    ///NO SE PUEDE REPETIR ID CLIENTE E ID ACTIVIDAD
    int vec[3];
    bool ver=false,op=false;
    //int pos=0;
    while(ver==false){
    cout<<"INGRESE EL ID DE LA ACTIVIDAD:  ";  ///VERIFICAR EXISTENCIA
    cin>>IdActividad;
    if(buscar_Actividad_activa(IdActividad)!=-1){
    if(primerAcClie()==true){op=false;}
    else{if(repetido(IdActividad,idCli)==true){
            cout<<"CODIGO DE CLIENTE Y DE ACTIVIDAD YA EXISTEN";op=true;Pausa();Borrar();}
    }
    if(op==false){
            setIDC(idCli);
            setIDA(IdActividad); ver=true;}
    }
    }
    ver=false;

    while(ver==false){
    cout<<"DIA DE ALTA: ";
    cin>>vec[0];
    if(vec[0]>=1 && vec[0]<=7){setDiaAct(vec[0]);ver=true;}
    else{cout<<"DIA INVALIDO (1-7)";Pausa();Borrar();}
    }
    ver=false;
    while(ver==false){
    cout<<"MES DE ALTA: ";
    cin>>vec[1];
    if(vec[1]>=1 && vec[1]<=12){setMesAct(vec[1]);ver=true;}
    else{cout<<"MES INVALIDO (1-12)";Pausa();Borrar();}
	}
	ver=false;
	while(ver==false){
    cout<<"ANIO DE ALTA: ";
    cin>>vec[2];
    if(vec[2]>=2017){setAnioAct(vec[2]);ver=true;}
    else{cout<<"ANIO INVALIDO (  ANIO > 2017)";Pausa();Borrar();}
    }
    setActivo(true);
	}

void nombreActividad(int cod, char nomb[30]){
int pos=0;
Actividad reg;
while(reg.Leer_de_disco(pos++)==1){
      if(cod==reg.getID())strcpy(nomb,reg.getNombre());
      }
}


void Actividades_x_Cliente::Mostrar(int pos)
	{
        char nombA[30];
        int b;
        b=getID_ACT();
    nombreActividad(b,nombA);
    cout<<" CLIENTE "<<getID_Cli()<<" | "<<endl;
	cout<<" ACTIVIDAD "<<nombA<<endl;
	cout<<" FECHA DE ALTA "<<getDiaAlta()<<"/"<<getMesAlta()<<"/"<<getanioAlta()<<endl<<endl<<endl<<endl;

	}

void Actividades_x_Cliente::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("actividadesClientes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Actividades_x_Cliente::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("actividadesClientes.dat","rb");
	if(p==NULL)
		{
        Borrar();
		cout<<"No existe el archivo"<<endl;
        system("pause");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Actividades_x_Cliente::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("actividadesClientes.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}




void Horarios_x_Actividad::Cargar(int id)
	{

    setID(id);
    bool dia=true,hI=true,hF=true;
    while(dia==true){
    recuadro(2,4,47,2,cBLANCO,cROJO);
    gotoxy(6,5);
    cout<<"INGRESE EL DIA DE LA ACTIVIDAD:  ";
    char DiaLetras[10];
    cin>>DiaLetras;

    for(int i=0; i<10; i++){
     DiaLetras[i] = toupper(DiaLetras[i]); ///<--convierte a Mayusculas
    }
    if(strcmp(DiaLetras,"LUNES")==0){setNroDia(1);dia=false;}
    if(strcmp(DiaLetras,"MARTES")==0){setNroDia(2);dia=false;}
    if(strcmp(DiaLetras,"MIERCOLES")==0){setNroDia(3);dia=false;}
    if(strcmp(DiaLetras,"JUEVES")==0){setNroDia(4);dia=false;}
    if(strcmp(DiaLetras,"VIERNES")==0){setNroDia(5);dia=false;}
    if(strcmp(DiaLetras,"SABADO")==0){setNroDia(6);dia=false;}
    if(strcmp(DiaLetras,"DOMINGO")==0){setNroDia(7);dia=false;}
    else{cout<<endl<<endl<<"DIA INVALIDO."; Sleep(3000);}

    Borrar();
    }
    while(hI==true){
    recuadro(2,7,54,2,cBLANCO,cROJO);
    gotoxy(6,8);
    cout<<"INGRESE LA HORA DE INICIO DE LA ACTIVIDAD:  ";
    cin>>HoraInicio;
    if(HoraInicio>0 && HoraInicio<=23){
        recuadro(2,10,30,2,cBLANCO,cROJO);
        gotoxy(6,11);
        cout<<"INGRESE LOS MINUTOS: ";
        cin>>SegI;
        if(SegI>=0 && SegI<60){setHoraIni(HoraInicio);setSegI(SegI);hI=false;}
    }
    else{cout<<"HORA DE INICIO INVALIDA";}
    Borrar();
    }
    while(hF==true){
    recuadro(2,10,54,2,cBLANCO,cROJO);
    gotoxy(6,11);
    cout<<"INGRESE LA HORA DE FIN DE LA ACTIVIDAD:  ";
    cin>>HoraFin;
    if (HoraFin>=HoraInicio && HoraFin<=24){
        recuadro(2,13,30,2,cBLANCO,cROJO);
        gotoxy(6,14);
        cout<<"INGRESE LOS MINUTOS: ";
        cin>>SegF;
        if(SegF>=0 && SegF<60){
        if(HoraFin==HoraInicio){if (SegF>SegI){setHoraFin(HoraFin);setSegF(SegF);hF=false;}}
        else{setHoraFin(HoraFin);setSegF(SegF);hF=false;}
        }
    }
    else{cout<<"HORA DE FIN INVALIDA";}
    Borrar();

    }
	}



void Horarios_x_Actividad::Mostrar(int pos)
	{int y;
        if (pos==0){y=7;}
        else{y=pos+4;}
	gotoxy(36,y);
	MostrarDiaTexto(getNroDia());
	///cout<<mdia[getNroDia()-1]<<endl;
	gotoxy(55,y);
	cout<<getHsIni()<<":"<<getSegIni()<<endl;
	gotoxy(69,y);
	cout<<getHsFin()<<":"<<getSegFin()<<endl;
	}

void Horarios_x_Actividad::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("HorariosActividades.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Horarios_x_Actividad::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("HorariosActividades.dat","rb");
	if(p==NULL)
		{
        Borrar();
		cout<<"No existe el archivo"<<endl;
        system("pause");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
	}

void Horarios_x_Actividad::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("HorariosActividades.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}





///FUNCIONES EXTERNAS

void alta_Actividad()
{
	Actividad reg;
	system("cls");
	reg.Cargar();
	reg.Grabar_en_disco();
}





int contarActividades() {
FILE *p=NULL;
  Actividad aux; int cant=0;
 p= fopen("actividades.dat","rb");
if(p==NULL) {cout<< "error de apertura"; return -1;}

 while(fread(&aux,sizeof(Actividad),1,p)==1) {
        cant++;
}
fclose(p);
return cant;
}

int buscar_Actividad_existente(int cod)
{
	int pos=0;
	Actividad reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getID())
			return pos;
		pos++;
		}
	return -1;
}

int buscar_Actividad_activa(int cod)
{
	int pos=0;
	Actividad reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getID() && reg.getActivo()==true)
			return pos;
		pos++;
		}
	return -1;
}


void baja_alta_Actividad()
{
	int cod;
	int pos;
	int P;
	Actividad reg;
	system("cls");
	recuadro(30,1,20,2,cBLANCO,cROJO);
	gotoxy(35,2);
	cout<<"DAR DE ALTA";
	recuadro(30,4,20,2,cBLANCO,cROJO);
	gotoxy(35,5);
	cout<<"DAR DE BAJA";
	recuadro(24,7,30,2,cBLANCO,cROJO);
	gotoxy(28,8);
	cout<<"VOLVER AL MENU ANTERIOR ";

	P=Mouse(28,48,1,9);
	bool ver=false;
	while(ver==false){
	if(P==1||P==2||P==3){Borrar();cout<<"Ingrese el codigo de la Actividad dar de Alta: ";
	cin>>cod;
	pos=buscar_Actividad_existente(cod);
	}
	if(P==4 || P==5||P==6){Borrar(); cout<<"Ingrese el codigo de la Actividad a eliminar: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);}
	if(P==7 || P==8||P==9)return;
	if(pos != -1){ver=true;}
	else{cout<<"No existe la actividad"<<endl;system("pause");}
	}
		reg.Leer_de_disco(pos);
		if(P==4||P==5||P==6){reg.setActivo(false);}
		else{reg.setActivo(true);}
		reg.Modificar_en_disco(pos);
}

void modifica_nombre()
{
	int cod;
	char npu[30];
	int pos;
	Actividad reg;
	bool ver=false;
	while(ver==false){
	system("cls");
	cout<<"INGRESE LA ID DE LA ACTIVIDAD A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);
	if(pos!=-1){ver=true;}
	else{cout<<"No existe la actividad"<<endl;system("pause");}
	}
		cout<<"Ingrese el nuevo Nombre: ";
		cin.ignore();///necesario para usar getline
        cin.getline(npu, 30);///necesario para guardar espacios entre nombres
		reg.Leer_de_disco(pos);
		reg.setNombre(npu);
		reg.Modificar_en_disco(pos);
}

void modifica_Hora_Inicio()
{
	int cod,pos,aux,seg;
	bool ver=false;
	Horarios_x_Actividad reg;
	system("cls");
	while (ver==false){
    cout<<"INGRESE LA ID DE LA ACTIVIDAD A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);
	if(pos != -1){ver=true;}
	else{cout<<"No existe la actividad"<<endl;system("pause");}

	}
		cout<<"INGRESE LA NUEVA HORA DE INICIO: ";
		cin>>aux;
		cout<<"INGRESE LOS MINUTOS: ";
		cin>>seg;
		reg.Leer_de_disco(pos);
		reg.setHoraIni(aux);
		reg.setSegI(seg);
		reg.Modificar_en_disco(pos);


}

void modifica_Hora_Fin()
{
	int cod;
	int aux,seg;
	int pos;
	Horarios_x_Actividad reg;
	system("cls");
	bool ver=false;
	while (ver==false){
	cout<<"INGRESE LA ID DE LA ACTIVIDAD A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);
	if (pos != -1){ver=true;}
    else{cout<<"No existe la actividad"<<endl;system("pause");}
	}
		cout<<"INGRESE LA NUEVA HORA DE FINALIZACION: ";
		cin>>aux;
		cout<<"INGRESE LOS MINUTOS: ";
		cin>>seg;
		reg.Leer_de_disco(pos);
		reg.setHoraFin(aux);
        reg.setSegF(seg);
		reg.Modificar_en_disco(pos);

}


void modifica_Dia()
{
	int cod;
	int aux;
	int pos;
	Horarios_x_Actividad reg;
	system("cls");
	bool ver=false;
	while (ver==false){
	cout<<"INGRESE LA ID DE LA ACTIVIDAD A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);
	if (pos != -1){ver=true;}
    else{cout<<"No existe la actividad"<<endl;system("pause");}
	}
		cout<<"INGRESE EL NUEVO DIA DE LA ACTIVIDAD: ";
		cin>>aux;
		reg.Leer_de_disco(pos);
		reg.setNroDia(aux);
		reg.Modificar_en_disco(pos);
}

void modifica_precio()
{
	int cod;
	float npu;
	int pos;
	Actividad reg;
	bool ver=false;
	while(ver==false){
	system("cls");
	cout<<"INGRESE LA ID DE LA ACTIVIDAD A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Actividad_activa(cod);
	if(pos!=-1){ver=true;}
	else{cout<<"No existe la Actividad"<<endl;system("pause");}
	}
		cout<<"Ingrese el nuevo Precio: ";
		cin>>npu;
		reg.Leer_de_disco(pos);
		reg.setPrecio(npu);
		reg.Modificar_en_disco(pos);
}

void Modificaciones_Actividades(){
Borrar();
    recuadro(28,1,30,2,cBLANCO,cROJO);
    gotoxy(32,2);
    cout<<"CAMBIAR NOMBRE";
    recuadro(28,4,30,2,cBLANCO,cROJO);
    gotoxy(32,5);
    cout<<"CAMBIAR PRECIO";
    recuadro(28,7,30,2,cBLANCO,cROJO);
    gotoxy(32,8);
    cout<<"CAMBIAR HORA DE INICIO";
    recuadro(28,10,30,2,cBLANCO,cROJO);
    gotoxy(32,11);
    cout<<"CAMBIAR HORA DE FIN";
    recuadro(28,13,30,2,cBLANCO,cROJO);
    gotoxy(30,14);
    cout<<"CAMBIAR DIA DE LA ACTIVIDAD";
    recuadro(28,16,30,2,cBLANCO,cROJO);
    gotoxy(32,17);
    cout<<"VOLVER AL MENU ANTERIOR";
        int pos;
        pos=Mouse(28,58,1,18);
        if(pos==1||pos==2||pos==3)    modifica_nombre();
        if(pos==4||pos==5||pos==6)    modifica_precio();
        if(pos==7||pos==8||pos==9)    modifica_Hora_Inicio();
        if(pos==10||pos==11||pos==12) modifica_Hora_Fin();
        if(pos==13||pos==14||pos==15) modifica_Dia();
         if(pos==16||pos==17||pos==18) return;
}


int mesAlta(int codigoID){
Actividades_x_Cliente reg;
int pos=0;
while(reg.Leer_de_disco(pos++)==1){
    if (codigoID==reg.getID_Cli()){return reg.getMesAlta();}
}
return -1;
}
int anioAlta(int codigoID){
Actividades_x_Cliente reg;
int pos=0;
while(reg.Leer_de_disco(pos++)==1){
    if (codigoID==reg.getID_Cli()){return reg.getanioAlta();}
}
return -1;
}

bool PrimeraActividad(){
FILE *p;
	p=fopen("actividades.dat","rb");
	if(p==NULL)
		{
		return true;
		}
fclose(p);
return false;

}

bool primerAcClie(){
FILE *p;
	p=fopen("actividadesClientes.dat","rb");
	if(p==NULL)
		{
		return true;
		}
fclose(p);
return false;

}

void listar_Actividades()
	{
	Actividad reg;
	int pos=0;
	system("cls");
	recuadro(1,0,6,2,cBLANCO,cROJO);
	gotoxy(3,1);
	cout<<"ID";
	recuadro(10,0,30,2,cBLANCO,cROJO);
	gotoxy(17,1);
	cout<<"NOMBRE";
	recuadro(43,0,20,2,cBLANCO,cROJO);
	gotoxy(50,1);
	cout<<"PRECIO";

	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getActivo()==1)
			{
			   reg.Mostrar(pos);
			}
		}
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		system("pause");
		}
		recuadro(28,pos+6,32,2,cBLANCO,cROJO);
		gotoxy(32,pos+7);
		cout<<"VOLVER AL MENU ANTERIOR";
		int opcionVolver;
        opcionVolver=Mouse(28,60,pos+6,pos+8);
        if(opcionVolver>=pos+6 && opcionVolver<=pos+8){
            return;
        }
	}


void listar_Horarios_Actividades()
	{
	Horarios_x_Actividad reg;///tengo el id de la actividad
	Actividad aux;
	int pos=0;
	system("cls");
	recuadro(0,0,32,2,cBLANCO,cROJO);
	gotoxy(14,1);
	cout<<"ACTIVIDAD";
	recuadro(33,0,15,2,cBLANCO,cROJO);
	gotoxy(34,1);
	cout<<"DIA ACTIVIDAD";
	recuadro(49,0,15,2,cBLANCO,cROJO);
	gotoxy(50,1);
	cout<<"HORA DE INICIO";
	recuadro(65,0,12,2,cBLANCO,cROJO);
	gotoxy(66,1);
	cout<<"HORA DE FIN";
	int cant;
	while(reg.Leer_de_disco(pos++)==1)
		{
		    int pos2=0;
		    while(aux.Leer_de_disco(pos2++)==1){
                if (reg.getID()==aux.getID()){
                    cant=strlen(aux.getNombre());
                    if(cant>10){gotoxy(1,pos+4);}
                    else{gotoxy(14,pos+4);}
                    cout<<aux.getNombre();
                }
		    }
			   reg.Mostrar(pos);
		}
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		system("pause");
		}
		recuadro(28,pos+6,32,2,cBLANCO,cROJO);
		gotoxy(32,pos+7);
		cout<<"VOLVER AL MENU ANTERIOR";
		int opcionVolver;
        opcionVolver=Mouse(28,60,pos+6,pos+8);
        if(opcionVolver>=pos+6 && opcionVolver<=pos+8){
            return;
        }
	}



void listar_Cliente_Actividad()
	{
	Actividades_x_Cliente reg;
	int pos=0;
	system("cls");

	while(reg.Leer_de_disco(pos++)==1)
		{
		if(reg.getActivo()==1)
			{///hacer que si cambia de id cliente muestre el id del que corresponda
			    reg.Mostrar(pos);
			}
		}
	if(pos==1)
		{
		cout<<"No existen registros"<<endl;
		system("pause");
		}
		recuadro(28,pos+6,32,2,cBLANCO,cROJO);
		gotoxy(32,pos+7);
		cout<<"VOLVER AL MENU ANTERIOR";
		int opcionVolver;
        opcionVolver=Mouse(28,60,pos+6,pos+8);
        if(opcionVolver>=pos+6 && opcionVolver<=pos+8){
            return;
        }
	}

void alta_Cliente_actividad(int a)
{
	Actividades_x_Cliente reg;
	system("cls");
	reg.Cargar(a);
	reg.Grabar_en_disco();
}


void alta_horario_actividad()
{
    int aux;
    aux=contarActividades();
	Horarios_x_Actividad reg;
	system("cls");
	reg.Cargar(aux);
	reg.Grabar_en_disco();
}


//FIN FUNCIONES EXTERNAS




void Actividades(){

   int op;
   while(true){
        textcolor(cBLANCO,cROJO);
       Borrar();

         MenuActividades();
        op=Mouse(22,59,4,15);
       ///cout<<"pos Y::: "<<op<<endl;pause();
   switch(op){
       case 4:
        case 5:
        case 6:
           Borrar();
           recuadro(22,1,52,2,cBLANCO,cROJO);
           gotoxy(36,2);
            cout<<"DAR ALTA UNA NUEVA ACTIVADAD";
           recuadro(22,4,52,2,cBLANCO,cROJO);
           gotoxy(26,5);
           cout<<"DAR ALTA / BAJA ACTIVIDADES PREVIAMENTE CARGADAS";
           recuadro(22,7,52,2,cBLANCO,cROJO);
           gotoxy(38,8);
           cout<<"VOLVER AL MENU ANTERIOR";
         int opcion;
         opcion=Mouse(22,78,1,9);
         switch(opcion){
            case 1:
            case 2:
            case 3:Borrar();
                    alta_Actividad();
                    alta_horario_actividad();
            break;
            case 4:
            case 5:
            case 6:Borrar();
                    baja_alta_Actividad();
            break;

            case 7:
            case 8:
            case 9:
            break;

         }
            break;
       case 7:
        case 8:
        case 9:
           Modificaciones_Actividades();
            break;
       case 10:
        case 11:
        case 12:
               textcolor(cBLANCO,cROJO);
                listar_Actividades();
                //listar_Horarios_Actividades();
                //listar_Cliente_Actividad();
            break;
        case 13:
        case 14:
        case 15:
                return;
            break;

    }//switch

   }///while
}

#endif // ACTIVIDADES_H_INCLUDED
