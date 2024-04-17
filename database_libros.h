/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de ingenieria del software (2º curso)
  * 
  * @file database_libros.h: Fichero de declaración de la clase DatabaseLibros.
  * @author Daniel Enrique Gómez Alcalá (alu0101547961@ull.edu.es)
  */

#ifndef DATABASE_LIBROS_H
#define DATABASE_LIBROS_H

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

#endif
