/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Miguel Ángel Latre
 * Última revisión: 3 de diciembre de 2019
 * Resumen: Ejemplo de uso de los operadores de extracción.
\******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/*
 * Programa de ejemplo de utilización de los operadores de extracción.
 */
int main() {
    cout << "Escriba un entero, un real, un carácter y una palabra "
         << "(separados por comas): ";
    int entero;
    double real;
    char caracter;
    string palabra;

    cin >> entero;
    cin.get(); // Nos saltamos el carácter separador ',';
    cin >> real;
    cin.get(); // Nos saltamos el carácter separador ',';
    cin >> caracter;
    cin.get(); // Nos saltamos el carácter separador ',';
    cin >> palabra;

    cout << "Los datos leídos son:" << endl;
    cout << "Entero: " << entero << endl; 
    cout << "Real: " << real << endl; 
    cout << "Carácter: '" << caracter << '\'' << endl; 
    cout << "Palabra: \"" << palabra << '\"' << endl; 

    return 0;
}