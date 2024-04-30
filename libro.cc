/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file libro.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase Libro.
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