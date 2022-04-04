// Cabecera

// includes
#include <iostream>
#include "../include/dispersionFunction.h"
#include "../include/explorationFunction.h"

#include "../include/fdModule.h"
#include "../include/fdSum.h"
#include "../include/fdPseudoaleatorio.h"

#include "../include/feLineal.h"
#include "../include/feCuadratica.h"
#include "../include/feDoble.h"
#include "../include/feReDispersion.h"

#include "../include/HashTabla.h"

using Key = long;

// programa principal
int main(int argc, char *argv[]) {

    // Preguntar el tañamo de la tabla
    int nTable;
    std::cout << "Introduzca el tamaño de la tabla:";
    std::cin >> nTable;

    // Preguntar que tipo de funcion dispersion desea
    int typeFuncDispersion;
    std::cout << "Elijas una funcion de dispersion:" 
              << "\n1. Modulo"
              << "\n2. Basada en la suma"
              << "\n3. Pseudoaleatorio"
              << "\nTu elección es:"; 
    std::cin >> typeFuncDispersion;

    DispersionFunction<Key>* ptr_fd;

    switch (typeFuncDispersion)
    {
    case 1:
        ptr_fd = new fdModule<Key>(nTable);
        break;
    case 2:
        ptr_fd = new fdSum<Key>(nTable);
        break;
    case 3:
        ptr_fd = new fdPseudorandom<Key>(nTable);
        break;
    default:
        std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
        break;
    }
        
    int techniqueDispersion;
    std::cout << "Qué tecnica de dispersion desea:"
              << "\n1. Dispersion abierta"
              << "\n2. Dispersion cerrada"
              << "\nTu elección es:"; 
    std::cin >> techniqueDispersion;

    switch (techniqueDispersion)
    {
    case 1: 
    {
        HashTable<Key>* ptr_hashtabla = new HashTable<Key>(nTable, ptr_fd);
    }
    break;

    case 2: {

        int funcExploracion;
        std::cout << "Qué tecnica de dispersion desea:"
                << "\n1. Exploración Lineal"
                << "\n2. Exploración Cuadratica"
                << "\n3. Doble exploración"
                << "\n4. Exploración Redispersion"
                << "\nTu elección es:"; 
        std::cin >> funcExploracion;

        int blockSize;
        std::cout << "Qué tamaño de bloque deseas:";
        std::cin >> blockSize;       

        ExplorationFunction<Key>* ptr_fe;

        switch (funcExploracion)
            {
            case 1:
                {
                    ptr_fe = new feLineal<Key>();
                }
                break;
            case 2:
                {
                    ptr_fe = new feCuadratica<Key>();
                }
                break;
            case 3:
                {
                    ptr_fe = new feDoble<Key>(blockSize);
                }
                break;
            case 4:
                {
                    ptr_fe = new feRedispersion<Key>(blockSize);
                }
            default:
                std::cout << "No es una opcion correcta, vuelva a indicar" << std::endl;
                break;
            }
            HashTable<Key>* ptr_hashtabla = new HashTable<Key>(nTable, ptr_fd, ptr_fe, blockSize);

            // default:
            //     std::cout << "No es una opcion correcta, vuelva a indicar" << std::endl;
            // break;
        }
        break;
    }

    return 0;
}