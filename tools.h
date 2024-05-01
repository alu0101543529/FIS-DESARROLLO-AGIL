/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file tools.h
  * @date 23/04/2024
  * @brief Este fichero contiene la declaración de funciones generales.
  */

#pragma once

class DatabaseUsuarios;

#include "database_usuarios.h"

std::string DescifrarCesar(const std::string&, int);
std::string CifrarCesar(const std::string&, int);  
bool GestionarInicioSesion(DatabaseUsuarios& datos, std::string& tipo_usuario, bool& sesion_iniciada);