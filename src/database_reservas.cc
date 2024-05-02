/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Asignatura: Fundamentos de Ingenieria del Software
  * 
  * @file database_reservas.cc
  * @date 23/04/2024
  * @brief Este fichero contiene la definición de los métodos de la clase DatabaseReservas.
  */

#include "database_reservas.h"

DatabaseReservas::DatabaseReservas(std::ifstream& input, std::ofstream& output) 
: Database(input, output) {
  std::string datos;
  while (getline(input, datos)) {
    if (!datos.empty()) {
      Reserva nueva_reserva(datos);
      this->reservas_.push_back(nueva_reserva);
    }
  }
}

bool DatabaseReservas::AgregarElemento() {
  DatosReserva datos_nuevos;
  std::cout << "Introduzca usuario: ";
  std::cin >> datos_nuevos.usuario;
  std::cout << "Introduzca ejemplar en formato correcto: ";
  std::cin >> datos_nuevos.ejemplar;
  if (this->BuscarReserva(datos_nuevos.usuario, datos_nuevos.ejemplar) != -1) {
    std::cout << "Reserva ya existe!\n";
    return false;
  }
  bool fechas_correctas{false};
  while (!fechas_correctas) {
    std::cout << "Introduzca día de entrada: ";
    std::cin >> datos_nuevos.fecha_entrada.dia;
    std::cout << "Introduzca mes de entrada: ";
    std::cin >> datos_nuevos.fecha_entrada.mes;
    std::cout << "Introduzca año de entrada: ";
    std::cin >> datos_nuevos.fecha_entrada.anyo;
    if (datos_nuevos.fecha_entrada.dia > 31 || datos_nuevos.fecha_entrada.dia < 1) {
      std::cout << "Día incorrecto!\n";
      continue;
    }
    if (datos_nuevos.fecha_entrada.mes > 12 || datos_nuevos.fecha_entrada.mes < 1) {
      std::cout << "Mes incorrecto!\n";
      continue;
    }
    if (datos_nuevos.fecha_entrada.anyo > 2025 || datos_nuevos.fecha_entrada.dia < 2024) {
      std::cout << "Año incorrecto!\n";
      continue;
    }
    datos_nuevos.fecha_caducidad.dia = ((15 + datos_nuevos.fecha_entrada.dia) % 31);
    if (datos_nuevos.fecha_entrada.dia > 15) {
      datos_nuevos.fecha_caducidad.mes = (datos_nuevos.fecha_entrada.mes + 1) % 12;
      if (datos_nuevos.fecha_caducidad.mes == 1) {
        datos_nuevos.fecha_caducidad.anyo = datos_nuevos.fecha_entrada.anyo + 1; 
      } 
    }
    fechas_correctas = true;
  }
  Reserva nueva_reserva(datos_nuevos);
  this->reservas_.push_back(nueva_reserva);
  std::cout << "\n\nReserva registrada correctamente.\nPlazo para devolución hasta"
  "el día " << datos_nuevos.fecha_caducidad.dia << " " << datos_nuevos.fecha_caducidad.mes
  << " " << datos_nuevos.fecha_caducidad.anyo << "\n";
  return true;
}


void DatabaseReservas::ModificarReserva() {
  std::string usuario{""}, ejemplar{""};
  std::cout << "Introduzca usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca ejemplar en formato correcto: ";
  std::cin >> ejemplar;
  int indice_modificar{BuscarReserva(usuario, ejemplar)};
  if (indice_modificar == -1) {
    std::cout << "Reserva no existe!\n";
  }  
  else {
    this->reservas_.erase(this->reservas_.begin() + indice_modificar);
    std::cout << "Modificación reserva: Introduce los datos nuevos:\n";
    this->AgregarElemento();
  }
}

void DatabaseReservas::EliminarElemento() {
  std::string usuario{""}, ejemplar{""};
  std::cout << "Introduzca usuario: ";
  std::cin >> usuario;
  std::cout << "Introduzca ejemplar en formato correcto: ";
  std::cin >> ejemplar;
  int indice_borrar{BuscarReserva(usuario, ejemplar)};
  if (indice_borrar == -1) {
    std::cout << "Reserva no existe!\n";
  }  
  else {
    this->reservas_.erase(this->reservas_.begin() + indice_borrar);
  }
}

int DatabaseReservas::BuscarReserva(std::string& nombre_usuario, std::string& ejemplar) {
  int busqueda_indice{0};
  // Hacemos la búsqueda de esta manera porque puede ser que un mismo usuario tenga
  // varias reservas. Tenemos que verificar que tanto el usuario como el ejemplar
  // coincidan.
  while (busqueda_indice < this->reservas_.size()) {
    busqueda_indice = this->BuscarElemento(nombre_usuario, busqueda_indice);
    if (reservas_[busqueda_indice].ejemplar() == ejemplar) {
      return busqueda_indice;
    }
    continue;
  }
  return -1;
}

int DatabaseReservas::BuscarElemento(std::string& nombre_usuario, int busqueda_inicio) {
  for (int i{busqueda_inicio}; i < this->reservas_.size(); i++) {
    if (reservas_[i].nombre_usuario() == nombre_usuario) {
      return i;
    }
  }
  return -1;
}

void DatabaseReservas::WriteFile() {
  if (this->output_stream_.is_open()) {
  for (int i{0}; i < this->reservas_.size(); i++) {
    this->reservas_[i].WriteFile(output_stream_);
  }
  output_stream_.close(); // close the file when done
  std::cout << "Fichero de Reservas sobreescrito\n";
  }
  else {
    std::cerr << "Error opening file\n";
  }
  return;
}

std::ostream& operator<<(std::ostream& os, DatabaseReservas& db) {
  os << std::endl;
  std::cout << "\033[1mRegistro de reservas:\033[0m\n\n";
  for (int i{0}; i < db.reservas_.size(); i++) {
    os << db.reservas_[i].nombre_usuario() << " " << db.reservas_[i].ejemplar()
    << " " << db.reservas_[i].fecha_caducidad().dia << "-" << 
    db.reservas_[i].fecha_caducidad().mes << "-" << db.reservas_[i].fecha_caducidad().anyo
    << std::endl;
  }
  os << std::endl;
  return os;
}