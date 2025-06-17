#include "Interfaz.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h>
#endif

Interfaz::Interfaz() : window(sf::VideoMode(400, 400), "Buscaminas SFML") {
    font.loadFromFile("data/arial.ttf");
    bufferExplosion.loadFromFile("data/explosion.wav");
    bufferVictoria.loadFromFile("data/victoria.wav");
}

void Interfaz::MostrarTablero(const Tablero& tablero, bool mostrarMinas) const {
    tablero.Mostrar(mostrarMinas);
}

void Interfaz::MostrarMensaje(const std::string& mensaje) const {
    std::cout << mensaje << std::endl;
}

void Interfaz::PedirJugada(int& fila, int& columna) const {
    std::cout << "Ingrese fila y columna: ";
    std::cin >> fila >> columna;
}

std::string Interfaz::PedirNombreJugador() const {
    std::string nombre;
    std::cout << "Ingrese su nombre: ";
    std::cin >> nombre;
    return nombre;
}

void Interfaz::AnimacionInicio() const {
    std::cout << "=========================\n";
    std::cout << "     BUSCAMINAS 2.0      \n";
    std::cout << "=========================\n";
    std::cout << "   Cargando tablero...   \n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1200));
    std::cout << "\n";
}

void Interfaz::AnimacionExplosion() const {
    std::cout << R"(
      _.-^^---....,,--
  _--                  --_
 <                        >)
 |                         |
  \._                   _./
     '''--. . , ; .--'''
           | |   |
        .-=||  | |=-.
        `-=#$%&%$#=-'
           | ;  :|
  _____.,-#%&$@%#&#~,._____
    )" << std::endl;
    std::cout << "¡BOOM! Pisaste una mina.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void Interfaz::AnimacionVictoria() const {
    std::cout << R"(
   __   __            _    _ _       
   \ \ / /           | |  | (_)      
    \ V /___  _   _  | |  | |_ _ __  
     \ // _ \| | | | | |/\| | | '_ \ 
     | | (_) | |_| | \  /\  / | | | |
     \_/\___/ \__,_|  \/  \/|_|_| |_|
    )" << std::endl;
    std::cout << "¡Felicidades! Has ganado.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

void Interfaz::MostrarVentana(Tablero& tablero, Jugador& jugador, bool& juegoTerminado, bool& victoria) {
    int filas = tablero.GetFilas();
    int columnas = tablero.GetColumnas();
    int tam = 40; // tamaño de celda
    while (window.isOpen() && !juegoTerminado) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                int x = event.mouseButton.x / tam;
                int y = event.mouseButton.y / tam;
                if (x >= 0 && x < columnas && y >= 0 && y < filas) {
                    int resultado = tablero.AbrirCelda(y, x);
                    if (resultado == -1) {
                        ReproducirSonido("data/explosion.wav");
                        juegoTerminado = true;
                        victoria = false;
                    } else {
                        jugador.IncrementarPuntaje(10 * resultado);
                        if (tablero.EsVictoria()) {
                            ReproducirSonido("data/victoria.wav");
                            juegoTerminado = true;
                            victoria = true;
                            jugador.IncrementarPuntaje(100);
                        }
                    }
                }
            }
        }
        window.clear(sf::Color::White);
        dibujarTablero(tablero);
        window.display();
    }
}

void Interfaz::dibujarTablero(Tablero& tablero) {
    int filas = tablero.GetFilas();
    int columnas = tablero.GetColumnas();
    int tam = 40;
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            sf::RectangleShape rect(sf::Vector2f(tam-2, tam-2));
            rect.setPosition(c * tam + 1, f * tam + 1);
            if (tablero.CeldaEstaAbierta(f, c)) {
                rect.setFillColor(sf::Color(200, 200, 200));
                if (tablero.EsMina(f, c)) {
                    rect.setFillColor(sf::Color::Red);
                }
            } else {
                rect.setFillColor(sf::Color(100, 100, 100));
            }
            window.draw(rect);

            if (tablero.CeldaEstaAbierta(f, c) && !tablero.EsMina(f, c)) {
                int minas = tablero.GetMinasAlrededor(f, c);
                if (minas > 0) {
                    sf::Text text;
                    text.setFont(font);
                    text.setString(std::to_string(minas));
                    text.setCharacterSize(24);
                    text.setFillColor(sf::Color::Blue);
                    text.setPosition(c * tam + 10, f * tam + 5);
                    window.draw(text);
                }
            }
        }
    }
}

void Interfaz::ReproducirSonido(const std::string& archivo) {
    if (archivo.find("explosion") != std::string::npos) {
        sound.setBuffer(bufferExplosion);
    } else if (archivo.find("victoria") != std::string::npos) {
        sound.setBuffer(bufferVictoria);
    }
    sound.play();
}