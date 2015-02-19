/* (C) Programmed by:
   Antonio Jimenez Martínez


Programa de cartas : Brisca
Version:0.1

Crearemos las interacciones de una partida.

En una partida existe: una baraja, una muestra y dos jugadores

Empieza uno de los jugadores de forma aleatoria, y despues va empezando el que ha ganado.
*/

#include<iostream>
#include<vector>
using namespace std;
#include "jugador.h"

class partida {

private:

    baraja ba;
    jugador j1,j2;
    carta muestra;

public:

    //constructor
    partida() {
        string n1,n2;
        cout<<"Nombre del primer jugador"<<endl;
        cin>>n1;
        cout<<"Nombre del segundo jugador"<<endl;
        cin>>n2;
        ba.barajar();
        carta a1=ba.coger_carta();
        carta a2=ba.coger_carta();
        carta b1=ba.coger_carta();
        carta b2=ba.coger_carta();
        carta c1=ba.coger_carta();
        carta c2=ba.coger_carta();
        muestra=ba.coger_carta();
        j1.set_inicial(a1,b1,c1,n1);
        j2.set_inicial(a2,b2,c2,n2);

    }

    void toda_partida(bool empieza) {
        //empieza el j1, asique inicialmente empieza es true.
        while(!ba.queda_1_carta()) { //mientrs que quedan mas de una carta
            empieza=jugar(empieza);
            robar(empieza);
        }
        empieza=jugar(empieza);//juega
        //roban
        //una carta para uno y la muestra para otro
        if(empieza) {
            j1.coger_carta(ba.coger_carta());
            j2.coger_carta(muestra);
        }
        else {
            j2.coger_carta(ba.coger_carta());
            j1.coger_carta(muestra);
        }
			
        while(!j1.empty()){//mientras le queden cartas al jugador
        	empieza=jugar(empieza);
        }
		if(j1.get_puntos()>j2.get_puntos())	cout<<"Ha ganado: "<<j1.get_nombre()<<"con "<<j1.get_puntos()<<" puntos"<<endl;
		else if(j1.get_puntos()<j2.get_puntos())	cout<<"Ha ganado: "<<j2.get_nombre()<<"con "<<j2.get_puntos()<<" puntos"<<endl;
		else /*j1.get_puntos()==j2.get_puntos()*/ cout<<"Han empatado"<<endl;

    }

    //devuelve true si gana el jugador1
    //devuvle false si gana el jugador2
    bool jugar(bool empieza) {
        carta c1,c2;
        if(empieza) { //si sale el jugador1
            c1=j1.jugada(muestra);
            c2=j2.jugada(muestra,c1);
        }
        else { //sale jugador2
            c2=j2.jugada(muestra);
            c1=j1.jugada(muestra,c2);
        }
        
        return comprobar(c1,c2,empieza);


    }
    //si sale es true roba el j1, else roba el j2
    void robar(bool sale) {
        if(sale) {
            j1.coger_carta(ba.coger_carta());
            j2.coger_carta(ba.coger_carta());
        }
        else {
            j2.coger_carta(ba.coger_carta());
            j1.coger_carta(ba.coger_carta());
        }

    }




    //comprobamos quien ha ganado de los dos jugadores y le damos los puntos al que gane
    //devolvemos true si gana jugador 1 y false si gana jugador 2.

    //hay q tener en cuenta que la carta 1 y 3 valen mas.
    //hay que tener en cuente que sean o no del mismo palo
    //si empieza=true sale jugador1, else sale jugador2
    bool comprobar(carta c1,carta c2,bool empieza) {
        //p son los puntos en juego
        //n1 numero de la carta del jugador1
        //n2 numero de la carta dle jugador2
        int n1=c1.get_numero(),n2=c2.get_numero(),p=c1.get_puntos()+c2.get_puntos();

        if(c1.get_palo()==muestra.get_palo()) { //si la carta del jugador1 es de la muestra

            if(c2.get_palo()!=muestra.get_palo()) { //si la carta del jugador2 no es de la muestra
                j1.anadir_puntos(c1.get_puntos()+c2.get_puntos());
                cout<<"gana "<<j1.get_nombre()<<endl;
                return true;
            }

            else { //si la carta del jugador2 es la muestra.
                if((n1==1) || (n1==3 && n2!=1) || (n1>n2 && n2!=3 && n2!=1)) {
                    j1.anadir_puntos(p);
                    cout<<"gana "<<j1.get_nombre()<<endl;
                    return true;
                }
                else {
                    j2.anadir_puntos(p);
                    cout<<"gana "<<j2.get_nombre()<<endl;
                    return false;
                }



            }

        }
        else { //si la carta del jugador1 no es de la muestra
            if(c2.get_palo()==muestra.get_palo()) { //si la carta del jugador2 es de la muestra
                j2.anadir_puntos(p);
                cout<<"gana "<<j2.get_nombre()<<endl;
                return false;
            }

            else { //si la carta del jugador2 no es la muestra.

                if(c1.get_palo()==c2.get_palo()) { //si ambos son del mismo palo
                    if((n1==1) || (n1==3 && n2!=1) || (n1>n2 && n2!=3 && n2!=1)) {
                        j1.anadir_puntos(p);
                        cout<<"gana "<<j1.get_nombre()<<endl;
                        return true;
                    }
                    else {
                        j2.anadir_puntos(p);
                        cout<<"gana "<<j2.get_nombre()<<endl;
                        return false;
                    }
                }
                else { //si no son del mismo palo, ni de la muestra
                    //gana quien sale primero
                    if(empieza) {
                        j1.anadir_puntos(p);
                        cout<<"gana "<<j1.get_nombre()<<endl;
                        return true;
                    }
                    else {
                        j2.anadir_puntos(p);
                        cout<<"gana "<<j2.get_nombre()<<endl;
                        return false;
                    }
                }
            }
        }
    }


    //mostramos cada jugador
    void mostrar(ostream &out=cout) const {
        cout<<"			La muestra es:";
        muestra.mostrar();
        j1.mostrar();
        j2.mostrar();

    }
};


