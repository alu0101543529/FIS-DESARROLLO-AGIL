#include "usuario.h"

Usuario::Usuario(std::string nombre, std::string apellido, std::string usuario, std::string email, std::string contrasena) {
  nombre_ = nombre;
  apellido_ = apellido;
  usuario_ = usuario;
  email_ = email;
  contrasena_ = contrasena;
}

Usuario::Usuario(std::string datos) {
  std::stringstream ss(datos);
    std::string nombre, apellido, usuario, email, contrasena;
    ss >> nombre >> apellido >> usuario >> email >> contrasena;
    
    nombre_ = nombre;
    apellido_ = apellido;
    usuario_ = usuario;
    email_ = email;
    contrasena_ = contrasena;
}

void Usuario::WriteFile(std::ofstream& file) {
  file << std::endl << nombre_ << " " << apellido_ << " " << usuario_ << " " << email_ << " " << contrasena_ << std::endl;
}