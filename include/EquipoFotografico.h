#ifndef EQUIPOFOTOGRAFICO_H
#define EQUIPOFOTOGRAFICO_H
#include <iostream>

using namespace std;

class EquipoFotografico { /// clase padre estan los atributos y metodos comunes en todos los equipos
public:             /// va a ser el molde para las clases hijas
    EquipoFotografico(string id, bool disponible);
    virtual ~EquipoFotografico() {} /// destructor virtual sirve cuando hay herencia y se usan punteros
    /// se libera bien la memoria con el delete
    string getId();
    bool estaDisponible(); ///dice si el equipo se puede prestar
    void setDisponible(bool valor);/// cambia su estado al prestar o devolver

    ///al ser virtuales puros las hijas tienen que implementar sus metodos con sus propios datos
    /// si no se implementan estos tambien sera abstracta

    virtual void mostrarInfo() = 0;///mostrara los datos del respectivo equipo
    virtual string Archivo() = 0; /// devuelve la linea que se guarda en el txt

protected:
    /// estan aca para que las clases hijas puedan acceder directamente
    string id;
    bool disponible;

private:

};

#endif
