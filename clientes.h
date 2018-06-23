#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
#include <stdexcept>


//****************************
//Prototipos funciones externas
int buscar_Cliente_activo(int);
int buscar_Cliente_activo_2(int,int);
int buscar_Cliente_existente(int);
void alta_Clientes();
void modifica_nom();
void baja_logica_cli();
void listar_Clientes();
bool PrimerCli();
int contarClientes();
//****************************

void Cliente::Cargar()
	{
    recuadro(64,1,10,2,cBLANCO,cROJO);
    gotoxy(66,2);
    cout<<"Volver";///hacer que siempre puede regresar al menu principal
	if(PrimerCli()==true){
	setID(1);

	 }///si es primero asigna ID 1
    else{setID(contarClientes()+1);}
    recuadro(2,1,47,2,cBLANCO,cROJO);
    gotoxy(6,2);
    cout<<"Ingrese el Nombre:  ";
    cin.ignore();
    cin.getline(Nombre,30);
    setNombre(Nombre);
    recuadro(2,4,47,2,cBLANCO,cROJO);
    gotoxy(6,5);
    cout<<"Ingrese Apellido:  ";///validar precio y stock( >0 )
     cin.ignore();
    cin.getline(Apellido,30);

    setApellido(Apellido);
    recuadro(2,7,47,2,cBLANCO,cROJO);
    gotoxy(6,8);
    cout<<"Ingrese el DNI:  ";
    cin>>DNI;
    setDNI(DNI);
	}

void Cliente::Mostrar(int pos)
	{int y;

	    if (pos==0){y=7;}
	    else{y=pos+2;}
	gotoxy(1,y);
	cout<<" | "<<getID()<<" | "<<endl;
	gotoxy(13,y);
	cout<<" | "<<getNombre()<<endl;
	gotoxy(44,y);
	cout<<" | "<<getApellido()<<endl;
	gotoxy(65,y);
	cout<<" | "<<getDNI()<<endl;
	}

void Cliente::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("clientes.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Cliente::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("clientes.dat","rb");
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

void Cliente::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("clientes.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

//FUNCIONES EXTERNAS

int contarClientes() {
FILE *p=NULL;
  Cliente aux; int cant=0;
 p= fopen("clientes.dat","rb");
if(p==NULL) {cout<< "error de apertura"; exit(-1);}

 while(fread(&aux,sizeof(Cliente),1,p)==1) {
        cant++;
}
fclose(p);
return cant;
}




int buscar_Cliente_existente(int cod)
{
	int pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getID())
			return pos;
		pos++;
		}
	return -1;
}


int buscar_Cliente_activo_2(int cod,int cant)
{
	int pos;
	pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getID() && reg.getActivo()==true){return pos;}
        pos++;
		}
		cout<<"no entro en el while"<<endl;Pausa();pause();

	return -1;
}


int buscar_Cliente_activo(int cod)
{
	int pos=0;
	Cliente reg;
	while(reg.Leer_de_disco(pos)==1)
		{
		if(cod==reg.getID() && reg.getActivo()==true)
			return pos;
		pos++;
		}
	return -1;
}


void alta_Clientes()
{
	Cliente reg;
	system("cls");
	reg.Cargar();
	reg.Grabar_en_disco();
}

void modifica_nom()
{
	int cod;
	char npu[30];
	int pos;
	Cliente reg;
	system("cls");
	cout<<"INGRESE EL ID DEL CLIENTE A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Cliente_activo(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo Nombre: ";
		cin.ignore();
        cin.getline(npu,30);
		reg.Leer_de_disco(pos);
		reg.setNombre(npu);
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el Cliente"<<endl;
		system("pause");
		}
}
void modifica_ape()
{
	int cod;
	char npu[30];
	int pos;
	Cliente reg;
	system("cls");
	cout<<"INGRESE EL ID DEL CLIENTE A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Cliente_activo(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo Apellido: ";
		cin.ignore();
        cin.getline(npu,30);
		reg.Leer_de_disco(pos);
		reg.setApellido(npu);
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el Cliente"<<endl;
		system("pause");
		}
}

void modifica_DNI()
{
	int cod;
	int npu;
	int pos;
	Cliente reg;
	system("cls");
	cout<<"INGRESE EL ID DEL CLIENTE A MODIFICAR: ";
	cin>>cod;
	pos=buscar_Cliente_activo(cod);
	if(pos!=-1)
		{
		cout<<"Ingrese el nuevo DNI: ";
		cin>>npu;
		reg.Leer_de_disco(pos);
		reg.setDNI(npu);
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el Cliente"<<endl;
		system("pause");
		}
}

void Modificaciones_Cliente(){
Borrar();
    recuadro(28,1,30,2,cBLANCO,cROJO);
    gotoxy(32,2);
    cout<<"CAMBIAR NOMBRE";
    recuadro(28,4,30,2,cBLANCO,cROJO);
    gotoxy(32,5);
    cout<<"CAMBIAR APELLIDO";
    recuadro(28,7,30,2,cBLANCO,cROJO);
    gotoxy(32,8);
    cout<<"CAMBIAR DNI";
     recuadro(28,10,30,2,cBLANCO,cROJO);
    gotoxy(32,11);
    cout<<"VOLVER AL MENU ANTERIOR";
        int pos;
        pos=Mouse(28,58,1,12);
        ///cout<<"POOS: : : "<<pos;Pausa();
        switch (pos){
            case 1:
            case 2:
            case 3:modifica_nom();
                break;
            case 4:
            case 5:
            case 6:modifica_ape();
                break;
            case 7:
            case 8:
            case 9:modifica_DNI();
                break;
            case 10:
            case 11:
            case 12:  return;
                break;


                }
}


void baja_alta_logica_cli()
{
	int cod;
	int pos;
	int P;
	Cliente reg;
	system("cls");
	recuadro(26,1,25,2,cBLANCO,cROJO);
	gotoxy(34,2);
	cout<<"DAR DE ALTA";
	recuadro(26,4,25,2,cBLANCO,cROJO);
	gotoxy(34,5);
	cout<<"DAR DE BAJA";
	recuadro(26,7,25,2,cBLANCO,cROJO);
	gotoxy(28,8);
	cout<<"VOLVER AL MENU ANTERIOR";
	P=Mouse(26,51,1,9);
	if(P==7||P==8||P==9)return;
	if(P==1||P==2||P==3){Borrar();cout<<"Ingrese el codigo del Cliente a dar de Alta: ";
	cin>>cod;
	pos=buscar_Cliente_existente(cod);
	}
	else{Borrar(); cout<<"Ingrese el codigo del Cliente a eliminar: ";
	cin>>cod;
	pos=buscar_Cliente_activo(cod);}
	if(pos!=-1)
		{
		reg.Leer_de_disco(pos);
		if(P==4||P==5||P==6){reg.setActivo(false);}
		else{reg.setActivo(true);}
		reg.Modificar_en_disco(pos);
		}
	else
		{
		cout<<"No existe el cliente"<<endl;
		system("pause");
		}

}

bool PrimerCli(){
FILE *p;
	p=fopen("clientes.dat","rb");
	if(p==NULL)
		{
		return true;
		}
fclose(p);
return false;

}


void listar_Clientes()
	{
	Cliente reg;
	int pos=0;
	system("cls");
	recuadro(0,0,6,2,cBLANCO,cROJO);
	gotoxy(2,1);
	cout<<"ID";
	recuadro(7,0,30,2,cBLANCO,cROJO);
	gotoxy(17,1);
	cout<<"NOMBRE";
	recuadro(38,0,20,2,cBLANCO,cROJO);
	gotoxy(45,1);
	cout<<"APELLIDO";
	recuadro(59,0,20,2,cBLANCO,cROJO);
	gotoxy(66,1);
	cout<<"DNI";
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
		recuadro(28,pos+2,32,2,cBLANCO,cROJO);
		gotoxy(32,pos+3);
		cout<<"VOLVER AL MENU ANTERIOR";
		int opcionVolver;
        opcionVolver=Mouse(28,60,pos+2,pos+4);
        if(opcionVolver>=pos+2 && opcionVolver<=pos+3){
            return;
        }
	}

bool existeCliente(int id){
Cliente reg;
int pos=0;
while(reg.Leer_de_disco(pos++)==1){
    if(id==reg.getID()){return true;}
}
return false;
}

char NombreCliente(int id){
Cliente reg;
int pos=0;
while(reg.Leer_de_disco(pos++)==1){
    if(id==reg.getID()){cout<<reg.getNombre()<<" "<<reg.getApellido();}
}
}

//FIN FUNCIONES EXTERNAS




void Cliente(){

   int op;
   while(true){

       Borrar();
         MenuCliente ();
        op=Mouse(22,59,4,21);
       ///cout<<"pos Y::: "<<op<<endl;pause();
   switch(op){
       case 4:
        case 5:
        case 6:
           Borrar();
            alta_Clientes();
            alta_Cliente_actividad(contarClientes());
            //alta_Pago();
            break;
       case 7:
        case 8:
        case 9:
            Modificaciones_Cliente();
            break;
       case 10:
        case 11:
        case 12:
               textcolor(cBLANCO,cROJO);
               listar_Clientes();
            break;
        case 13:
        case 14:
        case 15:
                baja_alta_logica_cli();

            break;
        case 16:
        case 17:
        case 18:
            int IDcli;
            char asd[30];
            Borrar();
            cout<<"INGRESE EL ID DEL CLIENTE: ";
            cin>>IDcli;
                alta_Cliente_actividad(IDcli);
            break;
        case 19:
        case 20:
        case 21:
                 return; break;
    }//switch

   }///while
}


#endif // CLIENTES_H_INCLUDED
