#include "bandencentrale.h"

Bandencentrale::Bandencentrale()
{

}

Bandencentrale::~Bandencentrale(){

}

// getters
QString Bandencentrale::getNaam(void){
    return _Naam;
}

Adres Bandencentrale::getAdres(void){
    return _Adres;
}

QVector<Klant*> Bandencentrale::getKlanten(void){
    return _Klanten;
}

QVector<Artikel*> Bandencentrale::getArtikels(void){
    return _Artikels;
}

// setters
void Bandencentrale::setNaam(QString newVal){
    _Naam = newVal;
}

void Bandencentrale::setAdres(Adres newVal){
    _Adres = newVal;
}

void Bandencentrale::setKlanten(QVector<Klant*> newVal){
    _Klanten = newVal;
}

void Bandencentrale::setArtikels(QVector<Artikel*> newVal){
    _Artikels = newVal;
}
