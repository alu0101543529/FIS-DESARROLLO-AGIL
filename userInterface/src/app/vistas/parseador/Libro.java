package app.vistas.parseador;


public class Libro {
    private String titulo;
    private String autor;
    private int ano;
    private String genero;
    private int rating;

    public Libro(String titulo, String autor, int ano, String genero, int rating) {
        this.titulo = titulo;
        this.autor = autor;
        this.ano = ano;
        this.genero = genero;
        this.rating = rating;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAno() {
        return ano;
    }

    public String getGenero() {
        return genero;
    }

    public int getRating() {
        return rating;
    }

    @Override
    public String toString() {
        return "Libro [ano=" + ano + ", autor=" + autor + ", genero=" + genero + ", rating=" + rating + ", titulo="
                + titulo + "]";
    }

}
