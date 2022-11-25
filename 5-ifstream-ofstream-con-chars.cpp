/*********************************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 3 de diciembre de 2019
 * Resumen: Algunas funciones que trabajan con ficheros leyendo o escribiendo datos carácter a
 *          carácter con los métodos «get» y «put».
 * Nota: El programa completo está contenido en este fichero, por lo que puede compilarse y
 *       ejecutarse con la extensión Code Runner de Visual Studio Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 5-ifstream-ofstream-con-chars.cpp -o 5-ifstream-ofstream-con-chars
 *       y ejecutarse en Windows a través de la orden
 *           .\5-ifstream-ofstream-con-chars.exe
 *       o en Linux y macOS
 *           ./5-ifstream-ofstream-con-chars
\*********************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  ---
 * Post: Crea un fichero denominado "mi-primer-fichero.txt" y escribe en él las letras
 *       mayúsculas del alfabeto inglés. En caso de que se produzca un error, informa de ello
 *       escribiendo en «cerr».
 */
void crearFichero() {
    // Declaración de un flujo de datos de salida
    ofstream f;

    // Asociación del flujo «f» a un fichero externo denominado
    // "mi-primer-fichero.txt"
    f.open("mi-primer-fichero.txt");

    // Comprobación de que el flujo «f» se ha asociado correctamente
    if (f.is_open()) {

        // Escritura en el flujo «f» del contenido deseado
        for(char c = 'A'; c <= 'Z'; c++) {
            f.put(c);
        }

        // Cierre del flujo «f»: disociación del flujo con el fichero externo.
        f.close();
    }
    else {
        // El flujo «f» no se ha asociado correctamente con el fichero externo
        cerr << "No se ha podido crear el fichero \"mi-primer-fichero.txt\"" << endl;
    }
}

/*
 * Pre:  ---
 * Post: Si «nombreFichero» define el nombre de un fichero, entonces muestra su contenido en la
 *       pantalla; en caso contrario, advierte del error escribiendo un mensaje en la pantalla.
 */
void mostrar(const string nombreFichero) {
    ifstream f;                    // Declara un flujo de entrada
    f.open(nombreFichero);         // Le asocia el fichero «nombreFichero»
    if (f.is_open()) {
        char c;        
        while (f.get(c)) {
        // Mientras se leen los datos del flujo y la última lectura es correcta
            // Se procesa el último dato leído: se escribe en la pantalla 
            cout << c;
        }
        f.close();                 // Disocia el flujo y el fichero externo
    } else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  ---
 * Post: Si «nombreFichero» define el nombre de un fichero, copia su contenido en
 *       «nombreCopia»; en caso contrario o en caso de otro error, advierte del mismo
 *       escribiendo un mensaje en la pantalla.
 */
void copiar(const string nombreFichero, const string nombreCopia) {
    ifstream original;              // Declara un flujo de entrada
    original.open(nombreFichero);  // Lo asocia con el fichero «nombreFichero»
    if (original.is_open()) {
        ofstream copia;             // Declara un flujo de salida
        copia.open(nombreCopia);    // Lo asocia con el fichero «nombreCopia»
        if (copia.is_open()) {
            char c;
            while (original.get(c)) {
            // Mientras se leen los datos del flujo y la última lectura es correcta
                // Se procesa el último dato leído: se escribe en «copia» 
                copia.put(c);
            }
            copia.close();             // Disocia el flujo y el fichero externo
        }
        else {
            cerr << "No se ha podido escribir en \"" << nombreCopia << "\"." << endl;
        }
        original.close();              // Disocia el flujo y el fichero externo
    }
    else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"." << endl;
    }
}


/*
 * Programa que hace una pequeña prueba de las funciones «crearFichero», «mostrar» y «copiar».
 */
int main() {
    crearFichero();
    mostrar("mi-primer-fichero.txt");
    copiar("mi-primer-fichero.txt", "mi-segundo-fichero.txt");
    return 0;
}
