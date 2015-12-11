#include "klant.h"

// ctor
Klant::Klant(QString naam, Adres adres, double smallKorting, double bigKorting, bool verwijderd, ClientType klantentype, int klantenID):
    _Naam(naam), _Adres(adres), _Setkorting(smallKorting), _Setkorting2(bigKorting), _Bedrijf(false), _Verwijderd(verwijderd), _ClientType(klantentype), _KlantID(klantenID)
{

}

// dtor
Klant::~Klant(){

}

// getters
QString Klant::getNaam(void) const {
    return this->_Naam;
}

Adres Klant::getAdres(void) const {
    return this->_Adres;
}

double Klant::getSetKorting(void) const {
    return this->_Setkorting;
}

bool Klant::getBedrijf(void) const {
    return this->_Bedrijf;
}

double Klant::getSetkorting2(void) const {
    return this->_Setkorting2;
}

int Klant::getClientID(void) const {
    return this->_KlantID;
}

bool Klant::getDeleted(void) const{
    return this->_Verwijderd;
}

ClientType Klant::getClientType(void) const{
    return this->_ClientType;
}

// setters
void Klant::setNaam(QString newVal){
    _Naam = newVal;
}

void Klant::setAdres(Adres newVal){
    _Adres = newVal;
}

void Klant::setSetkorting(double newVal){
    _Setkorting = newVal;
}

void Klant::setBedrijf(bool newVal){
    _Bedrijf = newVal;
}

void Klant::setSetkorting2(double newVal){
    _Setkorting2 = newVal;
}

void Klant::setDeleted(bool newVal){
    _Verwijderd = newVal;
}

void Klant::setClientID(int newVal){
    this->_KlantID = newVal;
}

void Klant::print(void){
    QTextStream qtout(stdout);
    //this->_ClientType;
    qtout << "\tDetailed information about the personal client:" << endl;
    qtout << "\tID: " << this->_KlantID << endl;
    qtout << "\tName: " << this->_Naam << endl;
    this->printAddress(this->_Adres);

    qtout << "\tSet Discount on a set of 4: " << this->_Setkorting << "[%]" << endl;
    qtout << "\tSet Discount on a bulk of 10 sets: " << this->_Setkorting2 << "[%]" << endl;

    qtout << "\tClient is deleted: ";
    if(this->_Verwijderd){
        qtout << "Yes" << endl;
    } else {
        qtout << "No" << endl;
    }
}

void Klant::printAddress(Adres& pass){
    QTextStream qtout(stdout);
    qtout << "\tStreetname: " << pass.straatnaam << endl;
    qtout << "\tStreetnumber: " << pass.straatnummer << endl;
    qtout << "\tTown: " << pass.gemeente << endl;
    qtout << "\tPostal code: " << pass.postcode << endl;
    qtout << "\tCountry: " << pass.land << endl;
}
