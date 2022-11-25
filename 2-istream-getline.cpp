/*********************************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2019
 * Resumen: Ejemplo de uso de las funciones getline, con y sin delimitador 
 *          explícito.
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 2-istream-getline.cpp -o 2-istream-getline
 *       y ejecutarse en Windows a través de la orden
 *           .\2-istream-getline.exe
 *       o en Linux y macOS
 *           ./2-istream-getline 
\*********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/*
 * Programa de ejemplo de utilización de las funciones getline, con y sin delimitador
 * explícito.
 */
int main() {
    cout << "Escriba una línea: ";
    string lineaCompleta;
    getline(cin, lineaCompleta);
    cout << "La línea escrita era \"" << lineaCompleta << "\"." << endl;

    cout << "Escriba otra línea que contenga una 'e' minúscula: ";
    string trozoDeLinea;
    getline(cin, trozoDeLinea, 'e');
    cout << "La línea escrita hasta la primera 'e' era \"" << trozoDeLinea << "\"." << endl;
    getline(cin, trozoDeLinea);
    cout << "El resto de la línea era \"" << trozoDeLinea << "\"." << endl;
    
    return 0;
}