/* (C) Programmed by:
   Antonio Jimenez Martínez


Programa de cartas : Brisca
Version:0.1

Prueba cartas
*/

using namespace std;
#include "include/partida.h"

int main() {
    cout<<"Programa de cartas: brisca "<<endl;
	cout<<"ELIGE:\n"<<"1.Un usuario contra otro usuario.\n2.Un usuario contra una maquina aleatorio\n";
	int i;
    cin>>i;
    while(i<1 || i>2) { //i solo puede ser 1,2
       cout<<"Elige una forma de juego ";
       cin>>i;
    }
	partida p(i);
	//comienza un jugador de forma aleatoria
	p.toda_partida(rand()%(2));
}
