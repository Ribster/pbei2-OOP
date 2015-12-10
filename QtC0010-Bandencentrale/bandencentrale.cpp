#include "bandencentrale.h"



using namespace std;

Bandencentrale::Bandencentrale(){
    // default constructor
}

Bandencentrale::Bandencentrale(Adres adr, QString naam, int clientID, int workshopID):
    _Naam(naam), _Adres(adr), _maxClientID(clientID), _tireWorkshopID(workshopID)
{

}

Bandencentrale::~Bandencentrale(){
    // delete all the clients
    QList<Klant*>::iterator i;
    for(i = _Klanten.begin(); i != _Klanten.end(); i++){
        delete *i;
    }
}

// getters
QString Bandencentrale::getNaam(void) const {
    return this->_Naam;
}

Adres Bandencentrale::getAdres(void) const {
    return this->_Adres;
}

QList<Klant*> Bandencentrale::getKlanten(void){
    return this->_Klanten;
}

QList<Artikel*> Bandencentrale::getArtikels(void){
    return this->_Artikels;
}

QList<Factuur*> Bandencentrale::getFacturen(void){
    return this->_Facturen;
}

int Bandencentrale::getWorkshopID(void) const {
    return this->_tireWorkshopID;
}

int Bandencentrale::getClientID(void) const {
    return this->_maxClientID;
}

// setters
void Bandencentrale::setNaam(QString newVal){
    this->_Naam = newVal;
}

void Bandencentrale::setAdres(Adres &newVal){
    this->_Adres = newVal;
}

void Bandencentrale::setKlanten(QList<Klant*> newVal){
    this->_Klanten = newVal;
}

void Bandencentrale::setArtikels(QList<Artikel*> newVal){
    this->_Artikels = newVal;
}

void Bandencentrale::setFacturen(QList<Factuur*> newVal){
    this->_Facturen = newVal;
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

bool Bandencentrale::addArtikel(Artikel& ptr){
    if(ptr.getArtikelID() == 0){
        ptr.setArtikelID(this->getNewArtikelID());
    }

    this->_Artikels.append(&ptr);

    return true;
}

bool Bandencentrale::addFactuur(Factuur& ptr){
    if(ptr.getFactuurnummer() == 0){
        ptr.setFactuurnummer(this->getNewFactuurID());
    }

    this->_Facturen.append(&ptr);

    return true;
}

int Bandencentrale::getNewClientID(void){
    return ++this->_maxClientID;
}

int Bandencentrale::getNewArtikelID(void){
    return ++this->_maxItemID;
}

int Bandencentrale::getNewFactuurID(void){
    return ++this->_maxInvoiceID;
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

void Bandencentrale::printItemList(void){
    QTextStream qtout(stdout);

    // return if vector is empty
    if(this->_Artikels.isEmpty()) return;

    QList<Artikel*>::iterator i;
    for(i = _Artikels.begin(); i != _Artikels.end(); i++){
        qtout << "\t" << globals_headerLine << endl;
        if((*i)->getType() == ArtikelType_Band){
            this->getBand((*i))->print();
        } else if ((*i)->getType() == ArtikelType_Velg){
            this->getVelg((*i))->print();
        }
    }
}

void Bandencentrale::printInvoiceList(void){
    QTextStream qtout(stdout);

    // return if vector is empty
    if(this->_Facturen.isEmpty()) return;
}

// CONVERSION
Bedrijfsklant* Bandencentrale::getBedrijfsklant(Klant* ptr){
    return dynamic_cast<Bedrijfsklant*>(ptr);
}

Velg* Bandencentrale::getVelg(Artikel* ptr){
    return dynamic_cast<Velg*>(ptr);
}

Band* Bandencentrale::getBand(Artikel* ptr){
    return dynamic_cast<Band*>(ptr);
}
