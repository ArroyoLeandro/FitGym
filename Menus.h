#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED



enum Color{
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};
void clrscr(void){
    system("cls");
}
void pause(void){
    system("pause >nul");
}
void gotoxy(short x, short y){
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}
void textcolor(short colorTexto=15, short colorFondo=0){
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=cBLANCO, short colorFondo=cNEGRO){
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 218;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 191;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 192;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 217;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 196;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 179;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
}
short Mouse(int cordenadaX1,int cordenadaX2, int cordenadaY1,int cordenadaY2){
        HANDLE hout= GetStdHandle(STD_OUTPUT_HANDLE);
        HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD InputRecord;
        DWORD Events;
        COORD coord;
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 25;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hout, &cci);
        SetConsoleMode(hin, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);


    while(1)
    {

        ReadConsoleInput(hin, &InputRecord, 1, &Events);

        if(InputRecord.EventType == MOUSE_EVENT)
        {
            if(InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
                coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
                SetConsoleCursorPosition(hout,coord);
                SetConsoleTextAttribute(hout,14);

                if(coord.X>=cordenadaX1&&coord.X<=cordenadaX2){
                 //  cout<<"entro"<<endl;pause();
                    if(coord.Y>=cordenadaY1 && coord.Y<=cordenadaY2){return coord.Y;
                    //return true;
                    }

                }
               /// break;
            }
        }
        FlushConsoleInputBuffer(hin);

    }
return -1;
//return false;
}

void Pausa(){system("pause");}

void Borrar(){system("cls");}

void MenuConfiguraciones(){
    textcolor(cBLANCO,cROJO);
    recuadro(26,1,30,2,cBLANCO,cROJO);
    gotoxy(34,2);
    cout<<"MENU CONFIGURACIONES";
    recuadro(26,8,30,2,cBLANCO,cROJO);
    gotoxy(36,9);
    cout<<"HACER BACKUP";
    recuadro(26,11,30,2,cBLANCO,cROJO);
    gotoxy(36,12);
    cout<<"RESTAURAR ARCHIVOS";
    recuadro(32,14,20,2,cBLANCO,cROJO);
    gotoxy(40,15);
    cout<<"SALIR";
}

void MenuPrincipal(){
    textcolor(cBLANCO,cROJO);
    recuadro(26,1,30,2,cBLANCO,cROJO);
    gotoxy(34,2);
    cout<<"MENU PRINCIPAL";
    recuadro(26,8,30,2,cBLANCO,cROJO);
    gotoxy(36,9);
    cout<<"CLIENTES";
    recuadro(26,11,30,2,cBLANCO,cROJO);
    gotoxy(36,12);
    cout<<"ACTIVIDADES";
    recuadro(26,14,30,2,cBLANCO,cROJO);
    gotoxy(38,15);
    cout<<"PAGOS";
    recuadro(26,17,30,2,cBLANCO,cROJO);
    gotoxy(34,18);
    cout<<"CONFIGURACIONES";
    recuadro(26,20,30,2,cBLANCO,cROJO);
    gotoxy(38,21);
    cout<<"SALIR";
}

void MenuBKP(){
    textcolor(cBLANCO,cROJO);
    recuadro(20,1,44,2,cBLANCO,cROJO);
    gotoxy(36,2);
    cout<<"MENU BACKUP";
    recuadro(20,8,44,2,cBLANCO,cROJO);
    gotoxy(34,9);
   cout<<"HACER BACKUP DE TODO";
   recuadro(20,11,44,2,cBLANCO,cROJO);
    gotoxy(30,12);
    cout<<"HACER BACKUP DE ACTIVIDADES";
    recuadro(20,14,44,2,cBLANCO,cROJO);
    gotoxy(30,15);
     cout<<"HACER BACKUP DE CLIENTES";
    recuadro(20,17,44,2,cBLANCO,cROJO);
    gotoxy(23,18);
    cout<<"HACER BACKUP DE ACTIVIDADES POR CLIENTES";
    recuadro(20,20,44,2,cBLANCO,cROJO);
    gotoxy(23,21);
    cout<<"HACER BACKUP DE HORARIOS POR ACTIVIDADES";
    recuadro(20,23,44,2,cBLANCO,cROJO);
    gotoxy(32,24);
    cout<<"HACER BACKUP DE PAGOS";
     recuadro(32,26,20,2,cBLANCO,cROJO);
    gotoxy(40,27);
    cout<<"SALIR";
}
void MenuRecuperar(){
    textcolor(cBLANCO,cROJO);
    recuadro(20,1,44,2,cBLANCO,cROJO);
    gotoxy(36,2);
    cout<<"MENU RESTAURAR";
    recuadro(20,8,44,2,cBLANCO,cROJO);
    gotoxy(34,9);
   cout<<"RESTAURAR TODO";
    recuadro(20,11,44,2,cBLANCO,cROJO);
    gotoxy(30,12);
    cout<<"RESTAURAR ARCHIVO ACTIVIDADES";
    recuadro(20,14,44,2,cBLANCO,cROJO);
    gotoxy(30,15);
     cout<<"RESTAURAR ARCHIVO CLIENTES";
    recuadro(20,17,44,2,cBLANCO,cROJO);
    gotoxy(21,18);
    cout<<"RESTAURAR ARCHIVO ACTIVIDADES POR CLIENTES";
    recuadro(20,20,44,2,cBLANCO,cROJO);
    gotoxy(21,21);
    cout<<"RESTAURAR ARCHIVO HORARIOS POR ACTIVIDADES";
    recuadro(20,23,44,2,cBLANCO,cROJO);
    gotoxy(32,24);
    cout<<"RESTAURAR ARCHIVO PAGOS";
    recuadro(32,26,20,2,cBLANCO,cROJO);
    gotoxy(40,27);
    cout<<"SALIR";
}



void fechaMaquina(){
time_t now =time(0);///objeto de una estructura tm con fecha/hora local
tm *time = localtime(&now);
cout<<"Dia: "<<time->tm_wday<<endl;
Pausa();
return;
}

void MenuCliente (){
    Borrar();
    recuadro(22,1,37,2,cBLANCO,cROJO);
    gotoxy(34,2);
    cout << "MENU CLIENTE" << endl;
 //   cout << "--------------" << endl;
    recuadro(22,4,37,2,cBLANCO,cROJO);
         gotoxy(30,5);
    cout << "1 - NUEVO CLIENTE" << endl;
    recuadro(22,7,37,2,cBLANCO,cROJO);
         gotoxy(30,8);
    cout << "2 - EDITAR CLIENTE" << endl;
    recuadro(22,10,37,2,cBLANCO,cROJO);
         gotoxy(30,11);
    cout << "3 - LISTAR CLIENTES" << endl;
    recuadro(22,13,37,2,cBLANCO,cROJO);
         gotoxy(25,14);
    cout << "4 - DAR DE ALTA/BAJA A UN CLIENTE" << endl;
     recuadro(22,16,37,2,cBLANCO,cROJO);
         gotoxy(29,17);
         cout << "5 - ANOTARSE EN ACTIVIDAD" << endl;
     recuadro(22,19,37,2,cBLANCO,cROJO);
         gotoxy(29,20);
   // cout << "-----------------" << endl;
    cout << "0 - VOLVER AL MENU ANTERIOR" << endl;
   /// gotoxy(22, 10);cout << "SELECCIONE UNA DE LAS OPCIONES: ";
}

void MenuActividades(){
        recuadro(22,1,37,2,cBLANCO,cROJO);
         gotoxy(34,2);
		cout<<"MENU ACTIVIDADES"<<endl;
		recuadro(22,4,37,2,cBLANCO,cROJO);
         gotoxy(30,5);
		cout<<"1. ALTA/BAJA"<<endl;
		recuadro(22,7,37,2,cBLANCO,cROJO);
         gotoxy(30,8);
		cout<<"2. MODIFICACIONES"<<endl;
        recuadro(22,10,37,2,cBLANCO,cROJO);
         gotoxy(30,11);
		cout<<"3. LISTAR ACTIVIDADES"<<endl;
        recuadro(22,13,37,2,cBLANCO,cROJO);
         gotoxy(30,14);
		cout<<"4. VOLVER AL MENU ANTERIOR"<<endl;
}

void MenuPagos(){
        recuadro(22,1,37,2,cBLANCO,cROJO);
         gotoxy(38,2);
		cout<<"MENU PAGOS"<<endl;
		recuadro(22,4,37,2,cBLANCO,cROJO);
         gotoxy(40,5);
		cout<<"PAGAR"<<endl;
		recuadro(22,7,37,2,cBLANCO,cROJO);
         gotoxy(24,8);
		cout<<"CONSULTAR FECHA DE PAGO DE CLIENTE"<<endl;
        recuadro(22,10,37,2,cBLANCO,cROJO);
         gotoxy(36,11);
		cout<<"LISTAR PAGOS"<<endl;
        recuadro(22,13,37,2,cBLANCO,cROJO);
         gotoxy(30,14);
		cout<<"VOLVER AL MENU ANTERIOR"<<endl;
}





#endif // MENUS_H_INCLUDED
