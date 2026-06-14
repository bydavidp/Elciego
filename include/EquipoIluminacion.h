//
// Created by dpala on 10/06/2026.
//

#ifndef PROYECTO_MATEO_EQUIPOILUMINACION_H
#define PROYECTO_MATEO_EQUIPOILUMINACION_H




#ifndef EQUIPOILUMINACION_H
#define EQUIPOILUMINACION_H
#include "EquipoFotografico.h"

/// hereda equipo fotografico  y tendra los atributos segun el taller
/// mostrarInfo y archivo tendran sus campos especificos

class EquipoIluminacion : public EquipoFotografico {
public:
    /// el contructor tambien contiene id y disponible del padre
    EquipoIluminacion(string id, bool disponible, string tipoIluminacion,
                      string potenciaMax, string tempColor, string peso);

    string getTipoIlum();
    string getPotencia();
    string getTempColor();
    string getPeso();

    /// implementaci�n de los m�todos abstractos del padre
    void mostrarInfo() override;
    string Archivo() override;

private:
    /// sus atributos exclusivos equipo de iluminacion
    string tipoIluminacion;
    string potenciaMax;
    string tempColor;
    string peso;
};

#endif


#endif //PROYECTO_MATEO_EQUIPOILUMINACION_H
