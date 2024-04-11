#ifndef TOOLS_H
#define TOOLS_H

#include <iostream>
#include "usuario.h"
#include <fstream>
#include <vector>

std::string cifrarCesar(const std::string& texto, int desplazamiento);
std::string descifrarCesar(const std::string& textoCifrado, int desplazamiento);
std::vector<Usuario> leerUsuarios(std::ifstream& file);
Usuario Registrar();
int buscarUsuario(std::vector<Usuario>& usuarios, std::string usuario);
bool IniciarSesion(std::vector<Usuario>& usuarios);


#endif