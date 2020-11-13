/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 22 de noviembre de 2019
 * Resumen: Algunas funciones que trabajan con ficheros leyendo o escribiendo
 *          datos carácter a carácter.
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  ---
 * Post: Ha creado un fichero denominado "miPrimerFichero.txt" y ha escrito en
 *       él las letras mayúsculas del alfabeto inglés. En caso de que se haya
 *       producido un error, ha informado de ello escribiendo en «cerr».
 */
void crearFichero() {
    // Declaración de un flujo de datos de salida
    ofstream f;

    // Asociación del flujo «f» a un fichero externo denominado
    // "miPrimerFichero.txt"
    f.open("miPrimerFichero.txt");

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
        cerr << "No se ha podido crear el fichero \"miPrimerFichero.txt\""
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
    f.open(nombreFichero);         // Le asocia el fichero «nombreFichero»
    if (f.is_open()) {
        char c = f.get();          // Intenta leer un primer carácter
        while (!f.eof()) {
        // Mientras el último intento de lectura ha sido correcto
            cout << c;             // Presenta el último carácter leído
            c = f.get();           // Intenta leer un nuevo carácter
        }
        f.close();                 // Disocia el flujo y el fichero externo
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
void mostrar2(const string nombreFichero) {
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
    ifstream fOriginal;               // Declara un flujo de entrada
    fOriginal.open (nombreFichero);   // Le asocia el fichero «nombreFichero»
    if (fOriginal.is_open()) {
        ofstream fCopia;              // Declara un flujo de salida
        fCopia.open(nombreCopia);     // Le asocia el fichero «nombreCopia»
        if (fCopia.is_open()) {
            char c = fOriginal.get();     // Intenta leer un primer carácter
            while (!fOriginal.eof()) {
            // Mientras el último intento de lectura ha sido correcto
                fCopia.put(c);            // Escribe el último carácter leído
                c = fOriginal.get();      // Intenta leer un nuevo carácter
            }
            fCopia.close();  // Disocia y libera ficheros
        }
        else {
            cerr << "No se ha podido escribir en \"" << nombreCopia << "\"."
                 << endl;
        }
        fOriginal.close();// Disocia y libera ficheros
    }
    else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"." << endl;
    }
}

/*
 * Programa que hace una pequeña prueba de las funciones «crearFichero», «mostrar»
 * y «mostrar2».
 */
int main() {
    crearFichero();
    mostrar("miPrimerFichero.txt");
    cout << endl;
    mostrar2("miPrimerFichero.txt");
    return 0;
}
