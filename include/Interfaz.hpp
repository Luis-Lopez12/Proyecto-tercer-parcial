#ifndef INTERFAZ_HPP
#define INTERFAZ_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Tablero.hpp"
#include "Jugador.hpp"
#include <string>

class Interfaz {
public:
    Interfaz();
    void MostrarVentana(Tablero& tablero, Jugador& jugador, bool& juegoTerminado, bool& victoria);
    void ReproducirSonido(const std::string& archivo);
private:
    sf::RenderWindow window;
    sf::Font font;
    sf::SoundBuffer bufferExplosion;
    sf::SoundBuffer bufferVictoria;
    sf::Sound sound;
    void dibujarTablero(Tablero& tablero);
    void mostrarMensaje(const std::string& mensaje);
};

#endif // INTERFAZ_HPP
