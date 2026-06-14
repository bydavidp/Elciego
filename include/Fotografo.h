#ifndef FOTOGRAFO_H
#define FOTOGRAFO_H
#include <iostream>
#include <vector>
using namespace std;

/// es una persona que toma prestados los equipos de estudio no va a heredar a nadie
/// es una clase independiente

class Fotografo{ /// en el dise�o se hizo que no guarde objetos si no ID como CAM1A
/// el fotografo solo tendra una lista de referencias
public:
    Fotografo(string nombre);

    string getNombre();
    int getCantidadEquipos();
    vector<string> getEquiposAsignados();

    bool asignarEquipo(string idEquipo); /// sirve para agregar equipo pero retirna false si ya hay 3
    bool devolverEquipo(string idEquipo); /// quitar el equipo de la lista si no hay nada retorna false
    void cargarEquipo(string idEquipo); /// va a agregar un equipo sin validar su limite desde el archivo(Fotografos.txt)

    void mostrarEquipos();

private:
    string nombre;
    vector<string> equiposAsignados;///importante solo ID
    int maxEquipos;/// maximo 3 equipos
};

#endif
