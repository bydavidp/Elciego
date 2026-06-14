#ifndef CAMARADSLR_H
#define CAMARADSLR_H
#include "EquipoFotografico.h"

/// hereda equipo fotografico  y tendra los atributos segun el taller
/// mostrarInfo y archivo tendran sus campos especificos


class CamaraDSLR : public EquipoFotografico {
public:
    /// el contructor tambien contiene id y disponible del padre
    CamaraDSLR(string id, bool disponible, string marca, string modelo,
               string resolucionMP, bool grabacion4K);

    string getMarca();
    string getModelo();
    string getResolucion();
    bool getGrabacion4K();

    /// implementaci�n de los m�todos abstractos del padre
    void mostrarInfo() override;
    string Archivo() override;

private:
    /// sus atributos exclusivos de camara
    string marca;
    string modelo;
    string resolucionMP;
    bool grabacion4K;
};

#endif
