#ifndef STRING_HPP
#define STRING_HPP

class String {
public:
    // Constructor y Destructor
    String(const char* str);
    ~String();

    // Métodos
    char caracterEn(int index) const;
    int contarCaracter(char caracter) const;
    int ultimoIndice(char caracter) const;
    void cambiarCadena(const char* nuevaCadena);
    int len() const;
    bool operator==(const String& other) const;
    String** split(char caracter) const;
    void concatenarEn(const char* str, int index);
    void concatenar(const char* str);
    void concatenarCadenas(const char** cadena, int count);
    void reemplazarEn(const char* cadena, int index);
    void reemplazarOcurrencias(const char* cadenaAnterior, const char* nuevaCadena);
    void guardarEnArchivo(const char* path, const char* mode) const;
    void leerArchivo(const char* path);

private:
    char* cadena;
};

#endif // STRING_HPP
