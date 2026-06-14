#ifndef PAQUETE_H
#define PAQUETE_H
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;


class Paquete
{
    public:
        Paquete();
        Paquete(string, string,string);
        ~Paquete();

        void imprimir(){
        cout<<"\n Id: "<<id<<" \n origen: "<<origen<<" \n destino: "<<destino<<" \n peso: "<<peso<<endl<<endl;
        }

        string format(){
            string datos;
            datos = id+" | " +origen+" | " +destino+"|" +peso+"|";
            return datos;
        }


       string getId(void) {return id;};
       void setId(string num){this->id = num;};
       
       string getOrigen(void){ return origen;};
       void setOrigen (string orig){origen = orig;};

       string getDestino(void){ return destino;};
       void setDestino (string des){destino = des;};
       
       string getPeso(void){ return peso;};
       void setPeso (string pe){peso = pe;};

       

    private:
    	string id;
        string origen;
        string destino;
        string peso;
};


Paquete::Paquete(string num, string orig,string des){
    id = num;
	origen = orig;
	destino=des;
    
}

Paquete::Paquete()
{
    id = "";
	origen = "";    
    destino = "";
    peso = ""; 
    
   
}

Paquete::~Paquete()
{
    
}


#endif 
