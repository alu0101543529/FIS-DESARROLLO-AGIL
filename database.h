#pragma once

#include <iostream>
#include "usuario.h"
#include <fstream>
#include <vector>

class Database {
 public:
  Usuario Registrar();
  bool IniciarSesion(std::vector<Usuario>&);
  int buscarUsuario(std::vector<Usuario>&, std::string);
  std::vector<Usuario> leerUsuarios(std::ifstream&);
  std::string descifrarCesar(const std::string&, int);

 private:
  std::string cifrarCesar(const std::string&, int);
};