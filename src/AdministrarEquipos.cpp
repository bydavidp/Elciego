//
// Created by dpala on 10/06/2026.
//

#include "../include/AdministrarEquipos.h"
#include "../include/AdministrarEquipos.h"

AdministrarEquipos::AdministrarEquipos() {} ///vector se inicializa vacio

/// recorre los dos vectores y libera cada objeto con un new
///se evita una fuga de memoria
AdministrarEquipos::~AdministrarEquipos() {
    for (int i = 0; i < (int)equipos.size(); i++)    delete equipos[i];
    for (int i = 0; i < (int)fotografos.size(); i++) delete fotografos[i];
}

///lee el inventario linea por linea y se crea el objeto
void AdministrarEquipos::cargarInventario() {
    ifstream archivo("../inventarioelciego.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir inventarioelciego.txt" << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        /// Quitar "\r" de finales de línea Windows sino no matchea
        if (!linea.empty() && linea.back() == '\r') linea.pop_back();
        if (linea.empty()) continue;

        ///leer todo los campos separados por ; ya que el ultimo ; es el tipo
        int posUltimo = linea.rfind(';');
        if (posUltimo == (int)string::npos) continue;///esta condicion quiere decir que si no hay
        string tipo = linea.substr(posUltimo + 1);  /// ";" pase la siguiente pos

        // Ahora parseamos campo a campo con getline + stringstream
        // Usamos istringstream para no depender de stringstream externo
        string f1, f2, f3, f4, f5, f6, f7;

        ///la funcion que se va a usar ahora para leer el siguiente campo
        /// separado por un ; pos avanza a lo largo en cada llamada
        int pos = 0;
        auto nextField = [&](string& campo) {///el [&] permite usar variables externas y modificarlas
            int sep = linea.find(';', pos);
            if (sep == (int)string::npos) { ///esto quiere decir que la busqueda fallo y no se encontro el caracter
                campo = linea.substr(pos);
                pos = linea.size();
            } else {
                campo = linea.substr(pos, sep - pos);
                pos = sep + 1;
            }
        };

        if (tipo == "Camara DSLR") {
            nextField(f1); // id
            nextField(f2); // marca
            nextField(f3); // modelo
            nextField(f4); // resolucionMP
            nextField(f5); // 4K
            nextField(f6); // disponible
            /// f7 sería el tipo, ya lo tenemos

            bool grabacion4K = (f5 == "Si");
            bool disp        = (f6 == "Si");
            equipos.push_back(new CamaraDSLR(f1, disp, f2, f3, f4, grabacion4K));

        } else if (tipo == "Lente") {
            nextField(f1); // id
            nextField(f2); // tipoLente
            nextField(f3); // focalMin
            nextField(f4); // focalMax
            nextField(f5); // apertura
            nextField(f6); // disponible

            bool disp = (f6 == "Si");
            equipos.push_back(new LenteIntercambiable(f1, disp, f2, f3, f4, f5));

        } else if (tipo == "Equipo de Iluminacion") {
            nextField(f1); // id
            nextField(f2); // tipoIluminacion
            nextField(f3); // potencia
            nextField(f4); // tempColor
            nextField(f5); // peso
            nextField(f6); // disponible

            bool disp = (f6 == "Si");
            equipos.push_back(new EquipoIluminacion(f1, disp, f2, f3, f4, f5));
        }
    }
    archivo.close();
    cout << "Inventario cargado: " << equipos.size() << " equipos." << endl;
}

/// lee fotografos.txt para reconstruir el fotografo que tiene que equipos
void AdministrarEquipos::cargarPrestamos() {
    ifstream archivo("../Fotografos.txt");
    if (!archivo.is_open()) {
        // Es normal que no exista al inicio
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty() && linea.back() == '\r') linea.pop_back();
        if (linea.empty()) continue;

        int pos = 0;
        string nombre;
        /// Primer campo nombre del fotógrafo
        int sep = linea.find(';', pos);///realmente al inicio no se encuentra nada debe agregarse el nombre ya que no hay ;
        if (sep == (int)string::npos) {
            nombre = linea;
            pos = linea.size();
        } else {
            nombre = linea.substr(pos, sep - pos);
            pos = sep + 1;
        }

        Fotografo* foto = new Fotografo(nombre);

        /// Campos restantes: IDs de equipos prestados
        while (pos < (int)linea.size()) {
            sep = linea.find(';', pos);
            string idEquipo;
            if (sep == (int)string::npos) {
                idEquipo = linea.substr(pos);
                pos = linea.size();
            } else {
                idEquipo = linea.substr(pos, sep - pos);
                pos = sep + 1;
            }
            if (!idEquipo.empty()) {
                foto->cargarEquipo(idEquipo);
                // Marcar el equipo como no disponible
                EquipoFotografico* eq = buscarEquipo(idEquipo);
                if (eq != nullptr) eq->setDisponible(false);
            }
        }
        fotografos.push_back(foto);
    }
    archivo.close();
}
///prestar
void AdministrarEquipos::prestarEquipo(string nombreFotografo, string idEquipo) {
    EquipoFotografico* equipo = buscarEquipo(idEquipo);
    if (equipo == nullptr) {
        cout << "Equipo " << idEquipo << " no encontrado." << endl;///verificar si el equipo existe y estaDisponible
        return;
    }
    if (!equipo->estaDisponible()) {
        cout << "El equipo " << idEquipo << " no esta disponible." << endl;
        return;
    }

    /// Buscar o crear el fotógrafo
    Fotografo* foto = buscarFotografo(nombreFotografo);
    if (foto == nullptr) {
        foto = new Fotografo(nombreFotografo);
        fotografos.push_back(foto);
    }

    if (foto->asignarEquipo(idEquipo)) { ///false si tiene tres equipos
        equipo->setDisponible(false);
        registrarOperacion("Prestamo", nombreFotografo, idEquipo);
        guardarPrestamos();
        guardarInventario();
        cout << "Equipo " << idEquipo << " prestado a " << nombreFotografo << "." << endl;
    }
}

///devoluciones
void AdministrarEquipos::devolverEquipo(string nombreFotografo, string idEquipo) {
    Fotografo* foto = buscarFotografo(nombreFotografo);
    if (foto == nullptr) {
        cout << "Fotografo " << nombreFotografo << " no encontrado." << endl;
        return;
    }

    EquipoFotografico* equipo = buscarEquipo(idEquipo);
    if (equipo == nullptr) {
        cout << "Equipo " << idEquipo << " no encontrado." << endl;
        return;
    }

    if (foto->devolverEquipo(idEquipo)) {
        equipo->setDisponible(true);
        registrarOperacion("Devolucion", nombreFotografo, idEquipo);
        guardarPrestamos();
        guardarInventario();
        cout << "Equipo " << idEquipo << " devuelto por " << nombreFotografo << "." << endl;
    }
}

/// Búsquedas
EquipoFotografico* AdministrarEquipos::buscarEquipo(string id) {
    for (int i = 0; i < (int)equipos.size(); i++) {
        if (equipos[i]->getId() == id) return equipos[i];///revisa si tiene ese equipos[i] igual al nombre de busqueda
    }                                                      ///se muestra su nombre
    return nullptr;
}

Fotografo* AdministrarEquipos::buscarFotografo(string nombre) {
    for (int i = 0; i < (int)fotografos.size(); i++) {
        if (fotografos[i]->getNombre() == nombre) return fotografos[i];
    }
    return nullptr;
}

///Operaciones uso de ios::app para no borrar el historial
void AdministrarEquipos::registrarOperacion(string tipo, string nombre, string id) {
    ofstream archivo("registroOperaciones.txt", ios::app);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir registroOperaciones.txt" << endl;
        return;
    }
    archivo << tipo << " - " << nombre << " - " << id << endl;
    archivo.close();
}

void AdministrarEquipos::mostrarRegistro() {
    ifstream archivo("../registroOperaciones.txt");
    if (!archivo.is_open()) {
        cout << "No hay registro de operaciones todavia." << endl;
        return;
    }
    string linea;
    bool hayLineas = false;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            cout << linea << endl;
            hayLineas = true;
        }
    }
    if (!hayLineas) cout << "El registro esta vacio." << endl;
    archivo.close();
}


///Guardar prestamos activos y Sobreescribe Fotografos.txt con el estado actual
void AdministrarEquipos::guardarPrestamos() {
    ofstream archivo("../Fotografos.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo guardar Fotografos.txt" << endl;
        return;
    }
    for (int i = 0; i < (int)fotografos.size(); i++) {
        vector<string> ids = fotografos[i]->getEquiposAsignados();
        if (ids.empty()) continue; /// no guarda fotógrafos sin equipos
        archivo << fotografos[i]->getNombre();
        for (int j = 0; j < (int)ids.size(); j++) {
            archivo << ";" << ids[j];///solo guarda un fotografo que tenga un equipo
        }
        archivo << endl;
    }
    archivo.close();
}

///cada equipo genera su propia linea ejemplo camara llama a camaraDSLR
///sin que administrador de equipos lo sepa
void AdministrarEquipos::guardarInventario() {
    ofstream archivo("../inventarioelciego.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo guardar inventarioelciego.txt" << endl;
        return;
    }
    for (int i = 0; i < (int)equipos.size(); i++) {
        archivo << equipos[i]->Archivo() << endl; ///polimorfismo
    }
    archivo.close();
}