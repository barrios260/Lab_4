#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class Enrutador
{
private://atributos
    vector<int>valConexRuter;
    vector<string>NomConexRuter;
    map<char,vector<string>>routers;
public://metodos
    Enrutador();//constructor
    void lecturaCaminos(char router, string caminoRecorrido, char destino,char copi,char an,int ValorCami,int &B,string &caminoMayor);
    void LectuArchi();
    void Actualizacion();
    void IngresoManualRouters();
    vector<int> getValConexRuter() const;
    void setValConexRuter(const vector<int> &value);
    vector<string> getNomConexRuter()const;
    void setNomConexRuter(const vector<string> &value);
    map<char,vector<string>>getRouters()const;
    void setRouters(const map<char,vector<string>>&value);

};

#endif // ENRUTADOR_H
