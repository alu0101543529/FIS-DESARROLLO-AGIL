/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database.cc
  * @author Enmanuel Vegas (alu0101281698@ull.edu.es)
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase Database.
  */

 #include "database.h"

Database::Database(std::ifstream& input) {
  LeerUsuarios(input);
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
  return nuevo_usuario;
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
