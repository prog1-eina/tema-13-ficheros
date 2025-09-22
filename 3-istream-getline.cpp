/******************************************************************************
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 28 de noviembre de 2022
 * Resumen: Ejemplo de uso de las funciones getline, con y sin delimitador 
 *          explícito.
 * Nota: El programa completo está contenido en este fichero, por lo que puede
 *       compilarse y ejecutarse con la extensión Code Runner de
 *       Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 3-istream-getline.cpp -o 3-istream-getline
 *       y ejecutarse en Windows a través de la orden
 *           .\3-istream-getline.exe
 *       o en Linux y macOS
 *           ./3-istream-getline 
 *****************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
 * Programa de ejemplo que muestra cómo utilizar las funciones getline, tanto
 * con delimitador explícito como sin él, para leer líneas completas o partes
 * de una línea desde la entrada estándar.
 */
int main() {
    cout << "Escriba una línea: ";
    string lineaCompleta;
    getline(cin, lineaCompleta);
    cout << "La línea escrita era \"" << lineaCompleta << "\"." << endl;

    cout << "Escriba otra línea que contenga una arroba ('@'): ";
    string trozoDeLinea;
    getline(cin, trozoDeLinea, '@');
    cout << "La línea escrita hasta la primera arroba era \""
         << trozoDeLinea << "\"." << endl;
    getline(cin, trozoDeLinea);
    cout << "El resto de la línea era \"" << trozoDeLinea << "\"." << endl;
    
    return 0;
}