#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Usuario {
 public:
  Usuario() {}
  Usuario(std::string, std::string, std::string, std::string, std::string, std::string);
  Usuario(std::string);
  std::string getUsuario() { return usuario_;}
  std::string getContrasena() { return contrasena_;}
  void WriteFile(std::ofstream&);
 private:
  std::string nombre_;
  std::string apellido_1_;
  std::string apellido_2_;
  std::string usuario_;
  std::string email_;
  std::string contrasena_;
};