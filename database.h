/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Algoritmos y Estructuras de Datos Avanzadas (2º curso)
  * 
  * @file sort_library.h: Fichero de definición de librería para algoritmos de 
  * ordenación.
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
  * @brief Contiene la definición de los métodos que implementan algoritmos de 
  * ordenación.
  */

#ifndef DATABASE_H
#define DATABASE_H

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

#endif