#include "artikel.h"

// ctor
Artikel::Artikel(QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal):
    _Naam(naam), _Fabrikant(fabrikant), _Prijs(prijs), _Diameter(diameter), _Type(type), _Aantal(aantal)
{

}


// dtor
Artikel::~Artikel(){

}

// getters
const QString Artikel::getNaam(void) const {
    return this->_Naam;
}

const QString Artikel::getFabrikant(void) const {
    return this->_Fabrikant;
}

const double Artikel::getPrijs(void) const {
    return this->_Prijs;
}

const double Artikel::getDiameter(void) const {
    return this->_Diameter;
}

const ArtikelType Artikel::getType(void) const {
    return this->_Type;
}

const int Artikel::getAantal(void) const {
    return this->_Aantal;
}

// setters
void Artikel::setNaam(QString newVal){
    this->_Naam = newVal;
}

void Artikel::setFabrikant(QString newVal){
    this->_Fabrikant = newVal;
}

void Artikel::setPrijs(double newVal){
    this->_Prijs = newVal;
}

void Artikel::setDiameter(double newVal){
    this->_Diameter = newVal;
}

void Artikel::setType(ArtikelType newVal){
    this->_Type = newVal;
}

void Artikel::setAantal(int newVal){
    this->_Aantal = newVal;
}
