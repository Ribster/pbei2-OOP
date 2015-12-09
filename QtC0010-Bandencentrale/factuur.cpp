#include "factuur.h"

// ctor
Factuur::Factuur()
{

}

// dtor
Factuur::~Factuur(){

}

// getters
const int Factuur::getFactuurnummer(void) const {
    return _Factuurnummer;
}

const Klant* Factuur::getKlant(void) const {
    return _Klant;
}

QVector<Artikel*> Factuur::getArtikels(void){
    return _Artikels;
}

const double Factuur::getTotaalprijs(void) const {
    return _Totaalprijs;
}

const double Factuur::getKorting(void) const {
    return _Korting;
}

// setters
void Factuur::setFactuurnummer(int newVal){
    _Factuurnummer = newVal;
}

void Factuur::setKlant(Klant* newVal){
    _Klant = newVal;
}

void Factuur::setArtikels(QVector<Artikel*> newVal){
    _Artikels = newVal;
}

void Factuur::setTotaalprijs(double newVal){
    _Totaalprijs = newVal;
}

void Factuur::setKorting(double newVal){
    _Korting = newVal;
}
