/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2019
 * Resumen: Ejemplo de uso de los operadores de extracción.
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 1-istream-extraccion-espacios.cpp -o 1-istream-extraccion-espacios
 *       y ejecutarse en Windows a través de la orden
 *           .\1-istream-extraccion-espacios.exe
 *       o en Linux y macOS
 *           ./1-istream-extraccion-espacios
\******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
 * Programa de ejemplo de utilización de los operadores de extracción.
 */
int main() {
    cout << "Escriba un entero, un real, un carácter y una palabra (separados "
         << "por blancos): ";
    int entero;
    double real;
    char caracter;
    string palabra;

    cin >> entero >> real >> caracter >> palabra;

    cout << "Los datos leídos son:" << endl;
    cout << "Entero: " << entero << endl; 
    cout << "Real: " << real << endl; 
    cout << "Carácter: '" << caracter << '\'' << endl; 
    cout << "Palabra: \"" << palabra << '\"' << endl; 

    return 0;
}