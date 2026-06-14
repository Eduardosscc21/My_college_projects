#ifndef DISPERSION_H_
#define DISPERSION_H_

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define NUMREGISTROS 100
#define CONTENEDOR   4

class Profesor
{
    private:
        char codigo[ 12 ];
        char nombre[ 35 ];
        char tesis_cons[ 35 ];
        char fecha[ 10 ];

        int dispersion( const char llave[ 12 ] );
        long int buscarId( const string & );
    public:
        Profesor( void );
        Profesor( const Profesor & );
        void setCodigo( const string & );
        void setNombre( const string & );
        void setTes( const string & );
        void setFecha( const string & );
        friend ostream &operator<<( ostream &, const Profesor & );

        bool agregar( const Profesor & );
        void mostrar( void );
        bool buscar( const string &, Profesor & );
        bool eliminar( const string &, Profesor & );
        bool modificar( const string &, const Profesor & );
        void mostrarIndice( void );
        Profesor pedirRegistro( void );
        bool contiene( const string & );
        void genera( void );
};


// constructor
Profesor::Profesor( void )
{
    for( int i = 0; i < sizeof( codigo ); codigo[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( nombre ); nombre[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( tesis_cons ); tesis_cons[ i++ ] = '\0' );
    for( int i = 0; i < sizeof( fecha ); fecha[ i++ ] = '\0' );
}


bool Profesor::contiene( const string &idABuscar )
{
    if( buscarId( idABuscar ) == -1 )
        return false;
    return true;
}


Profesor Profesor::pedirRegistro( void )
{
    Profesor registroARetornar;
    string cadena;

    cout << endl << "Codigo: ";
    fflush( stdin );
    getline( cin, cadena );
    while( contiene( cadena ) || cadena.size() == 0 )
    {
        cout << "Ese codigo ya existe o la cadena es invalida: ";
        fflush( stdin );
        getline( cin, cadena );
    }
    registroARetornar.setCodigo( cadena );

    cout << "Nombre: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setNombre( cadena );

    cout << "Tesis consultada: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setTes( cadena );
    
    cout << "Fecha: ";
    fflush( stdin );
    getline( cin, cadena );
    registroARetornar.setFecha( cadena );

    return registroARetornar;
}


//1
void Profesor::genera( void )
{
    Profesor pr;
    int contador = 0;
    ofstream archivo( "dispersion2.txt", ios::out );
    if( !archivo )
        cout << "No se pudo crear el archivo" << endl;
    else
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
        	// indica cuantos registros hay en el contenedor
        	archivo.write( ( char * ) &contador, sizeof( int ) );
        	for( int j = 0; j < CONTENEDOR; j++ )
            	archivo.write( ( char * ) &pr, sizeof( Profesor ) );
        }
    archivo.close();
}

int Profesor::dispersion( const char llave[ 12 ] )
{
    // llena la el sobrante de la llave con espacios
    char llaveCopia[ 12 ];
    strcpy( llaveCopia, llave );
    if( strlen( llaveCopia ) < 12 )
        for( int i = strlen( llaveCopia ); i < 12; i++ )
            llaveCopia[ i ] = ' ';
    llaveCopia[ 12 ] = '\0';

    // realiza el algoritmo
    long sum = 0;
    int j = 0;
    while( j < 12 )
    {
        sum = ( sum + 100 * llaveCopia[ j ] + llaveCopia[ j + 1 ] )  % 20000;
        j += 2;
    }
    return ( sum % 99 ); // retorna la posición donde se guardará el registros.
}

// retorna la posición donde se encontro el registro
long int Profesor::buscarId( const string &idABuscar )
{
    Profesor pr;
    int contador, posIndice;
    long int posByte;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return -1;
    }

    posIndice = dispersion( idABuscar.c_str() );
    posByte = posIndice * ( ( sizeof( Profesor ) * CONTENEDOR ) + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    if( contador > 0 )
    {
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &pr, sizeof( Profesor ) );
            if( strcmp( pr.codigo, idABuscar.c_str() ) == 0 )
            {
                posByte = ( long )archivo.tellg() - sizeof( Profesor );
                archivo.close();
                return posByte;
            }
        }
    }

    archivo.close();
    return -1;
}

void Profesor::setCodigo( const string &valorCodigo )
{
    int longitud = valorCodigo.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorCodigo.copy( codigo, longitud );
    codigo[ longitud ] = '\0';
}

void Profesor::setNombre( const string &valorNombre )
{
    int longitud = valorNombre.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorNombre.copy( nombre, longitud );
    nombre[ longitud ] = '\0';
}

void Profesor::setTes( const string &valorTes )
{
    int longitud = valorTes.size();
    longitud = ( longitud < 35 ? longitud : 34 );
    valorTes.copy( tesis_cons, longitud );
    tesis_cons[ longitud ] = '\0';
}

void Profesor::setFecha( const string &valorFecha )
{
    int longitud = valorFecha.size();
    longitud = ( longitud < 12 ? longitud : 11 );
    valorFecha.copy( fecha, longitud );
    fecha[ longitud ] = '\0';
}

ostream &operator<<( ostream &salida, const Profesor &pr )
{
    salida << "codigo:        " << pr.codigo << endl
            << "nombre:  " << pr.nombre << endl
            << "tesis_cons: " << pr.tesis_cons << endl
            << "fecha:    " << pr.fecha << endl;

    return salida;
}

bool Profesor::agregar( const Profesor &nuevaPromocion )
{
    Profesor pr;
    string cadena;
    int posIndice, contador;
    long int posByte;
    string idString = nuevaPromocion.codigo;

    if( contiene( idString ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    posIndice = dispersion( nuevaPromocion.codigo );
    cout << "Se guardara en la posicion indice: " << posIndice << endl;
    posByte = posIndice * ( sizeof( Profesor ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) ); // lee el numero de registros en el contador
    if( contador < CONTENEDOR ) // si el contenedor no esta lleno
    {
        // aumenta el contador y lo escribe
        contador++;
        archivo.seekg( posByte, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // escribe el nuevo registro en el contenedor
        for( int i = 0; i < CONTENEDOR; i++ )
        {
            archivo.read( ( char * ) &pr, sizeof( Profesor ) );
            if( pr.codigo[ 0 ] == '\0' )
            {
                archivo.seekg( ( long )archivo.tellg() - sizeof( Profesor ), ios::beg );
                archivo.write( ( char * ) &nuevaPromocion, sizeof( Profesor ) );
                archivo.close();
                return true;
            }
        }

    }
    else
        cout << endl << "No hay mas espacio para este registro" << endl;
    archivo.close();
    return false;
}

void Profesor::mostrar( void )
{
    Profesor pr;
    int contador;
    long int posByte;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
        cout << "No existe el archivo" << endl;
    else
    {
        cout << endl;
        for( int i = 0; i < NUMREGISTROS; i++ )
        {
            archivo.read( ( char * ) &contador, sizeof( int ) );
            if( contador > 0 )
            {
                for( int j = 0; j < CONTENEDOR; j++ )
                {
                    archivo.read( ( char * ) &pr, sizeof( Profesor ) );
                    if( pr.codigo[ 0 ] != '\0' )
                        cout << pr << endl;
                }
            }
            else
                archivo.seekg( sizeof( Profesor ) * CONTENEDOR, ios::cur );
        }
    }
    archivo.close();
}

bool Profesor::buscar( const string &idABuscar, Profesor &promocionEncontrada )
{
    long int posByte;

    if( !contiene( idABuscar ) )
        return false;

    ifstream archivo( "dispersion2.txt", ios::in );
    if( !archivo )
    {
        cout << "El archivo no existe" << endl;
        archivo.close();
        return false;
    }
    
    posByte = buscarId( idABuscar );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &promocionEncontrada, sizeof( Profesor ) );
    archivo.close();
    return true;
}

bool Profesor::modificar( const string &idAModificar, const Profesor &promocionNueva )
{
    Profesor registroLimpio, pr;
    int posIndiceAntiguo, posIndiceNuevo, contador;
    long int posByteAntiguo, posByteNuevo;

    if( !contiene( idAModificar ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    }

    posIndiceAntiguo = dispersion( idAModificar.c_str() );
    posByteAntiguo = buscarId( idAModificar );
    posIndiceNuevo = dispersion( promocionNueva.codigo );
    posByteNuevo = posIndiceNuevo * ( sizeof( Profesor ) * CONTENEDOR + sizeof( int ) );

    if( posByteAntiguo == posByteNuevo )
    {
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &promocionNueva, sizeof(  Profesor) );
    }
    else
    {
        // quita el registro antiguo y resta uno al contador del contenedor
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &registroLimpio, sizeof( Profesor ) );
        posByteAntiguo = posIndiceAntiguo * ( sizeof( Profesor ) * CONTENEDOR + sizeof( int ) );
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        contador--; 
        archivo.seekg( posByteAntiguo, ios::beg );
        archivo.write( ( char * ) &contador, sizeof( int ) );

        // intenta meter el nuevo registro en la nueva posicion
        archivo.seekg( posByteNuevo, ios::beg );
        archivo.read( ( char * ) &contador, sizeof( int ) );
        if( contador < CONTENEDOR )
        {
            // aumenta el contador y lo escribe
            contador++;
            archivo.seekg( posByteNuevo, ios::beg );
            archivo.write( ( char * ) &contador, sizeof( int ) );

            // escribe el nuevo registro en el contenedor
            for( int i = 0; i < CONTENEDOR; i++ )
            {
                archivo.read( ( char * ) &pr, sizeof( Profesor ) );
                if( pr.codigo[ 0 ] == '\0' ) // si el lugar no esta ocupado
                {
                    archivo.seekg( ( long )archivo.tellg() - sizeof( Profesor ), ios::beg );
                    archivo.write( ( char * ) &promocionNueva, sizeof( Profesor ) );
                    archivo.close();
                    return true;
                }
            }
        }
        else // el contenedor esta lleno
            return false;
    }
} // fin funcion modificar

bool Profesor::eliminar( const string &idAEliminar, Profesor &destinoEliminado )
{
    Profesor pr;
    int posIndice, posByte, contador;

    if( !contiene( idAEliminar ) )
        return false;

    fstream archivo( "dispersion2.txt", ios::in | ios::out );
    if( !archivo )
    {
        cout << "El archivo no exite" << endl;
        archivo.close();
        return false;
    } 

    posIndice = dispersion( idAEliminar.c_str() );
    posByte = buscarId( idAEliminar );

    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &destinoEliminado, sizeof(  Profesor) );
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &pr, sizeof(  Profesor) );

    posByte = posIndice * ( sizeof( Profesor ) * CONTENEDOR + sizeof( int ) );
    archivo.seekg( posByte, ios::beg );
    archivo.read( ( char * ) &contador, sizeof( int ) );
    contador--;
    archivo.seekg( posByte, ios::beg );
    archivo.write( ( char * ) &contador, sizeof( int ) );
    archivo.close();
    return true;
}



#endif 
