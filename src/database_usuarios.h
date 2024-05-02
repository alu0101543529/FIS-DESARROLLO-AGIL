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
#include "usuario.h"

std::string DescifrarCesar(const std::string&, int);
std::string CifrarCesar(const std::string&, int);  

class DatabaseUsuarios : public Database {
 public:

  std::vector<Usuario> usuarios() const { return this->usuarios_; }
  
  DatabaseUsuarios(std::ifstream& input, std::ofstream& output);

  int BuscarElemento(std::string& nombre_elemento, int busqueda_inicio = 0);

  bool AgregarElemento();

  void EliminarElemento();

  bool IniciarSesion(std::string& tipo_usuario);

  void WriteFile();

  friend std::ostream& operator<<(std::ostream& os, DatabaseUsuarios& db);

 private:
  std::vector<Usuario> usuarios_;
};
