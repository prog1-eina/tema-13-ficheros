/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 26 de noviembre de 2019
 * Resumen: Ejemplo de uso de las funciones getline, con y sin delimitador 
 *          explícito.
\******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
 * Programa de ejemplo de utilización de las funciones getline, con y sin 
 * delimitador explícito.
 */
int main() {
    cout << "Escriba una línea: ";
    string lineaCompleta;
    getline(cin, lineaCompleta);
    cout << "La línea escrita era \"" << lineaCompleta << "\"." << endl;

    cout << "Escriba otra línea: ";
    string trozoDeLinea;
    getline(cin, trozoDeLinea, 'e');
    cout << "La línea escrita hasta la primera 'e' era \"" 
         << trozoDeLinea << "\"." << endl;
    getline(cin, trozoDeLinea);
    cout << "El resto de la línea era \"" 
         << trozoDeLinea << "\"." << endl;
    return 0;
}