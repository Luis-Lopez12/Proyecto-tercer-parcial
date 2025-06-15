#pragma once

class Celda {
public:
    Celda();
    bool esMina() const;
    void ponerMina();
    bool estaDescubierta() const;
    void descubrir();
    int getMinasCerca() const;
    void setMinasCerca(int cantidad);
private:
    bool mina;
    bool descubierta;
    int minasCerca;
};
