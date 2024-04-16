#include "usuario.h"

Usuario::Usuario(std::string nombre, std::string apellido1, std::string apellido2, std::string usuario, std::string email, std::string contrasena) {
  nombre_ = nombre;
  apellido_1_ = apellido1;
  apellido_2_ = apellido2;
  usuario_ = usuario;
  email_ = email;
  contrasena_ = contrasena;
}

Usuario::Usuario(std::string datos) {
  std::stringstream ss(datos);
    std::string nombre, apellido1, apellido2, usuario, email, contrasena;
    ss >> nombre >> apellido1 >> apellido2 >> usuario >> email >> contrasena;
    
    nombre_ = nombre;
    apellido_1_ = apellido1;
    apellido_2_ = apellido2;
    usuario_ = usuario;
    email_ = email;
    contrasena_ = contrasena;
}

void Usuario::WriteFile(std::ofstream& file) {
  file << std::endl << nombre_ << " " << apellido_1_ << " " << apellido_2_ << " " << usuario_ << " " << email_ << " " << contrasena_ << std::endl;
}