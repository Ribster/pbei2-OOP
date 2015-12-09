#include "bandencentrale.h"



using namespace std;

Bandencentrale::Bandencentrale(Adres adr, QString naam, int clientID, int workshopID):
    _Adres(adr), _Naam(naam), _maxClientID(clientID), _tireWorkshopID(workshopID)
{
    _Klanten.clear();
    _Artikels.clear();
}

Bandencentrale::~Bandencentrale(){
    // delete all the clients
    QList<Klant*>::iterator i;
    for(i = _Klanten.begin(); i != _Klanten.end(); i++){
        delete *i;
    }
}

// getters
const QString Bandencentrale::getNaam(void) const {
    return this->_Naam;
}

const Adres Bandencentrale::getAdres(void) const {
    return this->_Adres;
}

QList<Klant*> Bandencentrale::getKlanten(void){
    return this->_Klanten;
}

QList<Artikel*> Bandencentrale::getArtikels(void){
    return this->_Artikels;
}

const int Bandencentrale::getWorkshopID(void) const {
    return this->_tireWorkshopID;
}

const int Bandencentrale::getClientID(void) const {
    return this->_maxClientID;
}

// setters
void Bandencentrale::setNaam(QString newVal){
    this->_Naam = newVal;
}

void Bandencentrale::setAdres(Adres newVal){
    this->_Adres = newVal;
}

void Bandencentrale::setKlanten(QList<Klant*> newVal){
    this->_Klanten = newVal;
}

void Bandencentrale::setArtikels(QList<Artikel*> newVal){
    this->_Artikels = newVal;
}

bool Bandencentrale::addClient(Klant& ptr){
    // make a client ID if current id is zero
    if(ptr.getClientID() == 0){
        ptr.setClientID(this->getNewClientID());
    }

    // add client to client list
    this->_Klanten.append(&ptr);

    // finished correctly
    return true;
}

int Bandencentrale::getNewClientID(void){
    return ++this->_maxClientID;
}

void Bandencentrale::printClientList(void){
    QTextStream qtout(stdout);

    // return if vector is empty
    if(this->_Klanten.isEmpty()) return;

    // loop over the Vector
    QList<Klant*>::iterator i;
    for(i = _Klanten.begin(); i != _Klanten.end(); i++){
        qtout << "\t" << globals_headerLine << endl;
        if((*i)->getBedrijf()){
            // we are dealing with a company
            this->getBedrijfsklant((*i))->print();
        } else {
            // client
            (*i)->print();
        }
    }
}

// CONVERSION
Bedrijfsklant* Bandencentrale::getBedrijfsklant(Klant* ptr){
    return dynamic_cast<Bedrijfsklant*>(ptr);
}
