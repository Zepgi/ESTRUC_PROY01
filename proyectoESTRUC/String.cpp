#include "String.hpp"
#include <stdio.h>
#include <fstream>
#include <iostream>

/*****Nombre***************************************
 * String
 * 
 *****Descripción**********************************
 * Constructor de la clase String que inicializa la instancia con el puntero a una cadena de caracteres existente.
 * 
 *****Retorno**************************************
 * Este constructor no retorna nada.
 * 
 *****Entradas*************************************
 * pCadena: Puntero a una cadena de caracteres que se utilizará como contenido inicial de la instancia String.
 * 
 **************************************************/

String::String(char *pCadena) {
    gpCadena = pCadena;
}

/*****Nombre***************************************
 * ~String
 * 
 *****Descripción**********************************
 * Destructor de la clase String.
 * 
 *****Retorno**************************************
 * Este destructor no retorna nada.
 * 
 *****Entradas*************************************
 * No requiere ninguna entrada.
 * 
 **************************************************/

String::~String() {
    delete[] gpCadena;
}

/*****Nombre***************************************
 * caracterEn
 * 
 *****Descripción**********************************
 * Devuelve el carácter en el índice especificado de la cadena actual.
 * 
 *****Retorno**************************************
 * Retorna el carácter en el índice dado. Si el índice es inválido (negativo o mayor/equivalente
 * al tamaño de la cadena), se devuelve el carácter nulo.
 * 
 *****Entradas*************************************
 * indice: El índice del carácter que se desea obtener de la cadena.
 * 
 **************************************************/

char String::caracterEn(int indice) {
    if (indice < 0 || indice >= len())
        return '\0';
    return gpCadena[indice];
}

/*****Nombre***************************************
 * contarCaracter
 * 
 *****Descripción**********************************
 * Cuenta y devuelve la cantidad de veces que aparece un carácter en la cadena actual.
 * 
 *****Retorno**************************************
 * Retorna el número de ocurrencias del carácter especificado en la cadena.
 * 
 *****Entradas*************************************
 * caracter: El carácter que se desea contar en la cadena.
 * 
 **************************************************/

int String::contarCaracter(char caracter) {
    int aContador = 0;
    for (int i = 0; i < len(); ++i) {
        if (gpCadena[i] == caracter) {
            aContador++;
        }
    }
    return aContador;
}

/*****Nombre***************************************
 * ultimoIndice
 * 
 *****Descripción**********************************
 * Encuentra y devuelve el último índice en el que aparece un carácter específico en la cadena actual.
 * 
 *****Retorno**************************************
 * Retorna el índice de la última ocurrencia del carácter especificado en la cadena.
 * Si el carácter no se encuentra en la cadena, se retorna -1.
 * 
 *****Entradas*************************************
 * caracter: El carácter del cual se desea encontrar el último índice en la cadena.
 * 
 **************************************************/

int String::ultimoIndice(char caracter) {
    for (int i = len() - 1; i >= 0; --i) {
        if (gpCadena[i] == caracter) {
            return i;
        }
    }
    return -1;
}

/*****Nombre***************************************
 * cambiarCadena
 * 
 *****Descripción**********************************
 * Cambia la cadena actual por una nueva cadena especificada.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pNuevaCadena: Puntero a una cadena de caracteres que se utilizará para reemplazar la cadena actual.
 * 
 **************************************************/

void String::cambiarCadena(const char *pNuevaCadena) {
    if (pNuevaCadena == nullptr)
        return;

    int aNewLargo = 0;
    while (pNuevaCadena[aNewLargo] != '\0')
        aNewLargo++;

    char *aNewCadena = new char[aNewLargo + 1];
    for (int i = 0; i < aNewLargo; i++)
        aNewCadena[i] = pNuevaCadena[i];
    aNewCadena[aNewLargo] = '\0';

    delete[] gpCadena;
    gpCadena = aNewCadena;
}


/*****Nombre***************************************
 *  obtenerCadenas()
 *****Descripción**********************************
 *  Se encarga de retornar la cadena de texto
 *****Retorno**************************************
 *  cadena de texto
 *****Entradas*************************************
 * No hay entradas
 **************************************************/
const char *String::obtenerCadena() const {
    return gpCadena;
}


/*****Nombre***************************************
 * len
 * 
 *****Descripción**********************************
 * Calcula y devuelve la longitud de la cadena actual.
 * 
 *****Retorno**************************************
 * Retorna la cantidad de caracteres en la cadena actual, sin contar el carácter nulo.
 * 
 *****Entradas*************************************
 * No se requiere entrada.
 * 
 **************************************************/

int String::len() {
    int aLargo = 0;
    while (gpCadena[aLargo] != '\0')
        aLargo++;
    return aLargo;
}

/*****Nombre***************************************
 * equals
 * 
 *****Descripción**********************************
 * Compara la cadena actual con una cadena de caracteres dada para verificar si son idénticas.
 * La cadena actual debe estar correctamente inicializada y tener contenido válido.
 * 
 *****Retorno**************************************
 * Retorna verdadero (true) si las cadenas son idénticas en contenido y longitud, o falso (false) en caso contrario.
 * 
 *****Entradas*************************************
 * pCadena: Puntero a una cadena de caracteres que se comparará con la cadena actual.
 * 
 **************************************************/

bool String::equals(const char *pCadena) {

    int aCadenaLen = 0;
    while (pCadena[aCadenaLen] != '\0')
        aCadenaLen++;

    if (len() != aCadenaLen)
        return false;

    for (int i = 0; i < len(); i++) {
        if (gpCadena[i] != pCadena[i])
            return false;
    }
    return true;
}

/*****Nombre***************************************
 * split
 * 
 *****Descripción**********************************
 * Divide la cadena actual en segmentos utilizando el carácter delimitador especificado.
 * Los segmentos resultantes se almacenan en un arreglo dinámico de objetos String.
 * 
 *****Retorno**************************************
 * Retorna un arreglo de punteros a objetos String, donde cada puntero apunta a un segmento
 * de la cadena original. El último elemento del arreglo es un puntero nulo.
 * 
 *****Entradas*************************************
 * caracterDelimitador: El carácter que se utilizará para delimitar y dividir la cadena.
 * 
 **************************************************/

String** String::split(char caracterDelimitador) {
    int aContador = 1;
    for (int i = 0; i < len(); i++) {
        if (gpCadena[i] == caracterDelimitador)
            aContador++;
    }

    String** apListaSplit = new String*[aContador + 1];

    int aIndiceInicio = 0;
    int aIndiceLista = 0;
    std::cout << "Lista de segmentos:" << std::endl;
    for (int i = 0; i <= len(); i++) {
        if (i == len() || gpCadena[i] == caracterDelimitador) {
            int aSplitLen = i - aIndiceInicio;
            char *apSplit = new char[aSplitLen + 1];
            for (int j = 0; j < aSplitLen; j++) {
                apSplit[j] = gpCadena[aIndiceInicio + j];
            }
            apSplit[aSplitLen] = '\0';

            std::cout << "- " << apSplit << std::endl;

            delete[] apSplit;
            aIndiceInicio = i + 1;
        }
    }

    apListaSplit[aContador] = nullptr;

    return apListaSplit;
}

/*****Nombre***************************************
 * concatenarEn
 * 
 *****Descripción**********************************
 * Concatena una cadena de caracteres dada en un índice específico de la cadena actual.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pString: Puntero a una cadena de caracteres que se concatenará en la cadena actual.
 * indice: Índice en el cual se insertará la cadena proporcionada. No puede ser un valor negativo.
 * 
 **************************************************/

void String::concatenarEn(const char *pString, int indice) {
    if (pString == nullptr || indice < 0) {
        return;
    }

    if (indice > len()) {
        indice %= len();
    }

    int aStringLen = 0;
    while (pString[aStringLen] != '\0') {
        aStringLen++;
    }

    int aNewLen = len() + aStringLen;

    if (indice > len()) {
        indice = len();
    }

    char *apNewCadena = new char[aNewLen + 1];

    int i = 0;
    int j = 0;

    while (i < indice) {
        apNewCadena[i] = gpCadena[j];
        i++;
        j++;
    }

    for (int k = 0; k < aStringLen; k++) {
        apNewCadena[i] = pString[k];
        i++;
    }

    while (j < len()) {
        apNewCadena[i] = gpCadena[j];
        i++;
        j++;
    }

    apNewCadena[aNewLen] = '\0';

    delete[] gpCadena;
    gpCadena = apNewCadena;
}

/*****Nombre***************************************
 * concatenar
 * 
 *****Descripción**********************************
 * Concatena una cadena de caracteres dada al final de la cadena actual.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pCadenaNueva: Puntero a una cadena de caracteres que se concatenará al final de la cadena actual.
 * 
 **************************************************/

void String::concatenar(const char *pCadenaNueva) {
    if (pCadenaNueva == nullptr) {
        return;
    }

    int aLargoOriginal = 0;
    int aLargoNueva = 0;

    while (gpCadena[aLargoOriginal] != '\0') {
        aLargoOriginal++;
    }

    while (pCadenaNueva[aLargoNueva] != '\0') {
        aLargoNueva++;
    }

    int aNuevoLargo = aLargoOriginal + aLargoNueva;

    char *apCadenaResultante = new char[aNuevoLargo + 1];
    for (int i = 0; i < aNuevoLargo; i++) {
        if (i < aLargoOriginal) {
            apCadenaResultante[i] = gpCadena[i];
        } else {
            apCadenaResultante[i] = pCadenaNueva[i- aLargoOriginal];
        }

    }
    apCadenaResultante[aNuevoLargo] = '\0';

    delete[] gpCadena;
    gpCadena= apCadenaResultante;
}

/*****Nombre***************************************
 * concatenarCadenas
 * 
 *****Descripción**********************************
 * Concatena múltiples cadenas de caracteres dadas al final de la cadena actual.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pNuevaCadena: Un arreglo de punteros a cadenas de caracteres que serán concatenadas al final
 *              de la cadena actual. El arreglo debe estar finalizado con un puntero nulo.
 * 
 **************************************************/

void String::concatenarCadenas(const char *pNuevaCadena[]) {
    int aLargoCadena = 0;
    int aLargoOriginal= 0;
    int aCantidadCadenas = 0;

    while (pNuevaCadena[aCantidadCadenas] != nullptr) {
        aCantidadCadenas++;
    }

    while (gpCadena[aLargoOriginal] != '\0') {
        aLargoOriginal++;
    }
    
    aLargoCadena = aLargoCadena + aLargoOriginal;

    for (int i = 0; i < aCantidadCadenas; i++) {
        const char *apPalabra;
        apPalabra= pNuevaCadena[i];

        int aLargoPalabra = 0;
        while (apPalabra[aLargoPalabra] != '\0') {
            aLargoPalabra++;
        }

        aLargoCadena= aLargoCadena + aLargoPalabra;

    }

    char *apCadenaResultante = new char[aLargoCadena + 1];

    for (int i = 0; i < aLargoOriginal; i++) {
        apCadenaResultante[i] = gpCadena[i];
    }

    for (int i = 0; i < aCantidadCadenas; i++) {
        const char *apPalabra;
        apPalabra= pNuevaCadena[i];

        int aLargoPalabra = 0;
        while (apPalabra[aLargoPalabra] != '\0') {
            aLargoPalabra++;
        }

        for (int x = 0; x < aLargoPalabra; x++) {
            apCadenaResultante[aLargoOriginal] = apPalabra[x];
            aLargoOriginal++;
        }

    }
    apCadenaResultante[aLargoCadena] = '\0';

    delete[] gpCadena;
    gpCadena= apCadenaResultante;
}


/*****Nombre***************************************
 * reemplazarEn
 * 
 *****Descripción**********************************
 * Reemplaza una porción de la cadena actual en un índice específico con una cadena de reemplazo dada.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pReemplazo: Puntero a una cadena de caracteres que se utilizará como reemplazo en la cadena actual.
 * pIndice: Índice donde se realizará el reemplazo. No puede ser un valor negativo.
 * 
 **************************************************/

void String::reemplazarEn(const char *pReemplazo, int indice) {
    if (pReemplazo == nullptr || indice < 0)
        return;

    if (indice > len()) {
        indice %= len();
    }

    int aReemplazoLen = 0;
    while (pReemplazo[aReemplazoLen] != '\0')
        aReemplazoLen++;

    int aNewLen = len() + aReemplazoLen - 1;

    char *apNewCadena = new char[aNewLen + 1];  

    int i = 0;
    int j = 0;
    while (j < len()) {
        if (i == indice) {
            for (int k = 0; k < aReemplazoLen; k++)
                apNewCadena[i++] = pReemplazo[k];
            j++;
        } else {
            apNewCadena[i++] = gpCadena[j++];
        }
    }

    delete[] gpCadena;
    gpCadena = apNewCadena;
}

/*****Nombre***************************************
 * reemplazarOcurrencias
 * 
 *****Descripción**********************************
 * Reemplaza todas las ocurrencias de una subcadena dada por otra subcadena en la cadena actual.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pOcurrencia: Puntero a una subcadena de caracteres que se buscará para ser reemplazada.
 * pNewTexto: Puntero a una subcadena de caracteres que se utilizará como reemplazo.
 * 
 **************************************************/

void String::reemplazarOcurrencias(const char *pOcurrencia, const char *pNewTexto) {
    if (pOcurrencia == nullptr || pNewTexto == nullptr)
        return;

    int aOcurrenciaLen = 0;
    while (pOcurrencia[aOcurrenciaLen] != '\0')
        aOcurrenciaLen++;

    int aNewTextoLen = 0;
    while (pNewTexto[aNewTextoLen] != '\0')
        aNewTextoLen++;

    int aNewCadenaLen = len();

    int aContador = 0;
    for (int i = 0; i < len(); i++) {
        bool aCoincide = true;
        for (int j = 0; j < aOcurrenciaLen; j++) {
            if (gpCadena[i + j] != pOcurrencia[j]) {
                aCoincide = false;
                break;
            }
        }
        if (aCoincide) {
            aContador++;
            i += aOcurrenciaLen - 1;
        }
    }

    aNewCadenaLen += (aNewTextoLen - aOcurrenciaLen) * aContador;

    char *apNewCadena = new char[aNewCadenaLen + 1];

    int i = 0;  // Índice para newCadena
    int j = 0;  // Índice para cadena
    while (j < len()) {
        bool aCoincide = true;
        for (int k = 0; k < aOcurrenciaLen; k++) {
            if (gpCadena[j + k] != pOcurrencia[k]) {
                aCoincide = false;
                break;
            }
        }
        if (aCoincide) {
            for (int k = 0; k < aNewTextoLen; k++)
                apNewCadena[i++] = pNewTexto[k];
            j += aOcurrenciaLen;
        } else {
            apNewCadena[i++] = gpCadena[j++];
        }
    }

    delete[] gpCadena;
    gpCadena = apNewCadena;
}

/*****Nombre***************************************
 * guardarEnArchivo
 * 
 *****Descripción**********************************
 * Guarda el contenido de la cadena actual en un archivo especificado, utilizando un modo de apertura dado.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * pDestino: Puntero a una cadena de caracteres que representa la ruta del archivo en el cual se guardará el contenido.
 * pModo: Modo de guardado del char* en el archivo. Recibirá solo dos valores, app o out.
 **************************************************/

void String::guardarEnArchivo(char* pRuta, char* pModo) {
    if (pRuta == nullptr || pModo == nullptr) {
        return;
    }

    std::ofstream archivo;
    if (std::string(pModo) == "out") {
        archivo.open(pRuta, std::ios::out);
    } else if (std::string(pModo) == "app") {
        archivo.open(pRuta, std::ios::out | std::ios::app);
    } else {
        std::cerr << "Modo de apertura no válido: " << pModo << std::endl;
        return;
    }

    if (archivo.is_open()) {
        archivo << gpCadena;
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << pRuta << std::endl;
    }
}

/*****Nombre***************************************
 * leerArchivo
 * 
 *****Descripción**********************************
 * Lee el contenido de un archivo especificado y reemplaza la cadena actual con dicho contenido.
 * 
 *****Retorno**************************************
 * No retorna nada.
 * 
 *****Entradas*************************************
 * path: Puntero a una cadena de caracteres que representa la ruta del archivo que se leerá.
 * 
 **************************************************/

void String::leerArchivo(char *pRuta) {
    if (pRuta == nullptr) {
        return;
    }

    std::ifstream archivo;
    archivo.open(pRuta);

    if (archivo.is_open()) {
        std::string content((std::istreambuf_iterator<char>(archivo)),
                            std::istreambuf_iterator<char>());
        cambiarCadena(content.c_str());
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << pRuta << std::endl;
    }
}

