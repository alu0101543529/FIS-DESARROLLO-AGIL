#include "database.h"

int main() {
  Database data;
  int opcion = 0;
  std::ofstream salida_usuario("data.txt", std::ios::app);
  std::ifstream entrada_usuario("data.txt");
  std::vector<Usuario> usuarios = data.leerUsuarios(entrada_usuario);
  bool sesion_iniciada = false;
  do {
    std::cout << "1. Registrarse" << std::endl;
    std::cout << "2. Iniciar sesion" << std::endl;
    std::cout << "-1. Salir" << std::endl;
    std::cout << std::endl;
    std::cout << "Opcion: ";
    std::cin >> opcion;
    switch (opcion) {
      case 1: { //Registrar
        Usuario aux = data.Registrar();
        aux.WriteFile(salida_usuario);
        usuarios.push_back(aux);
        break;
      } 
      case 2: { //Iniciar sesión
        if (data.IniciarSesion(usuarios)) {
          sesion_iniciada = true;
        }
        break;
      }
      case -1: { // Salir
        std::cout << "SALIENDO" << std::endl;
        std::exit(0);
      }
      case 50: { // Esto no es importante, solo es para mostrar los usuarios registrados
        for (Usuario& usuario : usuarios) {
          std::cout << usuario.getUsuario() << " " << data.descifrarCesar(usuario.getContrasena(), 3) << std::endl;
        }
        break;
      }
    }
  } while (!sesion_iniciada);

  if (sesion_iniciada) {
    std::cout << "SESION INICIADA" << std::endl; // Mostar menu de opciones cuando inicias sesion
  }
  return 0;
}