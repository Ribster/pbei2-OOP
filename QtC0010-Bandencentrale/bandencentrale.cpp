#include "bandencentrale.h"

using namespace std;

Bandencentrale::Bandencentrale()
{

}

Bandencentrale::~Bandencentrale(){
    // delete all the clients
    QVector<Klant*>::iterator i;
    for(i = _Klanten.begin(); i != _Klanten.end(); i++){
        delete *i;
    }
}

// getters
QString Bandencentrale::getNaam(void){
    return _Naam;
}

Adres Bandencentrale::getAdres(void){
    return _Adres;
}

QVector<Klant*> Bandencentrale::getKlanten(void){
    return _Klanten;
}

QVector<Artikel*> Bandencentrale::getArtikels(void){
    return _Artikels;
}

// setters
void Bandencentrale::setNaam(QString newVal){
    _Naam = newVal;
}

void Bandencentrale::setAdres(Adres newVal){
    _Adres = newVal;
}

void Bandencentrale::setKlanten(QVector<Klant*> newVal){
    _Klanten = newVal;
}

void Bandencentrale::setArtikels(QVector<Artikel*> newVal){
    _Artikels = newVal;
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
    // increment value and return
    return ++this->_maxClientID;
}

void Bandencentrale::printClientList(void){
    QVector<Klant*>::iterator i;
    for(i = _Klanten.begin(); i != _Klanten.end(); i++){
        if((*i)->getBedrijf()){
            cout << "Bedrijf" << endl;
            // we are dealing with a company
            //this->getBedrijfsklant((*i))->print();
        } else {
            cout << "Client" << endl;
            // client
            //(*i)->print();
        }
    }
}

// CONVERSION
Bedrijfsklant* Bandencentrale::getBedrijfsklant(Klant* ptr){
    return dynamic_cast<Bedrijfsklant*>(ptr);
}
