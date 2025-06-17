#include "Tablero.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Tablero::Tablero(int filas, int columnas, int minas)
    : filas(filas), columnas(columnas), minas(minas), celdas(filas, std::vector<Celda>(columnas)) {}

void Tablero::GenerarMinas(int filaInicial, int columnaInicial) {
    srand(time(0));
    int colocadas = 0;
    while (colocadas < minas) {
        int f = rand() % filas;
        int c = rand() % columnas;
        if ((f == filaInicial && c == columnaInicial) || celdas[f][c].EsMina())
            continue;
        celdas[f][c].SetMina(true);
        colocadas++;
    }
    CalcularMinasAlrededor();
}

void Tablero::CalcularMinasAlrededor() {
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            int contador = 0;
            for (int df = -1; df <= 1; ++df) {
                for (int dc = -1; dc <= 1; ++dc) {
                    int nf = f + df, nc = c + dc;
                    if (nf >= 0 && nf < filas && nc >= 0 && nc < columnas && celdas[nf][nc].EsMina())
                        contador++;
                }
            }
            celdas[f][c].SetMinasAlrededor(contador);
        }
    }
}

void Tablero::Mostrar(bool mostrarMinas) const {
    std::cout << "   ";
    for (int c = 0; c < columnas; ++c) std::cout << c << " ";
    std::cout << "\n";
    for (int f = 0; f < filas; ++f) {
        std::cout << f << "  "; // Ajusta el espacio para alinear con el encabezado de columnas
        for (int c = 0; c < columnas; ++c) {
            if (celdas[f][c].EstaAbierta()) {
                if (celdas[f][c].EsMina())
                    std::cout << "* ";
                else
                    std::cout << celdas[f][c].GetMinasAlrededor() << " ";
            } else if (celdas[f][c].EstaMarcada()) {
                std::cout << "F ";
            } else if (mostrarMinas && celdas[f][c].EsMina()) {
                std::cout << "* ";
            } else {
                std::cout << ". ";
            }
        }
        std::cout << "\n";
    }
}

int Tablero::AbrirCelda(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas)
        return 0;
    if (celdas[fila][columna].EstaAbierta() || celdas[fila][columna].EstaMarcada())
        return 0;
    celdas[fila][columna].Abrir();
    if (celdas[fila][columna].EsMina())
        return -1;
    int abiertas = 1;
    if (celdas[fila][columna].GetMinasAlrededor() == 0) {
        for (int df = -1; df <= 1; ++df) {
            for (int dc = -1; dc <= 1; ++dc) {
                int nf = fila + df, nc = columna + dc;
                if ((df != 0 || dc != 0) && nf >= 0 && nf < filas && nc >= 0 && nc < columnas)
                    abiertas += AbrirCelda(nf, nc);
            }
        }
    }
    return abiertas;
}

void Tablero::MarcarCelda(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas)
        return;
    celdas[fila][columna].Marcar();
}

bool Tablero::EsVictoria() const {
    for (int f = 0; f < filas; ++f)
        for (int c = 0; c < columnas; ++c)
            if (!celdas[f][c].EsMina() && !celdas[f][c].EstaAbierta())
                return false;
    return true;
}

int Tablero::GetFilas() const { return filas; }
int Tablero::GetColumnas() const { return columnas; }

bool Tablero::CeldaEstaAbierta(int fila, int columna) const {
    return celdas[fila][columna].EstaAbierta();
}

bool Tablero::EsMina(int fila, int columna) const {
    return celdas[fila][columna].EsMina();
}

int Tablero::GetMinasAlrededor(int fila, int columna) const {
    return celdas[fila][columna].GetMinasAlrededor();
}