#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;

	//ACTUALIZAR CONOCIMIENTO
	switch(ultimaAccion){
		case actFORWARD:
			switch(brujula){
				case 0: fil--; //Norte
				case 1: col++; //Sur
				case 2: fil++; //Este
				case 3: col--; //Oeste
			}
			break;
		case actTURN_L:
			brujula = (brujula + 3) % 4;
			girar_derecha = (rand()%2 == 0);
			break;
		case actTURN_R:
			brujula = (brujula + 1) % 4;
			girar_derecha = (rand()%2 == 0);
			break;
	}

	if(sensores.terreno[0] == 'G' and !bien_situado){
		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
	}

	if(bien_situado){
		mapaResultado[fil][col] = sensores.terreno[0];
	}

	//DECIDIR NUEVA ACCIÓN
	if( ( sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G') 
		and sensores.superficie[2] == '_'){
		accion = actFORWARD;
	}
	else if(!girar_derecha){
		accion = actTURN_L;
	}
	else{
		accion = actTURN_R;
	}

	//Recordar ultima accion
	ultimaAccion = accion;
	return accion;
}

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}