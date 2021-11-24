/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2019
 * Resumen: Ejemplo de uso de los operadores de un «ostream».
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 3-ostream.cpp -o 3-ostream
 *       y ejecutarse en Windows a través de la orden
 *           .\3-ostream.exe
 *       o en Linux y macOS
 *           ./3-ostream
\******************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

/*
 * Programa de ejemplo de utilización de «put» y los operadores de inserción.
 */
int main() {
    char caracter = 'E';

    cout << "Escritura de caracteres con put: ";
    cout.put('a');
    cout.put(caracter);
    cout << endl;

    cout << "Escritura de caracteres con <<: ";
    cout << 'a';
    cout << caracter;
    cout << endl;

    cout << "Escritura de otros tipos de datos con <<: " << endl;
    cout << -23 << endl;                                  // int
    cout << 3.1415927 << endl;                            // double
    cout << "Cadena literal de caracteres" << endl;       // c-string
    string cadena = "Cadena de caracteres de la clase string";
    cout << cadena << endl;                               // string
    cout << boolalpha << true << ", " << false << endl;   // booleanos
    cout << noboolalpha << true << ", " << false << endl; // booleanos como ints
    return 0;
}