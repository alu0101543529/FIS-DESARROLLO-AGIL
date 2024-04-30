/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database.h
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
  std::ifstream& file() { return file_; }
  virtual int BuscarElemento(std::string&) = 0;
  virtual void AgregarElemento() = 0;
  virtual void EliminarElemento() = 0;


  // int BuscarUsuario(std::string);
  // void LeerUsuarios(std::ifstream&);
  // void AgregarUsuario(Usuario aux) { this->usuarios_.push_back(aux); }

 private:
  virtual void LeerElementos() = 0;
  std::ifstream& file_;
};