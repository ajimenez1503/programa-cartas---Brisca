/* (C) Programmed by:
   Antonio Jimenez Martínez


Programa de cartas : Brisca
Version:0.1

Descricion y funciones del jugador
Cada jugador tiene siempre 3 cartas

diferentes tipos de partida:
1.Un usuario 
2.maquina aleatorio
*/

#include<iostream>
#include<vector>
using namespace std;
#include "baraja.h"

class jugador {

private:

    //una jugador tiene 3 cartas
    vector<carta> c3;
    string nombre;//nombre jugador
    int puntos;//los puntos que tiene el jugador
	int tipo;



public:


    //constructor por deecto
    jugador() {
        nombre=" ";
        puntos=0;
		tipo=0;
    }
    //constructor
    jugador(const carta & a,const carta & b,const carta & c,string n,int t) {
        c3.push_back(a);
        c3.push_back(b);
        c3.push_back(c);
        nombre=n;
        puntos=0;
		tipo=t;
        //chequeamos traS crear jugador
        check();
    }
    void set_inicial(const carta & a,const carta & b,const carta & c,string n,int t) {
        c3.push_back(a);
        c3.push_back(b);
        c3.push_back(c);
        nombre=n;
        puntos=0;
		tipo=t;
        //chequeamos traS crear jugador
        check();
    }


    //acceso a una cara, el indice debe ser 0,1,2
    carta get_carta(int i) {
        return c3[i];
    }

    /*en una jugada:
    	-puede que salgamos nosotros o no. Si salimos=true salimos nosostros, si salimos=false sale el jugador contrario.
    	-Si salimos=false, habra un tercer argumentos con de la carta del oponente.
    	-Elegimos la carta por el usuario
    	-Tiramos la carta
    */
    carta jugada(const carta  & muestra,const carta & oponente) {
        int i=elegir_carta(muestra,oponente);
        carta c=echar_carta(i);
        return c;


    }

    carta jugada(const carta  & muestra) {
        int i=elegir_carta(muestra);
        carta c=echar_carta(i);
        return c;


    }

    //añade una carta e incrementa el indice
    void coger_carta(carta c) {
        c3.push_back(c);
        //comprobamso que teenmos las 3 cartas
        check();
    }

    //mostrar cartas
    void mostrar(ostream &out=cout) const {
        out<<"Mostramos las cartas de "<<nombre<<" con "<<puntos<<" puntos.\n\n";
        for(int i=0; i<c3.size(); i++) {
            cout<<"Carta "<<i<<": ";
            c3[i].mostrar();
        }
        cout<<endl<<endl;
    }

    void anadir_puntos(int p) {
        puntos+=p;
    }

    //devuevle true si no quedan cartas al jugador
    bool empty() {
        return c3.empty();
    }

	int get_puntos(){
		return puntos;
	}

	string get_nombre(){
		return nombre;
	}


private:

    //si sale el oponente
    int elegir_carta(const carta  & muestra,const carta & oponente) {
		int i;
		if(tipo==1){
		    cout<<"			La muestra es:";
		    muestra.mostrar();
		    cout<<"\nEl oponente ha tirado ";
		    oponente.mostrar();
		    mostrar();
		    cout<<"\nElige una carta ";
		    cin>>i;
		    while(i<0 || i>c3.size()-1) { //indice solo puede ser 0,1,2
		        cout<<"Elige una carta ";
		        cin>>i;
		    }
		}
		else /*tipo==2*/{
			i=rand()%(c3.size());
		}
        return i;



    }
    int elegir_carta(const carta  & muestra) {
		int i;
		if(tipo==1){
		    cout<<"			La muestra es:";
		    muestra.mostrar();
		    mostrar();
		    cout<<"\nElige una carta ";
		    cin>>i;
		    while(i<0 || i>c3.size()-1) { //indice solo puede ser 0,1,2
		        cout<<"Elige una carta ";
		        cin>>i;
		    }
		}
		else /*tipo==2*/{
			i=rand()%(c3.size());
		}
        return i;
    }

    //cogemos una de las 3 cartas, asique el indice solo puede ser 0,1,2
    carta echar_carta(int i) {
        carta c=c3[i];
        //swap
        swap(i,c3.size()-1);//cambiamos la carta por la ultima
        c3.pop_back();//eliminamos la ultima carta
        return c;

    }



    //swap: cambiamosla carta en la posicion i por la carta de la posicion d
    void swap(int i,int d) {
		if(i!=d){
		    carta aux=c3[i];
		    c3[i]=c3[d];
		    c3[d]=aux;
		}
    }
    //compruebo que tiene 3 cartas
    void check() {
		if(tipo<1 || tipo>2) cout<<"ERROR: tipo no existe"<<endl;
        if(c3.size()!=3) cout<<"ERROR: no tiene 3 cartas"<<endl;

    }

};


