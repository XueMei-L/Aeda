// includes
#include <iostream>
#include <vector>

#include "../include/sort.h"

// tipo generico
using Key = int;

// programa principal
int main(int argc, char *argv[]) {
    std::cout << "----------------Bienvenido al programa de ordenacion---------------" << std::endl;
    
    // Preguntar el tañamo de la secuencia
    int nSeq;
    std::cout << ">>> Introduzca el tamaño de la secuencia:";
    std::cin >> nSeq;

    // Introducir los values de la secuencia
    std::vector<Key> sequence;
    Key value;
    for(int i = 0; i < nSeq; i++) {
        bool stop = true;
        while(stop) {
            std::cout << ">>> Introduzca [" << i+1 << "] valor de secuancias:";
            std::cin >> value;
            if( value > 1000 && value < 9999) {
                sequence.push_back(value);
                stop = false;
            } else {
                std::cout << "No es un numero valido, vuelva a introducir.\n";
            }
        }
    }

    // Numero de algoritmo seleccionado
    int selectAlgorithm;

    // Crear puntero de la clase abstracta Ordenacion
    Ordenacion<Key>* ptr_orden;

    // Crear puntero de la clase ("Contexto") Sort
    Sort<Key>* ptr_sort;
    ptr_sort = new Sort<Key>(sequence, nSeq);

    bool stop = false;
    while (!stop)
    {
        std::cout << "\n>>> Elijas un algoritmo de ordenacion:" 
                << "\n>>> 1. Seleccion"
                << "\n>>> 2. QuickSort"
                << "\n>>> 3. ShellSort"
                << "\n>>> 4. HeapSort"
                << "\n>>> 5. RadixSort"
                << "\nTu seleccion es:"; 
        std::cin >> selectAlgorithm;
        std::cout << ">>> Has elegido el algoritmo:" << selectAlgorithm;

        switch (selectAlgorithm)
        {
        case 1:
            ptr_orden = new Seleccion<Key>();
            break;
        case 2:
            ptr_orden = new QuickSort<Key>();
            break;
        case 3:
            // ptr_orden = new HeapSort<Key>();
            break;
        case 4:
            ptr_orden = new HeapSort<Key>();
            break;
        case 5:
            // ptr_orden = new HeapSort<Key>();
            break;
        default:
            std::cout << "No es una opción valida, vuelva a ejecutar el programa." << std::endl;
            break;
        }
        ptr_sort->SetMethod(ptr_orden);

        std::string sortAgain;
        std::cout << "Deseas ordenar con otro algoritmo?(y/n)";
        std::cin >> sortAgain;
        if(sortAgain == "y" || sortAgain == "Y") {
            stop = false;
        } else {
            stop = true;
        }
    }
    
    delete ptr_orden;
    delete ptr_sort;

    std::cout << "\n----------------Terminando el programa---------------" << std::endl;
    return 0;
}