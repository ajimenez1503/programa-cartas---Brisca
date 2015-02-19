/* (C) Programmed by:
   Antonio Jimenez Martínez


Programa de cartas : Brisca
Version:0.1

Descricion de una carta.
Las cartas van de 1 al 12
Exsiten cuatro palos: bastos,espadas,oros y copas.
Los puntos varian segun el numero:
	-1 tiene 11 puntos.
	-3 tiene 10 puntos.
	-10 tiene 2 puntos
	-11 tiene 3 puntos
	-12 tiene 4 puntos

Las demas cartas tiene 0 puntos
*/

#include<iostream>

using namespace std;

class carta {

private:

    //cada carta esta formado por:un palo, un numero y un puntuacion
    string palo;
    unsigned short numero; //desde 1..12
    int puntos;

public:
    //constructor por defecto
    carta() {//constructor
        palo=" ";
        numero=0;
        puntos=0;
    }

    //constructor
    carta(string p,unsigned short n) {//constructor
        palo=p;
        numero=n;
        puntos=0;
        if(numero==1) puntos=11;
        else if(numero==3) puntos=10;
        else if(numero==10) puntos=2;
        else if(numero==11) puntos=3;
        else if(numero==12) puntos=4;

        //chequeamos tras crear la carta
        check();
    }

    carta(string p,unsigned short n,int punt) {//constructor
        palo=p;
        numero=n;
        puntos=punt;

        //chequeamos tras crear la carta
        check();
    }

    //Modificador SET

    void set_palo(string p) {
        palo=p;
    }
    void set_numero(unsigned short n) {
        numero=n;

    }
    void set_puntos(int p) {
        puntos=p;

    }

    void set(string p,unsigned short n,int punt) {
        palo=p;
        numero=n;
        puntos=punt;
        //chequeamos tras modificar la carta
        check();
    }
    void clear() {
        numero=puntos=0;
        palo="";
    }

    //acceso GET
    string get_palo() const {
        return palo;
    }
    unsigned short get_numero() const {
        return numero;
    }
    int get_puntos() const {
        return puntos;
    }
    void mostrar(ostream &out=cout) const {
        out<<numero<<" de "<<palo<<" con "<<puntos<<" puntos\n";
    }



private:

    /*Las cartas van de 1 al 12, sin el 8 y 9
    Exsiten cuatro palos: bastos,espadas,oros y copas.
    Los puntos varian segun el numero:
    	-1 tiene 11 puntos.
    	-3 tiene 10 puntos.
    	-10 tiene 2 puntos
    	-11 tiene 3 puntos
    	-12 tiene 4 puntos

    Las demas cartas tiene 0 puntos*/

    void check() {
        if(numero<1 || numero>12|| numero==8 || numero==9) cout<<"ERROR: numero de la carta fuera de rango\n";
        if(palo!="OROS" && palo!="BASTOS" && palo!="ESPADAS" && palo!="COPAS") cout<<"ERROR: el palo no existe\n";
        if(!(
                    (numero==1 && puntos==11) || (numero==3 && puntos==10) || (numero==10 && puntos==2) || (numero==11 && puntos==3) ||
                    (numero==12 && puntos==4) ||(numero==2 && puntos==0) || (numero>=4 && numero<=7 && puntos==0)
                ))cout<<"ERROR: el los puntos"<<numero<<"  "<<puntos<<"\n";
    }
};


