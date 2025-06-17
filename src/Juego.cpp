#include "Juego.hpp"

Juego::Juego(int filas, int columnas, int minas) {
    interfaz = new Interfaz();
    std::string nombre = interfaz->PedirNombreJugador();
    jugador = new Jugador(nombre);
    tablero = new Tablero(filas, columnas, minas);
    juegoTerminado = false;
}

Juego::~Juego() {
    delete tablero;
    delete jugador;
    delete interfaz;
}

void Juego::Iniciar() {
    // No hace falta nada aquí para SFML
}

void Juego::Jugar() {
    bool victoria = false;
    interfaz->MostrarVentana(*tablero, *jugador, juegoTerminado, victoria);
    if (victoria) {
        interfaz->mostrarMensaje("¡Ganaste!");
    } else {
        interfaz->mostrarMensaje("¡Perdiste!");
    }
    interfaz->mostrarMensaje("Puntaje final de " + jugador->GetNombre() + ": " + std::to_string(jugador->GetPuntaje()));
}