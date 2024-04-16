/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Algoritmos y Estructuras de Datos Avanzadas (2º curso)
  * 
  * @file sort_library.h: Fichero de definición de librería para algoritmos de 
  * ordenación.
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
  * @brief Contiene la definición de los métodos que implementan algoritmos de 
  * ordenación.
  */

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

struct DatosUsuario {
  std::string nombre{""};
  std::string apellido_1{""};
  std::string apellido_2{""};  
  std::string usuario{""};
  std::string email{""};
  std::string contrasena{""};
  std::string tipo_usuario{""};
};

class Usuario {
 public:
  Usuario() { }
  Usuario(DatosUsuario input);
  Usuario(std::string);
  std::string usuario() { return usuario_; }
  std::string contrasena() { return contrasena_; }
  std::string tipo_usuario() { return tipo_usuario_; }
  void WriteFile(std::ofstream&);
 private:
  std::string nombre_;
  std::string apellido_1_;
  std::string apellido_2_;
  std::string usuario_;
  std::string email_;
  std::string contrasena_;
  std::string tipo_usuario_;
};

#endif