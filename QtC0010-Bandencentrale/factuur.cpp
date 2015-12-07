#include "factuur.h"

// ctor
Factuur::Factuur()
{

}

// dtor
Factuur::~Factuur(){

}

// getters
int Factuur::getFactuurnummer(void){
    return _Factuurnummer;
}

Klant* Factuur::getKlant(void){
    return _Klant;
}

QVector<Artikel*> Factuur::getArtikels(void){
    return _Artikels;
}

double Factuur::getTotaalprijs(void){
    return _Totaalprijs;
}

double Factuur::getKorting(void){
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
