
  # Universidad de La Laguna
  # Escuela Superior de Ingeniería y Tecnología
  # Grado en Ingeniería Informática
  # Asignatura: Fundamentos de Ingeniería del Software (2º curso)
  # 
  # @file makefile: Fichero de compilación automática para proyectos.

# Nombre del archivo ejecutable
TARGET = library

# Compilador de C++
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11

# Archivos fuente
SOURCES = ./src/library_main.cc ./src/usuario.cc ./src/tools.cc ./src/database_usuarios.cc ./src/reserva.cc ./src/database_reservas.cc

# Archivos objeto generados durante la compilación
OBJECTS = $(SOURCES:.cc=.o)

# Reglas para la construcción del programa
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Reglas para la generación de archivos objeto
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados durante la compilación
clean:
	rm -f $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados por la compilación y limpiar terminal
clmake:
	clear
	make
	rm -f $(OBJECTS)