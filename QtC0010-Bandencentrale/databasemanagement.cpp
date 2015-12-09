#include "databasemanagement.h"

// ctor
DatabaseManagement::DatabaseManagement()
{

}

// dtor
DatabaseManagement::~DatabaseManagement()
{

}

Bandencentrale* DatabaseManagement::getTireCompany(void){
    // fetch bandencentrale from filesystem
    return readTirecompanyObject(0);
}

bool DatabaseManagement::writeTirecompany(Bandencentrale* ptr){

    // make the folder
    checkMakeFolder(getBandencentraleFoldername(ptr));

    // write the whole bandencentrale object
    writeTirecompanyObject(ptr);

    // write each klanten object
    checkMakeFolder(getBandencentraleFoldernameKlantenCorporate(ptr));
    checkMakeFolder(getBandencentraleFoldernameKlantenPersonal(ptr));
    writeTirecompanyObjectClients(ptr);

    // write each artikels object
    checkMakeFolder(getBandencentraleFoldernameArtikels(ptr));
    writeTirecompanyObjectItems(ptr);

    // write each facturen object
    checkMakeFolder(getBandencentraleFoldernameFacturen(ptr));
    writeTirecompanyObjectInvoices(ptr);

    return true;
}

bool DatabaseManagement::writeTirecompanyObject(Bandencentrale* ptr){
    QString path = getBandencentraleFullPathname(ptr) + "/" + getBandencentraleFoldername(ptr) + globals_bandencentrale_fileExtension;
    QFile file(path);

    if (file.open(QIODevice::WriteOnly))
    {
        QDataStream out(&file);
        out << *ptr;
        file.close();
    }

    return true;
}

bool DatabaseManagement::readTirecompanyObject(Bandencentrale* ptr){
    QString path = getBandencentraleFullPathname(ptr) + "/" + getBandencentraleFoldername(ptr) + globals_bandencentrale_fileExtension;
    QFile file(path);
    Bandencentrale *tempCentrale = new Bandencentrale();
    if(file.exists())
    {
      if (file.open(QIODevice::ReadOnly))
      {
         QDataStream in(&file);
         in >> *tempCentrale;
         file.close();
         }
    }
    // no deletion of a nullptr.
    if(ptr != NULL){
        delete ptr;
    }
    ptr = tempCentrale;
    return true;
}

Bandencentrale* DatabaseManagement::readTirecompanyObject(int id){
    QString path = getBandencentraleFullPathname(id) + "/" + getBandencentraleFoldername(id) + globals_bandencentrale_fileExtension;
    QFile file(path);
    Bandencentrale *tempCentrale = new Bandencentrale();
    if(file.exists())
    {
      if (file.open(QIODevice::ReadOnly))
      {
         QDataStream in(&file);
         in >> *tempCentrale;
         file.close();
         }
    }
    return tempCentrale;
}

bool DatabaseManagement::writeTirecompanyObjectClients(Bandencentrale* ptr){

}

bool DatabaseManagement::writeTirecompanyObjectItems(Bandencentrale* ptr){

}

bool DatabaseManagement::writeTirecompanyObjectInvoices(Bandencentrale* ptr){

}


QDir DatabaseManagement::getProgramDirectory(void){
    QDir dir = QApplication::applicationDirPath();
    #ifdef Q_OS_MAC
    //dir.cdUp();
    //dir.cdUp();
    //dir.cdUp();
    #endif
    return (dir);
}

bool DatabaseManagement::checkMakeFolder(QString folder){
    QTextStream qtout(stdout);

    //qtout << "Trying to make: " << getProgramDirectory().path() << "/" << folder << endl;

    if(!QDir(getProgramDirectory().path() + "/" + folder).exists()){
        bool success = QDir().mkdir(getProgramDirectory().path() + "/" + folder);
        //qtout << "Failed?: " << !success << endl;
        return success;
    }

    return true;
}

QString DatabaseManagement::getBandencentraleFoldername(Bandencentrale* ptr){
    return QString::number(ptr->getWorkshopID()) + globals_bandencentrale_foldername;
}

QString DatabaseManagement::getBandencentraleFoldername(int id){
    return QString::number(id) + globals_bandencentrale_foldername;
}

QString DatabaseManagement::getBandencentraleFoldernameKlantenPersonal(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_ClientsPersonal;
}

QString DatabaseManagement::getBandencentraleFoldernameKlantenCorporate(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_ClientsCorporate;
}

QString DatabaseManagement::getBandencentraleFoldernameArtikels(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_Articles;
}

QString DatabaseManagement::getBandencentraleFoldernameFacturen(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_Invoices;
}

QString DatabaseManagement::getBandencentraleFullPathname(Bandencentrale* ptr){
    return getProgramDirectory().path() + "/" + getBandencentraleFoldername(ptr);
}

QString DatabaseManagement::getBandencentraleFullPathname(int id){
    return getProgramDirectory().path() + "/" + getBandencentraleFoldername(id);
}

QDataStream &operator<<(QDataStream &out, const Adres &ptr){
    out << ptr.gemeente << ptr.land << ptr.postcode << ptr.straatnaam << ptr.straatnummer;
    return out;
}

QDataStream &operator>>(QDataStream &in, Adres &ptr){
    QString gemeente;
    QString land;
    int postcode;
    QString straatnaam;
    QString straatnummer;
    in >> gemeente >> land >> postcode >> straatnaam >> straatnummer;
    ptr = Adres({straatnaam, straatnummer, postcode, gemeente, land});
    return in;
}

QDataStream &operator<<(QDataStream &out, const Bandencentrale &ptr){
    out << ptr.getAdres() << ptr.getNaam() << ptr.getClientID() << ptr.getWorkshopID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Bandencentrale &ptr){
    Adres adr;
    QString naam;
    int clientID;
    int workshopID;
    in >> adr >> naam >> clientID >> workshopID;
    ptr = Bandencentrale(adr, naam, clientID, workshopID);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Klant &ptr){
    out << ptr.getNaam() << ptr.getAdres() << ptr.getSetKorting() << ptr.getSetkorting2() << ptr.getBedrijf()
        << ptr.getDeleted() << ptr.getClientType() << ptr.getClientID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Klant &ptr){
    QString naam;
    Adres adres;
    double setkorting1;
    double setkorting2;
    bool bedrijf;
    bool verwijderd;
    ClientType clienttype;
    int klantid;
    in >> naam >> adres >> setkorting1 >> setkorting2 >> bedrijf
            >> verwijderd >> clienttype >> klantid;
    ptr = Klant(naam, adres, setkorting1, setkorting2, verwijderd, clienttype, klantid);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Bedrijfsklant &ptr){
    out << ptr.getNaam() << ptr.getAdres() << ptr.getSetKorting() << ptr.getSetkorting2() << ptr.getBedrijf()
        << ptr.getDeleted() << ptr.getClientType() << ptr.getClientID()
        << ptr.getBTWnummer() << ptr.getBedrijfskorting() << ptr.getVolumekorting();
    return out;
}

QDataStream &operator>>(QDataStream &in, Bedrijfsklant &ptr){
    QString naam;
    Adres adres;
    double setkorting1;
    double setkorting2;
    bool bedrijf;
    bool verwijderd;
    ClientType clienttype;
    int klantid;
    QString btwnummer;
    double bedrijfskorting;
    double volumekorting;
    in >> naam >> adres >> setkorting1 >> setkorting2 >> bedrijf
            >> verwijderd >> clienttype >> klantid >> btwnummer >> bedrijfskorting >> volumekorting;
    ptr = Bedrijfsklant(naam, adres, setkorting1, setkorting2, btwnummer, volumekorting, bedrijfskorting, verwijderd, klantid);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Artikel &ptr){
    out >> ptr.getNaam() >> ptr.getFabrikant() >> ptr.getPrijs() >> ptr.getDiameter() >> ptr.getType() >> ptr.getAantal();
    return out;
}

QDataStream &operator>>(QDataStream &in, Artikel &ptr){
    QString Naam;
    QString Fabrikant;
    double Prijs;
    double Diameter;
    ArtikelType Type;
    int Aantal;
    in >> Naam >> Fabrikant >> Prijs >> Diameter >> Type >> Aantal;
    ptr = Artikel(Naam, Fabrikant, Prijs, Diameter, Type, Aantal);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Velg &ptr){

    return out;
}

QDataStream &operator>>(QDataStream &in, Velg &ptr){

    return in;
}

QDataStream &operator<<(QDataStream &out, const Band &ptr){

    return out;
}

QDataStream &operator>>(QDataStream &in, Band &ptr){

    return in;
}

QDataStream &operator<<(QDataStream &out, const Factuur &ptr){

    return out;
}

QDataStream &operator>>(QDataStream &in, Factuur &ptr){

    return in;
}

QDataStream &operator<<(QDataStream &out, const ClientType &ptr){

    return out;
}

QDataStream &operator>>(QDataStream &in, ClientType &ptr){

    return in;
}

QDataStream &operator<<(QDataStream &out, const ArtikelType &ptr){

    return out;
}

QDataStream &operator>>(QDataStream &in, ArtikelType &ptr){

    return in;
}
