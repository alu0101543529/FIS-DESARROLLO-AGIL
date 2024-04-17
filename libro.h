/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de ingenieria del software (2º curso)
  * 
  * @file libro.h: Fichero de declaración de la clase Libro.
  * @author Daniel Enrique Gómez Alcalá (alu0101547961@ull.edu.es)
  */


#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Libro {
 public:
  Libro(std::string datos);
  Libro(std::string titulo, std::string autor, std::string anio, std::string genero, int unidades);
  std::string get_titulo() {return titulo_;}
  std::string get_autor() {return autor_;}
  std::string get_anio() {return anio_;}
  std::string get_genero() {return genero_;}
  int get_unidades() {return unidades_;}
  void set_unidades(int unidades) {unidades_ = unidades;}
 private:
  std::string titulo_;
  std::string autor_;
  std::string anio_;
  std::string genero_;
  int unidades_;
};

#endif