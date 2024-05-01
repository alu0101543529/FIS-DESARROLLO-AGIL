/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_reservas.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase DatabaseLibros.
  */

#pragma once

#include "database.h"
#include "reserva.h"

class DatabaseReservas : public Database {
 public:

  std::vector<Reserva> reservas() const { return this->reservas_; }
  
  DatabaseReservas(std::ifstream& input, std::ofstream& output);

  int BuscarReserva(std::string& nombre_usuario, std::string& ejemplar);

  int BuscarElemento(std::string& nombre_elemento, int busqueda_inicio = 0);

  bool AgregarElemento();

  void EliminarElemento();

  void ModificarReserva();

  void WriteFile();

  friend std::ostream& operator<<(std::ostream& os, DatabaseReservas& db);

 private:
  std::vector<Reserva> reservas_;
};
