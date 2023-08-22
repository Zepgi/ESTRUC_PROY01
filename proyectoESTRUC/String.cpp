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

String::String(char* pCadena) {
    cadena = pCadena;
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
    delete[] cadena;
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
 * pIndice: El índice del carácter que se desea obtener de la cadena.
 * 
 **************************************************/

char String::caracterEn(int pIndice) {
    if (pIndice < 0 || pIndice >= len())
        return '\0';  // Retorna el caracter nulo para índices inválidos
    return cadena[pIndice];
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
 * pCaracter: El carácter que se desea contar en la cadena.
 * 
 **************************************************/

int String::contarCaracter(char pCaracter) {
    int contador = 0;
    for (int i = 0; i < len(); ++i) {
        if (cadena[i] == pCaracter) {
            contador++;
        }
    }
    return contador;
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
 * pCaracter: El carácter del cual se desea encontrar el último índice en la cadena.
 * 
 **************************************************/

int String::ultimoIndice(char pCaracter) {
    for (int i = len() - 1; i >= 0; --i) {
        if (cadena[i] == pCaracter) {
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
    int largo = 0;
    while (cadena[largo] != '\0')
        largo++;
    return largo;
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
 * pCaracterDelimitador: El carácter que se utilizará para delimitar y dividir la cadena.
 * 
 **************************************************/

String** String::split(char pCaracterDelimitador) {
    int contador = 1;
    for (int i = 0; i < len(); i++) {
        if (cadena[i] == pCaracterDelimitador)
            contador++;
    }

    String** listaSplit = new String*[contador + 1];  // +1 para el puntero nulo al final

    int indiceInicio = 0;
    int indiceLista = 0;
    std::cout << "Lista de segmentos:" << std::endl;
    for (int i = 0; i <= len(); i++) {  // <= aquí para procesar el último segmento
        if (i == len() || cadena[i] == pCaracterDelimitador) {
            int splitLen = i - indiceInicio;
            char* split = new char[splitLen + 1];
            for (int j = 0; j < splitLen; j++) {
                split[j] = cadena[indiceInicio + j];
            }
            split[splitLen] = '\0';

            std::cout << "- " << split << std::endl;

            delete[] split;
            indiceInicio = i + 1;
        }
    }

    listaSplit[contador] = nullptr;  // Agregamos el puntero nulo al final

    // Liberar memoria de los objetos String y el arreglo de punteros
    for (int i = 0; listaSplit[i] != nullptr; i++) {
        delete listaSplit[i];
    }
    delete[] listaSplit; //Libera la memoria

    return nullptr;  // Returna null de ser necesario
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
 * pIndice: Índice en el cual se insertará la cadena proporcionada. No puede ser un valor negativo.
 * 
 **************************************************/

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
    }//fin if (pCadena == nullptr)

    int largo_original = 0;
    int largo_nueva = 0;

    while (cadena[largo_original] != '\0') {
        largo_original++;
    }//fin while(cadena[larho_original] != '\0')

    while (pCadenaNueva[largo_nueva] != '\0') {
        largo_nueva++;
    }//fin while(pCadena[largo_nueva] != '\0')

    int nuevo_largo = largo_original+largo_nueva;

    char* pCadenaResultante = new char[nuevo_largo + 1];
    for (int i = 0; i < nuevo_largo; i++) {
        if (i < largo_original) {
            pCadenaResultante[i] = cadena[i];
        } else {
            pCadenaResultante[i] = pCadenaNueva[i- largo_original];
        }//if (i < largo_original)

    }// fin for (int i = 0; i < nuevo_largo; i++)
    pCadenaResultante[nuevo_largo] = '\0';

    delete[] cadena;
    cadena= pCadenaResultante;
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
    int largo_cadena = 0;
    int largo_original= 0;
    int cantidad_cadenas = 0;

    while (pNuevaCadena[cantidad_cadenas] != nullptr) {
        cantidad_cadenas++;
    }//fin while (pNuevaCadena[cantidad_cadenas] != nullptr)

    while (cadena[largo_original] != '\0') {
        largo_original++;
    }//fin while (cadena[largo_original] != '\0')
    
    largo_cadena= largo_cadena + largo_original;

    for (int i = 0; i < cantidad_cadenas; i++) {
        const char *pPalabra;
        pPalabra= pNuevaCadena[i];

        int largo_palabra = 0;
        while (pPalabra[largo_palabra] != '\0') {
            largo_palabra++;
        }//fin while (pPalabra[largo_palabra] != '\0')

        largo_cadena= largo_cadena + largo_palabra;

    }//fin for (int i = 0; i < cantidad_cadenas; i++)

    char *pCadenaResultante = new char[largo_cadena + 1];

    for (int i = 0; i < largo_original; i++) {
        pCadenaResultante[i] = cadena[i];
    }// fin for (int i = 0; i < largo_original; i++)

    for (int i = 0; i < cantidad_cadenas; i++) {
        const char *pPalabra;
        pPalabra= pNuevaCadena[i];

        int largo_palabra = 0;
        while (pPalabra[largo_palabra] != '\0') {
            largo_palabra++;
        }//fin while (pPalabra[largo_palabra] != '\0')

        for (int x = 0; x < largo_palabra; x++) {
            pCadenaResultante[largo_original] = pPalabra[x];
            largo_original++;
        }//fin for (int x = 0; x < largo_palabra; x++)

    }//fin for (int i = 0; i < cantidad_cadenas; i++)
    pCadenaResultante[largo_cadena] = '\0';

    delete[] cadena;
    cadena= pCadenaResultante;
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
 * path: Puntero a una cadena de caracteres que representa la ruta del archivo en el cual se guardará el contenido.
 * mode: Puntero a una cadena de caracteres que representa el modo de apertura del archivo.
 * 
 **************************************************/

void String::guardarEnArchivo(const char* path, const char* mode) {
    if (path == nullptr || mode == nullptr) {
        return;
    }

    std::ofstream file;
    file.open(path, std::ios::out | std::ios::app);  // Modo de apertura

    if (file.is_open()) {
        file << cadena;
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << path << std::endl;
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

void String::leerArchivo(const char* path) {
    if (path == nullptr) {
        return;
    }

    std::ifstream file;
    file.open(path);  // Modo de apertura por defecto es std::ios::in

    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
        cambiarCadena(content.c_str());
        file.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << path << std::endl;
    }
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

    const char *ArrCadenas[] = {" ", "JAJAJJA ", "Vío", nullptr};
    miString.concatenarCadenas(ArrCadenas);

    miString.split('a');

    miString.concatenarEn("yolo", 1);

    // Imprimir el resultado final
    std::cout << "Resultado final: " << miString.obtenerCadena() << std::endl;

    // Guardar el contenido del String en un archivo
    miString.guardarEnArchivo("x.txt", "w");

    std::cout << "Contenido guardado en archivo." << std::endl;

    // Leer el contenido de un archivo y actualizar el String
    miString.leerArchivo("y.txt");

    std::cout << "Contenido después de leer el archivo: " << miString.obtenerCadena() << std::endl;


    return 0;
}
