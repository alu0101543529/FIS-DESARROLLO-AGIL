/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Algoritmos y Estructuras de Datos (2º curso)
  * 
  * @file tools.cc: Fichero con definición de métodos auxiliares del programa.
  * @brief Contiene la definición de los métodos que ayudan a especificar la 
  * utilización del programa.
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

int GestionarInicioSesion(Database& datos, std::string& tipo_usuario, bool& sesion_iniciada) {
  std::ofstream salida_usuario("bbdd.info", std::ios::app);
  int opcion{0};
  while (!sesion_iniciada) {
    std::cout << "1. Registrarse\n2. Iniciar sesion\n-1. Salir\n\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1: { //Registrar
        Usuario aux = datos.Registrar();
        aux.WriteFile(salida_usuario);
        datos.AgregarUsuario(aux);
        break;
      }
      case 2: { //Iniciar sesión
        if (IniciarSesion(datos, tipo_usuario)) {
          sesion_iniciada = true;
          return 1;
        }
        else {
          std::cout << "Inicio de sesión no satisfactorio\n";
        }
        break;
      }
      case -1: { // Salir
        std::cout << "Programa terminado.\n\n" << std::endl;
        return 0;
      }
      case 50: { // Esto no es importante, solo es para mostrar los usuarios registrados
        for (Usuario& usuario : datos.usuarios()) {
          std::cout << usuario.usuario() << " " << DescifrarCesar(usuario.contrasena(), 3) << std::endl;
        }
        break;
      }
    }
  }
}

bool IniciarSesion(Database& datos, std::string& tipo_usuario) {
  std::string usuario, contrasena;
  std::cout << "Introduzca su nombre de usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca su contraseña: ";
  std::cin >> contrasena;
  contrasena = CifrarCesar(contrasena, 3);
  int pos = datos.BuscarUsuario(usuario);
  if (pos != -1) {
    if (datos.usuarios()[pos].contrasena() == contrasena) {
      tipo_usuario = datos.usuarios()[pos].tipo_usuario();
      return true;
    }
    int contador = 3;
    while (contador >= 0) { // Tres intentos contraseña
      std::cout << "Contrasena incorrecta" << std::endl;
      std::cout << "Introduzca de nuevo la contraseña. (Intentos restantes: " << contador << "): ";
      std::cin >> contrasena;
      contrasena = CifrarCesar(contrasena, 3);
      if (datos.usuarios()[pos].contrasena() == contrasena) {
        tipo_usuario = datos.usuarios()[pos].tipo_usuario();
        return true;
      }
      contador--;
    }
    std::cout << "Acceso denegado. Ha agotado los intentos de inicio de sesión." << std::endl;
    return false;
  }
  std::cout << "Error: Usuario inexistente." << std::endl;
  return false;
}
