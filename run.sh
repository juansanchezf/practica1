#!/bin/bash

for i in {0..4}
do
    echo -e "\nNivel $i mapa30\n"
    ./practica1SG mapas/mapa30.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapa50\n"
    ./practica1SG mapas/mapa50.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapa75\n"
    ./practica1SG mapas/mapa75.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapa100\n"
    ./practica1SG mapas/mapa100.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapaMedieval\n"
    ./practica1SG mapas/medieval.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapaCuadricula\n"
    ./practica1SG mapas/cuadricula.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapaPicto\n"
    ./practica1SG mapas/picto.map 1 $i 6 8 0
    ((i++))
done

for i in {0..4}
do
    echo -e "\nNivel $i mapaVertigo\n"
    ./practica1SG mapas/vertigo.map 1 $i 6 8 0
    ((i++))
done
