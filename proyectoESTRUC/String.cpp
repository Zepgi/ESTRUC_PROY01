#include "String.hpp"
#include <cstring>
#include <fstream>

String::String(const char* str) {
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

String::~String() {
    delete[] data;
}

char String::caracterEn(int index) const {
    if (index >= 0 && index < len()) {
        return data[index];
    }
    return '\0';
}

int String::contarCaracter(char c) const {
    int count = 0;
    for (int i = 0; i < len(); ++i) {
        if (data[i] == c) {
            count++;
        }
    }
    return count;
}

int String::ultimoIndice(char c) const {
    for (int i = len() - 1; i >= 0; --i) {
        if (data[i] == c) {
            return i;
        }
    }
    return -1;
}

void String::cambiarCadena(const char* str) {
    delete[] data;
    data = new char[strlen(str) + 1];
    strcpy(data, str);
}

int String::len() const {
    return strlen(data);
}

bool String::operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
}

String** String::split(char delimiter) const {
    // Implementar lógica para dividir el string en partes usando el delimitador
    return nullptr;
}

void String::concatenarEn(const char* str, int index) {
    // Implementar lógica para concatenar el string en el índice especificado
}

void String::concatenar(const char* str) {
    // Implementar lógica para concatenar al final del string
}

void String::concatenarCadenas(const char** strs, int count) {
    // Implementar lógica para concatenar un arreglo de cadenas al final del string
}

void String::reemplazarEn(const char* str, int index) {
    // Implementar lógica para reemplazar en el índice especificado
}

void String::reemplazarOcurrencias(const char* oldStr, const char* newStr) {
    // Implementar lógica para reemplazar todas las ocurrencias de oldStr con newStr
}

void String::guardarEnArchivo(const char* path, const char* mode) const {
    std::ofstream file(path, mode);
    if (file.is_open()) {
        file << data;
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
