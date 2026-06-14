#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include<iostream>
#include "Nodo.h"
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>


class Paqueteria
{
    public:
         Paqueteria();
        ~Paqueteria();

        void Inicializar();
        void Insertar_Al_Inicio(Paquete);
        void Mostrar();        
        void Eliminar_Al_Inicio();
        void Guardar();
        void Recuperar();
    protected:
        Nodo *h;

};



Paqueteria::Paqueteria()
{
        h = NULL;
}

void Paqueteria::Inicializar()
{
    h = NULL;
}

void Paqueteria::Insertar_Al_Inicio(Paquete paquete){
    Nodo *tmp = new Nodo();
    tmp->elemento = paquete;

    if (h == NULL) {
        h = tmp;
    } else {
        tmp->sig = h;
        h = tmp;
    }
}

void Paqueteria::Mostrar(){
     Nodo *aux;
     aux = h;
    if(aux == NULL)
    {
        cout<<"Lista Vacia"<<endl;
    }
    while(aux != NULL)
    {
        aux->elemento.imprimir();
        aux = aux->sig;
    }
}

void Paqueteria::Eliminar_Al_Inicio()
{
    
	Nodo *tmp=h->sig;
	delete h;
	
	h=tmp;
	
}

void Paqueteria::Guardar()
{
        ofstream archivo("file01.txt", ios::out);
        if(archivo.is_open()){
            Nodo *temp = h;
            while(temp != NULL){
                archivo<<temp->elemento.format();
                temp=temp->sig;
            }
        }
        archivo.close();
}

void Paqueteria::Recuperar()
{

	ifstream archivo;
	string texto;
	
	archivo.open("file01.txt",ios::in);
	
	if(archivo.fail())
	{
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	while(!archivo.eof())
	{
		getline(archivo,texto);
		cout<<texto<<endl;
	}
	
	archivo.close();
}


Paqueteria::~Paqueteria()
{
    
}

#endif 
