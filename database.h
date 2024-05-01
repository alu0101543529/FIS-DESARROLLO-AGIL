/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de los métodos de la clase Database.
  */

#pragma once

#include <vector>
#include <fstream>

class Database {
 public:
  Database(std::ifstream& input, std::ofstream& output) : input_stream_(input),
  output_stream_(output) { }
  std::ifstream& input_stream() { return input_stream_; }
  virtual int BuscarElemento(std::string&, int indice_inicio = 0) = 0;
  virtual bool AgregarElemento() = 0;
  virtual void EliminarElemento() = 0;
  virtual void WriteFile() = 0;

 protected:
  std::ifstream& input_stream_;
  std::ofstream& output_stream_;
};