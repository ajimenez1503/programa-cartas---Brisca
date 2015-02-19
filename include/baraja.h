/* (C) Programmed by:
   Antonio Jimenez Martínez


Programa de cartas : Brisca
Version:0.1

Descricion y funciones de la baraja.
Existen 40 cartas:
	-10 de cada palo
	-4 de cada numero.
*/

#include<iostream>
#include<vector>
#include <cstdlib> // rand, srand
using namespace std;
#include "carta.h"

class baraja {

private:

    //una baraja esta formada por 40 cartas
    vector<carta> ba;


public:

    //constructor
    baraja() {//constructor por defecto
        //crea las 40 cartas

        //OROS
        vector<carta> aux(40);
        carta c("OROS",1,11);
        aux[0]=c;
        c.set("OROS",2,0);
        aux[1]=c;
        c.set("OROS",3,10);
        aux[2]=c;
        c.set("OROS",4,0);
        aux[3]=c;
        c.set("OROS",5,0);
        aux[4]=c;
        c.set("OROS",6,0);
        aux[5]=c;
        c.set("OROS",7,0);
        aux[6]=c;
        c.set("OROS",10,2);
        aux[7]=c;
        c.set("OROS",11,3);
        aux[8]=c;
        c.set("OROS",12,4);
        aux[9]=c;


        //BASTOS
        c.set("BASTOS",1,11);
        aux[10]=c;
        c.set("BASTOS",2,0);
        aux[11]=c;
        c.set("BASTOS",3,10);
        aux[12]=c;
        c.set("BASTOS",4,0);
        aux[13]=c;
        c.set("BASTOS",5,0);
        aux[14]=c;
        c.set("BASTOS",6,0);
        aux[15]=c;
        c.set("BASTOS",7,0);
        aux[16]=c;
        c.set("BASTOS",10,2);
        aux[17]=c;
        c.set("BASTOS",11,3);
        aux[18]=c;
        c.set("BASTOS",12,4);
        aux[19]=c;

        //COPAS

        c.set("COPAS",1,11);
        aux[20]=c;
        c.set("COPAS",2,0);
        aux[21]=c;
        c.set("COPAS",3,10);
        aux[22]=c;
        c.set("COPAS",4,0);
        aux[23]=c;
        c.set("COPAS",5,0);
        aux[24]=c;
        c.set("COPAS",6,0);
        aux[25]=c;
        c.set("COPAS",7,0);
        aux[26]=c;
        c.set("COPAS",10,2);
        aux[27]=c;
        c.set("COPAS",11,3);
        aux[28]=c;
        c.set("COPAS",12,4);
        aux[29]=c;


        //ESPADAS
        c.set("ESPADAS",1,11);
        aux[30]=c;
        c.set("ESPADAS",2,0);
        aux[31]=c;
        c.set("ESPADAS",3,10);
        aux[32]=c;
        c.set("ESPADAS",4,0);
        aux[33]=c;
        c.set("ESPADAS",5,0);
        aux[34]=c;
        c.set("ESPADAS",6,0);
        aux[35]=c;
        c.set("ESPADAS",7,0);
        aux[36]=c;
        c.set("ESPADAS",10,2);
        aux[37]=c;
        c.set("ESPADAS",11,3);
        aux[38]=c;
        c.set("ESPADAS",12,4);
        aux[39]=c;


        ba=aux;
        aux.clear();
        //chequeamos tras crear la baraja
        check();
    }



    //acceso a una cara
    carta get_carta(int i) {
        return ba[i];
    }


    //barajar las cartas
    //precondicion: Solo se baraja cuando estan todas las cartas
    void barajar() {
        int i=0,n=0;
        vector<bool> esta(40,true);//si true la carta no se ha cogido.
        srand (time(0));//lanzamos semilla del generador de aleatorios
        vector<carta> aux(40);
        while(i<40) {
            n=rand()%(40);//un numero aleatorio entre 0-39
            if(!esta[n]) {
                coger_siguiente_n(esta,n);
            }
            aux[i]=ba[n];
            esta[n]=false;
            i++;
        }
        ba=aux;
        //chequeamos tras barjar la baraja
        check();
    }


    //quitar la ultima carta carta
    //devolvemos la ultima carta y decrementamos el indice y eliminamos la carta de la baraja
    carta coger_carta() {
        carta c=ba[ba.size()-1];
        ba.pop_back();
        return c;

    }


    //mostrar baraja
    void mostrar(ostream &out=cout) const {
        out<<"Mostramos la baraja\n";
        for(int i=0; i<ba.size(); i++) {
            ba[i].mostrar();
        }
        cout<<endl<<endl;
    }

    //devuevle true si no quedan cartas en la baraja
    bool empty() {
        return ba.empty();
    }

    //devuevle true si no quedan cartas en la baraja
    bool queda_1_carta() {
        return ba.size()==1;
    }

private:

    /*precondicion:
    	-Solo se baraja cuando estan todas las cartas
    	-quedan espacios libres
    	-esta(n) es false
    */
    void coger_siguiente_n(const vector<bool> & esta,int & n) {
        while(!esta[n]) {
            n++;
            n%=40;
        }
    }


    //comprueba si hay 10 copas,10 bastos,10 espadas y 10 oros
    //comprueba que hay 4 de cada numero
    void check() {
        int auxn;
        string auxs;
        vector<int> esta(14,0);
        //esta[0]: cuantos 1
        //esta[1]: cuantos 2
        //esta[2]: cuantos 3
        //esta[3]: cuantos 4
        //esta[4]: cuantos 5
        //esta[5]: cuantos 6
        //esta[6]: cuantos 7
        //esta[7]: cuantos 10
        //esta[8]: cuantos 11
        //esta[9]: cuantos 12
        //esta[10]: cuantas copas
        //esta[11]: cuantas bastos
        //esta[12]: cuantas espadas
        //esta[13]: cuantos oros
        for(int i=0; i<40; i++) {
            auxn=ba[i].get_numero();
            if(auxn>=1 && auxn<=7) esta[auxn-1]++;
            else if(auxn>=10 && auxn<=12) esta[auxn-3]++;
            auxs=ba[i].get_palo();
            if(auxs=="COPAS") esta[10]++;
            else if(auxs=="BASTOS") esta[11]++;
            else if(auxs=="ESPADAS") esta[12]++;
            else if(auxs=="OROS") esta[13]++;
        }
        //comprobamos el vector esta
        for(int i=0; i<14; i++) {
            if(i<=9 && esta[i]!=4) cout<<"ERROR: faltan cartas de 4"<<endl;
            if(i>=10 && esta[i]!=10) cout<<"ERROR: falta cartas de 10"<<endl;
        }
    }

};


