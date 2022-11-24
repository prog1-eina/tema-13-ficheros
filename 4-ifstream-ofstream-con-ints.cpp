/******************************************************************************\
 * Curso de Programación 1. Tema 13 (Ficheros)
 * Autores: Javier Martínez y Miguel Ángel Latre
 * Última revisión: 3 de diciembre de 2019
 * Resumen: Algunas funciones que trabajan con ficheros leyendo o escribiendo
 *          datos de tipo entero a través del operador de extracción >>.
 * Nota: El programa completo está contenido en este fichero, por lo que puede 
 *       compilarse y ejecutarse con la extensión Code Runner de Visual Studio 
 *       Code.
 *       También puede compilarse desde la terminal través de la orden
 *           g++ -Wall -Wextra 4-ifstream-ofstream-con-ints.cpp -o 4-ifstream-ofstream-con-ints
 *       y ejecutarse en Windows a través de la orden
 *           .\4-ifstream-ofstream-con-ints.exe
 *       o en Linux y macOS
 *           ./4-ifstream-ofstream-con-ints
\******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * Pre:  ---
 * Post: Crea un fichero denominado "mi-primer-fichero.txt" y escribe en
 *       él los números del 1 al 100, a razón de uno por línea. En caso de que
 *       se produzca un error, informa de ello escribiendo en «cerr».
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
        for (unsigned i = 1; i <= 100; i++) {
            f << i << endl;
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
 * Pre:  «nombreFichero» es un fichero que contiene una secuencia de números
 *       enteros, a razón de uno por línea
 * Post: Si «nombreFichero» define el nombre de un fichero, entonces muestra su
 *       contenido por pantalla, escribiendo cada entero del fichero
 *       separándolos entre sí con un espacio en blanco; en caso contrario
 *       advierte del error escribiendo un mensaje en la pantalla.
 */
void mostrar(const string nombreFichero) {
    ifstream f;                    // Declara un flujo de entrada
    f.open(nombreFichero);         // Le asocia el fichero «nombreFichero»
    if (f.is_open()) {
        int n;
        while (f >> n) {
        // Mientras se leen los datos del flujo y la última lectura es correcta
            // Se procesa el último dato leído: 
            // Escribe en la pantalla el último entero leído
            cout << n << " ";
        }
        f.close();                 // Disocia el flujo y el fichero externo
    }
    else {
        cerr << "No se ha podido acceder a \"" << nombreFichero << "\"" << endl;
    }
}


/*
 * Pre:  «nombreFichero» es un fichero que contiene una secuencia de números
 *       enteros, a razón de uno por línea.
 * Post: Si «nombreFichero» define el nombre de un fichero, copia su contenido
 *       en «nombreCopia»; en caso contrario o en caso de otro error, advierte
 *       del mismo escribiendo un mensaje en la pantalla.
 */
void copiar(const string nombreFichero, const string nombreCopia) {
    ifstream original;               // Declara un flujo de entrada
    original.open(nombreFichero);    // Le asocia el fichero «nombreFichero»
    if (original.is_open()) {
        ofstream copia;              // Declara un flujo de salida
        copia.open(nombreCopia);     // Le asocia el fichero «nombreCopia»
        if (copia.is_open()) {
            int n;            
            while (original >> n) {
            // Mientras se leen los datos del flujo y la última lectura es correcta
                // Se procesa el último dato leído: 
                // Escribe en copia el último entero leído
                copia << n << endl;      
            }
            copia.close();  // Disocia y libera ficheros
        }
        else {
            cerr << "No se ha podido escribir en \"" << nombreCopia << "\"."
                 << endl;
        }
        original.close();// Disocia y libera ficheros
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
    copiar("mi-primer-fichero.txt", "mi-segundo-fichero.txt");
    return 0;
}
