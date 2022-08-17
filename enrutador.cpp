#include "enrutador.h"

Enrutador::Enrutador()
{

}

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
