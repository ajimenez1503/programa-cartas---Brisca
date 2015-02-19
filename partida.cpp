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
    partida p;
	//comienza un jugador de forma aleatoria
	p.toda_partida(rand()%(2));
}
