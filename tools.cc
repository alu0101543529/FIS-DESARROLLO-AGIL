#include "tools.h"

std::string cifrarCesar(const std::string& texto, int desplazamiento) {
  std::string textoCifrado = texto;
  for (char& c : textoCifrado) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      c = (c - base + desplazamiento) % 26 + base;
    }
  }
  return textoCifrado;
}

std::string descifrarCesar(const std::string& textoCifrado, int desplazamiento) {
    return cifrarCesar(textoCifrado, 26 - desplazamiento);
}

std::vector<Usuario> leerUsuarios(std::ifstream& file) { // Crea vector con todos los usuarios del archivo
  std::vector<Usuario> usuarios;
  std::string datos;
  while (getline(file, datos)) {
    if (!datos.empty()) {
      Usuario usuario(datos);
      usuarios.push_back(usuario);
    }
  }
  return usuarios;
}

Usuario Registrar() {
  std::string nombre, apellido, usuario, email, contrasena;
  std::cout << "Nombre: ";
  std::cin >> nombre;
  std::cout << "Apellido: ";
  std::cin >> apellido;
  std::cout << "Usuario: ";
  std::cin >> usuario;
  std::cout << "Email: ";
  std::cin >> email;
  std::cout << "Contrasena: ";
  std::cin >> contrasena;
  contrasena = cifrarCesar(contrasena, 3);
  Usuario usuario1(nombre, apellido, usuario, email, contrasena);
  return usuario1;
}

int buscarUsuario(std::vector<Usuario>& usuarios, std::string usuario) { // Busca usuario en el vector y devuelve la posicion
  for (int i = 0; i < usuarios.size(); i++) {
    if (usuarios[i].getUsuario() == usuario) {
      return i;
    }
  }
  return -1;
}

bool IniciarSesion(std::vector<Usuario>& usuarios) {
  std::string usuario, contrasena;
  std::cout << "Usuario: ";
  std::cin >> usuario;
  std::cout << "Contrasena: ";
  std::cin >> contrasena;
  contrasena = cifrarCesar(contrasena, 3);
  int pos = buscarUsuario(usuarios, usuario);
  if (pos != -1) {
    if (usuarios[pos].getContrasena() == contrasena) {
      return true;
    }
    int contador = 0;
    while (contador < 3) { // Tres intentos contraseña
      std::cout << "Contrasena incorrecta" << std::endl;
      std::cout << "Contrasena: ";
      std::cin >> contrasena;
      contrasena = cifrarCesar(contrasena, 3);
      if (usuarios[pos].getContrasena() == contrasena) {
        return true;
      }
      contador++;
    }
    std::cout << "Acceso denegado" << std::endl;
    return false;
  }
  std::cout << "Usuario no encontrado" << std::endl;
  return false;
}
