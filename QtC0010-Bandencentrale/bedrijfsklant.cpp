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
QString Bedrijfsklant::getBTWnummer(void) const {
    return _BTWnummer;
}

bool Bedrijfsklant::getVolumekorting(void) const {
    return _Volumekorting;
}

bool Bedrijfsklant::getBedrijfskorting(void) const {
    return _Bedrijfskorting;
}

bool Bedrijfsklant::getVerwijderd(void) const {
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
    qtout << "\tDetailed information about the company client:" << endl;
    qtout << "\tID: " << this->_KlantID << endl;
    qtout << "\tName: " << this->_Naam << endl;
    this->printAddress(this->_Adres);

    qtout << "\tTAV number: " << this->_BTWnummer << endl;

    qtout << "\tSet Discount on a set of 4: " << this->_Setkorting << "%" << endl;
    qtout << "\tSet Discount on a bulk of 10 sets: " << this->_Setkorting2 << "%" << endl;
    qtout << "\tVolume discount: " << this->_Volumekorting << "%" << endl;
    qtout << "\tCompany discount: " << this->_Bedrijfskorting << "%" << endl;

    qtout << "\tClient is deleted: ";
    if(this->_Verwijderd){
        qtout << "Yes" << endl;
    } else {
        qtout << "No" << endl;
    }
}

