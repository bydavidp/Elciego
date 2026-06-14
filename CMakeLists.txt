cmake_minimum_required(VERSION 4.2)
project(Proyecto_Mateo)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_Mateo main.cpp
        src/AdministrarEquipos.cpp
        include/AdministrarEquipos.h
        src/CamaraDSLR.cpp
        include/CamaraDSLR.h
        src/EquipoFotografico.cpp
        include/EquipoFotografico.h
        src/Fotografo.cpp
        include/Fotografo.h
        src/LenteIntercambiable.cpp
        include/LenteIntercambiable.h
        src/EquipoIluminacion.cpp
        include/EquipoIluminacion.h)
