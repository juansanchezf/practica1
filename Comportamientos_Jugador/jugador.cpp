#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;

	////////Actualizar conocimiento////////
	switch(ultimaAccion){
		case actFORWARD:
			switch(brujula){
				case 0: fil--; break; //Norte
				case 1: col++; break; //Este
				case 2: fil++; break; //Sur
				case 3: col--; break; //Oeste
			}
			break;
		case actTURN_L:
			brujula = (brujula+3)%4;
			girar_derecha = (rand()%2==0);
			break;
		case actTURN_R:
			brujula = (brujula+1)%4;
			girar_derecha = (rand()%2==0);
			break;

	}

	if ((sensores.terreno[0]=='G') and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
	}

	if( sensores.terreno[0] == 'D'){
		tiene_zapatillas = true;
	}
	else if(sensores.terreno[0] == 'K'){
		tiene_bikini = true;
	}

	if(bien_situado){
		mapaResultado[fil][col] = sensores.terreno[0];
	}

	////////Decididir siguiente movimiento////////
	if( (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K' or
		(sensores.terreno[2]=='B' and tiene_zapatillas) or (sensores.terreno[2] == 'A' and tiene_bikini) ) and sensores.superficie[2] == '_' and en_linea < 5){
		accion = actFORWARD;
		en_linea++;
	}
	else if(!girar_derecha){
		accion = actTURN_L;
		en_linea = 0;
	}
	else{
		accion = actTURN_R;
		en_linea = 0;
	}

	////////Recordar ultima accion////////
	ultimaAccion = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}