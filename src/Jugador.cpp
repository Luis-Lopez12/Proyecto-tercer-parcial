#include "Jugador.hpp"

Jugador::Jugador(const std::string& nombre) : nombre(nombre), puntaje(0) {}

void Jugador::IncrementarPuntaje(int valor) {
    puntaje += valor;
}

int Jugador::GetPuntaje() const {
    return puntaje;
}

std::string Jugador::GetNombre() const {
    return nombre;
}