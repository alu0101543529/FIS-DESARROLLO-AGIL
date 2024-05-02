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

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct Date {
  int dia;
  int mes;
  int anyo;
};

struct DatosReserva {
  std::string ejemplar;
  std::string usuario;
  Date fecha_caducidad;
  Date fecha_entrada;  
};

class Reserva {
 public:
  Reserva(DatosReserva input);
  Reserva(std::string);
  Date& fecha_caducidad() { return fecha_caducidad_; }
  Date fecha_caducidad() const { return fecha_caducidad_; }
  std::string ejemplar() { return ejemplar_; }
  std::string nombre_usuario() { return nombre_usuario_; }
  void WriteFile(std::ofstream&);
 private:
  std::string ejemplar_;
  std::string nombre_usuario_;
  Date fecha_caducidad_;
  Date fecha_entrada_;
};