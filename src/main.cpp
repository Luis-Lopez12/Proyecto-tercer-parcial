#include "Juego.hpp"

int main() {
    Juego juego(8, 8, 10); // 8x8 con 10 minas
    juego.Iniciar();
    juego.Jugar();
    return 0;
}
