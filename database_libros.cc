/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_libros.cc
  * @author Daniel Enrique Gómez Alcalá (alu0101547961@ull.edu.es)
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase DatabaseLibros.
  */

#include "database_libros.h"

DatabaseLibros::DatabaseLibros(std::ifstream& input) {
  std::string datos;
  while (getline(input, datos)) {
    if (!datos.empty()) {
      Libro libro(datos);
      this->libros_.push_back(libro);
    }
  }
}

int DatabaseLibros::BuscarLibro(std::string titulo) {
  for (int i{0}; i < this->libros_.size(); i++) {
    if (libros_[i].get_titulo() == titulo) {
      return i;
    }
  }
  return -1;
}

std::ostream& operator<<(std::ostream& os, DatabaseLibros& db) {
  os << std::endl;
  std::cout << "\033[1mCatálogo de libros:\033[0m\n\n";
  for (int i{0}; i < db.libros_.size(); i++) {
    os << db.libros_[i].get_titulo() << " " << db.libros_[i].get_autor() << " " << db.libros_[i].get_anio() << " " << db.libros_[i].get_genero() << " " << db.libros_[i].get_unidades() << std::endl;
  }
  os << std::endl;
  return os;
}