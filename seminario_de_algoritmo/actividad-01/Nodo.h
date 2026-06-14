#ifndef NODO_H
#define NODO_H
#include "Paquete.h"

class Nodo
{
    public:
        Nodo() {sig = NULL; };
        ~Nodo();

        Paquete elemento;
        Nodo *sig;

    private:

};


Nodo::~Nodo()
{
    //dtor
}

#endif
