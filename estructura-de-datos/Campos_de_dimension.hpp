#ifndef CAMPOS_DE_DIMENSION_H_
#define CAMPOS_DE_DIMENSION_H_

#include <stdlib.h>
#include "iostream"
#include "fstream"
#include "cstring"

using namespace std;

class Articulo{
	public:
		char ID[15],Titulo[15],Autores[15],paginas[15],DireccionPg[15],ISBN[15];
		
		 void Agregar();
	     void Mostrar();
	     void Modificar();
	     void Eliminar();
	     void Buscar();
	     void menu();
	
}pr;

int dim1, dim2, dim3,dim4,dim5,dim6, opc = 0;


void Articulo::Agregar()
{
    cout<<"Escribe ID ";
    cin.getline(ID, 15);
    cin.getline(ID, 15);
    cout<<"Escribe Titulo: ";
    cin.getline(Titulo,15);
    cout<<"Escribe Autores: ";
    cin.getline(Autores,15);
    cout<<"Escribe paginas: ";
    cin.getline(paginas,15);
    cout<<"Escribe DireccionPg: ";
    cin.getline(DireccionPg,15);
    cout<<"Escribe ISBN: ";
    cin.getline(ISBN,15);
    
    
    
    //*********************************************************
    ofstream Archivo("Articulos.txt",ios::app);
   
    dim1 = strlen(ID);
    dim2 = strlen(Titulo);
    dim3 = strlen(Autores);
    dim4 = strlen(paginas);
    dim5 = strlen(DireccionPg);
    dim6 = strlen(ISBN);
    
    //*************************************************************
   
    Archivo.write((char*)&dim1, sizeof(int));
    Archivo.write((char*)&ID, dim1);
    Archivo.write((char*)&dim2, sizeof(int));
    Archivo.write((char*)&Titulo, dim2);
    Archivo.write((char*)&dim3, sizeof(int));
    Archivo.write((char*)&Autores, dim3);
    Archivo.write((char*)&dim4, sizeof(int));
    Archivo.write((char*)&paginas, dim4);
    Archivo.write((char*)&dim5, sizeof(int));
    Archivo.write((char*)&DireccionPg, dim5);
    Archivo.write((char*)&dim6, sizeof(int));
    Archivo.write((char*)&ISBN, dim6);

    Archivo.close();

}
//***********************************************************************

void Articulo::Mostrar()
{
	system("cls");

    ifstream archivo("Articulos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
		while(!archivo.eof()){
			
			dim1 = strlen(ID);
            dim2 = strlen(Titulo);
            dim3 = strlen(Autores);
            dim4 = strlen(paginas);
            dim5 = strlen(DireccionPg);
            dim6 = strlen(ISBN);
			
			
			
			
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&ID, dim1);
			ID[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&Titulo, dim2);
			Titulo[dim2] = '\0';
			
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&Autores, dim3);
			Autores[dim3] = '\0';
			
			archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';
			
			if(archivo.eof())
                break;
			
            cout<<"\t\tArticulos\n";
            cout<<"ID: "<<ID<<endl;
            cout<<"Titulo: "<<Titulo<<endl;
            cout<<"Autores: "<<Autores<<endl;
            cout<<"paginas: "<<paginas<<endl;
            cout<<"DireccionPg: "<<DireccionPg<<endl;
            cout<<"ISBN: "<<ISBN<<endl;
		}
	}
    archivo.close();
}


//*************************************************************************************************

void Articulo::Buscar()
{
	
    char codigo2[15];
    int band = 0;
    system("cls");

    ifstream archivo("Articulos.txt");
	if(!archivo.good()){
		cout<<"\nEl archivo no existe...";
	}
	else{
        cout << "escribe el ID: ";
        cin.getline(codigo2, 15);
        cin.getline(codigo2, 15);
		while(!archivo.eof() && !band)
        {
			archivo.read((char*)&dim1, sizeof(int));// dim1 contiene el tama�o de la cadena que se quiere leer
			archivo.read((char*)&ID, dim1);
			ID[dim1] = '\0'; // asignar fin de cadena al arreglo usuario para que no imprima basura
			
			archivo.read((char*)&dim2, sizeof(int));
			archivo.read((char*)&Titulo, dim2);
			Titulo[dim2] = '\0';
			
			archivo.read((char*)&dim3, sizeof(int));
			archivo.read((char*)&Autores, dim3);
			Autores[dim3] = '\0';
			
			archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';
			
			
			///modificacion
			if( strcmpi(codigo2, ID) == 0)
            {
                cout<<"\t\tArticulos\n";
                cout<<"ID: "<<ID<<endl;
                cout<<"Titulo: "<<Titulo<<endl;
                cout<<"Autores: "<<Autores<<endl;
                cout<<"paginas: "<<paginas<<endl;
                cout<<"DireccionPg: "<<DireccionPg<<endl;
                cout<<"ISBN: "<<ISBN<<endl;
                band = 1;
            }
		}
		if (!band)
            cout << "NO SE ENCUENTRA EL PRODUCTO..." << endl;
	}
    archivo.close();
   
}






//**********************************************************************************************************

void Articulo::Modificar()
{
    int band = 0;
    char codigo2[10];
    system("cls");
    

	ifstream archivo("Articulos.txt");
	if(!archivo.good())
    {
				cout<<"\nEl archivo no existe...";
	}
	else
	{
	    
        cout << "ID: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&ID, dim1);
            ID[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&Titulo, dim2);
            Titulo[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&Autores, dim3);
            Autores[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';

            if(strcmp(codigo2,ID) == 0)
            {
                
                cout<<"\tEl registo a modificar es ..?";
                

                cout << "\nID: " <<ID << "\nTitulo:  " << Titulo << "\nAutores:  " << Autores <<endl;
                cout << "\npaginas:  " << paginas << "\nDireccionPg:  " << DireccionPg <<"\n"<< "\nISBN:  " << ISBN << endl;
                band = 0;

                cout<<"---------------------------------------------\n";
                cout<<"quieres modificar el registro?";
                cout<<"\n[1.SI][2.NO]\n ";
                cout<<"QUE OPCION ELIGES?:";
                cin>>opc;
            }//condicion
            }//ciclo

	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Articulos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&ID, dim1);
            ID[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&Titulo, dim2);
            Titulo[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&Autores, dim3);
            Autores[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';

            if(strcmp(codigo2, ID) == 0)
            {
                cout<<"\n---------------------------------------------\n";
                cout<<"Escribe ID: ";
                cin.getline(ID, 15);
                cin.getline(ID, 15);
                cout<<"Escribe Titulo: ";
                cin.getline(Titulo,15);
                cout<<"Escribe Autores: ";
                cin.getline(Autores,15);
                cout<<"Escribe paginas: ";
                cin.getline(paginas,15);
                cout<<"Escribe DireccionPg: ";
                cin.getline(DireccionPg,15);
                cout<<"Escribe ISBN: ";
                cin.getline(ISBN,15);
                cout<<"\n";

                dim1 = strlen(ID);
                dim2 = strlen(Titulo);
                dim3 = strlen(Autores);
                dim4 = strlen(paginas);
                dim5 = strlen(DireccionPg);
                dim6 = strlen(ISBN);
            }//condicion

            temporal.write((char*)&dim1, sizeof(int));
            temporal.write((char*)&ID, dim1);
            temporal.write((char*)&dim2, sizeof(int));
            temporal.write((char*)&Titulo, dim2);
            temporal.write((char*)&dim3, sizeof(int));
            temporal.write((char*)&Autores, dim3);
            temporal.write((char*)&dim4, sizeof(int));
            temporal.write((char*)&paginas, dim4);
            temporal.write((char*)&dim5, sizeof(int));
            temporal.write((char*)&DireccionPg, dim5);
            temporal.write((char*)&dim6, sizeof(int));
            temporal.write((char*)&ISBN, dim6);
            

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Articulos.txt");
	rename("temporal.txt", "Articulos.txt");
	}//condicional de la opcion

    }// else

}

void Articulo::Eliminar()
{

    int band = 0;
    char codigo2[10];
    system("cls");
  

	ifstream archivo("Articulos.txt");
	if(!archivo.good())
    {
			cout<<"\nNO HAY REGISTRO\n";
           
	}
	else
	{
	    cout << "\nESCRIBE EL CODIGO DE LA SERIE QUE QUIERES ELIMINAR:\n ";
        cout << "CODIGO: ";
        cin.getline(codigo2, 10);
        cin.getline(codigo2, 10);
		while(!archivo.eof() && !band)
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&ID, dim1);
            ID[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&Titulo, dim2);
            Titulo[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&Autores, dim3);
            Autores[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';

            if(strcmp(codigo2, ID) == 0)
            {

                cout<<"\n---------------------------------------------\n";
                cout<<"\tEl registro a eliminar es...?";
                cout<<"\n---------------------------------------------\n";

                cout << "\nID: " <<ID << "\nTitulo:  " << Titulo << "\nAutores:  " << Autores <<endl;
                cout << "\npaginas:  " << paginas << "\nDireccionPg:  " << DireccionPg <<"\n"<< "\nISBN:  " << ISBN << endl;
                band = 1;

                cout<<"---------------------------------------------\n";
                cout<<"quieres eliminar el registro?";
                cout<<"\n[1.SI][0.NO]\n ";
                cout<<"QUE OPCION ELIGES?:";
                cin>>opc;
               

            }//condicion

        }	//ciclo
	archivo.close();

	if(opc == 1)
    {
        ifstream archivo("Articulos.txt");
        ofstream temporal("temporal.txt", ios::app);
        while(!archivo.eof())
        {
            archivo.read((char*)&dim1, sizeof(int));
            archivo.read((char*)&ID, dim1);
            ID[dim1] = '\0';
            archivo.read((char*)&dim2, sizeof(int));
            archivo.read((char*)&Titulo, dim2);
            Titulo[dim2] = '\0';
            archivo.read((char*)&dim3, sizeof(int));
            archivo.read((char*)&Autores, dim3);
            Autores[dim3] = '\0';
            archivo.read((char*)&dim4, sizeof(int));
			archivo.read((char*)&paginas, dim4);
			paginas[dim4] = '\0';
			archivo.read((char*)&dim5, sizeof(int));
			archivo.read((char*)&DireccionPg, dim5);
			DireccionPg[dim5] = '\0';
			archivo.read((char*)&dim6, sizeof(int));
			archivo.read((char*)&ISBN, dim6);
			ISBN[dim6] = '\0';

            if(strcmp(codigo2, ID) != 0)
            {
                temporal.write((char*)&dim1, sizeof(int));
                temporal.write((char*)&ID, dim1);
                temporal.write((char*)&dim2, sizeof(int));
                temporal.write((char*)&Titulo, dim2);
                temporal.write((char*)&dim3, sizeof(int));
                temporal.write((char*)&Autores, dim3);
                temporal.write((char*)&dim4, sizeof(int));
                temporal.write((char*)&paginas, dim4);
                temporal.write((char*)&dim5, sizeof(int));
                temporal.write((char*)&DireccionPg, dim5);
                temporal.write((char*)&dim6, sizeof(int));
                temporal.write((char*)&ISBN, dim6);
            }//condicion

        }//ciclo while

	temporal.close();
	archivo.close();
	remove("Articulos.txt");
	rename("temporal.txt", "Articulos.txt");
	}//condicional de la opcion

    }//

}









#endif 
