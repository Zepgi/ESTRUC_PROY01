#include "String.hpp"
#include <cstring>
#include <fstream>

String::String(const char* cadena) {
    this->cadena = new char[strlen(cadena) + 1];
    strcpy(this->cadena, cadena);
}

String::~String() {
    delete[] cadena;
}

char String::caracterEn(int index) const {
    if (index >= 0 && index < len()) {
        return cadena[index];
    }
    return '\0';
}

int String::contarCaracter(char caracter) const {
    int count = 0;
    for (int i = 0; i < len(); ++i) {
        if (cadena[i] == caracter) {
            count++;
        }
    }
    return count;
}

int String::ultimoIndice(char caracter) const {
    for (int i = len() - 1; i >= 0; --i) {
        if (cadena[i] == caracter) {
            return i;
        }
    }
    return -1;
}

void String::cambiarCadena(const char* nuevaCadena) {
    delete[] cadena;
    this->cadena = new char[strlen(nuevaCadena) + 1];
    strcpy(this->cadena, nuevaCadena);
}

int String::len() const {
    return strlen(cadena);
}

bool String::operator==(const String& other) const {
    return strcmp(cadena, other.cadena) == 0;
}

String** String::split(char caracter) const {
    // Implementar lógica para dividir el string en partes usando el delimitador
    return nullptr;
}

void String::concatenarEn(const char* str, int index) {
    // Implementar lógica para concatenar el string en el índice especificado
}

void String::concatenar(const char* str) {
    // Implementar lógica para concatenar al final del string
}

void String::concatenarCadenas(const char** cadena, int count) {
    // Implementar lógica para concatenar un arreglo de cadenas al final del string
}

void String::reemplazarEn(const char* cadena, int index) {
    // Implementar lógica para reemplazar en el índice especificado
}

void String::reemplazarOcurrencias(const char* cadenaAnterior, const char* nuevaCadena) {
    // Implementar lógica para reemplazar todas las ocurrencias de cadenaAnterior con nuevaCadena
}

void String::guardarEnArchivo(const char* path, const char* mode) const {
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
