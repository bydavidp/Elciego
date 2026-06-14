#ifndef LENTEINTERCAMBIABLE_H
#define LENTEINTERCAMBIABLE_H
#include "EquipoFotografico.h"

/// hereda equipo fotografico  y tendra los atributos segun el taller
/// mostrarInfo y archivo tendran sus campos especificos

class LenteIntercambiable : public EquipoFotografico {
public:
    /// el contructor tambien contiene id y disponible del padre
    LenteIntercambiable(string id, bool disponible, string tipoLente,
                        string focalMin, string focalMax, string aperturaMax);

    string getTipoLente();
    string getFocalMin();
    string getFocalMax();
    string getApertura();

    /// implementaci�n de los m�todos abstractos del padre
    void mostrarInfo() override;
    string Archivo() override;

private:
    /// sus atributos exclusivos de lente
    string tipoLente;
    string focalMin;
    string focalMax;
    string aperturaMax;
};

#endif
