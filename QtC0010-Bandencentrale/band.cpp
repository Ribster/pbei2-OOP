#include "band.h"

// ctor
Band::Band(double breedte, double hoogte, QChar snelheidsindex, Seizoen seizoen, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal, int artikelID, bool verwijderd):
    Artikel(naam, fabrikant, prijs, diameter, type, aantal, artikelID, verwijderd), _Breedte(breedte), _Hoogte(hoogte), _Snelheidsindex(snelheidsindex), _Seizoen(seizoen)
{

}

// dtor
Band::~Band(){

}

// getters
double Band::getBreedte(void) const {
    return _Breedte;
}

double Band::getHoogte(void) const {
    return _Hoogte;
}

QChar Band::getSnelheidsindex(void) const {
    return _Snelheidsindex;
}

Seizoen Band::getSeizoen(void) const {
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

void Band::print(void){
    QTextStream qtout(stdout);
    qtout << "\tDetailed information about the tire:" << endl;
    qtout << "\tID: " << this->_ArtikelID << endl;
    qtout << "\tName: " << this->_Naam << endl;
    qtout << "\tManufacturer: " << this->_Fabrikant << endl;
    qtout << "\tPrice: " << this->_Prijs << endl;
    qtout << "\tDiameter: " << this->_Diameter << endl;
    qtout << "\tAmount: " << this->_Aantal << endl;
    qtout << "\tWidth: " << this->_Breedte << endl;
    qtout << "\tHeigth: " << this->_Hoogte << endl;
    qtout << "\tSpeed Index: " << this->_Snelheidsindex << endl;

    qtout << "\tSeason: ";
    if(_Seizoen == Seizoen_Winter){
        qtout << "Winter";
    } else {
        qtout << "Zomer";
    }
    qtout << endl;

}
