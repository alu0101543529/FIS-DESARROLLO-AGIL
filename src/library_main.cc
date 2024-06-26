/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file usuario.h
  * @date 23/04/2024
  * @brief Este fichero contiene el programa principal.
  * @compilation: make
  */

#include <iostream>

#include "tools.h"
#include "database_usuarios.h"
#include "database_reservas.h"

int main() {
  std::ofstream salida_usuario("bbdd_usuarios.info", std::ios::app);
  std::ifstream entrada_usuario("bbdd_usuarios.info");
  std::ofstream salida_reserva("bbdd_reservas.info", std::ios::app);
  std::ifstream entrada_reserva("bbdd_reservas.info");
  // std::ofstream salida_libros("catalogo.info", std::ios::app);
  // std::ifstream entrada_libros("catalogo.info");
  DatabaseUsuarios datos_usuarios(entrada_usuario, salida_usuario);
  DatabaseReservas datos_reservas(entrada_reserva, salida_reserva);
  // DatabaseLibros catalogo(entrada_libros);
  bool sesion_iniciada = false;
  std::string tipo_usuario{""};
  GestionarInicioSesion(datos_usuarios, tipo_usuario, sesion_iniciada);
  // Ya deberíamos saber si se pudo iniciar sesión, y qué tipo de usuario es.
  if (sesion_iniciada) {
    std::cout << "Sesión iniciada como " << tipo_usuario << ".\n"; 
    int opcion{-1};
    if (tipo_usuario == "bibliotecario") { // Menú bibliotecario
      std::cout << "Elija opción: "; 
      std::cin >> opcion;

    }
    else if (tipo_usuario == "cliente") { // Menú cliente
      while (opcion != 0) {
        std::cout << "1. Modificar fecha reserva.\n2. Crear reserva\n3. Mostrar "
        "reservas\n4. Mostrar catálogo\n0. Salir \n";
        std::cout << "Elija opción: ";  
        std::cin >> opcion;
        switch (opcion) {
        case 1:
          /* code */
          break;
        case 2:
          /* code */
          break;
        case 3:
          /* code */
          break;
        case 4:
          // std::cout << catalogo;
          break;
        default:
          break;
        }
      }
    }
    else if (tipo_usuario == "administrador") { // Menú administrador
      std::cout << "Elija opción: "; 
      std::cin >> opcion;
    }
    else {
      std::cout << "Error: tipo de usuario no reconocido.\n";
      std::exit(1);
    }
  }
  datos_usuarios.WriteFile();
  datos_reservas.WriteFile();
  std::cout << "Sesión cerrada.\n";
  std::cout << "FIN\n";
  return 0;
}