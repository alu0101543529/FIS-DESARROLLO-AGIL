/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_libros.h
  * @author Daniel Enrique Gómez Alcalá (alu0101547961@ull.edu.es)
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase DatabaseLibros.
  */

#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "libro.h"

class DatabaseLibros {
 public:
  DatabaseLibros(std::ifstream& input);
  int BuscarLibro(std::string titulo);
  friend std::ostream& operator<<(std::ostream& os, DatabaseLibros& db);

 private:
  std::vector<Libro> libros_;
};
