#ifndef ADMINISTRAREQUIPOS_H
#define ADMINISTRAREQUIPOS_H
#include <iostream>
#include <vector>
#include <fstream>
#include "EquipoFotografico.h"
#include "CamaraDSLR.h"
#include "LenteIntercambiable.h"
#include "EquipoIluminacion.h"
#include "Fotografo.h"
using namespace std;

/// es el que coordina todo el que maneja casi todas mis acciones
/// maneja fotografos(incluye sus prestamos) y inventario, registra todo en el historial
class AdministrarEquipos {
public:
    AdministrarEquipos();
    ~AdministrarEquipos();///libera memoria de todo objeto con new

    // Carga desde archivos al arrancar
    void cargarInventario();/// lee el inventarioelciego.txt crea los objetos
    void cargarPrestamos();/// lee fotografos.txt y revisa que tienen los fotografos

    /// Operaciones del menu
    void prestarEquipo(string nombreFotografo, string idEquipo);
    void devolverEquipo(string nombreFotografo, string idEquipo);

    // Búsquedas
    EquipoFotografico* buscarEquipo(string id);/// la dos devulven nullptr si no encuentran al ser puntero
    Fotografo* buscarFotografo(string nombre);

    // Registro de operaciones
    void mostrarRegistro();///lee y imprime Operaciones.txt

    /// Guardar estado al prestar o devolver
    void guardarInventario();///sobreescribe el inventarioelciego.txt
    void guardarPrestamos();///sobreescribe el fotografo.txt
    void Mostrarestadistica();

private:
    /// usa polimorfismo con los punteros de la clase PADRE aunque cada objeto
    /// siga siendo una camara o un lente
    vector<EquipoFotografico*> equipos;
    vector<Fotografo*> fotografos;

    ///abre el registro de operaciones en modo append
    void registrarOperacion(string tipo, string nombre, string id);
};

#endif
