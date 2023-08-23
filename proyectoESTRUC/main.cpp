#include "String.cpp"

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

    miString.reemplazarEn(", mírame", 37);

    miString.concatenar("SIIIIII");

    const char *ArrCadenas[] = {" ", "JAJAJJA ", "Vío", nullptr};
    miString.concatenarCadenas(ArrCadenas);

    miString.split('a');

    miString.concatenarEn("yolo", 70);

    // Imprimir el resultado final
    std::cout << "Resultado final: " << miString.obtenerCadena() << std::endl;

    // Guardar el contenido del String en un archivo
    miString.guardarEnArchivo("x.txt");

    std::cout << "Contenido guardado en archivo." << std::endl;

    // Leer el contenido de un archivo y actualizar el String
    miString.leerArchivo("y.txt");

    std::cout << "Contenido después de leer el archivo: " << miString.obtenerCadena() << std::endl;

    miString.concatenar(", descansen.");
    std::cout << "Contenido después de concatenar: " << miString.obtenerCadena() << std::endl;

    return 0;
}
