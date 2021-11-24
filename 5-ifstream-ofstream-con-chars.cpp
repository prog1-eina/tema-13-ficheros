/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 3 de diciembre de 2019
 * Resumen: Algunas funciones que trabajan con ficheros leyendo o escribiendo
 *          datos carácter a carácter con los métodos «get» y «put».
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 5-ifstream-ofstream-con-chars.cpp -o 5-ifstream-ofstream-con-chars
 *       y ejecutarse en Windows a través de la orden
 *           .\5-ifstream-ofstream-con-chars.exe
 *       o en Linux y macOS
 *           ./5-ifstream-ofstream-con-chars
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  ---
 * Post: Ha creado un fichero denominado "mi-primer-fichero.txt" y ha escrito en
 *       él las letras mayúsculas del alfabeto inglés. En caso de que se haya
 *       producido un error, ha informado de ello escribiendo en «cerr».
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
        cerr << "No se ha podido crear el fichero \"mi-primer-fichero.txt\""
             << endl;
    }
}

/*
 * Pre:  ---
 * Post: Si «nombreFichero» define el nombre de un fichero, entonces muestra su
 *       contenido por pantalla; en caso contrario advierte del error
 *       escribiendo un mensaje en la pantalla.
 */
void mostrar(const string nombreFichero) {
    ifstream f;                    // Declara un flujo de entrada
    f.open(nombreFichero);         // Lo asocia con el fichero «nombreFichero»
    if (f.is_open()) {
        // Intenta leer el primer carácter del flujo:
        char c = f.get();          

        while (!f.eof()) {
        // Mientras f.eof() devuelve «false», indica que la última 
        // operación de lectura fue correcta: hay, por lo tanto, un nuevo 
        // carácter que procesar.
            // Escribe en la pantalla el último carácter leído
            cout << c;             
            // Intenta leer un nuevo carácter para la siguiente iteración
            c = f.get();           
        }
        f.close();                 // Disocia el flujo del fichero externo
    }
    else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  ---
 * Post: Si «nombreFichero» define el nombre de un fichero, entonces muestra su
 *       contenido por pantalla; en caso contrario advierte del error
 *       escribiendo un mensaje en la pantalla.
 * Nota: Versión de la función anterior, que utiliza istream::get(char&).
 */
void mostrar_versionGetReferencia(const string nombreFichero) {
    ifstream f;                    // Declara un flujo de entrada
    f.open(nombreFichero);         // Le asocia el fichero «nombreFichero»
    if (f.is_open()) {
        char c;
        f.get(c);                  // Intenta leer un primer carácter
        while (!f.eof()) {
        // Mientras el último intento de lectura ha sido correcto
            cout << c;             // Presenta el último carácter leído
            f.get(c);              // Intenta leer un nuevo carácter
        }
        f.close();                 // Disocia el flujo y el fichero externo
    } else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"" << endl;
    }
}

/*
 * Pre:  ---
 * Post: Si «nombreFichero» define el nombre de un fichero, copia su contenido
 *       en «nombreCopia»; en caso contrario o en caso de otro error, advierte
 *       del mismo escribiendo un mensaje en la pantalla.
 */
void copiar(const string nombreFichero, const string nombreCopia) {
    ifstream original;              // Declara un flujo de entrada
    original.open(nombreFichero);  // Lo asocia con el fichero «nombreFichero»
    if (original.is_open()) {
        ofstream copia;             // Declara un flujo de salida
        copia.open(nombreCopia);    // Lo asocia con el fichero «nombreCopia»
        if (copia.is_open()) {
            char c = original.get();     // Intenta leer un primer carácter
            while (!original.eof()) {
            // Mientras el último intento de lectura ha sido correcto
                copia.put(c);            // Escribe el último carácter leído
                c = original.get();      // Intenta leer un nuevo carácter
            }
            copia.close();             // Disocia el flujo y el fichero externo
        }
        else {
            cerr << "No se ha podido escribir en \"" << nombreCopia << "\"."
                 << endl;
        }
        original.close();              // Disocia el flujo y el fichero externo
    }
    else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"." << endl;
    }
}

/*
 * Programa que hace una pequeña prueba de las funciones «crearFichero»,
 *  «mostrar» y «mostrar_versionGetReferencia».
 */
int main() {
    crearFichero();
    mostrar("mi-primer-fichero.txt");
    cout << endl;
    mostrar_versionGetReferencia("mi-primer-fichero.txt");
    return 0;
}
