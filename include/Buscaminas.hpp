#pragma once
#include "Tablero.hpp"
#include "Jugador.hpp"
#include "Puntaje.hpp"
#include <string>

class Buscaminas {
public:
    Buscaminas(int filas, int columnas, int minas, const std::string& nombreJugador);
    void jugar();
private:
    int filas;
    int columnas;
    int minas;
    Tablero tablero;
    Jugador jugador;
    Puntaje puntaje;
};

