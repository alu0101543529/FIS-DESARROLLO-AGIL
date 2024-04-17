/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de ingenieria del software (2º curso)
  * 
  * @file libro.cc: Fichero de definicion de la clase Libro.
  * @author Daniel Enrique Gómez Alcalá (alu0101547961@ull.edu.es)
  */

#include "libro.h"

Libro::Libro(std::string datos) {
  std::stringstream ss(datos);
  std::string titulo, autor, anio, genero;
  int unidades;
  ss >> titulo >> autor >> anio >> genero >> unidades;
  titulo_ = titulo;
  autor_ = autor;
  anio_ = anio;
  genero_ = genero;
  unidades_ = unidades;
}

Libro::Libro(std::string titulo, std::string autor, std::string anio, std::string genero, int unidades) {
  titulo_ = titulo;
  autor_ = autor;
  anio_ = anio;
  genero_ = genero;
  unidades_ = unidades;
}