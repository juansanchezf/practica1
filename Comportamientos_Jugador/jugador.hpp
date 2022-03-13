#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
using namespace std;

class ComportamientoJugador : public Comportamiento{

  public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
      girar_derecha = bien_situado = false;
      fil = col = 99;
      brujula = 0;
      ultimaAccion = actIDLE;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
    bool girar_derecha, bien_situado;
    int fil, col, brujula;
    Action ultimaAccion;
  
  // Declarar aquí las variables de estado

};

#endif
