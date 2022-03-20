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
      tiene_zapatillas = false;
      ultimaAccion = actIDLE;
    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);
    int interact(Action accion, int valor);

  private:
    int fil, col, brujula;
    bool girar_derecha, bien_situado;
    bool tiene_zapatillas;
    Action ultimaAccion;
  
  // Declarar aquí las variables de estado

};

#endif
