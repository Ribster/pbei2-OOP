#include "artikel.h"

// ctor
Artikel::Artikel()
{

}


// dtor
Artikel::~Artikel(){

}

// getters
QString Artikel::getNaam(void){
    return this->_Naam;
}

QString Artikel::getFabrikant(void){
    return this->_Fabrikant;
}

double Artikel::getPrijs(void){
    return this->_Prijs;
}

double Artikel::getDiameter(void){
    return this->_Diameter;
}

ArtikelType Artikel::getType(void){
    return this->_Type;
}

int Artikel::getAantal(void){
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
