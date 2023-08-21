#include "String.hpp"
#include <fstream>

String::String(const char* pCadena) {
    cadena = pCadena;
}

String::~String() {
    delete[] data;
}

char String::caracterEn(int pIndice) {
    if (pIndice < 0 || pIndice >= len())
        return '\0';  // Retorna el caracter nulo para índices inválidos
    return cadena[pIndice];
}

int String::contarCaracter(char pCaracter) const {
    int contador = 0;
    for (int i = 0; i < len(); ++i) {
        if (cadena[i] == pCaracter) {
            contador++;
        }
    }
    return contador;
}

int String::ultimoIndice(char pCaracter) const {
    for (int i = len() - 1; i >= 0; --i) {
        if (cadena[i] == pCaracter) {
            return i;
        }
    }
    return -1;
}

void String::cambiarCadena(const char* pNuevaCadena) {
    if (pNuevaCadena == nullptr)
        return;

    int nuevoLargo = 0;
    while (pNuevaCadena[nuevoLargo] != '\0')
        nuevoLargo++;

    char* nuevaCadena = new char[nuevoLargo + 1];  // +1 para el carácter nulo
    for (int i = 0; i < nuevoLargo; i++)
        nuevaCadena[i] = pNuevaCadena[i];
    nuevaCadena[nuevoLargo] = '\0';

    delete[] cadena;
    cadena = nuevaCadena;
}

int String::len() {
    int largo = 0;
    while (cadena[largo] != '\0')
        largo++;
    return largo;
}

bool String::equals(String pNuevaCadena) {

    int newCadenaLargo = 0;
    while (pNuevaCadena[newCadenaLargo] != '\0')
        newCadenaLargo++;

    if (len() != newCadenaLargo)
        return false;

    for (int i = 0; i < len(); i++) {
        if (cadena[i] != pNewCadena[i])
            return false;
    }
    
    return true;
}

String** String::split(char delimiter) const {
    // Implementar lógica para dividir el string en partes usando el delimitador
    std::vector<String*> partes;
    
    int inicio = 0;
    int fin = 0;

    while (cadena[fin] != '\0') {
        if (cadena[fin] == caracter) {
            int longitud = fin - inicio; //Obtiene la longitud
            char* subcadena = new char[longitud + 1];
            strncpy(subcadena, cadena + inicio, longitud);
            subcadena[longitud] = '\0';
            partes.push_back(new String(subcadena));
            delete[] subcadena;  // Liberar memoria de la subcadena temporal
            inicio = fin + 1;
        }
        fin++;
    }

    int longitud = fin - inicio;
    char* subcadena = new char[longitud + 1];
    strncpy(subcadena, cadena + inicio, longitud);
    subcadena[longitud] = '\0';
    partes.push_back(new String(subcadena));
    delete[] subcadena;  // Liberar memoria de la última subcadena temporal

    String** arregloPartes = new String*[partes.size() + 1];
    for (size_t i = 0; i < partes.size(); ++i) {
        arregloPartes[i] = partes[i];
    }
    arregloPartes[partes.size()] = nullptr;

    return arregloPartes;
    //return nullptr;
}

void String::concatenarEn(const char* str, int index) {
    // Implementar lógica para concatenar el string en el índice especificado
}

char* String::concatenar(const char* CadenaNueva) {
    if (CadenaNueva == nullptr) {
        return nullptr;
    }

    int LargoOriginal = 0;
    int LargoNueva = 0;

    while (cadena[LargoOriginal] != '\0') {
        LargoOriginal++;
    }

    while (CadenaNueva[LargoNueva] != '\0') {
        LargoNueva++;
    }

    int nuevoLargo = LargoOriginal+LargoNueva;

    char* CadenaResultante = new char[nuevoLargo + 1];
    for (int i = 0; i < nuevoLargo; i++) {
        if (i < LargoOriginal){
            CadenaResultante[i] = cadena[i];
        } 
        else {
            CadenaResultante[i] = CadenaNueva[i- LargoOriginal];
        } 
    }
    CadenaResultante[nuevoLargo] = '\0';

    return CadenaResultante;
}

void String::concatenarCadenas(const char** strs, int count) {
    // Implementar lógica para concatenar un arreglo de cadenas al final del string
}

void String::reemplazarEn(const char* pReemplazo, int pIndice) {
}

void String::reemplazarOcurrencias(const char* pOcurrencia, const char* pNewTexto) {
}

void String::guardarEnArchivo(const char* path, const char* mode) {
    std::ofstream file(path, mode);
    if (file.is_open()) {
        file << cadena;
        file.close();
    }
}

void String::leerArchivo(const char* path) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        cambiarCadena(content.c_str());
        file.close();
    }
}
