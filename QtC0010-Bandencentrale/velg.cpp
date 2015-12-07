#include "velg.h"

// ctor
Velg::Velg()
{

}

// dtor
Velg::~Velg(){

}

// getters
double Velg::getBreedte(void){
    return _Breedte;
}

Kleuren Velg::getKleur(void){
    return _Kleur;
}

bool Velg::getAluminium(void){
    return _Aluminium;
}

// setters
void Velg::setBreedte(double newVal){
    _Breedte = newVal;
}

void Velg::setKleur(Kleuren newVal){
    _Kleur = newVal;
}

void Velg::setAluminium(bool newVal){
    _Aluminium = newVal;
}
