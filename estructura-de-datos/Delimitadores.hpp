#ifndef DELIMITADORES_H_
#define DELIMITADORES_H_

using namespace std;

#include <iostream>
#include <fstream> //FUNCIONES DE LECTURA Y ESCRITURA DENTRO DEL ARCHIVO
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* cin>> // lectura de numeros
   cin.getline(cadena, longitud) // para leer tipos de datos char
   getline(cin, cadena) // para leer tipos de datos string
*/

using namespace std;

class Tesis
{
	private:
		friend class proyecto;
public:
    char codigo[10], categoria[30], lista[30]; //ARREGLOS UNIDIMENSIONALES
    void Agregar(); //METODOS
    void Mostrar();
    void Buscar();
    void Eliminar();
    void Modificar();
}p;

/////METODO CAPTURAR
void Tesis::Agregar() // DE LA CLASE ALUMNO PERTENECE CAPTURAR ESO SIGNIFICAN LOS DOS PUNTOS
{
    cout<<"------AGREGAR------"<<endl;
    cout<<"Codigo de de estudiante o profesor: ";
    cin.getline(codigo, 10);
    cin.getline(codigo, 10); //EN LUGAR DE FFLUSH X QUE NO SIRVE CON GETLINE PARA LEER CADENAS
    cout<<"Categoria de la tesis:";
    cin.getline(categoria,30);
    cout<<"Lista:";
    cin.getline(lista,30);
    ofstream Archivo("Tesis.txt",ios::app); // ofstream crea un objeto para escritura en el archivo llamado "Archivo", ios::app = entrada y salida de datos
    Archivo<<codigo<<'|'<<categoria<<'|'<<lista<<'|'; // se escribiendo en el archivo creado campo por campo separado por el delimitador '|'
    Archivo.close(); // cerrar el archivo
    system("cls");
}


//////METODO MOSTRAR
void Tesis::Mostrar()
{
    int i;
    ifstream Lectura("Tesis.txt"); // abrir archivo en formato de lectura, "Lectura" que es un objeto
    if(!Lectura.good()) // good ( libreria fstream) nos verifica si hubo problema al abrir el archivo a traves de true o false
    {
        cout<<"No existe el archivo\n";
        system("pause");
    }
    else
    {
        while(!Lectura.eof()) // eof = end of file
        {
/////Lectura de la variable codigo
            i=0;
            do
            {
                Lectura.read((char *)&codigo[i],1); //leo el objeto de tipo char, lo asigno a la variable user en la posicion que tenga el subindice, y se lee de caracter en carácter
                if(Lectura.eof())
                    break;
                i++;
            }while(codigo[i-1]!='|'); // mientras user en la posicion del subindice menos 1 sea diferente al delimitador, sigues escribiendo en el arreglo "user"
            codigo[i-1]='\0'; // si no se cumple el while anterior, entonces escribe en la posicion del delimitador '\0' que significa final de la cadena para saber que se termino ese campo "user"

            //Lectura de la variable genero
            i=0;
            do
            {
                Lectura.read((char *)&categoria[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(categoria[i-1]!='|');
            categoria[i-1]='\0';

            //Lectura de la variable nombre
            i=0;
            do
            {
                Lectura.read((char *)&lista[i],1);
                if(Lectura.eof())
                    break;
                i++;
            }while(lista[i-1]!='|');
            lista[i-1]='\0';

            //Lectura de la variable ape

            if(Lectura.eof())
                break;

            cout<<"-----MOSTRAR-----\n";
            //Imprimes valores
            cout<<endl<<"\nCodigo: "<<codigo<<endl<<"\ncategoria: "<<categoria<<endl<<"\n lista: "<<lista<<endl<<"\n"; // endl=salto de linea
            if(Lectura.eof())
                break;
                

        }
        system("pause");
        system("cls");
    }
    Lectura.close(); // cierras el archivo a traves del objeto "Lectura"
}
/* PARA BUSCAR POR CUALQUIER ATRIBUTO O VARIABLE SE TIENE QUE RECORRER TODOS LOS CAMPOS DEL REGISTRO CARACTER POR CARACTER */


//////BUSCAR
void Tesis::Buscar(){
    int b;  b = 0; // Bandera
    int i; // Contador
    int iguales;
    char caracter;
    char alubus[10];


    ifstream arc("Tesis.txt");/* Abrimos el archivo */
    if(!arc.good())   /* Verificamos si el archivo existe */
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }

    else{
        cout<<"-----BUSCAR-----";
        cout<<"\n Escribe el codigo : ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);


        while(!arc.eof()){
    ////codigo
            i = 0;
            do{ // ciclo para leer cada uno de los campos
                arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                if(caracter!='|')
                {
                    codigo[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                    i++;
                }

            }while(caracter != '|');

            codigo[i]= '\0'; // Finaliza la cadena despues del fin del atributo
    ////categoria
            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                   categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            categoria[i]= '\0';



    ///////lista
            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                {
                    lista[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
            lista[i]= '\0';


            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(codigo,alubus);

            if(iguales == 0){
                cout<<"\n codigo: " <<codigo <<"\n categoria: " <<categoria<<"\n lista: " <<lista<< endl<<"\n";
                b = 1; // Activamos la bandera
                break;
            }
        }

        if( b == 0){
            cout<<"\n\n NO EXISTE EL REGISTRO... \n\n";
        }
        arc.close();
    }
    system("pause");
    system("cls");
}

//////ELIMINAR
void Tesis::Eliminar(){
    int b = 0; // Bandera
    int i; // Contador
    int iguales,respuesta; respuesta = 0;
    char caracter;
    char alubus[10];


    ifstream arc("Tesis.txt"); /* Abrimos el archivo */
    if(!arc.good())   /* Verificamos si el archivo existe */
    {
        cout<<"\n NO EXISTE ARCHIVO...\n";
    }
    else{
         cout<<"-----ELIMINAR-----\n";
        cout<<"\n Escribe el codigo: ";
        cin.getline(alubus,10);
        cin.getline(alubus,10);

        while(!arc.eof()){
/////////codigo
            i = 0;
            do{ // ciclo para leer cada uno de los campos
                arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                if(caracter!='|')
                {
                    codigo[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                    i++;
                }

            }while(caracter != '|');

            codigo[i]= '\0'; // Finaliza la cadena despues del fin de la cadena

/////////categoria
            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|')
                {
                    categoria[i] = caracter;
                    i++;
                }

            }while(caracter != '|');
            categoria[i]= '\0';



///////lista
            i = 0;
            do
            {
                arc.read((char*)&caracter,1);
                if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                {
                    lista[i] = caracter;
                    i++;
                }

            }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
            lista[i]= '\0';


            if(arc.eof())
            {
                break;
            }

            iguales = strcmp(codigo,alubus); // COMPARACION DE LOS CAMPOS 0 ES VERDADERO

            if(iguales == 0){
                cout<<"\n codigo: " <<codigo <<"\n categoria: " <<categoria <<"\n lista: " <<lista <<endl<<"\n";
                b = 1; // Activamos la bandera            }
        }


        }
        arc.close();
        }

        if(b == 0) {
            cout<<"\n\n EL REGISTRO NO EXISTE \n\n";
        }
        if(b == 1){

            cout<<"\n Escribe 1 si deseas eliminar este registro: ";

            cin>>respuesta;

            if(respuesta == 1){
                ifstream arc ("Tesis.txt"); // Abrimos el archivo de datos
                ofstream temporal ("temporalauto.txt",ios::app); // Creamos el archivo temporal

                while(!arc.eof()){
///////codigo
                    i = 0;
                    do{ // ciclo para leer cada uno de los campos
                        arc.read((char*)&caracter,1); // Leo 1 caracter y se lo asigno a la variable caracter
                        if(caracter!='|')

                        {
                            codigo[i] = caracter; // Le asigna al arreglo en la posicion i, el valor del caracter leido
                            i++;
                        }

                    }while(caracter != '|');
                    codigo[i]= '\0'; // Finaliza la cadena despues del fin de la cadena

////////categoria

                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|')
                        {

                            categoria[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|');
                    categoria[i]= '\0';





//////lista
                    i = 0;
                    do
                    {
                        arc.read((char*)&caracter,1);
                        if(caracter!='|' && !arc.eof()) // Validacion que se debe hacer con el ultimo campo
                        {
                            lista[i] = caracter;
                            i++;
                        }

                    }while(caracter != '|' && !arc.eof()); // Validacion que se debe hacer con el ultimo campo
                    lista[i]= '\0';

                   if(arc.eof())
                    {
                        break;
                    }

                    iguales = strcmp(codigo,alubus);
                    if(iguales != 0){
                        temporal <<codigo<<"|"<<categoria<<"|"<<lista<<"|";

                    }
                } // while

                arc.close();
                temporal.close();
                remove("Tesis.txt");
                rename("temporalauto.txt","Tesis.txt");
                cout<<"\n\n EL REGISTRO FUE ELIMINADO... \n\n";
                b = 1;
            } // if

            else {
                cout<<"\n EL REGISTRO NO FUE ELIMINADO... \n\n";
            }

        }
        system("pause");
        system("cls");



}


void Tesis::Modificar()
{
    int i;//contador
    int opcion;
    char tesMod[10];
    bool b;

    ifstream Lectura("Tesis.txt");/* Abrimos el archivo */
    ofstream LecturaTemporal("temporalauto.txt",ios::app);

    if(!Lectura.good())
        cout<<"\n EL REGISTRO NO EXISTE \n ";
    else
    {
         cout<<"-----MODIFICAR-----\n";
        cout<<"\n Introduce el codigo a modificar :  ";
        cin.getline(tesMod,10);
        cin.getline(tesMod,10);

        b = false;

        while(!Lectura.eof()){
/////codigo
            i=0;
            do{
                Lectura.read((char*)&codigo[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(codigo[i-1]!='|');
            codigo[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;

////////categoria
            i=0;
            do{
                Lectura.read((char*)&categoria[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(categoria[i-1]!='|' && !Lectura.eof());
            categoria[i-1]='\0';//Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;




//////////lista
            i=0;
            do{// ciclo para leer cada uno de los campos
                Lectura.read((char*)&lista[i],1);// Leo 1 caracter y se lo asigno a la variable caracter
                if(Lectura.eof()) break;
                i++;
            }while(lista[i-1]!='|');
            lista[i-1]='\0';// Finaliza la cadena despues del fin de la cadena
            if(Lectura.eof()) break;

            if(strcmp(codigo,tesMod)==0 && !b)
            {
                cout<<endl<<"\n  codigo : "<<codigo<<endl<<"\n  categoria : "<<categoria<<endl<<"\n  lista : "<<lista<<endl<<endl;

                cout <<"\n  Que desea realiza ?\n ";
                cout <<"\n 1) Modificar Codigo: ";
                cout <<"\n 2) Modificar categoria: ";
                cout <<"\n 3) Modificar lista:";
                cout <<"\n 4) Regresar: ";

                cout<<"\n   Elige la opcion a realizar: ";
                cin>>opcion;


                switch(opcion) ///switch para realizar las modificaciones
                {
                    case 1:///////codigo
                        cout<<"\n Codigo de la pelicula : ";
                        cin.getline(codigo,10);
                        cin.getline(codigo,10);
                        break;
                    case 2://////categoria
                        cout<<"\n categoria : ";
                        cin.getline(categoria,30);
                        cin.getline(categoria,30);
                        break;
                   
                    case 3:///lista
                        cout<<"\n lista : ";
                        cin.getline(lista,30);
                        cin.getline(lista,30);
                        break;
                    default: cout<<"\n No se encontro la opcion ";
                }

                if(opcion!=5 && opcion>0 && opcion<7)
                    b = true;
            }
            LecturaTemporal<<codigo<<'|'<<categoria<<'|'<<lista<<'|';
        }
        Lectura.close();
        LecturaTemporal.close();
        if(!b)
            cout<<"\n No se encontro arhcivo ";

        remove("Tesis.txt");
        rename("temporalauto.txt","Tesis.txt");
    }
    system("cls");
    system("pause");
}
#endif 
