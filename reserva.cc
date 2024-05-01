/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file usuario.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase Reserva.
  */
 
#include "reserva.h"

Reserva::Reserva(DatosReserva input) {
  this->ejemplar_ = input.ejemplar;
  this->nombre_usuario_ = input.usuario;
  this->fecha_caducidad_ = input.fecha_caducidad;
  this->fecha_entrada_ = input.fecha_entrada;
}

Reserva::Reserva(std::string datos) {
  std::stringstream ss(datos);
  std::string usuario, ejemplar;
  int dia_entrada, mes_entrada, anyo_entrada, dia_caducidad, mes_caducidad, anyo_caducidad;
  ss >> usuario >> ejemplar >> dia_entrada >> mes_entrada >> anyo_entrada >> dia_caducidad;
  ss >> mes_caducidad >> anyo_caducidad;
  nombre_usuario_ = usuario;
  ejemplar_ = ejemplar;
  fecha_entrada_.dia = dia_entrada;
  fecha_entrada_.mes = mes_entrada;
  fecha_entrada_.anyo = anyo_entrada;
  fecha_caducidad_.dia = dia_caducidad;
  fecha_caducidad_.mes = mes_caducidad;
  fecha_caducidad_.anyo = anyo_caducidad;
}

void Reserva::WriteFile(std::ofstream& file) {
  file << std::endl <<  nombre_usuario_ << " " << ejemplar_ << " " << fecha_entrada_.dia;
  file << " " << fecha_entrada_.mes << " " << fecha_entrada_.anyo << " " << 
  fecha_caducidad_.dia << " " << fecha_caducidad_.mes << " " << fecha_caducidad_.anyo;
}