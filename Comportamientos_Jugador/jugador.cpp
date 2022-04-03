#include "../Comportamientos_Jugador/jugador.hpp"
#include <iostream>
using namespace std;



Action ComportamientoJugador::think(Sensores sensores){

	Action accion = actIDLE;



	///////////////ACCIONES QUE SOLO REALIZARÉ EN LA PRIMERA ITERACIÓN DEL PROGRAMA///////
	if(primer_paso){
		nivel = sensores.nivel;
		fil_aux = col_aux = mapaResultado.size()-1;
		primer_paso = false;
	}
	///////////////////////////////////////////////////////////////////////////////////


	////////Actualizar conocimiento////////
	switch(ultimaAccion){
		case actFORWARD:
			switch(brujula){
				case 0: //Norte
				{
					if(bien_situado)
						fil--;
					else
						fil_aux--;
				}
				break;
				case 1: //Este
				{
					if(bien_situado)
						col++;
					else
						col_aux++;
				}
				break;
				case 2: //Sur
				{
					if(bien_situado)
						fil++;
					else
						fil_aux++;
				} 
				break;
				case 3: //Oeste
				{
					if(bien_situado)
						col--;
					else
						col_aux--;
				}
				break;
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


	if(sensores.reset){
		bien_situado = false;
		brujula = 0;

		for(int i = 0; i < 200; i++)
			for(int j = 0; j < 200 ; j++)
				mapaAuxiliar[i][j] = '?';
		
		fil_aux = col_aux = mapaResultado.size()-1;
		tiene_zapatillas = false;
		tiene_bikini = false;
	}
	

	if ((sensores.terreno[0]=='G' || nivel == 0) and !bien_situado){
		brujula = sensores.sentido; 
		fil = sensores.posF;
		col = sensores.posC;
		brujula = sensores.sentido;
		bien_situado = true;

		if(nivel != 0){
			int despl_fil = fil_aux - fil;
			int despl_col = col_aux - col;

			for(int i = 0; i < mapaResultado.size(); i++){
				for(int j = 0; j < mapaResultado.size(); j++){
					
					mapaResultado[i][j] = mapaAuxiliar[i+despl_fil][j+despl_col];
				}
			}
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
			{
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j = -i; j<=i; j++){
						mapaAuxiliar[fil_aux-i][col_aux+j] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break;

			case 1: //Este
			{
				int sensor = 0;
				for(int i = 0; i < 4; i++){
					for(int j =-i; j<=i; j++){
						mapaAuxiliar[fil_aux+j][col_aux+i] = sensores.terreno[sensor];
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
						mapaAuxiliar[fil_aux+i][col_aux-j] = sensores.terreno[sensor];
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
						mapaAuxiliar[fil_aux-j][col_aux-i] = sensores.terreno[sensor];
						sensor++;
					}
				}
			}
			break;
		}
	}

	////////Decididir siguiente movimiento////////
	if( (sensores.terreno[2] == 'T' or sensores.terreno[2] == 'S' or sensores.terreno[2] == 'G' or sensores.terreno[2] == 'D' or sensores.terreno[2] == 'K' or
		(sensores.terreno[2]=='B' and tiene_zapatillas) or (sensores.terreno[2] == 'A' and tiene_bikini) ) and sensores.superficie[2] == '_' and en_linea < 5){
		accion = actFORWARD;
		en_linea++;
	}
	else if( !tiene_zapatillas and sensores.terreno[0] == 'B' and (sensores.terreno[2] != 'B' or sensores.terreno[6] != 'B' or sensores.terreno[12] != 'B') ){
		accion = actFORWARD;
	}
	else if( !tiene_zapatillas and sensores.terreno[0] == 'A' and (sensores.terreno[2] != 'A' or sensores.terreno[6] != 'A' or sensores.terreno[12] != 'A') ){
		accion = actFORWARD;
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