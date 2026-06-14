#include "../include/CamaraDSLR.h"

/// constructor con sus respectivas variable y despues estan los heredados del padre
CamaraDSLR::CamaraDSLR(string id, bool disponible, string marca, string modelo,
                       string resolucionMP, bool grabacion4K)
    : EquipoFotografico(id, disponible) {
    this->marca = marca;
    this->modelo = modelo;
    this->resolucionMP = resolucionMP;
    this->grabacion4K = grabacion4K;
}
/// aqui estan los getters de la informaci�n de este caso camara
string CamaraDSLR::getMarca() { return marca; }
string CamaraDSLR::getModelo() { return modelo; }
string CamaraDSLR::getResolucion(){ return resolucionMP; }
bool   CamaraDSLR::getGrabacion4K(){ return grabacion4K; }

void CamaraDSLR::mostrarInfo(){
    cout << "--- Camara DSLR ---" << endl;
    cout << "ID: " << id << endl;
    cout << "Marca: " << marca << endl;
    cout << "Modelo: "<< modelo  << endl;
    cout << "Resolucion: " << resolucionMP << endl;
    cout << "4K: " << (grabacion4K ? "Si" : "No") << endl;
    cout << "Disponible: " << (disponible  ? "Si" : "No") << endl;
}

string CamaraDSLR::Archivo() {  /// aqui se puede ver que la clase camara usa el metodo archivo
    /// y usa los ";" que separan la informacion para identificar cuando empieza y cuando
    /// termina un dato y con el + se concatena
    return id + ";" + marca + ";" + modelo + ";" + resolucionMP + ";" +
           (grabacion4K ? "Si" : "No") + ";" +
           (disponible  ? "Si" : "No") + ";Camara DSLR";
}
