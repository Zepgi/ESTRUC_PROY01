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

String** String::split(char pCaracterDelimitador) {
    int contador = 1;
    for (int i = 0; i < len(); i++) {
        if (cadena[i] == pCaracterDelimitador)
            contador++;
    }

    String** listaSplit = new String*[contador + 1];  // +1 para el puntero nulo al final

    int indiceInicio = 0;
    int indiceLista = 0;
    for (int i = 0; i < len(); i++) {
        if (cadena[i] == pCaracterDelimitador) {
            int splitLen = i - indiceInicio;
            char* split = new char[splitLen + 1];
            for (int j = 0; j < splitLen; j++) {
                split[j] = cadena[indiceInicio + j];
            }
            split[splitLen] = '\0';
            listaSplit[indiceLista++] = new String(split);
            delete[] split;
            indiceInicio = i + 1;
        }
    }

    int splitLen = len() - indiceInicio;
    char* splitFinal = new char[splitLen + 1];
    for (int j = 0; j < splitLen; j++) {
        splitFinal[j] = cadena[indiceInicio + j];
    }
    splitFinal[splitLen] = '\0';
    listaSplit[indiceLista] = new String(splitFinal);
    delete[] splitFinal;

    listaSplit[contador] = nullptr;  // Agregamos el puntero nulo al final

    std::cout << "Resultado split: " << listaSplit << std::endl;
    return listaSplit;
}

void String::concatenarEn(const char* pString, int pIndice) {
    if (pString == nullptr || pIndice < 0) {
        return;
    }

    int pStringLen = 0;
    while (pString[pStringLen] != '\0') {
        pStringLen++;
    }

    int newLen = len() + pStringLen;

    if (pIndice > len()) {
        pIndice = len();  // Ajustamos el índice si es mayor que la longitud actual
    }

    char* newCadena = new char[newLen + 1];  // +1 para el carácter nulo

    int i = 0;  // Índice para newData
    int j = 0;  // Índice para data (cadena original)

    // Copiamos los caracteres antes del índice deseado
    while (i < pIndice) {
        newCadena[i] = cadena[j];
        i++;
        j++;
    }

    // Copiamos la cadena a insertar
    for (int k = 0; k < pStringLen; k++) {
        newCadena[i] = pString[k];
        i++;
    }

    // Continuamos copiando los caracteres restantes de la cadena original
    while (j < len()) {
        newCadena[i] = cadena[j];
        i++;
        j++;
    }

    newCadena[newLen] = '\0';

    delete[] cadena;
    cadena = newCadena;
}

void String::concatenar(const char* CadenaNueva) {
    if (CadenaNueva == nullptr) {
        return;
    }

    int LargoOriginal = 0;
    int LargoNueva = 0;

    while (cadena[LargoOriginal] != '\0'){
        LargoOriginal++;
    }

    while (CadenaNueva[LargoNueva] != '\0'){
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

    delete[] cadena;
    cadena= CadenaResultante;
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
