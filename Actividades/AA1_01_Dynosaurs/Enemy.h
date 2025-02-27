#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include <iostream>
#include <cstdlib> 
#include <ctime>    

using namespace std;

// Definición del tipo de dato DynosaurType
enum class DynosaurType {
    TYRANNOSAURUS,
    VELOCIRAPTOR,
    BRACHIOSAURUS,
    DIPLODOCUS
};
// Función getDynosaurTypeToString que devuelve como un String el tipo de dinosaurio del que pasamos por parámetro
string getDynosaurTypeToString( DynosaurType type) {

    if (type == DynosaurType::TYRANNOSAURUS)
    {
        return "TYRANNOSAURUS";
    } else if (type == DynosaurType::VELOCIRAPTOR)
    {
        return "VELOCIRAPTOR";
    }
    else if (type == DynosaurType::BRACHIOSAURUS)
    {
        return "BRACHIOSAURUS";
    }
    else if (type == DynosaurType::DIPLODOCUS)
    {
        return "DIPLODOCUS";
    }
    else
    {
        return "UNKNOW";

    }

}

// Struct de dinosaurio
struct Dynosaur {
    //DynosaurType type;
    string name;
    int health = 100;
    int attackPower;
};

// Función compareDynosaurStrength que devuelve true si los dos dinosaurios que se pasan por parámetro tienen la misma fuerza (fuerza = vida + ataque)
bool compareDynosaurStrength(Dynosaur dyno1, Dynosaur dyno2) {

    // Calcular la fuerza de ambos
    int strength1, strength2;

    strength1 = dyno1.attackPower + dyno1.health;
    strength2 = dyno2.attackPower + dyno2.health;

    if (strength1 == strength2)
    {
        return true;
    }
    else
    {
        return false;
    }

}

Dynosaur createRandomDynosaur() {

    // cCreamos el dinosaurio
    Dynosaur randomDynosuar;

    int randomValue = rand() % 4;  // Genera un número entre 0 y 3 para definir que dinosaurio será

    // Inicializamos el dinosaurio dependiendo del tipo
    if (randomValue == 0) { // Si sale 0 es TYRANNOSAURUS
        randomDynosuar.name = "TYRANNOSAURUS";
        randomDynosuar.attackPower = 100;
    }
    else if (randomValue == 1) { // Si sale 1 es VELOCIRAPTOR
        randomDynosuar.name = "VELOCIRAPTOR";
        randomDynosuar.attackPower = 80;
    }
    else if (randomValue == 2) { // Si sale 2 es BRACHIOSAURUS
        randomDynosuar.name = "BRACHIOSAURUS";
        randomDynosuar.attackPower = 65;
    }
    else { // Si sale 3, es decir ELSE, es DIPLODOCUS
        randomDynosuar.name = "DIPLODOCUS";
        randomDynosuar.attackPower = 45;
    }

    // Devolvemos el dinosaurio inicializado
    return randomDynosuar;

}

#endif
