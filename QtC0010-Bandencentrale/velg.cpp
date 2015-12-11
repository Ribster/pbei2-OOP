#include "velg.h"

// ctor
Velg::Velg(double breedte, Kleuren kleur, bool aluminium, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal, int artikelID):
    Artikel(naam, fabrikant, prijs, diameter, type, aantal, artikelID), _Breedte(breedte), _Kleur(kleur), _Aluminium(aluminium)
{

}

// dtor
Velg::~Velg(){

}

// getters
double Velg::getBreedte(void) const {
    return _Breedte;
}

Kleuren Velg::getKleur(void) const {
    return _Kleur;
}

bool Velg::getAluminium(void) const {
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

void Velg::print(void){
    QTextStream qtout(stdout);

    qtout << "\tDetailed information about the tire:" << endl;
    qtout << "\tID: " << this->_ArtikelID << endl;
    qtout << "\tName: " << this->_Naam << endl;
    qtout << "\tManufacturer: " << this->_Fabrikant << endl;
    qtout << "\tPrice: " << this->_Prijs << endl;
    qtout << "\tDiameter: " << this->_Diameter << endl;
    qtout << "\tAmount: " << this->_Aantal << endl;
    qtout << "\tWidth: " << this->_Breedte << endl;

    qtout << "\tColor: ";
    if(_Kleur == Kleuren_Blauw){
        qtout << "Blauw";
    } else if(_Kleur == Kleuren_Goud){
        qtout << "Goud";
    } else if(_Kleur == Kleuren_Rood){
        qtout << "Rood";
    } else {
        qtout << "Unknown";
    }
    qtout << endl;

    qtout << "\tAluminum: ";
    if(_Aluminium == true){
        qtout << "Yes";
    } else {
        qtout << "No";
    }
    qtout << endl;
}
