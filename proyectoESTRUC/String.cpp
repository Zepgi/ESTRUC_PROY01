#include "String.hpp"
#include <stdio.h>
#include <fstream>
#include <iostream>

String::String(char* pCadena) {
    cadena = pCadena;
}

String::~String() {
    delete[] cadena;
}

char String::caracterEn(int pIndice) {
    if (pIndice < 0 || pIndice >= len())
        return '\0';  // Retorna el caracter nulo para índices inválidos
    return cadena[pIndice];
}

int String::contarCaracter(char pCaracter) {
    int contador = 0;
    for (int i = 0; i < len(); ++i) {
        if (cadena[i] == pCaracter) {
            contador++;
        }
    }
    return contador;
}

int String::ultimoIndice(char pCaracter) {
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

bool String::equals(const char* pCadena) {

    int cadenaLargo = 0;
    while (pCadena[cadenaLargo] != '\0')
        cadenaLargo++;

    if (len() != cadenaLargo)
        return false;

    for (int i = 0; i < len(); i++) {
        if (cadena[i] != pCadena[i])
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

    delete[] CadenaResultante;
    return CadenaResultante;
}

char* String::concatenarCadenas(const char* CadenaNueva[]) {
    int LargoCadena = 0;
    int LargoOriginal= 0;
    int CantidadCadenas = 0;

    while (cadena[CantidadCadenas] != '\0') {
        CantidadCadenas++;
    }


    while (cadena[LargoOriginal] != '\0') {
        LargoOriginal++;
    }
    
    LargoCadena= LargoCadena + LargoOriginal;

    for (int i = 0; i < CantidadCadenas; i++) {
        
        const char* palabra;
        palabra= CadenaNueva[i];

        int LargoPalabra = 0;
        while (palabra[LargoPalabra] != '\0') {
            LargoPalabra++;
        }
        LargoCadena= LargoCadena + LargoPalabra;
    }

    char* CadenaResultante = new char[LargoCadena + 1];

    for (int i = 0; i < LargoOriginal; i++) {
        CadenaResultante[i] = cadena[i];
    }

    for (int i = 0; i < CantidadCadenas; i++) {
        
        const char* palabra;
        palabra= CadenaNueva[i];

        int LargoPalabra = 0;
        while (palabra[LargoPalabra] != '\0') {
            LargoPalabra++;
        }

        for (int x = 0; x < LargoPalabra; x++) {
            CadenaResultante[LargoOriginal] = palabra[x];
            LargoOriginal++;
        }
    }
    delete[] CadenaResultante;
    CadenaResultante[LargoCadena] = '\0';

    return CadenaResultante;
}

void String::reemplazarEn(const char* pReemplazo, int pIndice) {
    if (pReemplazo == nullptr || pIndice < 0)
        return;

    int reemplazoLen = 0;
    while (pReemplazo[reemplazoLen] != '\0')
        reemplazoLen++;

    int newLen = len() + reemplazoLen - 1;

    char* newCadena = new char[newLen + 1];  // +1 para el carácter nulo

    int i = 0;  // Índice para newCadena
    int j = 0;  // Índice para cadena
    while (j < len()) {
        if (i == pIndice) {
            for (int k = 0; k < reemplazoLen; k++)
                newCadena[i++] = pReemplazo[k];
            j++;
        } else {
            newCadena[i++] = cadena[j++];
        }
    }

    delete[] cadena;
    cadena = newCadena;
}

void String::reemplazarOcurrencias(const char* pOcurrencia, const char* pNewTexto) {
    if (pOcurrencia == nullptr || pNewTexto == nullptr)
        return;

    int ocurrenciaLen = 0;
    while (pOcurrencia[ocurrenciaLen] != '\0')
        ocurrenciaLen++;

    int newTextoLen = 0;
    while (pNewTexto[newTextoLen] != '\0')
        newTextoLen++;

    int newCadenaLen = len();

    // Calcular la cantidad de veces que ocurre pOcurrencia en cadena
    int contador = 0;
    for (int i = 0; i < len(); i++) {
        bool coincide = true;
        for (int j = 0; j < ocurrenciaLen; j++) {
            if (cadena[i + j] != pOcurrencia[j]) {
                coincide = false;
                break;
            }
        }
        if (coincide) {
            contador++;
            i += ocurrenciaLen - 1;
        }
    }

    newCadenaLen += (newTextoLen - ocurrenciaLen) * contador;

    char* newCadena = new char[newCadenaLen + 1];  // +1 para el carácter nulo

    int i = 0;  // Índice para newCadena
    int j = 0;  // Índice para cadena
    while (j < len()) {
        bool coincide = true;
        for (int k = 0; k < ocurrenciaLen; k++) {
            if (cadena[j + k] != pOcurrencia[k]) {
                coincide = false;
                break;
            }
        }
        if (coincide) {
            for (int k = 0; k < newTextoLen; k++)
                newCadena[i++] = pNewTexto[k];
            j += ocurrenciaLen;
        } else {
            newCadena[i++] = cadena[j++];
        }
    }

    delete[] cadena;
    cadena = newCadena;
}


void String::guardarEnArchivo(const char* path, const char* mode) {
}

void String::leerArchivo(const char* path) {
}

int main() {
    String miString("Hola, soy un String.");

    // Ejemplo de uso de las funciones
    miString.cambiarCadena("Hola, ahora soy un String diferente!");
    
    char caracter = miString.caracterEn(0);
    std::cout << "Caracter en la posición 0: " << caracter << std::endl;

    int contador = miString.contarCaracter('a');
    std::cout << "Cantidad de 'a' en el String: " << contador << std::endl;

    int ultimoInd = miString.ultimoIndice('o');
    std::cout << "Última posición de 'o': " << ultimoInd << std::endl;

    int longitud = miString.len();
    std::cout << "Longitud del String: " << longitud << std::endl;

    if (miString.equals("Hola, ahora soy un String diferente!")) {
      std::cout << "Son iguales." << std::endl;
    } else {
      std::cout << "Son diferentes." << std::endl;
    }

    miString.reemplazarOcurrencias("soy", "era");

    miString.reemplazarEn(", mírame", 35);

    miString.concatenar("SIIIIII");
    
    // Imprimir el resultado final
    std::cout << "Resultado final: " << miString.cadena << std::endl;

    return 0;
}
