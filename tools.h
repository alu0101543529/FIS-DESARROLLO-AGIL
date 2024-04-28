/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file tools.h
  * @author Raúl González Acosta (alu0101543529@ull.edu.es)
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de funciones generales.
  */

#pragma once

class Database;

#include "database.h"

std::string DescifrarCesar(const std::string&, int);
std::string CifrarCesar(const std::string&, int);  
int GestionarInicioSesion(Database& datos, std::string& tipo_usuario, bool& sesion_iniciada);
bool IniciarSesion(Database& datos, std::string&);