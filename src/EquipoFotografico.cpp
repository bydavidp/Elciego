#include "../include/EquipoFotografico.h"

EquipoFotografico::EquipoFotografico(string id, bool disponible) {
    this->id = id;
    this->disponible = disponible;
}

string EquipoFotografico::getId() {
    return id;
}

bool EquipoFotografico::estaDisponible() {
    return disponible;
}

void EquipoFotografico::setDisponible(bool valor) {
    this->disponible = valor;
}
