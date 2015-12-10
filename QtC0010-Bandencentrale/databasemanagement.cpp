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
    QTextStream qtout(stdout);

    //qtout << "Reading the tire company object from file" << endl;
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

    // read all the clients
    //qtout << "Reading all the clients from file" << endl;
    tempCentrale->setKlanten(readTirecompanyObjectClients(tempCentrale));

    return tempCentrale;
}

bool DatabaseManagement::writeTirecompanyObjectClients(Bandencentrale* ptr){
    // run over each client
    // determine if it is a company or personal client
    // push it out
    QList<Klant*> klantenList = ptr->getKlanten();
    if(!klantenList.isEmpty()){
        QList<Klant*>::iterator i;
        for(i = klantenList.begin(); i != klantenList.end(); i++){
            Klant* tmp = (*i);
            if(tmp->getClientType() == ClientType_Business){
                // it is a business client
                Bedrijfsklant* tmp2 = dynamic_cast<Bedrijfsklant*>(tmp);
                QString path = getBandencentraleFilenameKlantenCorporate(ptr, tmp2);
                QFile file(path);
                if (file.open(QIODevice::WriteOnly))
                {
                    QDataStream out(&file);
                    out << *tmp2;
                    file.close();
                }
            } else if (tmp->getClientType() == ClientType_Personal){
                // it is a personal client
                QString path = getBandencentraleFilenameKlantenPersonal(ptr, tmp);
                QFile file(path);
                if (file.open(QIODevice::WriteOnly))
                {
                    QDataStream out(&file);
                    out << *tmp;
                    file.close();
                }
            }
        }
    }
    return true;
}

QList<Klant*> DatabaseManagement::readTirecompanyObjectClients(Bandencentrale* ptr){
    // loop over all the items in the clients folder
    // split the filename on -
    // get instring corporate or private
    // convert first split part to an int
    // convert data in file to a new object
    // put the object in the list
    // return the whole list
    QTextStream qtout(stdout);
    QList<Klant*> returnList;
    if(ptr == NULL) return returnList;

    // loop over every item in folder
    QString itemsFolderPath = getProgramDirectory().path() + "/" + getBandencentraleFoldernameKlanten(ptr);

    //qtout << "Reading files from folder: " << itemsFolderPath << endl;

    QDirIterator it(itemsFolderPath, QStringList() << "*"+globals_bandencentrale_fileExtension, QDir::Files, QDirIterator::NoIteratorFlags);
    while (it.hasNext()) {
        it.next();
        QString filename = it.fileName();

        //qtout << "Item: " << filename << endl;


        if(filename.contains(globals_bandencentrale_foldername_Clients_Corporate)){
            //qtout << "Item corporate: " << filename << endl;
            // filename contains corporate
            QFile file(it.filePath());
            if(file.exists()){
              if (file.open(QIODevice::ReadOnly)){
                 QDataStream in(&file);
                 Bedrijfsklant *tmpClient = NULL;
                 in >> &tmpClient;
                 file.close();
                 tmpClient->setBedrijf(true);
                 returnList.append(dynamic_cast<Klant*>(tmpClient));
                }
            }
        } else if (filename.contains(globals_bandencentrale_foldername_Clients_Personal)){
            //qtout << "Item personal: " << filename << endl;
            // filename contains personal
            QFile file(it.filePath());
            if(file.exists()){
              if (file.open(QIODevice::ReadOnly)){
                 QDataStream in(&file);
                 Klant *tmpClient = NULL;
                 in >> &tmpClient;
                 file.close();
                 returnList.append(tmpClient);
                }
            }
        }
    }

    return returnList;
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

QString DatabaseManagement::getBandencentraleFoldernameKlanten(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_Clients;
}

QString DatabaseManagement::getBandencentraleFilenameKlantenCorporate(Bandencentrale* centr, Bedrijfsklant* ptr){
return getBandencentraleFoldername(centr) + "/" + globals_bandencentrale_foldername_Clients + "/" + QString::number(ptr->getClientID()) + globals_bandencentrale_foldername_Clients_Corporate + globals_bandencentrale_fileExtension;
}

QString DatabaseManagement::getBandencentraleFilenameKlantenPersonal(Bandencentrale* centr, Klant* ptr){
return getBandencentraleFoldername(centr) + "/" + globals_bandencentrale_foldername_Clients + "/" + QString::number(ptr->getClientID()) + globals_bandencentrale_foldername_Clients_Personal + globals_bandencentrale_fileExtension;
}

QString DatabaseManagement::getBandencentraleFoldernameArtikels(Bandencentrale* ptr){
    return getBandencentraleFoldername(ptr) + "/" + globals_bandencentrale_foldername_Articles;
}

QString DatabaseManagement::getBandencentraleFilenameArtikelsBand(Bandencentrale* centr, Band* ptr){
    return getBandencentraleFoldername(centr) + "/" + globals_bandencentrale_foldername_Articles + "/" + QString::number(ptr->getArtikelID()) + globals_bandencentrale_foldername_Articles_Band + globals_bandencentrale_fileExtension;
}

QString DatabaseManagement::getBandencentraleFilenameArtikelsVelg(Bandencentrale* centr, Velg* ptr){
    return getBandencentraleFoldername(centr) + "/" + globals_bandencentrale_foldername_Articles + "/" + QString::number(ptr->getArtikelID()) + globals_bandencentrale_foldername_Articles_Velg + globals_bandencentrale_fileExtension;
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

QDataStream &operator<<(QDataStream &out, const Klant *ptr){
    out << ptr->getNaam() << ptr->getAdres() << ptr->getSetKorting() << ptr->getSetkorting2() << ptr->getBedrijf()
        << ptr->getDeleted() << ptr->getClientType() << ptr->getClientID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Klant **ptr){
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
    *ptr = new Klant(naam, adres, setkorting1, setkorting2, verwijderd, clienttype, klantid);
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

QDataStream &operator<<(QDataStream &out, const Bedrijfsklant *ptr){
    // push the pointer out. Assume that the object already exists
    out << ptr->getNaam() << ptr->getAdres() << ptr->getSetKorting() << ptr->getSetkorting2() << ptr->getBedrijf()
        << ptr->getDeleted() << ptr->getClientType() << ptr->getClientID()
        << ptr->getBTWnummer() << ptr->getBedrijfskorting() << ptr->getVolumekorting();
    return out;
}

QDataStream &operator>>(QDataStream &in, Bedrijfsklant **ptr){
    QTextStream qtout(stdout);
    // dynamically create a new pointer and assign to ptr
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

    qtout << "Bedrijfskorting: " << bedrijfskorting << " Volumekorting: " << volumekorting << endl;

    // use the data from the stream in the constructor of the new object
    *ptr = new Bedrijfsklant(naam, adres, setkorting1, setkorting2, btwnummer, volumekorting, bedrijfskorting, verwijderd, klantid);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Artikel &ptr){
    out << ptr.getNaam() << ptr.getFabrikant() << ptr.getPrijs()
        << ptr.getDiameter() << ptr.getType() << ptr.getAantal() << ptr.getArtikelID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Artikel &ptr){
    QString Naam;
    QString Fabrikant;
    double Prijs;
    double Diameter;
    ArtikelType Type;
    int Aantal;
    int artikelID;
    in >> Naam >> Fabrikant >> Prijs >> Diameter >> Type >> Aantal >> artikelID;
    ptr = Artikel(Naam, Fabrikant, Prijs, Diameter, Type, Aantal, artikelID);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Velg &ptr){
    out << ptr.getBreedte() << ptr.getKleur() << ptr.getAluminium() << ptr.getNaam() << ptr.getFabrikant()
        << ptr.getPrijs() << ptr.getDiameter() << ptr.getType()
        << ptr.getAantal() << ptr.getArtikelID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Velg &ptr){
    double Breedte;
    Kleuren Kleur;
    bool Aluminium;
    QString Naam;
    QString Fabrikant;
    double Prijs;
    double Diameter;
    ArtikelType Type;
    int Aantal;
    int artikelID;

    in >> Breedte >> Kleur >> Aluminium >> Naam >> Fabrikant >> Prijs >> Diameter >> Type >> Aantal >> artikelID;
    ptr = Velg(Breedte, Kleur, Aluminium, Naam, Fabrikant, Prijs, Diameter, Type, Aantal, artikelID);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Band &ptr){
    out << ptr.getBreedte() << ptr.getHoogte() << ptr.getSnelheidsindex() << ptr.getSeizoen()
        << ptr.getNaam() << ptr.getFabrikant() << ptr.getPrijs() << ptr.getDiameter() << ptr.getType()
        << ptr.getAantal() << ptr.getArtikelID();
    return out;
}

QDataStream &operator>>(QDataStream &in, Band &ptr){
    double Breedte;
    double Hoogte;
    QChar Snelheidsindex;
    Seizoen seizoen;
    QString Naam;
    QString Fabrikant;
    double Prijs;
    double Diameter;
    ArtikelType Type;
    int Aantal;
    int artikelID;

    in >> Breedte >> Hoogte >> Snelheidsindex >> seizoen >> Naam >> Fabrikant >> Prijs >> Diameter
            >> Type >> Aantal >> artikelID;
    ptr = Band(Breedte, Hoogte, Snelheidsindex, seizoen, Naam, Fabrikant, Prijs, Diameter, Type, Aantal, artikelID);
    return in;
}

QDataStream &operator<<(QDataStream &out, const Factuur &ptr){
    out << ptr.getFactuurnummer() << ptr.getKlant() << ptr.getArtikels() << ptr.getTotaalprijs() << ptr.getKorting();
    return out;
}

QDataStream &operator>>(QDataStream &in, Factuur &ptr){
    int Factuurnummer;
    int Klant = 0;
    QMap<int, int> ArtikelCount;
    double Totaalprijs;
    double Korting;
    in >> Factuurnummer >> Klant >> ArtikelCount >> Totaalprijs >> Korting;
    ptr = Factuur(Factuurnummer, Klant, ArtikelCount, Totaalprijs, Korting);
    return in;
}

QDataStream &operator<<(QDataStream &out, const ClientType &ptr){
    out << ptr;
    return out;
}

QDataStream &operator>>(QDataStream &in, ClientType &ptr){
    in >> ptr;
    return in;
}

QDataStream &operator<<(QDataStream &out, const ArtikelType &ptr){
    out << ptr;
    return out;
}

QDataStream &operator>>(QDataStream &in, ArtikelType &ptr){
    in >> ptr;
    return in;
}

QDataStream &operator<<(QDataStream &out, const Kleuren &ptr){
    out << ptr;
    return out;
}

QDataStream &operator>>(QDataStream &in, Kleuren &ptr){
    in >> ptr;
    return in;
}

QDataStream &operator<<(QDataStream &out, const Seizoen &ptr){
    out << ptr;
    return out;
}

QDataStream &operator>>(QDataStream &in, Seizoen &ptr){
    in >> ptr;
    return in;
}
