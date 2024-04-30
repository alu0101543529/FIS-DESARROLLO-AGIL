/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file usuario.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase Usuario.
  */

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct DatosUsuario {
  std::string nombre{""};
  std::string apellido_1{""};
  std::string apellido_2{""};  
  std::string usuario{""};
  std::string email{""};
  std::string contrasena{""};
  std::string tipo_usuario{""};
};

class Usuario {
 public:
  Usuario(DatosUsuario input);
  Usuario(std::string&);
  std::string usuario() { return informacion_.usuario; }
  std::string contrasena() { return informacion_.contrasena; }
  std::string tipo_usuario() { return informacion_.tipo_usuario; }
  std::string email() { return informacion_.email; }
  void WriteFile(std::ofstream&);
 
 private:
  DatosUsuario informacion_;
};