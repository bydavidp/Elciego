#include "../include/Fotografo.h"

Fotografo::Fotografo(string nombre) {
    this->nombre = nombre;
    this->maxEquipos = 3;
}

string Fotografo::getNombre() {
    return nombre;
}

int Fotografo::getCantidadEquipos() {
    return equiposAsignados.size();
}

vector<string> Fotografo::getEquiposAsignados() { /// se guardan los ID en el vector
    return equiposAsignados;
}

bool Fotografo::asignarEquipo(string idEquipo) {
    if ((int)equiposAsignados.size() >= maxEquipos) {
        cout << "El fotografo " << nombre << " ya tiene el maximo de " << maxEquipos << " equipos." << endl;
        return false;
    }
    equiposAsignados.push_back(idEquipo);/// almacena en el vector los ID
    return true;
}

bool Fotografo::devolverEquipo(string idEquipo) {
    for (int i = 0; i < (int)equiposAsignados.size(); i++) {
        if (equiposAsignados[i] == idEquipo) {
            equiposAsignados.erase(equiposAsignados.begin() + i);/// aqui se busca con el iterador +i cual es
            return true;                                         /// el que necesito borrar
        }
    }
    cout << "El fotografo " << nombre << " no tiene el equipo " << idEquipo << endl;
    return false;
}

void Fotografo::cargarEquipo(string idEquipo) {
    /// Sin validacion se usa al reconstruir el estado desde archivo los ID que tenia
    equiposAsignados.push_back(idEquipo);
}

void Fotografo::mostrarEquipos() {
    cout << "Fotografo: " << nombre << endl;
    if (equiposAsignados.empty()) {
        cout << "  No tiene equipos asignados." << endl;
        return;
    }
    cout << "  Equipos (" << equiposAsignados.size() << "/" << maxEquipos << "):" << endl;
    for (int i = 0; i < (int)equiposAsignados.size(); i++) {
        cout << "  - " << equiposAsignados[i] << endl;///aqui se muestra cuales son la cantidad de equipos que tiene el fotografo
    }                                                  /// y cuales son esos equipos
}
