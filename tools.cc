/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file tools.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de funciones generales.
  */

#include "tools.h"

std::string CifrarCesar(const std::string& texto, int desplazamiento) {
  std::string textoCifrado = texto;
  for (char& c : textoCifrado) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      c = (c - base + desplazamiento) % 26 + base;
    }
  }
  return textoCifrado;
}

std::string DescifrarCesar(const std::string& textoCifrado, int desplazamiento) {
    return CifrarCesar(textoCifrado, 26 - desplazamiento);
}

bool GestionarInicioSesion(DatabaseUsuarios& datos, std::string& tipo_usuario, bool& sesion_iniciada) {
  int opcion{0};
  while (!sesion_iniciada) {
    std::cout << "1. Registrarse\n2. Iniciar sesion\n-1. Salir\n\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1: { // Registrar
        bool exito_registro{false};
        while (!exito_registro) {
          exito_registro = datos.AgregarElemento();
        }
        break;
      }
      case 2: { // Iniciar sesión
        if (datos.IniciarSesion(tipo_usuario)) {
          sesion_iniciada = true;
        }
        else {
          std::cout << "Inicio de sesión no satisfactorio\n";
        }
        break;
      }
      case -1: { // Salir
        std::cout << "Programa terminado.\n\n" << std::endl;
        return false;
      }
      case 50: { // Esto no es importante, solo es para mostrar los usuarios registrados
        for (Usuario& usuario : datos.usuarios()) {
          std::cout << usuario.usuario() << " " << DescifrarCesar(usuario.contrasena(), 3) << std::endl;
        }
        break;
      }
    }
  }
  return true;
}
