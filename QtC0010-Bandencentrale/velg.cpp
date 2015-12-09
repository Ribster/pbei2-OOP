#include "velg.h"

// ctor
Velg::Velg(double breedte, Kleuren kleur, bool aluminium, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal):
    Artikel(naam, fabrikant, prijs, diameter, type, aantal), _Breedte(breedte), _Kleur(kleur), _Aluminium(aluminium)
{

}

// dtor
Velg::~Velg(){

}

// getters
const double Velg::getBreedte(void) const {
    return _Breedte;
}

const Kleuren Velg::getKleur(void) const {
    return _Kleur;
}

const bool Velg::getAluminium(void) const {
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
