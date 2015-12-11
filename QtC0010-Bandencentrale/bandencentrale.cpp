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

bool Bandencentrale::removeClient(int clientID){
    QList<Klant*> tmp = _Klanten;
    QList<Klant*>::iterator i;
    for(i = tmp.begin(); i != tmp.end(); i++){
        int tmpID = (*i)->getClientID();
        if(tmpID == clientID){
            (*i)->setDeleted(true);
            return true;
        }
    }
    return false;
}

bool Bandencentrale::addArtikel(Artikel& ptr){
    if(ptr.getArtikelID() == 0){
        ptr.setArtikelID(this->getNewArtikelID());
    }

    this->_Artikels.append(&ptr);

    return true;
}

bool Bandencentrale::removeArtikel(int artikelID){
    // loop over each item
    // if artikel ID matches
    // set removed on true
    QList<Artikel*> tmp = _Artikels;
    QList<Artikel*>::iterator i;
    for(i = tmp.begin(); i!= tmp.end(); i++){
       int tmpID = (*i)->getArtikelID();
       if(tmpID == artikelID){
           (*i)->setVerwijderd(true);
           return true;
       }
    }

    return false;
}

void Bandencentrale::printArtikel(int artikelID){
    QList<Artikel*> tmp = _Artikels;
    QList<Artikel*>::iterator i;
    for(i = tmp.begin(); i!= tmp.end(); i++){
       int tmpID = (*i)->getArtikelID();
       if(tmpID == artikelID){
            if((*i)->getType() == ArtikelType_Band){
                //
                Band* tmp2 = dynamic_cast<Band*>((*i));
                tmp2->print();
            } else if ((*i)->getType() == ArtikelType_Velg){
                //
                Velg* tmp2 = dynamic_cast<Velg*>((*i));
                tmp2->print();
            }
       }
    }

}

void Bandencentrale::setArtikelStock(int artikelID, int newStock){
    QList<Artikel*> tmp = _Artikels;
    QList<Artikel*>::iterator i;
    for(i = tmp.begin(); i!= tmp.end(); i++){
       int tmpID = (*i)->getArtikelID();
       if(tmpID == artikelID){
           (*i)->setAantal(newStock);
       }
    }
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

void Bandencentrale::print(void){
    QTextStream qtout(stdout);
    qtout << "\tInformation about the workshop:" << endl;
    qtout << "\tID: " << this->_tireWorkshopID << endl;
    qtout << "\tName: " << this->_Naam << endl;
    Klant::printAddress(this->_Adres);

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
