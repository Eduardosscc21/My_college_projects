#ifndef ACCESO_DIRECTO_H_
#define ACCESO_DIRECTO_H_


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string.h> 


using namespace std;

class Alumno
{
public:
    char codigo[4],carrera[30],Nombre_de_tesis[35],NumeroDeAlumno[25],Director[25],Sinodal[25];
    void Agregar();
    void Mostrar();
    void Modificar();
    void Buscar();
    void Eliminar();
} AlumCom;

void Alumno::Agregar()
{
    cout<<"AGREGAR"<<endl;
    
    cout<<"codigo: ";
    cin.getline(codigo,4);
    cin.getline(codigo,4);
    
    cout<<"carrera: ";
    cin.getline(carrera,30);
    
    cout<<"Nombre de la tesis: ";
    cin.getline(Nombre_de_tesis,35);
    
    cout<<"Numero de Alumno: ";
    cin.getline(NumeroDeAlumno,25);
    
    cout<<"Director: ";
    cin.getline(Director,25);
    
    cout<<"Sinodal: ";
    cin.getline(Sinodal,25);
    
    ofstream archivo("Alumnos.txt",ios::app);
    archivo.write((char*)&AlumCom,sizeof(AlumCom));
    archivo.close();
}

void Alumno::Mostrar()
{
    char usuario2[10], password2[10];
    int band=0;
    ifstream archivo("Alumnos.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MOSTRAR"<<endl;
        while(!archivo.eof())
        {
            archivo.read((char*)&AlumCom,sizeof(AlumCom));
            if(archivo.eof())
            {
                break;
            }
            cout<<"codigo: "<<codigo<<endl;
            cout<<"carrera: "<<carrera<<endl;
            cout<<"Nombre de la tesis: "<<Nombre_de_tesis<<endl;
            cout<<"Numero de Alumno: "<<NumeroDeAlumno<<endl;
            cout<<"Director: "<<Director<<endl;
            cout<<"Sinodal: $"<<Sinodal<<endl;
            cout<<""<<endl;
        }
        archivo.close();
    }
}


void Alumno::Modificar()
{
    char valor[4];
    ifstream archivo("Alumnos.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"MODIFICAR"<<endl;
        cout<<"Ingrese el codigo modificar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&AlumCom,sizeof(AlumCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(codigo,valor)==0)
            {
                cout<<""<<endl;
                cout<<"codigo: ";
                cin.getline(codigo,4);
                
                cout<<"carrera: ";
                cin.getline(carrera,30);
                
                cout<<"Nombre de tesis: ";
                cin.getline(Nombre_de_tesis,35);
                
                cout<<"Numero de Alumno: ";
                cin.getline(NumeroDeAlumno,25);
                
                cout<<"Director: ";
                cin.getline(Director,25);
                
                cout<<"Sinodal: ";
                cin.getline(Sinodal,25);
                
                ofstream archivo("Alumnos.txt",ios::app);
                archivo2.write((char*)&AlumCom,sizeof(AlumCom));
            }
            else
            {
                archivo2.write((char*)&AlumCom,sizeof(AlumCom));
            }

        }
        archivo.close();
        archivo2.close();
        remove("Alumnos.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="Alumnos.txt";
        rename(oldname,newname);
    }
}
//

void Alumno::Eliminar()
{
    char valor[4];
    int opcion=0;
    ifstream archivo("Alumnos.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"ELIMINAR "<<endl;
        cout<<"Ingrese el codigo a eliminar: ";
        cin.getline(valor,4);
        cin.getline(valor,4);
        
        ofstream archivo2("temporal.txt",ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&AlumCom,sizeof(AlumCom));
            if(archivo.eof())
            {
                break;
            }
            if(strcmp(AlumCom.codigo,valor)==0)
            {
                cout<<"\tALUMNO"<<endl;
                cout<<"codigo: "<<codigo<<endl;
                cout<<"carrera: "<<carrera<<endl;
                cout<<"Nombre de tesis: "<<Nombre_de_tesis<<endl;
                cout<<"Numero de Alumno: "<<NumeroDeAlumno<<endl;
                cout<<"Director: "<<Director<<endl;
                cout<<"Sinodal: $"<<Sinodal<<endl;
                cout<<"DESEAS ELIMINAR?\n1.- SI\n0.- NO\n>: ";
                cin>>opcion;
                if(opcion==1)
                {

                }
                else
                {
                    archivo2.write((char*)&AlumCom,sizeof(AlumCom));
                }
            }
            else
            {
                archivo2.write((char*)&AlumCom,sizeof(AlumCom));
            }
        }
        archivo.close();
        archivo2.close();
        remove("Alumnos.txt");
        char oldname[] ="temporal.txt";
        char newname[] ="Alumnos.txt";
        rename(oldname,newname);
    }

}

//******************************************

void Alumno::Buscar()
{
    char valor[4];
    ifstream archivo("Alumnos.txt");
    if(!archivo.good())
    {
        cout<<"\n El archivo no existe....."<<endl;
    }
    else
    {
        cout<<"BUSCAR"<<endl;
        cout<<"codigo: ";
        cin.ignore();
		cin.getline(valor,4);
        archivo.read((char*)&AlumCom,sizeof(AlumCom));
        if(strcmp(codigo,valor)==0)
        {
            cout<<"\tALUMNO"<<endl;
            cout<<"codigo: "<<codigo<<endl;
            cout<<"carrera: "<<carrera<<endl;
            cout<<"Nombre de tesis: "<<Nombre_de_tesis<<endl;
            cout<<"Numero de Alumno: "<<NumeroDeAlumno<<endl;
            cout<<"Director: "<<Director<<endl;
            cout<<"Sinodal: $"<<Sinodal<<endl;
        }
        else
        {
            cout << " no encontrada..." << endl;
        }
    }
    archivo.close();
}

//******************************
void Pausar()
{
    cin.get();
    cout << "Presione entrar para continuar..." << endl;
    cin.get();
    system("cls");
}

//*************************





#endif 
