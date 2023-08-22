#ifndef STRING_HPP
#define STRING_HPP

class String {
public:
    String(char* pCadena);  // Constructor
    ~String();  // Destructor

    char caracterEn(int pIndice);
    int contarCaracter(char pCaracter);
    int ultimoIndice(char pCaracter);
    void cambiarCadena(const char* pNewCadena);
    int len();
    const char* obtenerCadena() const;
    bool equals(const char* pCadena);

    String** split(char pDelimitador);
    void concatenarEn(const char* pString, int pIndice);
    void concatenar(const char* pString);
    void concatenarCadenas(const char** strArray);
    void reemplazarEn(const char* pReemplazo, int pIndice);
    void reemplazarOcurrencias(const char* pOcurrencia, const char* pReemplazo);
    void guardarEnArchivo(const char* path, const char* mode);
    void leerArchivo(const char* path);

private:
    char* cadena;  // Actual character array
};

#endif

