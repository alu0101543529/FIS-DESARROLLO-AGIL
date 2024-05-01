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

DatabaseUsuarios::DatabaseUsuarios(std::ifstream& input, std::ofstream& output) 
: Database(input, output) {
  std::string datos;
  while (getline(input, datos)) {
    if (!datos.empty()) {
      Usuario nuevo_usuario(datos);
      this->usuarios_.push_back(nuevo_usuario);
    }
  }
}

bool DatabaseUsuarios::AgregarElemento() {
  DatosUsuario datos_nuevos;
  std::cout << "Introduzca un nombre de usuario: ";
  std::cin >> datos_nuevos.usuario;
  if (this->BuscarElemento(datos_nuevos.usuario) != -1) {
    std::cout << "Usuario ya existe!\n";
    return false;
  }
  std::cout << "Introduzca su nombre: ";
  std::cin >> datos_nuevos.nombre;
  std::cout << "Introduzca el primer apellido: ";
  std::cin >> datos_nuevos.apellido_1;
  std::cout << "Introduzca el segundo apellido: ";
  std::cin >> datos_nuevos.apellido_2;
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
  std::cout << "\n\nUsuario registrado correctamente\n";
  Usuario nuevo_usuario(datos_nuevos);
  this->usuarios_.push_back(nuevo_usuario);
  return true;
}

void DatabaseUsuarios::EliminarElemento() {
  std::string usuario{""}, email{""};
  std::cout << "Introduzca un nombre de usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca su e-mail: ";
  std::cin >> email;
  int indice_borrar{BuscarElemento(usuario)};
  if (this->usuarios_[indice_borrar].email() == email) {
    this->usuarios_.erase(this->usuarios_.begin() + indice_borrar);
  }
}


bool DatabaseUsuarios::IniciarSesion(std::string& tipo_usuario) {
  std::string usuario, contrasena;
  std::cout << "Introduzca su nombre de usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca su contraseña: ";
  std::cin >> contrasena;
  contrasena = CifrarCesar(contrasena, 3);
  int pos = BuscarElemento(usuario);
  if (pos != -1) {
    if (this->usuarios()[pos].contrasena() == contrasena) {
      tipo_usuario = this->usuarios()[pos].tipo_usuario();
      return true;
    }
    int contador = 3;
    while (contador >= 0) { // Tres intentos para contraseña
      std::cout << "Contrasena incorrecta" << std::endl;
      std::cout << "Introduzca de nuevo la contraseña. (Intentos restantes: " << contador << "): ";
      std::cin >> contrasena;
      contrasena = CifrarCesar(contrasena, 3);
      if (this->usuarios()[pos].contrasena() == contrasena) {
        tipo_usuario = this->usuarios()[pos].tipo_usuario();
        return true;
      }
      contador--;
    }
    std::cout << "Acceso denegado. Ha agotado los intentos de inicio de sesión." << std::endl;
    return false;
  }
  std::cout << "Error: Usuario inexistente." << std::endl;
  return false;
}


int DatabaseUsuarios::BuscarElemento(std::string& nombre_usuario, int busqueda_inicio) {
  for (int i{busqueda_inicio}; i < this->usuarios_.size(); i++) {
    if (usuarios_[i].usuario() == nombre_usuario) {
      return i;
    }
  }
  return -1;
}

void DatabaseUsuarios::WriteFile() {
  if (this->output_stream_.is_open()) {
  for (int i{0}; i < this->usuarios_.size(); i++) {
    this->usuarios_[i].WriteFile(output_stream_);
  }
  output_stream_.close(); // close the file when done
  std::cout << "Fichero de Usuarios sobreescrito\n";
  }
  else {
    std::cerr << "Error opening file\n";
  }
  return;
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
