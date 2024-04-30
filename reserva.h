/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file reserva.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase reserva.
  */

#pragma once

#include "libro.h"
#include "usuario.h"

struct DatosReserva {
  Libro ejemplar;
  Usuario usuario;
};

struct Date {
  int dia;
  int mes;
  int año;
};

class Reserva {
 public:
  Reserva(DatosReserva input);
  Reserva(std::string);
  Date& fecha_caducidad() { return fecha_caducidad_; }
  Date fecha_caducidad() const { return fecha_caducidad_; }
  Libro ejemplar() { return ejemplar_; }
  void WriteFile(std::ofstream&);
 private:
  Date fecha_caducidad_;
  Date fecha_entrada_;
  Libro ejemplar_;
};