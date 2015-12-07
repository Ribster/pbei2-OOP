#include "band.h"

// ctor
Band::Band()
{

}

// dtor
Band::~Band(){

}

// getters
double Band::getBreedte(void){
    return _Breedte;
}

double Band::getHoogte(void){
    return _Hoogte;
}

char Band::getSnelheidsindex(void){
    return _Snelheidsindex;
}

Seizoen Band::getSeizoen(void){
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
