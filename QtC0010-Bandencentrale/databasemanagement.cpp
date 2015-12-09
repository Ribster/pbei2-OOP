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
    checkMakeFolder(QString::number(ptr->getWorkshopID()) + globals_bandencentrale_foldername);
}

QDir DatabaseManagement::getProgramDirectory(void){
    QDir dir = QApplication::applicationDirPath();
    #ifdef Q_OS_MAC
    dir.cdUp();
    dir.cdUp();
    dir.cdUp();
    #endif
    return (dir);
}

bool DatabaseManagement::checkMakeFolder(QString folder){
    if(!QDir(getProgramDirectory().path() + "/" + folder).exists()){
        return QDir().mkdir(getProgramDirectory().path() + "/" + folder);
    }
    return true;
}
