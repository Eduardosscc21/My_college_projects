#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include "Paqueteria.h"


using namespace std;

int main()
{
    Paqueteria *listasimple = new Paqueteria;
    Paquete paque;
    int opc, tamanio;
    string id,origen,destino,peso;
    bool vacio;
    Nodo *primero;
    Nodo *ultimo;
    Nodo *siguiente;
    Nodo *anterior;
    do
    {
        cout<<"\tActividad 01"<<endl<<endl;
        cout<<"1.- Inicializar"<<endl;
        cout<<"2.- Agregar paquete"<<endl;
        cout<<"3.- Eliminar al Inicio"<<endl;
        cout<<"4.- Mostrar"<<endl;
        cout<<"5.- Guardar"<<endl;
        cout<<"6.- Recuperar"<<endl;
        cout<<"7.- Salir"<<endl<<endl;
        cout<<"Opci\xA2n: ";
        cin>>opc;
        cout<<endl;

        switch(opc)
        {
        case 1:
            listasimple->Inicializar();
            cout<<"¡Lista Inicializada con Exito!"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            break;
        case 2:        	
        	cout<<"Id: ";
            fflush(stdin);
            getline(cin, id);
            
            cout<<"origen: ";
            fflush(stdin);
            getline(cin, origen);
            
            cout<<"destino: ";
            fflush(stdin);
            getline(cin, destino);
            
            cout<<"peso: ";
            fflush(stdin);
            getline(cin, peso);
            
            
            
            paque.setOrigen(origen);
            paque.setId(id);
            paque.setDestino(destino);
            paque.setPeso(peso);
            
            listasimple->Insertar_Al_Inicio(paque);
            cout<<endl;
            system("pause");
            system("cls");
            break;

        case 3:       
            listasimple->Eliminar_Al_Inicio();
            system("pause");
            system("cls");
            break;
        case 4: 
            listasimple->Mostrar();
            cout<<endl;
            system("pause");
            system("cls");           
            break;          
        case 5:
        	listasimple->Guardar();
            cout<<"Datos Guardados correctamente"<<endl;
            system("pause");
            system("cls");
            break;
        case 6:
        	 listasimple->Recuperar();
            cout<<"Datos Cargados correctamente"<<endl;
            system("pause");
            system("cls");
            break;
        case 7:        
            break;
           
        default:
            cout<<"Opci\xA2n invalida\n"<<endl;
            cout<<endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while(opc != 7);

    return 0;
}
