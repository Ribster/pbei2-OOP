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

}

bool DatabaseManagement::writeTirecompany(Bandencentrale* ptr){
//    ptr->getKlanten();
//    ptr->getArtikels();
//    ptr->getNaam();
//    ptr->getAdres();

    // make the folder
    checkMakeFolder(getBandencentraleFoldername(ptr));

    // write the whole bandencentrale object
    writeTirecompanyObject(ptr);

    // write each klanten object
    checkMakeFolder(getBandencentraleFoldernameKlanten(ptr));
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

QString DatabaseManagement::getBandencentraleFoldernameKlanten(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_Clients;
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


