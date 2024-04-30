/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_usuarios.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase DatabaseUsuarios.
  */

#include "database_usuarios.h"

DatabaseUsuarios::DatabaseUsuarios(std::ifstream& input) : Database(input) {
  std::string datos;
  while (getline(input, datos)) {
    if (!datos.empty()) {
      Usuario nuevo_usuario(datos);
      this->usuarios_.push_back(nuevo_usuario);
    }
  }
}

void DatabaseUsuarios::AgregarElemento() {
  DatosUsuario datos_nuevos;
  std::cout << "Introduzca su nombre: ";
  std::cin >> datos_nuevos.nombre;
  std::cout << "Introduzca el primer apellido: ";
  std::cin >> datos_nuevos.apellido_1;
  std::cout << "Introduzca el segundo apellido: ";
  std::cin >> datos_nuevos.apellido_2;
  std::cout << "Introduzca un nombre de usuario: ";
  std::cin >> datos_nuevos.usuario;
  std::cout << "Introduzca su e-mail: ";
  std::cin >> datos_nuevos.email;
  std::string contrasena_comprobar{"."};
  while (datos_nuevos.contrasena != contrasena_comprobar) {
    std::cout << "Cree una contraseña: ";
    std::cin >> datos_nuevos.contrasena;
    std::cout << "Confirme la contraseña: ";
    std::cin >> contrasena_comprobar;
    if (datos_nuevos.contrasena != contrasena_comprobar) {
      std::cout << "Error: La contraseña no coincide. Vuelva a intentarlo.\n";
    }
  }
  datos_nuevos.contrasena = CifrarCesar(datos_nuevos.contrasena, 3);  
  while (datos_nuevos.tipo_usuario != "cliente" && datos_nuevos.tipo_usuario != "bibliotecario" &&
  datos_nuevos.tipo_usuario != "administrador") {
    std::cout << "Tipo de usuario: ";
    std::cin >> datos_nuevos.tipo_usuario;
    if (datos_nuevos.tipo_usuario != "cliente" && datos_nuevos.tipo_usuario != "bibliotecario" &&
    datos_nuevos.tipo_usuario != "administrador") {
      std::cout << "Tipo de usuario no válido. Opciones: administrador, cliente, bibliotecario\n";
    }
  }
  Usuario nuevo_usuario(datos_nuevos);
  this->usuarios_.push_back(nuevo_usuario);
}

void DatabaseUsuarios::EliminarElemento() {
  std::string usuario{""}, email{""};
  std::cout << "Introduzca un nombre de usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca su e-mail: ";
  std::cin >> email;
  int indice_borrar{BuscarElemento(usuario)};
  if (this->usuarios_[indice_borrar].email() == email) {
    this->usuarios_.erase(indice_borrar);
  }
}


int DatabaseUsuarios::BuscarElemento(std::string& nombre_usuario) {
  for (int i{0}; i < this->usuarios_.size(); i++) {
    if (usuarios_[i].usuario() == nombre_usuario) {
      return i;
    }
  }
  return -1;
}

std::ostream& operator<<(std::ostream& os, DatabaseUsuarios& db) {
  os << std::endl;
  std::cout << "\033[1mRegistro de usuarios:\033[0m\n\n";
  for (int i{0}; i < db.usuarios_.size(); i++) {
    os << db.usuarios_[i].usuario() << " " << db.usuarios_[i].tipo_usuario() <<
    " " << db.usuarios_[i].email() << std::endl;
  }
  os << std::endl;
  return os;
}