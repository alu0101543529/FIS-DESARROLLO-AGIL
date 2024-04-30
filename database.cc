/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase Database.
  */

 #include "database.h"

Database::Database(std::ifstream& input) : file_(input) {
  LeerElementos();
}

void Database::LeerUsuarios(std::ifstream& file) { // Crea vector con todos los usuarios del archivo
  std::string datos;
  while (getline(file, datos)) {
    if (!datos.empty()) {
      Usuario usuario(datos);
      this->usuarios_.push_back(usuario);
    }
  }
  return;
}

Usuario Database::Registrar() {
}

int Database::BuscarUsuario(std::string usuario) { // Busca usuario en el vector y devuelve la posicion
  for (int i{0}; i < this->usuarios_.size(); i++) {
    if (usuarios_[i].usuario() == usuario) {
      //std::cout << usuarios_[i].usuario() << std::endl;
      return i;
    }
  }
  return -1;
}
