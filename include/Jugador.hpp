#ifndef JUGADOR_HPP
#define JUGADOR_HPP

#include <string>

class Jugador {
private:
    std::string nombre;
    int puntaje;

public:
    Jugador(const std::string& nombre);
    void IncrementarPuntaje(int valor);
    int GetPuntaje() const;
    std::string GetNombre() const;
};

#endif // JUGADOR_HPP
