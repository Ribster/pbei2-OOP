#include "factuur.h"

// ctor
Factuur::Factuur(int factuurnummer, int klant, QMap<int, int> artikelcount, double totaalprijs, double korting):
    _Factuurnummer(factuurnummer), _Klant(klant), _ArtikelCount(artikelcount), _Totaalprijs(totaalprijs), _Korting(korting)
{

}

// dtor
Factuur::~Factuur(){

}

// getters
int Factuur::getFactuurnummer(void) const {
    return _Factuurnummer;
}

int Factuur::getKlant(void) const {
    return _Klant;
}

QMap<int, int> Factuur::getArtikels(void) const{
    return _ArtikelCount;
}

double Factuur::getTotaalprijs(void) const {
    return _Totaalprijs;
}

double Factuur::getKorting(void) const {
    return _Korting;
}

// setters
void Factuur::setFactuurnummer(int newVal){
    _Factuurnummer = newVal;
}

void Factuur::setKlant(int newVal){
    _Klant = newVal;
}

void Factuur::setArtikels(QMap<int,int> newVal){
    _ArtikelCount = newVal;
}

void Factuur::setTotaalprijs(double newVal){
    _Totaalprijs = newVal;
}

void Factuur::setKorting(double newVal){
    _Korting = newVal;
}
