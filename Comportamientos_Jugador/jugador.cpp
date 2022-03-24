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

	nivel = sensores.nivel;

	if ((sensores.terreno[0]=='G' || nivel == 0) and !bien_situado){
		brujula = sensores.sentido ; 
		fil = sensores.posF;
		col = sensores.posC;
		bien_situado = true;
		for(int i = 0; i < mapaResultado.size(); i++){
			mapaAuxiliar.push_back(mapaResultado[i]);
		}
	}

	if( sensores.terreno[0] == 'D'){
		tiene_zapatillas = true;
	}
	else if(sensores.terreno[0] == 'K'){
		tiene_bikini = true;
	}



	if(bien_situado){
		switch(brujula){
			case 0:{	//Norte
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j = -i; j<=i; j++){
						mapaResultado[fil-i][col+j] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break;

			case 1:{	//Este
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j =-i; j<=i; j++){
						mapaResultado[fil+j][col+i] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break; 

			case 2: //Sur
			{
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j =-i; j<=i; j++){
						mapaResultado[fil+i][col-j] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break; 

			case 3://Oeste
			{
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j =-i; j<=i; j++){
						mapaResultado[fil-j][col-i] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break;
		}
	}
	else{
		switch(brujula){
			case 0://Norte
			break;

			case 1: //Este
			break; 

			case 2: //Sur
			break; 

			case 3://Oeste
			break;
		}

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