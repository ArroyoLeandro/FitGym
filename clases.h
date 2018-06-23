#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED


class Actividad{
    private:
        int ID; ///codigo ID autogenerado
        char Nombre[30];///Nombre
        float precio;
        bool estado;

    public:
        void setID(int a){ID=a;};
        void setActivo(bool b){estado=b;};
        void setNombre(char nom[30]){strcpy(Nombre,nom);};
        void setPrecio(float pre){precio=pre;};

        int getID(){return ID;};
        bool getActivo(){return estado;};
        char *getNombre(){return Nombre;};
        float getPrecio(){return precio;};

        void Cargar();
		void Mostrar(int);

		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);

};









class Actividades_x_Cliente{

private:
    int IdActividad;
    int IdCliente;
    bool Estado;
    Fecha fech;
public:
        void setIDA(int a){IdActividad=a;};
        void setIDC(int b){IdCliente=b;};
        void setActivo(bool c){Estado=c;};

        void setDiaAct(int d){fech.setDia(d);};
        void setMesAct(int e){fech.setMes(e);};
        void setAnioAct(int f){fech.setAnio(f);};



        int getID_ACT(){return IdActividad;};
        bool getActivo(){return Estado;};
        int getID_Cli(){return IdCliente;};
        int getDiaAlta(){return fech.getDia();};
        int getMesAlta(){return fech.getMes();};
        int getanioAlta(){return fech.getAnio();};

        void Cargar(int);
		void Mostrar(int);

		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);
	};





class Pago{
private: int idPago;
        int IdClien,MesAPagar,AnioAPagar;
        Fecha fec;
        float Importe;
public:
    void setIdP(int a){idPago=a;};
    void setIdC(int b){IdClien=b;};
    void setMes(int c){MesAPagar=c;};
    void setAnio(int d){AnioAPagar=d;};
    void setFdia(int e){fec.setDia(e);};
    void setFmes(int f){fec.setMes(f);};
    void setFanio(int g){fec.setAnio(g);};
    void setImporte(float h){Importe=h;};

    int getIdP(){return idPago;}
    int getIdC(){return IdClien;}
    int getMes(){return MesAPagar;}
    int getAnio(){return AnioAPagar;}
    int getFdia(){return fec.getDia();}
    int getFmes(){return fec.getMes();}
    int getFanio(){return fec.getAnio();}
    int getImp(){return Importe;}

    void Cargar();
    void Mostrar(int);

    void Grabar_en_disco(void);
    int Leer_de_disco(int);
    void Modificar_en_disco(int);

};







class Horarios_x_Actividad{

private: int idActividad;
            int nroDia,HoraInicio,HoraFin,SegI,SegF;
public:
        void setID(int a){idActividad=a;};
        void setNroDia(int b){nroDia=b;};
        void setHoraIni(int c){HoraInicio=c;};
        void setHoraFin(int d){HoraFin=d;};
        void setSegI(int e){SegI=e;};
        void setSegF(int f){SegF=f;};

        int getID(){return idActividad;};
        int getNroDia(){return nroDia;};
        int getHsIni(){return HoraInicio;};
        int getHsFin(){return HoraFin;};
        int getSegIni(){return SegI;};
        int getSegFin(){return SegF;};

        void Cargar(int);
		void Mostrar(int);

		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);

};






class Cliente{
    private:
        int ID; ///codigo ID autogenerado
        char Nombre[30];///Nombre y apellido
        char Apellido[30];
        int DNI;
        bool estado;

    public:
        void setID(int a){ID=a;};
        void setActivo(bool b){estado=b;};
        void setNombre(char nom[30]){strcpy(Nombre,nom);};
        void setApellido(char ape[30]){strcpy(Apellido,ape);};
        void setDNI(int dn){DNI=dn;};

        int getID(){return ID;};
        bool getActivo(){return estado;};
        char *getNombre(){return Nombre;};
        char *getApellido(){return Apellido;};
        int getDNI(){return DNI;};

        void Cargar();
		void Mostrar(int);

		void Grabar_en_disco(void);
		int Leer_de_disco(int);
		void Modificar_en_disco(int);

};

#endif // CLASES_H_INCLUDED
