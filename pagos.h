#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED

struct ClientesPago{
int mes,anio,idCliente;
};
//****************************
//Prototipos funciones externas
int buscar_Pago(int);
void Pagar();
float aPagar(int);
void Mnombre(int);
void modificar();
bool PrimerPago();
int contarPagos();
bool CExistePago(int);
bool guardarClientePago(ClientesPago,int);
struct ClientesPago obtenerCliP(int);
int buscarClienteStruct(int);
//****************************






void Pago::Cargar()
	{///SI COINSIDE EL ID CLIENTE+MES+ANIO QUIERE DECIR QUE YA PAGO
	    ///CASO CONTRARIO GUARDAR NUEVO PAGO
	    ///CONTAR CUANTOS CLIENTES HAY, CON ESE TAM (VA A SER EL ID) MOSTRAR LOS PAGOS QUE TENGAN ESOS ID
	    time_t now =time(0);///objeto de una estructura tm con fecha/hora local
    tm *time = localtime(&now);
    int cant=0;
    bool clienteExistenteReg=false;
	if(PrimerPago()==true){setIdP(1);}///si es primero asigna ID 1
    else{cant=contarPagos()+1;
        setIdP(cant);}
    bool existe=false;
    bool existe2=false;
    ClientesPago auxiliar;
    while (existe==false){
    recuadro(2,1,47,2,cBLANCO,cROJO);
    gotoxy(6,2);
    int posicion=0;
    bool bandera=false;

    cout<<"INGRESE EL ID DEL CLIENTE:  ";
    cin>>IdClien;
    existe=existeCliente(IdClien);
    existe2=CExistePago(IdClien);

    auxiliar.idCliente=IdClien;
    if (existe==true){
    ///ya tenia pago guardado

    if(existe2==true){

            setIdC(IdClien);
    clienteExistenteReg=true;
    int pos_aux;

		existe=false;
    while(existe==false){

            FILE *P;
    P=fopen("yaPago.dat","rb");
    if(P==NULL)exit(1);
    recuadro(2,4,47,2,cBLANCO,cROJO);
    gotoxy(6,5);
    cout<<"INGRESE EL MES A PAGAR:  ";
    cin>>MesAPagar;
    int mpago;

    while(fread(&auxiliar,sizeof(ClientesPago),1,P)==1){
        if(IdClien==auxiliar.idCliente){
                   mpago=auxiliar.mes+1;
                if(mpago==13){auxiliar.anio=auxiliar.anio+1;mpago=1;}
            if(MesAPagar==mpago){

                ///guardar aca
            pos_aux = buscarClienteStruct(auxiliar.idCliente);
            if (pos_aux >= 0){
                auxiliar = obtenerCliP(pos_aux);
                setMes(MesAPagar);existe=true;
                if(MesAPagar==12){auxiliar.mes=0;}
                else{auxiliar.mes=MesAPagar;}
                if(MesAPagar==1){bandera=true;}


            }
        }
    }

    }
    //cout<<"afuera de while";Pausa();
    fclose(P);
    if(existe==false){cout<<"MES INCORRECTO"; Pausa();Borrar();}
    }


    existe=false;
    while (existe==false){
    recuadro(2,7,47,2,cBLANCO,cROJO);
    gotoxy(6,8);
    cout<<"INGRESE EL ANIO DEL PAGO:  ";
    cin>>AnioAPagar;
    Pago regis;
    if(bandera==true){
                if(AnioAPagar>auxiliar.anio){
                    auxiliar.anio=AnioAPagar;
            guardarClientePago(auxiliar,pos_aux);
        setAnio(AnioAPagar);
		setImporte(aPagar(IdClien));
        setFdia(time->tm_mday);
        setFmes(time->tm_mon+1);
        setFanio(time->tm_year+1900);
		existe=true;
                }
                else{cout<<"ANIO INCORRECTO"; Pausa();Borrar();}
            }
            else{
    if (AnioAPagar==auxiliar.anio){

            auxiliar.anio=AnioAPagar;
            guardarClientePago(auxiliar,pos_aux);
        setAnio(AnioAPagar);
		setImporte(aPagar(IdClien));
        setFdia(time->tm_mday);
        setFmes(time->tm_mon+1);
        setFanio(time->tm_year+1900);
		existe=true;}
		else{cout<<"ANIO INCORRECTO"; Pausa();Borrar();}
		}

    }

    }
    //*/
    }//existe

    else{cout<<"NO EXISTE CLIENTE"; Pausa();Borrar();}
    }



    existe=false;
    if(clienteExistenteReg==false){
    /// struct
    FILE *p;
    p=fopen("yaPago.dat","ab");
    if(p==NULL)exit(1);
    ///.--
    setIdC(IdClien);
    while(existe==false){
    recuadro(2,4,47,2,cBLANCO,cROJO);
    gotoxy(6,5);
    cout<<"INGRESE EL MES A PAGAR:  ";
    cin>>MesAPagar;
    if (MesAPagar==mesAlta(auxiliar.idCliente)){setMes(MesAPagar);auxiliar.mes=MesAPagar;existe=true;}
    else{cout<<"MES INCORRECTO"; Pausa();Borrar();}
    }


    existe=false;
    while (existe==false){
    recuadro(2,7,47,2,cBLANCO,cROJO);
    gotoxy(6,8);
    cout<<"INGRESE EL ANIO DEL PAGO:  ";
    cin>>AnioAPagar;
    if (AnioAPagar==anioAlta(auxiliar.idCliente)){setAnio(AnioAPagar);auxiliar.anio=AnioAPagar;existe=true;
    setImporte(aPagar(IdClien));
    setFdia(time->tm_mday);
    setFmes(time->tm_mon+1);
    setFanio(time->tm_year+1900);
    }
    else{cout<<"ANIO INCORRECTO"; Pausa();Borrar();}
    }
    guardarClientePago(auxiliar, -1);
    fclose(p);
    }///NO EXISTEN REGISTROS EN ARCHIVO PAGOS

	}

void Pago::Mostrar(int pos)
	{int y;
	    if (pos==0){y=7;}
	    else{y=pos+2;}
	gotoxy(0,y);
	cout<<" | "<<getIdP()<<" | "<<endl;
	gotoxy(10,y);
	cout<<" "<<NombreCliente(getIdC());
	gotoxy(40,y);
	cout<<" | "<<getMes()<<endl;
	gotoxy(55,y);
	cout<<" | "<<getAnio()<<endl;
	gotoxy(70,y);
	cout<<" | "<<getImp()<<endl;
	}

void Pago::Grabar_en_disco(void)
	{
	FILE *p;
	p=fopen("pagos.dat","ab");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

int Pago::Leer_de_disco(int pos)
	{
	int x;
	FILE *p;
	p=fopen("pagos.dat","rb");
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

void Pago::Modificar_en_disco(int pos)
	{
	FILE *p;
	p=fopen("pagos.dat","rb+");
	if(p==NULL){cout<<"Error de archivo";exit(1);}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	}

//FUNCIONES EXTERNAS

int buscarClienteStruct(int cod){
  FILE *p;
  p = fopen("yaPago.dat", "rb");
  if (p == NULL){
    return -1;
  }
  ClientesPago aux;
  int i=0;
  while(fread(&aux, sizeof(ClientesPago), 1, p) == 1){
    if(cod==aux.idCliente){
      fclose(p);
      return i;
    }
    i++;
  }
  fclose(p);
  return -1;
}

struct ClientesPago obtenerCliP(int pos){
  struct ClientesPago reg;
  FILE *p;
  p = fopen("yaPago.dat", "rb");
  if (p == NULL){ exit(1);}

fseek(p, pos*sizeof(ClientesPago), SEEK_SET);
fread(&reg, sizeof(ClientesPago), 1, p);
fclose(p);
  return reg;
}

bool guardarClientePago(ClientesPago regD, int pos){
  FILE *p;

  if(pos >= 0){
    ///MODIFICAR
    p = fopen("yaPago.dat", "rb+");
    if (p == NULL){
      return false;
    }
    fseek(p, sizeof(ClientesPago) * pos, SEEK_SET);
  }
  else{
    ///AGREGAR
    p = fopen("yaPago.dat", "ab");
    if (p == NULL){
      return false;
    }
    fseek(p, 0, SEEK_END);
  }
  fwrite(&regD, sizeof(ClientesPago), 1, p);
  fclose(p);
  return true;
}



int contarPagos() {
FILE *p;
  Pago aux;
  int cant=0;
 p = fopen("pagos.dat","rb");
if(p==NULL) {cout<< "error de apertura"; Pausa();return 0;}

 while(fread(&aux,sizeof(Pago),1,p)==1) {
        cant++;
}
fclose(p);
return cant;
}


bool CExistePago(int idC) {
FILE *p;
  Pago aux;
  int cant=0;
 p = fopen("pagos.dat","rb");
if(p==NULL) {return false;}
int pos=0;
 while(aux.Leer_de_disco(pos++)==1) {
        if(idC==aux.getIdC()){return true;}
}
fclose(p);
return false;
}

bool consultarFechaDePago(int idClientePago){

FILE *p;
  p = fopen("yaPago.dat", "rb");
  if (p == NULL){
   return false;
  }
  ClientesPago aux;
              while(fread(&aux, sizeof(ClientesPago), 1, p) == 1){
                    if (idClientePago==aux.idCliente){
                            Borrar();
                            cout<<"PROXIMO VENCIMIENTO: 0"<<aux.mes+1<<" DEL "<<aux.anio<<endl;
                    Pausa();
                    fclose(p);
                    return true;
                    }
                }
    fclose(p);
cout<<"no entro pero paso el null";
Pausa();
return false;
}


bool PrimerPago(){
FILE *p;
 p = fopen("pagos.dat","rb");
if(p==NULL)
		{
		return true;
		}
fclose(p);
return false;
}

void mostrame(){
ClientesPago reg;
FILE *p;
p=fopen("yaPago.dat","rb");
if(p==NULL)return;
while(fread(&reg,sizeof(ClientesPago),1,p)==1){
    cout<<"Id: "<<reg.idCliente<<endl;
    cout<<"MES: "<<reg.mes<<endl;
    cout<<"ANIO-. "<<reg.anio<<endl;
    cout<<"_____________________________________"<<endl;
}
Pausa();
fclose(p);
return;
}

void alta_Pago()
{
	Pago reg;
	system("cls");
	reg.Cargar();
	reg.Grabar_en_disco();
}

void Listar_Pagos()
	{
	Pago reg;
	int pos=0;
	system("cls");
	recuadro(0,0,6,2,cBLANCO,cROJO);
	gotoxy(2,1);
	cout<<"ID";
	recuadro(7,0,30,2,cBLANCO,cROJO);
	gotoxy(17,1);
	cout<<"CLIENTE";
	recuadro(38,0,13,2,cBLANCO,cROJO);
	gotoxy(40,1);
	cout<<"MES A PAGAR";
	recuadro(52,0,13,2,cBLANCO,cROJO);
	gotoxy(53,1);
	cout<<"ANIO A PAGAR";
	recuadro(67,0,10,2,cBLANCO,cROJO);
	gotoxy(68,1);
	cout<<"TOTAL";

	while(reg.Leer_de_disco(pos++)==1)
		{
			    reg.Mostrar(pos);
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

float aPagar(int clienteID){
float acumulador=0;
int pos=0,pos2=0;
Actividades_x_Cliente reg;
Actividad aux;
while(reg.Leer_de_disco(pos++)==1){
        pos2=0;
    if (reg.getID_Cli()==clienteID){
        while(aux.Leer_de_disco(pos2++)==1){
            if (reg.getID_ACT()==aux.getID() && buscar_Actividad_activa(aux.getID())>=0){acumulador+=aux.getPrecio();}
        }
    }
}

return acumulador;
}



void Pagos(){
   ///boton de pago  / cancelar
int op;
   while(true){

       Borrar();
         MenuPagos();
        op=Mouse(22,59,4,15);
       ///cout<<"pos Y::: "<<op<<endl;pause();
   switch(op){
       case 4:
        case 5:
        case 6:
           Borrar();
            alta_Pago();
            break;
       case 7:
        case 8:
        case 9:
            /// VER FECHA DE PAGO POR ID DE CLIENTE
            int cli;
            Borrar();
            while(true){
            cout<<"INGRESE EL ID DEL CLIENTE ";
            cin>>cli;
            if(consultarFechaDePago(cli)==true){break;}
            //else{cout<<"NO ENTRO";Pausa();}
            Borrar();
            }
            break;
       case 10:
        case 11:
        case 12:
               textcolor(cBLANCO,cROJO);
                Listar_Pagos();
            break;
        case 13:
        case 14:
        case 15:
                return;
                //mostrame();
            break;
        }//switch

   }///while

}




#endif // PAGOS_H_INCLUDED
