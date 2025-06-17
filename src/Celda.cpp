#include "Celda.hpp"

Celda::Celda() : mina(false), abierta(false), marcada(false), minasAlrededor(0) {}

void Celda::Abrir() { abierta = true; }
void Celda::Marcar() { marcada = !marcada; }
bool Celda::EsMina() const { return mina; }
bool Celda::EstaAbierta() const { return abierta; }
bool Celda::EstaMarcada() const { return marcada; }
void Celda::SetMina(bool valor) { mina = valor; }
void Celda::SetMinasAlrededor(int cantidad) { minasAlrededor = cantidad; }
int Celda::GetMinasAlrededor() const { return minasAlrededor; }