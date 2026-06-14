#include "../include/EquipoIluminacion.h"
/// constructor con sus respectivas variable y despues estan los heredados del padre
EquipoIluminacion::EquipoIluminacion(string id, bool disponible, string tipoIluminacion,
                                     string potenciaMax, string tempColor, string peso)
    : EquipoFotografico(id, disponible) {
    this->tipoIluminacion = tipoIluminacion;
    this->potenciaMax = potenciaMax;
    this->tempColor= tempColor;
    this->peso  = peso;
}
/// aqui estan los getters de la informacion de este caso lente
string EquipoIluminacion::getTipoIlum(){ return tipoIluminacion; }
string EquipoIluminacion::getPotencia(){ return potenciaMax; }
string EquipoIluminacion::getTempColor() { return tempColor; }
string EquipoIluminacion::getPeso() { return peso; }

void EquipoIluminacion::mostrarInfo() {
    cout << "--- Equipo de Iluminacion ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Tipo iluminacion: " << tipoIluminacion << endl;
    cout << "Potencia max: " << potenciaMax  << endl;
    cout << "Temperatura color: " << tempColor << endl;
    cout << "Peso: "  << peso  << endl;
    cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
}

string EquipoIluminacion::Archivo() {   /// aqui se puede ver que la clase camara usa el metodo archivo
    /// y usa los ";" que separan la informacion para identificar cuando empieza y cuando
    /// termina un dato y con el + se concatena
    return id + ";" + tipoIluminacion + ";" + potenciaMax + ";" +
           tempColor + ";" + peso + ";" +
           (disponible ? "Si" : "No") + ";Equipo de Iluminacion";
}
