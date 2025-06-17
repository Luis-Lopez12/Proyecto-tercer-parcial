#ifndef JUEGO_HPP
#define JUEGO_HPP

#include "Tablero.hpp"
#include "Jugador.hpp"
#include "Interfaz.hpp"

class Juego {
private:
    Tablero* tablero;
    Jugador* jugador;
    Interfaz* interfaz;
    bool juegoTerminado;

public:
    Juego(int filas, int columnas, int minas);
    ~Juego();
    void Iniciar();
    void Jugar(); // Sin cambios en la firma
};

#endif // JUEGO_HPP
