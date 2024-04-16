#include "database.h"

std::string Database::cifrarCesar(const std::string& texto, int desplazamiento) {
  std::string textoCifrado = texto;
  for (char& c : textoCifrado) {
    if (isalpha(c)) {
      char base = isupper(c) ? 'A' : 'a';
      c = ((c - base + desplazamiento) % 26 + base);
    }
  }
  return textoCifrado;
}

std::string Database::descifrarCesar(const std::string& textoCifrado, int desplazamiento) {
  return cifrarCesar(textoCifrado, (26 - desplazamiento));
}

// Crea vector con todos los usuarios del archivo
std::vector<Usuario> Database::leerUsuarios(std::ifstream& file) { 
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

Usuario Database::Registrar() {
  std::string nombre, apellido_1, apellido_2 , usuario, email, contrasena_1, contrasena_2;

  std::cout << "Introduzca su nombre: ";
  std::cin >> nombre;

  std::cout << "Introduzca el primer apellido: ";
  std::cin >> apellido_1;

  std::cout << "Introduzca el segundo apellido: ";
  std::cin >> apellido_2;

  std::cout << "Introduzca un nombre de usuario: ";
  std::cin >> usuario;

  std::cout << "Introduzca su e-mail: ";
  std::cin >> email;

  std::cout << "Cree una contraseña: ";
  std::cin >> contrasena_1;

  while (contrasena_1 != contrasena_2) {
    std::cout << "Vuelva a introducir la contraseña: ";
    std::cin >> contrasena_2;

    if (contrasena_1 != contrasena_2) {
      std::cout << "Error: La contraseña no coincide. Vuelva a intentarlo." << std::endl;
    }
  }
  contrasena_1 = cifrarCesar(contrasena_1, 3);
  Usuario usuario1(nombre, apellido_1, apellido_2, usuario, email, contrasena_1);
  return usuario1;
}

int Database::buscarUsuario(std::vector<Usuario>& usuarios, std::string usuario) { // Busca usuario en el vector y devuelve la posicion
  for (int i = 0; i < usuarios.size(); i++) {
    if (usuarios[i].getUsuario() == usuario) {
      return i;
    }
  }
  return -1;
}

bool Database::IniciarSesion(std::vector<Usuario>& usuarios) {
  std::string usuario, contrasena;

  std::cout << "Introduzca su nombre de usuario: ";
  std::cin >> usuario;

  std::cout << "Introduzca su contraseña: ";
  std::cin >> contrasena;

  contrasena = cifrarCesar(contrasena, 3);
  int pos = buscarUsuario(usuarios, usuario);

  if (pos != -1) {
    if (usuarios[pos].getContrasena() == contrasena) { return true; }
    
    int contador = 3;
    while (contador > 0) { // Tres intentos contraseña
      std::cout << "La contraseña es incorrecta. Vuelva a intentarlo..." << std::endl;
      std::cout << "Introduzca de nuevo la contraseña. (Intentos restantes: " << contador << "): ";
      std::cin >> contrasena;

      contrasena = cifrarCesar(contrasena, 3);
      if (usuarios[pos].getContrasena() == contrasena) { return true; }
      contador--;
    }

    std::cout << "Error: Acceso denegado. Ha agotado los intentos de inicio de sesión." << std::endl;
    return false;
  }
  
  std::cout << "Error: Usuario inexistente..." << std::endl;
  return false;
}
