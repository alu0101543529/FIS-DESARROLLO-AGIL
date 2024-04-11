#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


class Usuario {
 public:
  Usuario();
  Usuario(std::string nombre, std::string apellido, std::string usuario, std::string email, std::string contrasena);
  Usuario(std::string);
  std::string getUsuario() { return usuario_;}
  std::string getContrasena() { return contrasena_;}
  void WriteFile(std::ofstream&);
 private:
  std::string nombre_;
  std::string apellido_;
  std::string usuario_;
  std::string email_;
  std::string contrasena_;
};

#endif