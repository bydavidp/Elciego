#include "../include/LenteIntercambiable.h"
/// constructor con sus respectivas variable y despues estan los heredados del padre
LenteIntercambiable::LenteIntercambiable(string id, bool disponible, string tipoLente,
                                         string focalMin, string focalMax, string aperturaMax)
    : EquipoFotografico(id, disponible) {
    this->tipoLente = tipoLente;
    this->focalMin = focalMin;
    this->focalMax = focalMax;
    this->aperturaMax = aperturaMax;
}
/// aqui estan los getters de la informaci�n de este caso lente
string LenteIntercambiable::getTipoLente(){ return tipoLente; }
string LenteIntercambiable::getFocalMin(){ return focalMin; }
string LenteIntercambiable::getFocalMax(){ return focalMax; }
string LenteIntercambiable::getApertura() { return aperturaMax; }

void LenteIntercambiable::mostrarInfo() {
    cout << "--- Lente Intercambiable ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Tipo: " << tipoLente  << endl;
    cout << "Focal min: " << focalMin << endl;
    cout << "Focal max: " << focalMax << endl;
    cout << "Apertura max: "<< aperturaMax << endl;
    cout << "Disponible: " << (disponible ? "Si" : "No") << endl;
}

string LenteIntercambiable::Archivo() { /// aqui se puede ver que la clase camara usa el metodo archivo
    /// y usa los ";" que separan la informacion para identificar cuando empieza y cuando
    /// termina un dato y con el + se concatena
    return id + ";" + tipoLente + ";" + focalMin + ";" + focalMax + ";" +
           aperturaMax + ";" + (disponible ? "Si" : "No") + ";Lente";
}
