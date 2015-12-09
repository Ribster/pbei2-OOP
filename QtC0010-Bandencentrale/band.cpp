#include "band.h"

// ctor
Band::Band(double breedte, double hoogte, QChar snelheidsindex, Seizoen seizoen, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal):
    Artikel(naam, fabrikant, prijs, diameter, type, aantal), _Breedte(breedte), _Hoogte(hoogte), _Snelheidsindex(snelheidsindex), _Seizoen(seizoen)
{

}

// dtor
Band::~Band(){

}

// getters
const double Band::getBreedte(void) const {
    return _Breedte;
}

const double Band::getHoogte(void) const {
    return _Hoogte;
}

const QChar Band::getSnelheidsindex(void) const {
    return _Snelheidsindex;
}

const Seizoen Band::getSeizoen(void) const {
    return _Seizoen;
}

// setters
void Band::setBreedte(double newVal){
    _Breedte = newVal;
}

void Band::setHoogte(double newVal){
    _Hoogte = newVal;
}

void Band::setSnelheidsindex(char newVal){
    _Snelheidsindex = newVal;
}

void Band::setSeizoen(Seizoen newVal){
    _Seizoen = newVal;
}
