#include "modelado.h"
#include <iostream>

using namespace std;

modelado::modelado()
{

}

void modelado::IngresoManualRouters()
{

    cout<<"para agregar un enrutador a la red debe ingresar las conexiones con los demas routers "<<endl;
    cout<<"la siguiente manera: "<<endl;
    cout<<"<enturador+enrutador al que esta conectado>,< , >,<valor que tendra la conexion>"<<endl;
    cout<<"Ejemplo: AB,7"<<endl;
    cout<<"para dejar de ingresar conexiones entre routers ingrese la letra 'n' "<<endl;


    while (true){
        int longitud=NomConexRuter.size();
        for(int i=0;i<longitud;i++){
            cout<<" [ "<<NomConexRuter[i]<<" ] ";
        }
        string linea,conexionRuter,ValorConex;


        cout<<"==> ";
        cin>>linea;

        if (linea == "n"){
            break;
        }
        else{
            int separador=0,longitud=linea.size();
            for (int i =0;i < longitud;i++){
                if (linea[i]==','){
                    separador++;
                }
                else if(separador==0){

                    conexionRuter+=linea[i];

                }
                else if(separador==1){
                    ValorConex+=linea[i];
                }
            }
            int cont=0;
            int longitudVector=NomConexRuter.size();
            for(int i =0;i<longitudVector;i++){
                if (NomConexRuter[i] == conexionRuter){
                    cont++;
                }

            }
            if(cont==0){
                NomConexRuter.push_back(conexionRuter);
                valConexRuter.push_back(stoi(ValorConex));
            }
            else{
                cout<<"Ingreso no valido, las conexiones estan repetidas"<<endl;
            }

        }
    }
}

void modelado::borrarConexiones()
{
    int longitud=NomConexRuter.size();
    string datoPop;

    cout<<"para eliminar alguna conexion entre routers ingrese de la siguente manera: "<<endl;
    cout<<"<enturador+enrutador al que esta conectado>"<<endl;
    cout<<" ejemplo: AB "<<endl;
    cout<<"para dejar de borrar conexiones entre routers ingrese la letra 'n' "<<endl;

    while(true){
        for(int i=0;i<longitud;i++){
            cout<<" [ "<<NomConexRuter[i]<<" ] ";
        }
        cout<<" ==> ";
        cin>>datoPop;

        if (datoPop == "n"){
            break;
        }
        else{
            int posicion=-1;
            for (auto it = NomConexRuter.begin(); it != NomConexRuter.end(); ) {
                posicion++;
                if (*it == datoPop ) {
                    it = NomConexRuter.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
            int cont=-1;
            for (auto it = valConexRuter.begin(); it != valConexRuter.end(); ) {
                cont++;
                if (cont == posicion ) {
                    it = valConexRuter.erase(it);
                    break;
                } else {
                    ++it;
                }
            }
        }
    }
}

void modelado::borrarRouter()
{
    char datoPop;

    cout<<"para eliminar alguna conexion entre routers ingrese de la siguente manera: "<<endl;
    cout<<"<Nombre del Enrutador>"<<endl;
    cout<<" ejemplo: A "<<endl;
    cout<<"para dejar de borrar conexiones entre routers ingrese la letra 'n' "<<endl;

    while(true){
        int longitud=NomConexRuter.size();
        for(int i=0;i<longitud;i++){
            cout<<" [ "<<NomConexRuter[i]<<" ] ";
        }
        cout<<endl;
        cout<<" ==> ";
        cin>>datoPop;

        if (datoPop == 'n'){
            break;
        }
        else{
            int iter=0;

            while(iter<longitud){
            int posicion=-1;
            for (auto it = NomConexRuter.begin(); it != NomConexRuter.end(); ) {
                posicion++;
                if ((*it)[0] == datoPop or (*it)[1] == datoPop ) {
                    it = NomConexRuter.erase(it);
                    int cont=-1;
                    for (auto il = valConexRuter.begin(); il != valConexRuter.end(); ) {
                        cont++;
                        if (cont == posicion ) {
                            il = valConexRuter.erase(il);
                            break;}
                        else {
                            ++il;}
                    }
                    break;}
                 else {
                    ++it;}
            }
            iter++;}
    }
    }
}

void modelado::cambioValorConex()
{
    string conexion;
    int valorCam=0;
    int longitud=NomConexRuter.size();

    cout<<"para cambiar el valor de alguna conexion ingrese: "<<endl;
    cout<<"<enturador+enrutador al que esta conectado>"<<endl;
    cout<<"ejemplo AB: "<<endl;
    cout<<"==> ";cin>>conexion;
    cout<<"Valor entre la conexion: ";cin>>valorCam;


    for(int i=0;i<longitud;i++){
        if(NomConexRuter[i]==conexion){
            valConexRuter[i]=valorCam;
        }
    }
}

void modelado::mostrarCamino(char inicio, string destino)
{
    for(map <char,vector<string>>::iterator DefinicionR =routers.begin();DefinicionR != routers.end();++DefinicionR){
        int longitud=DefinicionR->second.size();
        for(int i=0;i< longitud;i++){
            if(DefinicionR->first == inicio and destino == DefinicionR->second[i] ){
                cout<<"El mejor camino desde "<<inicio<<" hasta "<<destino<<" es "<< DefinicionR->second[i+2]<<" y su valor es de "<< DefinicionR->second[i+1]<<endl;
            }
        }
    }
}

vector<int> modelado::getValConexRuter() const
{
    return valConexRuter;
}

void modelado::setValConexRuter(const vector<int> &value)
{
    valConexRuter = value;
}

vector<string> modelado::getNomConexRuter() const
{
    return NomConexRuter;
}

void modelado::setNomConexRuter(const vector<string> &value)
{
    NomConexRuter = value;
}

map<char, vector<string> > modelado::getRouters() const
{
    return routers;
}

void modelado::setRouters(const map<char, vector<string> > &value)
{
    routers = value;
}
