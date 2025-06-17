#ifndef TABLERO_HPP
#define TABLERO_HPP

#include "Celda.hpp"
#include <vector>

class Tablero {
private:
    int filas;
    int columnas;
    int minas;
    std::vector<std::vector<Celda>> celdas;

public:
    Tablero(int filas, int columnas, int minas);
    void GenerarMinas(int filaInicial, int columnaInicial);
    void CalcularMinasAlrededor();
    void Mostrar(bool mostrarMinas = false) const;
    // Cambia el tipo de retorno de bool a int
    int AbrirCelda(int fila, int columna);
    void MarcarCelda(int fila, int columna);
    bool EsVictoria() const;
    int GetFilas() const;
    int GetColumnas() const;
    bool CeldaEstaAbierta(int fila, int columna) const;
    bool ConsultarCeldaSegura(int fila, int columna) const;
    bool EsMina(int fila, int columna) const;
    int GetMinasAlrededor(int fila, int columna) const;
};

#endif // TABLERO_HPP
