# Nombre del archivo ejecutable
TARGET = Prueba

# Compilador de C++
CXX = g++

# Opciones de compilación
CXXFLAGS = -std=c++11

# Archivos fuente
SOURCES = main.cc usuario.cc database.cc

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