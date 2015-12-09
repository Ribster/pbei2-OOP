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
const QString Klant::getNaam(void) const {
    return _Naam;
}

const Adres Klant::getAdres(void) const {
    return _Adres;
}

const double Klant::getSetKorting(void) const {
    return _Setkorting;
}

const bool Klant::getBedrijf(void) const {
    return _Bedrijf;
}

const double Klant::getSetkorting2(void) const {
    return _Setkorting2;
}

const int Klant::getClientID(void) const {
    return this->_KlantID;
}

const bool Klant::getDeleted(void) const{
    return this->_Verwijderd;
}

const ClientType Klant::getClientType(void) const{
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
