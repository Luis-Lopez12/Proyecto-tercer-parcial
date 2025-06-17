#ifndef CELDA_HPP
#define CELDA_HPP

class Celda {
private:
    bool mina;
    bool abierta;
    bool marcada;
    int minasAlrededor;

public:
    Celda();
    void Abrir();
    void Marcar();
    bool EsMina() const;
    bool EstaAbierta() const;
    bool EstaMarcada() const;
    void SetMina(bool valor);
    void SetMinasAlrededor(int cantidad);
    int GetMinasAlrededor() const;
};

#endif // CELDA_HPP
