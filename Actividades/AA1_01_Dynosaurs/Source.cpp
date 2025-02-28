#include <string>
#include <iostream>
#include <cstdlib> 
#include <ctime>    

#include "Enemy.h"

using namespace std;

// Constante para definir el numero de dinosuartios que hay
const int MAX_DINOSAURS = 15;

int main()
{
    srand(time(nullptr)); // Inicializar la semilla para números aleatorios

    // Declaración del array estático de punteros a dinosaurios
    Dynosaur * jurassicPark[MAX_DINOSAURS] = { nullptr };

    // Inicialización de los dinosaurios en posiciones pares, asegurando que no sean iguales a i-2
    for (int i = 0; i < MAX_DINOSAURS; i += 2)
    {
        Dynosaur* newDino = nullptr;
        do
        {
            newDino = new Dynosaur(createRandomDynosaur());
        } while (i >= 2 && compareDynosaurStrength(*newDino, *jurassicPark[i - 2]));

        jurassicPark[i] = newDino;
    }

    // Mostrar información de los dinosaurios
    cout << "Dinosaurios en Jurassic Park:\n";
    for (int i = 0; i < MAX_DINOSAURS; i++)
    {
        if (jurassicPark[i] != nullptr)
        {
            cout << "Posicion " << i << ": Nombre: " << jurassicPark[i]->name
                << ", Vida: " << jurassicPark[i]->health
                << ", Ataque: " << jurassicPark[i]->attackPower << endl;
        }
        else
        {
            cout << "Posicion " << i << ": No hay dinosaurio" << endl;
        }
    }

    // Liberar memoria
    for (int i = 0; i < MAX_DINOSAURS; i++)
    {
        delete jurassicPark[i];
    }

    return 0;
}