package app.vistas.parseador;


import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Parser {
    public List<Libro> libros = new ArrayList<>();

    public Parser(String archivo) {
        try (BufferedReader br = new BufferedReader(new FileReader(archivo))) {
            String linea;
            while ((linea = br.readLine()) != null) {
                String[] partes = linea.split(" ");
                if (partes.length >= 5) {
                    String titulo = partes[0].replace("_", " ");
                    String autor = partes[1].replace("_", " ");
                    int ano = Integer.parseInt(partes[2]);
                    String genero = partes[3];
                    int rating = Integer.parseInt(partes[4]);
                    libros.add(new Libro(titulo, autor, ano, genero, rating));
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public List<Libro> parse() {
        return libros;
    }
    
}

