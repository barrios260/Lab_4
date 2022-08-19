#include <iostream>
#include <fstream>
#include <map>
#include "enrutador.h"
#include "modelado.h"


/*
 *este algoritmo tiene ciertos parametros restrictivos
 *1. hay diferencia entre mayusculas y minusculas
 *2.a la hora de crear routers hacerlos de un solo caracter, es decir
 *si va a haber conexion entre un enrutador y otro que ambos enrutadores sean de un caracter
 *ejemplo: A B etc
*/

using namespace std;

int main()
{

    Enrutador ruter;
    modelado Manejored;

    unsigned int opcion=1;


    cout<<"Como desea obtener la red de enrutadores?"<<endl;
    cout<<"Introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
    cout<<"1.Archivo de texto"<<endl;
    cout<<"2.Ingreso manual"<<endl;
    cout<<"=> ";cin>>opcion;
    if(opcion ==1){
        ruter.LectuArchi();
        ruter.Actualizacion();
    }
    else if(opcion == 2){
        ruter.IngresoManualRouters();
        ruter.Actualizacion();
    }

    while(opcion!=0){

        cout<<"Introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
        cout<<"1. Ingresar nuevas conexiones o routers"<<endl;
        cout<<"2. Eliminar conexiones entre routers"<<endl;
        cout<<"3. Eliminar routers"<<endl;;
        cout<<"4. Cambio el valor de la conexion entre routers"<<endl;;
        cout<<"5. Mostrar el mejor camino entre un enrutador y otro"<<endl;
        cout<<"0. Salir;"<<endl;
        cout<<"=> ";cin>>opcion;

        switch(opcion){
            case 1:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.IngresoManualRouters();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 2:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.borrarConexiones();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 3:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.borrarRouter();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 4:
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());

                Manejored.cambioValorConex();
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

            case 5:
                char Inicio;
                string destino;
                Manejored.setNomConexRuter(ruter.getNomConexRuter());
                Manejored.setValConexRuter(ruter.getValConexRuter());
                Manejored.setRouters(ruter.getRouters());
                cout<<"ingrese el router de partida: ";
                cin>>Inicio;
                cout<<"ingrese el router de destino: ";
                cin>>destino;

                Manejored.mostrarCamino(Inicio, destino);
                ruter.setNomConexRuter(Manejored.getNomConexRuter());
                ruter.setValConexRuter(Manejored.getValConexRuter());
                ruter.setRouters(Manejored.getRouters());
                ruter.Actualizacion();

            break;

        }

    }

    return 0;
}

