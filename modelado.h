#ifndef MODELADO_H
#define MODELADO_H
#include <vector>
#include <map>
#include <fstream>


using namespace std;

class modelado
{
private:
    vector <int> valConexRuter;

    vector <string> NomConexRuter;

    map <char,vector<string>> routers;
public:
    modelado();

    void IngresoManualRouters();

    void borrarConexiones();

    void borrarRouter();

    void cambioValorConex();

    void mostrarCamino(char inicio,string destino);

    vector<int> getValConexRuter() const;
    void setValConexRuter(const vector<int> &value);

    vector<string> getNomConexRuter() const;
    void setNomConexRuter(const vector<string> &value);

    map<char, vector<string> > getRouters() const;
    void setRouters(const map<char, vector<string> > &value);



};
#endif // MODELADO_H
