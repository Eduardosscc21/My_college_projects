#ifndef SERIALIZACION_H_
#define SERIALIZACION_H_

#include <iostream>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h>

using namespace std;

class Historial_de_usuario
{
    public:
    char codigo[10], consultas[10],favoritos[40],fecha_consulta[40], nombre_usuario[40],numero_usuario[10];

    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();

} hrep;

void Historial_de_usuario::Agregar()
{
    cout<<"-----------------------------------"<<endl;
    cout<<"\t AGREGAR"<<endl;
    cout<<"-----------------------------------"<<endl;

    cout<<"Codigo: ";
     cin.getline(codigo,10);
     cin.getline(codigo,10);
    cout<<"Numero de consultas: ";
     cin.getline(consultas,10);
    cout<<"Favoritos: ";
     cin.getline(favoritos,40);
    cout<<"Fecha de consultas: ";
     cin.getline(fecha_consulta,40);
    cout<<"Nombre de usuario: ";
     cin.getline(nombre_usuario,40);
    cout<<"Numero de usuario: ";
     cin.getline(numero_usuario,10);

    ofstream archivo("historial.txt",ios::app);
    archivo.write((char*)&hrep,sizeof(hrep));
    archivo.close();
}

void Historial_de_usuario::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("historial.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"\t MOSTRAR"<<endl;
        cout<<"-----------------------------------"<<endl;
        
        while(!archivo.eof())
        {
            archivo.read((char*)&hrep,sizeof(hrep));
            if(archivo.eof())
            {
                break;
            }
            cout<<"Codigo: "<<codigo<<endl;
            cout<<"Numero de consultas: "<<consultas<<endl;
            cout<<"Favoritos: "<<favoritos<<endl;
            cout<<"Fecha de consultas: "<<fecha_consulta<<endl;
            cout<<"Nombre de usuario: "<<nombre_usuario<<endl;
            cout<<"Numero de usuario: "<<numero_usuario<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}

void Historial_de_usuario::Buscar()
{
    char valor[10];
    ifstream archivo("historial.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"\t BUSCAR"<<endl;
        cout<<"-----------------------------------"<<endl;
        
        cout<<"Ingrese el codigo a buscar: ";
        cin.getline(valor,10);
        cin.getline(valor,10);

        archivo.read((char*)&hrep,sizeof(hrep));
        if(strcmp(codigo,valor)==0)
        {
            cout<<"Codigo: "<<codigo<<endl;
            cout<<"Numero de consultas: "<<consultas<<endl;
            cout<<"Favoritos: "<<favoritos<<endl;
            cout<<"Fecha de consultas: "<<fecha_consulta<<endl;
            cout<<"Nombre de usuario: "<<nombre_usuario<<endl;
            cout<<"Numero de usuario: "<<numero_usuario<<endl;
            cout<<""<<endl;
        }
        else
        {
            cout << "codigo no encontrado..." << endl;
        }
    }
    archivo.close();
}

void Historial_de_usuario::Modificar()
{
    char valor[10];
    ifstream archivo("historial.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"-----------------------------------"<<endl;
        cout<<"\t MODIFICAR"<<endl;
        cout<<"-----------------------------------"<<endl;
		
        cout<<"Ingrese el codigo a modificar: ";
        cin.getline(valor,10);
        cin.getline(valor,10);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&hrep,sizeof(hrep));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(codigo,valor)==0)
            {
                cout<<""<<endl;

                cout<<"Codigo: ";
                cin.getline(codigo,10);
                cout<<"Numero de consultas: ";
                cin.getline(consultas,10);
                cout<<"Favoritos: ";
                cin.getline(favoritos,40);
                cout<<"Fecha de consultas: ";
                cin.getline(fecha_consulta,40);
                cout<<"Nombre de usuario: ";
                cin.getline(nombre_usuario,40);
                cout<<"Numero de usuario: ";
                cin.getline(numero_usuario,10);

                ofstream archivo("historial.txt",ios::app);
                archivo2.write((char*)&hrep,sizeof(hrep));
            }
            else
            {
                archivo2.write((char*)&hrep,sizeof(hrep));
            }

        }
        archivo.close();
        archivo2.close();
        remove("historial.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="historial.txt";
        rename(oldname,newname);
    }
}


void Historial_de_usuario::Eliminar()
{
    char valor[10];
    int opcion=0;
    ifstream archivo("historial.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {       
        cout<<"-----------------------------------"<<endl;
        cout<<"\t ELIMINAR"<<endl;
        cout<<"-----------------------------------"<<endl;
        
        cout<<"Ingrese el codigo a eliminar: ";
        cin.getline(valor,10);
        cin.getline(valor,10);
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&hrep,sizeof(hrep));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(codigo,valor)==0)
            {
                cout<<"Codigo: "<<codigo<<endl;
                cout<<"Numero de consultas: "<<consultas<<endl;
                cout<<"Favoritos: "<<favoritos<<endl;
                cout<<"Fecha de consultas: "<<fecha_consulta<<endl;
                cout<<"Nombre de usuario: "<<nombre_usuario<<endl;
                cout<<"Numero de usuario: "<<numero_usuario<<endl;
                cout<<""<<endl;

                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&hrep,sizeof(hrep));
                }
            }
            else
            {
                archivo2.write((char*)&hrep,sizeof(hrep));
            }
        }
        archivo.close();
        archivo2.close();
        remove("historial.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="historial.txt";
        rename(oldname,newname);
    }
}




#endif 
