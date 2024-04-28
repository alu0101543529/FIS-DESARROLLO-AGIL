/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file usuario.h
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
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
  Usuario() { }
  Usuario(DatosUsuario input);
  Usuario(std::string);
  std::string usuario() { return usuario_; }
  std::string contrasena() { return contrasena_; }
  std::string tipo_usuario() { return tipo_usuario_; }
  void WriteFile(std::ofstream&);
 private:
  std::string nombre_;
  std::string apellido_1_;
  std::string apellido_2_;
  std::string usuario_;
  std::string email_;
  std::string contrasena_;
  std::string tipo_usuario_;
};