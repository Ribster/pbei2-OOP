#include "klant.h"

// ctor
Klant::Klant()
{

}

// dtor
Klant::~Klant(){

}

// getters
QString Klant::getNaam(void){
    return _Naam;
}

Adres Klant::getAdres(void){
    return _Adres;
}

double Klant::getSetKorting(void){
    return _Setkorting;
}

bool Klant::getBedrijf(void){
    return _Bedrijf;
}

double Klant::getSetkorting2(void){
    return _Setkorting2;
}

// setters
void Klant::setNaam(QString newVal){
    _Naam = newVal;
}

void Klant::setAdres(Adres newVal){
    _Adres = newVal;
}

void Klant::setSetkorting(double newVal){
    _Setkorting = newVal;
}

void Klant::setBedrijf(bool newVal){
    _Bedrijf = newVal;
}

void Klant::setSetkorting2(double newVal){
    _Setkorting2 = newVal;
}
