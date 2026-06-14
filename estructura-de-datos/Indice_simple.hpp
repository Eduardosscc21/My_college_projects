#ifndef INDICE_SIMPLE_H_
#define INDICE_SIMPLE_H_




#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;
int orden=0;

class Popular
{
    public:
    char codigo[20],rfc[14], titulo[35], autor[40],area[20],fecha[20];
    int NoDePaginas;


    void capturar();
    void buscar();
    void mostrar();
    void Modificar();
    void Eliminar();
    void Mostrar_Indice();
    void Orden();
}x;

///////PUNTERO/////
class Indice
{
    public:
    char codigo[14];
    long int pos;

}y;

////////CAPTURAR
void Popular::capturar()
{
    system ("cls");
    cout<<"\n-------------------------------------"<<endl;
    cout<<"\t_OPCION CAPTURAR_";
    cout<<"\n-------------------------------------"<<endl;

    fflush(stdin);
    cout<<"INGRESE EL CODIGO:"<<endl;
    cin.getline(codigo,14);
    cout<<"INGRESE RFC:"<<endl;
    cin.getline(rfc,35);
    cout<<"INGRESE EL TITULO: "<<endl;
    cin.getline(titulo,40);
    cout<<"INGRESE EL AUTOR:"<<endl;
    cin.getline(autor,20);
    cout<<"INGRESE EL AREA:"<<endl;
    cin.getline(area,20);
    fflush(stdin);
    cout<<"INGRESE FECHA:"<<endl;
    cin.getline(fecha,20);

    cout<<"INGRESE EL NUMERO DE PAGINAS:"<<endl;
    cin>>NoDePaginas;

    ofstream a("datos.txt",ios::app);
    a.write((char*)&x,sizeof(x));
    y.pos=a.tellp();
    y.pos-=sizeof(x);
    a.close();
    strcpy(y.codigo,codigo);
    ofstream b("indice.txt",ios::app);
    b.write((char*)&y,sizeof(y));
    b.close();
    orden++;
}

///////MOSTRAR
void Popular::mostrar()
{
    system ("cls");
    cout<<"\n-------------------------------------"<<endl;
    cout<<"\t_OPCION_MOSTRAR_";
    cout<<"\n-------------------------------------"<<endl;

    ifstream a("datos.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&x,sizeof(x));
            if(a.eof())
            {
            	break;
            }
                
            cout<<"CODIGO:"<<x.codigo<<endl;
            cout<<"RFC: "<<x.rfc<<endl;
            cout<<"TITULO: "<<x.titulo<<endl;
            cout<<"AUTOR:"<<x.autor<<endl;
            cout<<"AREA:"<<x.area<<endl;
            cout<<"FECHA:"<<fecha<<endl;
            cout<<" NUMERO DE PAGINAS:"<<NoDePaginas<<endl;          
        }
    }
    a.close();
}

////////MOSTRAR INDICE
void Popular::Mostrar_Indice()
{
  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
            {
            	break;
            }
                
            cout<<"CODIGO:"<<y.codigo<<endl<<endl;
            
        }
    }
    a.close();
}

///////BUSCAR
void Popular::buscar()
{
    system ("cls");
    cout<<"\n-------------------------------------"<<endl;
    cout<<"\t_OPCION_BUSCAR_";
    cout<<"\n-------------------------------------"<<endl;


    char codbus[14];
    int band=0;

    ifstream b("indice.txt");
    if(!b.good()){
    cout<<"No existe el archivo";}
    else{
    cout<<"\nCODIGO A BUSCAR:"<<endl;
    fflush(stdin);cin.getline(codbus,14);
    cout<<"\n-------------------------------------"<<endl;
    cout<<"///EL REGISTRO QUE BUSCASTE ES ESTE///"<<endl;
    cout<<"-------------------------------------"<<endl;

    while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.codigo,codbus)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&x,sizeof(x));
            
            cout<<"CODIGO:"<<x.codigo<<endl;
            cout<<"RFC: "<<x.rfc<<endl;
            cout<<"TITULO: "<<x.titulo<<endl;
            cout<<"AUTOR:"<<x.autor<<endl;
            cout<<"AREA:"<<x.area<<endl;
            cout<<"FECHA:"<<fecha<<endl;
            cout<<" NUMERO DE PAGINAS:"<<NoDePaginas<<endl;
            
            a.close();
            band=1;
            break;
        }
    }
    if(band==0)
    {
     cout<<"\n NO EXISTE REGISTRO....."   ;
    }
    }
    b.close();

}

//////MODIFICAR
void Popular::Modificar()
{
    system ("cls");
    cout<<"\n-------------------------------------"<<endl;
    cout<<"\t_OPCION_MODIFICAR_";
    cout<<"\n-------------------------------------"<<endl;

     char codmod[15];
     int band=0;
     int opc;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nCODIGO A MODIFICAR:"<<endl;
     fflush(stdin);cin.getline(codmod,14);
    cout<<"\n------------------------------------------------"<<endl;
    cout<<"///EL REGISTRO QUE QUIERES MODIFICAR ES ESTE?///"<<endl;
    cout<<"------------------------------------------------\n"<<endl;
     while(!b.eof())
    {   opc=0;
        b.read((char*)&y,sizeof(y));
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.codigo,codmod)==0 && band==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);

             a.read((char*)&x,sizeof(x));
             if(a.eof())  
			 {
			 	break;
			 } 
            cout<<"CODIGO:"<<x.codigo<<endl;
            cout<<"RFC: "<<x.rfc<<endl;
            cout<<"TITULO: "<<x.titulo<<endl;
            cout<<"AUTOR:"<<x.autor<<endl;
            cout<<"AREA:"<<x.area<<endl;
            cout<<"FECHA:"<<fecha<<endl;
            cout<<" NUMERO DE PAGINAS:"<<NoDePaginas<<endl;
            cout<<"\n-------------------------------------"<<endl;
            cout<<"\tQUIERES MODIFICARLO?"<<endl;
            cout<<"\t[1.SI] O [2.NO]";
            cout<<"\n-------------------------------------"<<endl;
            cout<<"OPCION:"; cin>>opc;
            band=1;
            a.close();
            break;
         }//if de comparacion
         }//while
         b.close();
         if(opc==1)
{
    fflush(stdin);
    ifstream indice("indice.txt");
    ifstream datos("datos.txt");
          while(!indice.eof())
         {
            cout<<"\n----------------------------------------"<<endl;
            cout<<"///ENTRO AL CICLO, CARGANDO OPCION...///"<<endl;
            cout<<"----------------------------------------"<<endl;
            cout<<"///PROCEDA A HACER LOS CAMBIOS///"<<endl;
            cout<<"----------------------------------------"<<endl;

          indice.read((char*)&y,sizeof(y));
          cout<<"\nCODIGO ACTUAL:"<<y.codigo<<"\n";
          datos.read((char*)&x,sizeof(x));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.codigo,codmod)==0)
        {
        cout<<"INGRESE EL CODIGO:"<<endl;
    cin.getline(codigo,14);
    cout<<"INGRESE RFC:"<<endl;
    cin.getline(rfc,35);
    cout<<"INGRESE EL TITULO: "<<endl;
    cin.getline(titulo,40);
    cout<<"INGRESE EL AUTOR:"<<endl;
    cin.getline(autor,20);
    cout<<"INGRESE LA AREA:"<<endl;
    cin.getline(area,20);
    fflush(stdin);
    cout<<"INGRESE FECHA:"<<endl;
    cin.getline(fecha,20);
    cout<<"INGRESE EL NUMERO DE PAGINAS:"<<endl;
    cin>>NoDePaginas;
     }

          ofstream c("temp.txt",ios::app);
          c.write((char*)&x,sizeof(x));

        strcpy(y.codigo,codigo);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();

        }//while archivo
}

    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}

    }//else
    remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");
}

//////////////ELIMINAR
void Popular::Eliminar()
{
    system ("cls");
    cout<<"\n-------------------------------------"<<endl;
    cout<<"\t_OPCION_ELIMINAR_";
    cout<<"\n-------------------------------------"<<endl;
     char codieli[15];
     int band=0;
     int opc,cont=0,cont2=0;
     ifstream b("indice.txt");
     if(!b.good()){
     cout<<"No existe el archivo";}
     else{
     cout<<"\nCODIGO A ELIMINAR:"<<endl;
     fflush(stdin);cin.getline(codieli,14);
     while(!b.eof())
    {
        b.read((char*)&y,sizeof(y));
        cont++;
            cout<<"\n------------------------------------------------"<<endl;
            cout<<"////[CONTADOR]////"<<cont;
            cout<<"\n------------------------------------------------"<<endl;
            cout<<"///EL REGISTRO QUE QUIERES ELIMINAR ES ESTE?///"<<endl;
            cout<<"------------------------------------------------\n"<<endl;
        if(b.eof())
        {
            break;
        }
        if(strcmp(y.codigo,codieli)==0)
        {
            ifstream a("datos.txt");
            a.seekg(y.pos,ios::beg);
            a.read((char*)&x,sizeof(x));
             if(a.eof())  
			 {
			 	break;
			 }
			  

            cout<<"CODIGO:"<<x.codigo<<endl;
            cout<<"RFC: "<<x.rfc<<endl;
            cout<<"TITULO: "<<x.titulo<<endl;
            cout<<"AUTOR:"<<x.autor<<endl;
            cout<<"AREA:"<<x.area<<endl;
            cout<<"FECHA:"<<fecha<<endl;
            cout<<" NUMERO DE PAGINAS:"<<NoDePaginas<<endl;
            cout<<"\n-------------------------------------"<<endl;
            cout<<"\tQUIERES ELIMINARLO?"<<endl;
            cout<<"\t[1.SI] O [2.NO]";
            cout<<"\n-------------------------------------"<<endl;
            cout<<"OPCION:"; cin>>opc;
            band=1;
           a.close();
             break;
         }//if de comparacion

         }//while
        b.close();
        cout<<"\n------------------";
        cout<<"\n////[SALIENDO]////";
        cout<<"\n------------------";
         if(opc==1)
         {cout<<"\n////[ELIMINADO]////"<<endl;
          cout<<"///////////////////"<<endl;
          ifstream indice("indice.txt");
          ifstream datos("datos.txt");
          while(!indice.eof())
         {
          indice.read((char*)&y,sizeof(y));
          cout<<"\nCODIGO:"<<y.codigo<<"\n";
          datos.read((char*)&x,sizeof(x));
           if(indice.eof())
        {
            break;
        }
        if(strcmp(y.codigo,codieli))
        {cont2++; cout<<"contador de if es "<<cont2;


          cout<<"EL NOMBRE ES: "<<x.titulo;
          ofstream c("temp.txt",ios::app);
          c.write((char*)&x,sizeof(x));

        strcpy(y.codigo,codigo);
        ofstream d("tempind.txt",ios::app);
        d.write((char*)&y,sizeof(y));
        d.close();
        c.close();
        }
        }//while archivo
       indice.close();
       datos.close();
       remove("indice.txt"); rename("tempind.txt","indice.txt");
    remove("datos.txt");  rename("temp.txt","datos.txt");
        }//if
        else
        {}
    if(band==0)
    {cout<<"\n NO EXISTE REGISTRO....."   ;}
    }//else
}


/////ORDENAR
void Popular::Orden()
{int i=0;
char indice[20][14];
char aux[20];

  ifstream a("indice.txt");
    if(!a.good())
    cout<<"No existe el archivo";
    else
    {cout<<"else";
        while(!a.eof())
        {
            a.read((char*)&y,sizeof(y));
            if(a.eof())
            {
            	break;
            }
                

                char *cadena=y.codigo;
                strcpy(indice[i],cadena);
                i++;
        }
		
		for(int i=0;i<orden-1;i++)
for(int j=i+1;j<orden;j++)
if(strcmp(indice[i],indice[j])>0)
{
strcpy(aux,indice[j]);
strcpy(indice[j],indice[i]);
strcpy(indice[i],aux);
system("cls");}
for(int i=0;i<orden;i++)
{

strcpy(y.codigo,indice[i]);
ofstream a("tempind.txt",ios::app);
a.write((char*)&y,sizeof(y));
a.close();
}

		
		}
    //a.close();

    
 remove("indice.txt");
 rename("tempind.txt","indice.txt");

}




#endif 
