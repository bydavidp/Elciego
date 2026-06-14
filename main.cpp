#include <iostream>
#include "include/AdministrarEquipos.h"
#include "include/Fotografo.h"
using namespace std;

int main() {
    AdministrarEquipos sistema;
    sistema.cargarInventario();
    sistema.cargarPrestamos();

    int opcion;
    do {
        cout << endl;
        cout << "- - - Equipo profesional de fotos El Ciego - - -" << endl;
        cout << "1 - Prestar equipo" << endl;
        cout << "2 - Devolver equipo"<< endl;
        cout << "3 - Buscar equipo"  << endl;
        cout << "4 - Buscar fotografo" << endl;
        cout << "5 - Ver registro" << endl;
        cout << "6 - Estadisticas" << endl;
        cout << "0 - Salir" << endl;
        cin  >> opcion;

        switch (opcion) {
            case 1: {
                string nombre, id;
                cout << "Nombre fotografo: "; cin >> nombre;
                cout << "ID equipo: "; cin >> id;
                sistema.prestarEquipo(nombre, id);
                break;
            }
            case 2: {
                string nombre, id;
                cout << "Nombre fotografo: "; cin >> nombre;
                cout << "ID equipo: "; cin >> id;
                sistema.devolverEquipo(nombre, id);
                break;
            }
            case 3: {
                string id;
                cout << "Ingrese ID del equipo: "; cin >> id;
                EquipoFotografico* eq = sistema.buscarEquipo(id);
                if (eq != nullptr) eq->mostrarInfo();
                else cout << "Equipo no encontrado." << endl;
                break;
            }
            case 4: {
                string nombre;
                cout << "Ingrese nombre del fotografo: "; cin >> nombre;
                Fotografo* foto = sistema.buscarFotografo(nombre);
                if (foto != nullptr) foto->mostrarEquipos();
                else cout << "Fotografo no encontrado." << endl;
                break;
            }
            case 5:
                cout << "Mostrando registro:" << endl;
                sistema.mostrarRegistro();
                cout << "Fin del registro." << endl;
                break;
            case 6:
                cout << "Mostrar Estadisticas" <<endl;
                break;
                cout << "Fin del estadistica." << endl;



            case 0:
                cout << "Saliendo." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 0);

    return 0;
}
