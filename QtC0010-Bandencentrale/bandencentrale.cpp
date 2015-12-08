#include "bandencentrale.h"

using namespace std;

Bandencentrale::Bandencentrale()
{
//    cout << "Klanten empty: " << _Klanten.isEmpty() << endl;
//    cout << "Artikel empty: " << _Artikels.isEmpty() << endl;
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
QString Bandencentrale::getNaam(void){
    return _Naam;
}

Adres Bandencentrale::getAdres(void){
    return _Adres;
}

QList<Klant*> Bandencentrale::getKlanten(void){
    return _Klanten;
}

QList<Artikel*> Bandencentrale::getArtikels(void){
    return _Artikels;
}

// setters
void Bandencentrale::setNaam(QString newVal){
    _Naam = newVal;
}

void Bandencentrale::setAdres(Adres newVal){
    _Adres = newVal;
}

void Bandencentrale::setKlanten(QList<Klant*> newVal){
    _Klanten = newVal;
}

void Bandencentrale::setArtikels(QList<Artikel*> newVal){
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
    QTextStream qtout(stdout);
    QString ptrStr = QString("0x%1").arg((quintptr)this,
                        QT_POINTER_SIZE * 2, 16, QChar('0'));
    qtout << "2 bandencentrale ptr: " << ptrStr << endl;

    // return if vector is empty
    if(this->_Klanten.isEmpty()) return;

    // loop over the Vector
    QList<Klant*>::iterator i;
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
