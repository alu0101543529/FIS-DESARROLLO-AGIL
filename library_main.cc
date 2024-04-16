/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingeniería del Software (2º curso)
  * 
  * @file library_main.cc: Programa cliente.
  * @brief Contiene la función main del proyecto 'library', que 
  * usa las clases ___ para gestionar las reservas y usuarios de una biblioteca.
  * Compilación: Makefile
  */

#include "usuario.h"
#include "tools.h"
#include "database.h"

int main() {
  std::ofstream salida_usuario("bbdd_usuarios.info", std::ios::app);
  std::ifstream entrada_usuario("bbdd_usuarios.info");
  std::ofstream salida_reserva("bbdd_reservas.info", std::ios::app);
  std::ifstream entrada_reserva("bbdd_reservas.info");
  Database datos(entrada_usuario);
  bool sesion_iniciada = false;
  std::string tipo_usuario{""};
  if (!GestionarInicioSesion(datos, tipo_usuario, sesion_iniciada)) {
    return EXIT_SUCCESS; // Elegimos salir
  }
  // Ya deberíamos saber si se pudo iniciar sesión, y qué tipo de usuario es
  if (sesion_iniciada) {
    std::cout << "Sesión iniciada como " << tipo_usuario << ".\n"; 
    std::cout << "Elija opción:\n";  
    int opcion{0};
    if (tipo_usuario == "bibliotecario") { // Menú bibliotecario

    }
    if (tipo_usuario == "cliente") { // Menú cliente
      while (opcion != 0) {
        std::cout << "1. Modificar fecha reserva.\n2. Crear reserva\n0. Salir ";
        std::cin >> opcion;
        
      }
    }
    if (tipo_usuario == "administrador") { // Menú administrador
      
    }
  }
  return 0;
}