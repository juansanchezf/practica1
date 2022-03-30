#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      fil = col = 99;
      brujula = 0;
      girar_derecha = bien_situado = false;
      tiene_zapatillas = tiene_bikini = false;
      ultimaAccion = actIDLE;
      en_linea = 0;
      nivel = -1;
      primer_paso = true;
      vector<unsigned char> aux(200,'?');
      for(int i = 0; i < 200; i++){
        mapaAuxiliar.push_back(aux);
      }
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
    int fil, col, brujula;
    int fil_aux, col_aux;
    bool girar_derecha, bien_situado;
    bool tiene_zapatillas, tiene_bikini;
    int en_linea;
    int nivel;
    Action ultimaAccion;
    vector< vector< unsigned char> > mapaAuxiliar;
    bool primer_paso;
  
  // Declarar aquí las variables de estado

};

#endif
