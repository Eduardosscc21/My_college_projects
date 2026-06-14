#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Delimitadores.hpp"
#include "Campos_de_dimension.hpp"
#include "Acceso_directo.hpp"
#include "Indice_simple.hpp"
#include "Serializacion.hpp"
#include "Dispersion.hpp"


using namespace std;

class ProyectoFinal{
	private:
		Tesis Deli;
		Articulo cdd;
		Alumno ad;
		Popular po;
		Historial_de_usuario hdu;
		Profesor pr;
		
	public:
		ProyectoFinal();
		void delimitadores();
		void campodimension();	
		void accesodirecto();
		void indice_simple();
		void historial();
		void profe();
		void Pmenu();	
};
ProyectoFinal::ProyectoFinal()
{
	
}

void ProyectoFinal::delimitadores()
{
	int opc;
    do{
            system("cls");
        cout<<"\n 1.- AGREGAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6.- SALIR \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: Deli.Agregar();
                break;

            case 2: Deli.Mostrar();
			 
            
                break;


            case 3: Deli.Buscar();
                break;


            case 4: Deli.Eliminar(); 
                break;


            case 5: Deli.Modificar();
              break; 
                
        }

    }while(opc!=6);
    system("cls");
}
void ProyectoFinal::campodimension()
{
	int opc;
    do{
            system("cls");
        cout<<"\n 1.- AGREGAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6.- SALIR \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: cdd.Agregar();
                break;

            case 2: cdd.Mostrar();
			 
            
                break;


            case 3: cdd.Buscar();
                break;


            case 4: cdd.Eliminar(); 
                break;


            case 5: cdd.Modificar();
              break; 
                
        }

    }while(opc!=6);
    system("cls");
}

void ProyectoFinal::accesodirecto()
{
		int opc;
    do{
            system("cls");
        cout<<"\n 1.- AGREGAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6.- SALIR \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: ad.Agregar();
                break;

            case 2: ad.Mostrar();
			 
            
                break;


            case 3: ad.Buscar();
                break;


            case 4: ad.Eliminar(); 
                break;


            case 5: ad.Modificar();
              break; 
                
        }

    }while(opc!=6);
    system("cls");
}

void ProyectoFinal::indice_simple()
{
			int opc;
    do{
            system("cls");
        cout<<"\n 1.- AGREGAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6.- SALIR \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: ad.Agregar();
                break;

            case 2: ad.Mostrar();
			 
            
                break;


            case 3: ad.Buscar();
                break;


            case 4: ad.Eliminar(); 
                break;


            case 5: ad.Modificar();
              break; 
                
        }

    }while(opc!=6);
    system("cls");
}

void ProyectoFinal::historial()
{
	int opc;
    do{
            system("cls");
        cout<<"\n 1.- AGREGAR \n 2.- MOSTRAR \n 3.- BUSCAR \n 4.- ELIMINAR \n 5.- MODIFICAR \n 6.- SALIR \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1: ad.Agregar();
                break;

            case 2: ad.Mostrar();
			 
            
                break;


            case 3: ad.Buscar();
                break;


            case 4: ad.Eliminar(); 
                break;


            case 5: ad.Modificar();
              break; 
                
        }

    }while(opc!=6);
    system("cls");
}
void ProyectoFinal::profe()
{
	Profesor pr,prBuscar, prModificar, prEliminar, registroAgregar;
    string codigoABuscar, codigoAModificar, codigoAEliminar;
    char opcion, op;

    pr.genera();
    system( "cls" );
    
    do{
        cout<<"\n\n\t\tBienvenido al menu \n\n";
        cout<<"Seleccione una opcion" << endl
            << "1. Agregar"   << endl
            << "2. Mostrar"   << endl
            << "3. Buscar"    << endl
            << "4. Modificar" << endl
            << "5. Eliminar"  << endl
            << "6. Salir"     << endl
            << endl;
        cin >> opcion;
        switch( opcion )
        {
          case '1':
            registroAgregar = pr.pedirRegistro();
            if( pr.agregar( registroAgregar ) )
                cout << "registro agregado con exito" << endl;
            else
                cout << "No se agrego el registro" << endl;
            break;

          case '2':
            system( "cls" );
            pr.mostrar();
            break;

          case '3':
            cout << "Ingrese el codigo del profesor a buscar: ";
            fflush( stdin );
            getline( cin, codigoABuscar );
            if( pr.buscar( codigoABuscar, prBuscar ) )
                cout << endl << prBuscar << endl;
            else
                cout << "No existe el registro" << endl;
            break;

          case '4':
            cout << "Ingrese el codigo del profesor a modificar: ";
            fflush( stdin );
            getline( cin, codigoAModificar );
            if( pr.buscar( codigoAModificar, prBuscar ) )
            {
                cout << endl << prBuscar << endl;
                cout << "Desea modificarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                {
                    prModificar = pr.pedirRegistro();
                    if( pr.modificar( codigoAModificar, prModificar ) )
                        cout << endl << "Registro modificado con exito" << endl;
                    else
                        cout << endl << "No se pudo modificar" << endl;
                }
            }
            else
                cout << "No existe el registro" << endl;
            break;

          case '5':
            cout << "Ingrese el codigo del profesor a eliminar: ";
            fflush( stdin );
            getline( cin, codigoAEliminar );
            if( pr.buscar( codigoAEliminar, prBuscar ) )
            {
                cout << endl << prBuscar << endl;
                cout << "Desea eliminarlo?" << endl;
                cout << "1) Si" << endl;
                cout << "2) No" << endl;
                cin >> op;

                if( op == '1' )
                    if( pr.eliminar( codigoAEliminar, prEliminar ) )
                        cout << endl << prEliminar << endl << "SE ELIMINO CORRECTAMENTE" << endl;
                    else
                        cout << "NO SE PUDO ELIMINAR" << endl;
            }
            else
                cout << "No existe el registro" << endl;
            break;
        }
        cout << endl;
        system("Pause");
        system( "cls" );
    }while(opcion != '6');
}

int main()
{
	
	ProyectoFinal p;
	int opc;
    do{
        system("cls");
        cout<<"\n--------------------------------------------------------------------------------\n";    
        cout<<"\n\tUniversidad de Guadalajara\t"<<endl;  
        cout<<"\n\tCentro Universitario de Ciencias Exactas e Ingenierias\t"<<endl;  
        cout<<"\n\tDepartamento de Ciencias Computacionales\t"<<endl;  
        cout<<"\n\tTESIS Y ARTICULOS DE LA UDG\t"<<endl;  
        cout<<"\n\tProyecto\t"<<endl;  
        cout<<"\n--------------------------------------------------------------------------------\n"; 
        
        
        
		  
        cout<<"\n 1.- Tesis(delimitadores) \n 2.- Articulos(campos de dimension) \n 3.- Alumnos(acceso directo) \n 4.- Populares(indice simple) \n 5.- Historial(Serializacion)\n 6.- Profesor(Dispersion))\n 7.- Salir\n \n\n SELECCIONA LA OPCION: ";
        cin>>opc;
        switch(opc){
            case 1:p.delimitadores();
                break;
            case 2:p.campodimension();
			    break;   
			case 3:p.accesodirecto();
			    break;	 
			case 4:p.indice_simple();  
			     break;
			case 5:p.historial();
				 break;
			case 6:p.profe();
			     break;               
        }

    }while(opc!=7);
    system("cls");
}




