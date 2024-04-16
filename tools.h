/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Algoritmos y Estructuras de Datos (2º curso)
  * 
  * @file tools.h: Fichero con definición de métodos auxiliares del programa.
  * @brief Contiene la declaración de los métodos que ayudan a especificar la 
  * utilización del programa.
  */


#ifndef TOOLS_H
#define TOOLS_H

class Database;

#include "database.h"


std::string DescifrarCesar(const std::string&, int);
std::string CifrarCesar(const std::string&, int);  
int GestionarInicioSesion(Database& datos, std::string& tipo_usuario, bool& sesion_iniciada);
bool IniciarSesion(Database& datos, std::string&);

#endif