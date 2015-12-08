#include "bedrijfsklant.h"

// ctor
Bedrijfsklant::Bedrijfsklant(QString naam, Adres adres, double smallKorting, double bigKorting, QString btwnummer, double volumekorting, double bedrijfskorting, bool verwijderd, int klantenID):
    Klant(naam, adres, smallKorting, bigKorting, verwijderd, ClientType_Business, klantenID), _BTWnummer(btwnummer), _Bedrijfskorting(bedrijfskorting), _Volumekorting(volumekorting)
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
    this->_BTWnummer = newVal;
}

void Bedrijfsklant::setVolumekorting(bool newVal){
    this->_Volumekorting = newVal;
}

void Bedrijfsklant::setBedrijfskorting(bool newVal){
    this->_Bedrijfskorting = newVal;
}

void Bedrijfsklant::setVerwijderd(bool newVal){
    this->_Verwijderd = newVal;
}

void Bedrijfsklant::print(void){
    QTextStream qtout(stdout);
    //this->_ClientType;
    qtout << "Detailed information about the company client:" << endl;
    qtout << "ID: " << this->_KlantID << endl;
    qtout << "Name: " << this->_Naam << endl;
    this->printAddress(this->_Adres);

    qtout << "TAV number: " << this->_BTWnummer << endl;

    qtout << "Set Discount on a set of 4: " << this->_Setkorting << "%" << endl;
    qtout << "Set Discount on a bulk of 10 sets: " << this->_Setkorting2 << "%" << endl;
    qtout << "Volume discount: " << this->_Volumekorting << "%" << endl;
    qtout << "Company discount: " << this->_Bedrijfskorting << "%" << endl;

    qtout << "Client is deleted: ";
    if(this->_Verwijderd){
        qtout << "Yes" << endl;
    } else {
        qtout << "No" << endl;
    }
}

