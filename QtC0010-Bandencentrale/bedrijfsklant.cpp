#include "bedrijfsklant.h"

// ctor
Bedrijfsklant::Bedrijfsklant(QString naam, Adres adres, double smallKorting, double bigKorting, QString btwnummer, bool volumekorting, bool bedrijfskorting, bool verwijderd):
    Klant(naam, adres, smallKorting, bigKorting, verwijderd, ClientType_Business), _BTWnummer(btwnummer), _Bedrijfskorting(bedrijfskorting), _Volumekorting(volumekorting)
{

}

// dtor
Bedrijfsklant::~Bedrijfsklant(){

}

// getters
QString Bedrijfsklant::getBTWnummer(void){
    return _BTWnummer;
}

bool Bedrijfsklant::getVolumekorting(void){
    return _Volumekorting;
}

bool Bedrijfsklant::getBedrijfskorting(void){
    return _Bedrijfskorting;
}

bool Bedrijfsklant::getVerwijderd(void){
    return _Verwijderd;
}

// setters
void Bedrijfsklant::setBTWnummer(QString newVal){
    _BTWnummer = newVal;
}

void Bedrijfsklant::setVolumekorting(bool newVal){
    _Volumekorting = newVal;
}

void Bedrijfsklant::setBedrijfskorting(bool newVal){
    _Bedrijfskorting = newVal;
}

void Bedrijfsklant::setVerwijderd(bool){

}
