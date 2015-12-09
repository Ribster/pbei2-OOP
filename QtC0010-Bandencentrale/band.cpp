#include "band.h"

// ctor
Band::Band()
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

const char Band::getSnelheidsindex(void) const {
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
