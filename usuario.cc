/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file usuario.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase Usuario.
  */
 
#include "usuario.h"

Usuario::Usuario(DatosUsuario input) {
  this->informacion_.nombre = input.nombre;
  this->informacion_.apellido_1 = input.apellido_1;
  this->informacion_.apellido_2 = input.apellido_2;
  this->informacion_.usuario = input.usuario;
  this->informacion_.email = input.email;
  this->informacion_.contrasena = input.contrasena;
  this->informacion_.tipo_usuario = input.tipo_usuario;
}

Usuario::Usuario(std::string& datos) {
  std::stringstream ss(datos);
  ss >> informacion_.nombre >> informacion_.apellido_1 >> informacion_.apellido_2
  >> informacion_.usuario >> informacion_.email >> informacion_.contrasena
  >> informacion_.tipo_usuario;
}

void Usuario::WriteFile(std::ofstream& file) {
  file << informacion_.nombre << informacion_.apellido_1 
  << informacion_.apellido_2 << informacion_.usuario << informacion_.email 
  << informacion_.contrasena << informacion_.tipo_usuario << std::endl;
}