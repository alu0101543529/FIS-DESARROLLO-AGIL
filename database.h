/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database.h
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase Database.
  */

#pragma once

#include <vector>

#include "usuario.h"
#include "tools.h"

class Database {
 public:
  Database(std::ifstream&);
  Usuario Registrar();
  std::vector<Usuario> usuarios() { return usuarios_; }
  int BuscarUsuario(std::string);
  void LeerUsuarios(std::ifstream&);
  void AgregarUsuario(Usuario aux) { this->usuarios_.push_back(aux); }

 private:
  std::vector<Usuario> usuarios_;
};