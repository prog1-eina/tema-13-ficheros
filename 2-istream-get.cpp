/******************************************************************************
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Ricardo J. Rodríguez
 * Última revisión: 25 de noviembre de 2022
 * Resumen: Ejemplo de uso del método get.
 * Nota: El programa completo está contenido en este fichero, por lo que puede
 *       compilarse y ejecutarse con la extensión Code Runner de
 *       Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 2-istream-get.cpp -o 2-istream-get
 *       y ejecutarse en Windows a través de la orden
 *           .\2-istream-get.exe
 *       o en Linux y macOS
 *           ./2-istream-get 
 *****************************************************************************/

#include <iostream>
using namespace std;

const char FIN = '.';

/*
 * Lee caracteres de la entrada estándar hasta reconocer el carácter FIN.
 * Muestra al usuario cada carácter leído y el número total de caracteres
 * leídos hasta encontrar el carácter FIN.
 */
int main() {
    unsigned numVeces = 0;
    char c;
	cout << "No voy a parar hasta que introduzcas el carácter '" << FIN << "': ";
	
    do{
		cin.get(c);
		cout << "Carácter leído: '" << c << "'" << endl;
		numVeces++;
	} while (c != FIN);

	cout << "Número de caracteres leídos hasta '" << FIN << "': ";
	cout << numVeces;
	
	return 0;
}
