/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Fernando
 *
 * Created on 19 de septiembre de 2019, 13:07
 */

#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
#include <ctime>
#include "vectordinamico.h"
#include "Cliente.h"


using namespace std;

double calculardistaciamaslejana(vectordinamico<Cliente> v) {
    double distancia, maxDistancia = 0;
    for (int i = 0; i < v.tam() - 1; i++) {
        for (int j = i + 1; j < v.tam(); j++) {
            distancia = v[i].distancia(v[j]);

            if (distancia > maxDistancia)
                maxDistancia = distancia;
        }
    }
    return maxDistancia;
}

void leeClientes(string fileNameClientes, vectordinamico<Cliente> &v) {
    ifstream fe; //Flujo de entrada
    string linea; //Cada linea tiene un clienete
    int total = 0; //Contador de lineas o clientes

    //Variables auxiliares para almacenar los valores leidos
    string dni, nombre, pass, direccion, latitud, longitud;
    double dlat, dlon;



    //Asociamos el flujo al fichero 
    fe.open(fileNameClientes);

    if (fe.good()) {
        //Mientras no se haya llegado al final del fichero
        while (!fe.eof()) {
            getline(fe, linea); //Toma una linea del fichero
            stringstream ss; //Stream que trabaja sobre buffer interno         

            if (linea != "") {
                ++total;
            }

            if (total > 1) {
                //Inicializamos el contenido de ss
                ss << linea;

                //Leemos el NIF
                getline(ss, dni, ';'); //El caracter ; se lee y se elimina de ss

                //Leemos el pass
                getline(ss, pass, ';'); //El carater ; se lee y se elimina de ss

                //Leemos el nombre
                getline(ss, nombre, ';'); //El carater ; se lee y se elimina de ss

                //Leemos la direcciÃ³n
                getline(ss, direccion, ';'); //El carater ; se lee y se elimina de ss

                //Leemos la latitud y longitud
                getline(ss, latitud, ';'); //El carater ; se lee y se elimina de ss
                getline(ss, longitud, ';'); //El carater ; se lee y se elimina de ss

                dlat = stod(latitud);
                dlon = stod(longitud);

                //con todos los atributos leidos, se crea el cliente
                //                cout<<dni<<endl;
                Cliente client(dni, pass, nombre, direccion, dlat, dlon);
                v.insertar(client);
                if (total % 100 == 0) {
                    cout << "Leido cliente " << total << "\n  ";
                }
            }
        }

        cout << "Total de clientes en el fichero: " << total - 1 << endl;
        fe.close(); //Cerramos el flujo de entrada
    } else {
        cerr << "No se puede abrir el fichero" << endl;
    }
}

int main(int argc, char** argv) {
    vectordinamico<Cliente> vector;
    unsigned t0, t1;
    //Instanciar el vector con todos los objetos de tipo Cliente leídos desde el fichero en formato csv proporcionado
    cout << "Comienzo de lectura de un fichero " << endl;
    leeClientes("clientes_v2.csv", vector);
    // Crear otro vector a partir de éste con los nombres ordenados
    vectordinamico<Cliente> ordenado(vector);
    ordenado.ordenar();
    cout << "Vector ya ordenado" << endl;
    // mostramos los clientes ordenados por pantalla para poder verificar si estan o no ordenados correctamente    
    for (int i = 0; i < ordenado.tam(); i++) {
        cout << ordenado[i].GetNOMBRE() << endl;
    }
    //Eliminar de éste último los clientes que se llamen con un determinado nombre, por ejemplo “Francesco”. Realizar previamente la búsqueda de forma eficiente.
    int x, y;
    Cliente cliente1;
    cliente1.SetNombre("Francesco ");
    // Creamos un cliente para poder buscarlo dentro del vector ordenado con la busqueda binaria
    x = ordenado.tam();
    //Mostramos el tamaño del vector ordenado antes de eliminar nada
    cout << "Antes de eliminar: " << ordenado.tam() << endl;
    int auxiliar = 0;
    do {
        auxiliar = ordenado.busquedaBin(cliente1);
        if (auxiliar != -1)
            ordenado.eliminar(auxiliar);
    } while (auxiliar != -1);
    //Mostramos el tamaño del vector ordenado despues de eliminar 
    cout << "Despues de eliminar: " << ordenado.tam() << endl;
    y = ordenado.tam();
    //Aqui mostramos la diferencia de tamaño para verificar cuantos se han eliminado
    cout << "Eliminados: " << x - y << endl;

    ///////////////////////////////////////////////////////////////////////////////////////
    //Aqui calculamos la distancia mas grande en grados entre todos los clientes
    cout << "Calculando la mayor distancia..." << endl;
    //Reloj antes de empezar a calcular la distancia
    t0 = clock();
    double maxDistancia = calculardistaciamaslejana(vector);
    cout << "La distancia máxima es: " << maxDistancia << endl;
    //Reloj despues de terminar de calcular la distancia
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    //Aqui mostramos el tiempo que tarda en calcular la distancia para hacernos una idea de la eficiencia de dicha eedd
    cout << "Tiempo de cálculo: " << time << " segundos\n";

    return 0;
}