
#ifndef STRING_HPP
#define STRING_HPP

/*****Datos administrativos************************
 * Nombre del archivo: String.hpp
 * Tipo de archivo: header (.hpp)
 * Proyecto: 
 * Autor: 
 *  Eyden Su Díaz
 *  Heldyis Aguero Espinoza
 *  Mary Paz Alvarez Navarrete
 * Empresa: TEC
 *****Descripción**********************************
 * declaraciones de clase y metodos y funciones del proyecto 
 * 
 *****Versión**************************************
 * ## | Fecha y hora | Autor
 *   22 AGO 2023, 5:23
 **************************************************/

class String {

private:
    char *gpCadena;
public:
    String(char *pCadena);
    ~String();

    char caracterEn(int indice);
    int contarCaracter(char caracter);
    int ultimoIndice(char caracter);
    void cambiarCadena(const char *pNewCadena);
    int len();
    const char* obtenerCadena() const;
    bool equals(const char *pCadena);

    String** split(char caracterDelimitador);
    void concatenarEn(const char *pString, int indice);
    void concatenar(const char *pString);
    void concatenarCadenas(const char *pNuevaCadena[]);
    void reemplazarEn(const char *pReemplazo, int indice);
    void reemplazarOcurrencias(const char *pOcurrencia, const char *pReemplazo);
    void guardarEnArchivo(const char *pDireccion);
    void leerArchivo(const char *pDirección);
};

#endif
