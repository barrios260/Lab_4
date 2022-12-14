#include "enrutador.h"
//constructor
Enrutador::Enrutador()
{

}
//metodos
void Enrutador::lecturaCaminos(char router, string caminoRecorrido, char destino, char copi, char an, int ValorCami, int &B, string &caminoMayor)
{
    int longitud=NomConexRuter.size();

    for(int i=0;i<longitud;i++){
        if ( NomConexRuter[i][0] == copi){
            int cont=0;
            for (auto letra:caminoRecorrido){
                if(NomConexRuter[i][1]==letra){
                    cont++;
                }
            }
            if (cont>1){

            }

            else if (NomConexRuter[i][1]==router or an==NomConexRuter[i][1]){

            }
            else if(NomConexRuter[i][1]==destino){
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];

                if(ValorCami<B){
                    B=ValorCami;
                    caminoMayor=caminoRecorrido;

                    ValorCami-=valConexRuter[i];
                    caminoRecorrido.pop_back();
                    caminoRecorrido.pop_back();
                }


                //copi=router;
            }
            else{
                caminoRecorrido+=NomConexRuter[i];
                ValorCami+=valConexRuter[i];

                copi=NomConexRuter[i][1];
                an=NomConexRuter[i][0];
                lecturaCaminos(router,caminoRecorrido,destino,copi,an,ValorCami,B,caminoMayor);
                copi=NomConexRuter[i][0];

                ValorCami-=valConexRuter[i];
                caminoRecorrido.pop_back();
                caminoRecorrido.pop_back();
            }
        }
    }
}

void Enrutador::LectuArchi()
{
    string data;

    // Abre el archivo en modo lectura
    ifstream infile;
    infile.open("Enrutadores.txt");

    if (!infile.is_open())
    {
      cout << "Error abriendo el archivo" << endl;
      exit(1);
    }
    infile >> data;

    string linea;

    while(!infile.eof()){
        string conexionRuter,ValorConex;
        getline(infile,linea);
        if (linea ==""){
            linea=data;
        }
        int longitud =linea.length();
        int separador=0;
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

        NomConexRuter.push_back(conexionRuter);
        valConexRuter.push_back(stoi(ValorConex));
    }
    // Se cierra el archivo abierto
    infile.close();
}

void Enrutador::Actualizacion()
{
    for (auto router:NomConexRuter){
        routers[router[0]]={};
    }
    for (map <char,vector<string>>::iterator DefinicionR =routers.begin();DefinicionR != routers.end();++DefinicionR){
        for (map <char,vector<string>>::iterator parametros =routers.begin();parametros != routers.end();++parametros){

            char copi=DefinicionR->first, an=DefinicionR->first;
            int ValorCami=0;
            int B=100;
            string caminoRecorrido,claveInter,Valor;
            string caminoMayor;
            claveInter.push_back(parametros->first);

            lecturaCaminos(DefinicionR->first,caminoRecorrido,parametros->first,copi,an,ValorCami,B,caminoMayor);
            routers[DefinicionR->first].push_back(claveInter);
            if (B==100){
                B=0;
            }
            routers[DefinicionR->first].push_back(to_string(B));
            routers[DefinicionR->first].push_back(caminoMayor);


        }
    }

}

void Enrutador::IngresoManualRouters()
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
        cout<<"=>";
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

vector<int> Enrutador::getValConexRuter() const
{
    return valConexRuter;
}

void Enrutador::setValConexRuter(const vector<int> &value)
{
    valConexRuter = value;
}

vector<string> Enrutador::getNomConexRuter() const
{
    return NomConexRuter;
}

void Enrutador::setNomConexRuter(const vector<string> &value)
{
    NomConexRuter = value;
}

map<char, vector<string> > Enrutador::getRouters() const
{
    return routers;
}

void Enrutador::setRouters(const map<char, vector<string> > &value)
{
    routers = value;
}

