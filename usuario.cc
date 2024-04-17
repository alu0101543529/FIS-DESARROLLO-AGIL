/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Algoritmos y Estructuras de Datos Avanzadas (2º curso)
  * 
  * @file nif.cc: Fichero de definición de la clase NIF.
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
  * @brief Contiene la definición de los métodos de la clase NIF.
  */
 
#include "usuario.h"

Usuario::Usuario(DatosUsuario input) {
  nombre_ = input.nombre;
  apellido_1_ = input.apellido_1;
  apellido_2_ = input.apellido_1;
  usuario_ = input.usuario;
  email_ = input.email;
  contrasena_ = input.contrasena;
  tipo_usuario_ = input.tipo_usuario;
}

Usuario::Usuario(std::string datos) {
  std::stringstream ss(datos);
  std::string nombre, apellido_1, apellido_2, usuario, email, contrasena;
  ss >> nombre >> apellido_1 >> apellido_2 >> usuario >> email >> contrasena;  
  nombre_ = nombre;
  apellido_1_ = apellido_1;
  apellido_2_ = apellido_2;
  usuario_ = usuario;
  email_ = email;
  contrasena_ = contrasena;
}

void Usuario::WriteFile(std::ofstream& file) {
  file << std::endl << nombre_ << " " << apellido_1_ << " " << apellido_2_ << " " 
  << usuario_ << " " << email_ << " " << contrasena_ << std::endl;
}