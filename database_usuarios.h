/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_usuarios.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase DatabaseLibros.
  */

#pragma once

#include "database.h"

class DatabaseUsuarios : public Database {
 public:
  DatabaseUsuarios(std::ifstream& input);

  int BuscarElemento(std::string& nombre_elemento);

  void AgregarElemento();

  void EliminarElemento();

  friend std::ostream& operator<<(std::ostream& os, DatabaseUsuarios& db);

 private:
  std::vector<Usuario> usuarios_;
};
