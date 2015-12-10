#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QVector>
#include <QDir>
#include <QDirIterator>
#include <QtWidgets/QApplication>
#include <QString>
#include <QDataStream>
#include <QChar>

#include "klant.h"
#include "artikel.h"
#include "globals.h"
#include "bedrijfsklant.h"
#include "velg.h"
#include "band.h"
#include "bandencentrale.h"
#include "factuur.h"


class DatabaseManagement final
{
public:
    DatabaseManagement();
    virtual ~DatabaseManagement();

    /**
     * @brief  Get the whole tire company from file
     * @param  None
     * @retval Bandencentrale   The pointer to the dynamic allocated object
     */
    static Bandencentrale* getTireCompany(void);

    /**
     * @brief  Write the object to file
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompany(Bandencentrale*);

    static void testSerialization(void);

private:

    /**
     * @brief  Low Level write of the Bandencentrale object.
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObject(Bandencentrale*);

    /**
     * @brief  Low Level read of the Bandencentrale object.
     * @param  Bandencentrale   The object that needs to be read
     * @retval bool             Wether the action was succesfull
     */
    static bool readTirecompanyObject(Bandencentrale*);

    /**
     * @brief  Low Level read of the Bandencentrale object.
     * @param  int              The id of the centrale
     * @param  Bandencentrale   The object that needs to be read
     * @retval bool             Wether the action was succesfull
     */
    static Bandencentrale* readTirecompanyObject(int);

    /**
     * @brief  Low Level write of the Bandencentrale object's Clients
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObjectClients(Bandencentrale*);

    /**
     * @brief  Low Level read of the Bandencentrale object's Clients
     * @param  Bandencentrale   The object that needs to be written
     * @retval QList<Klant*>    The list of dynamically created klant objects
     */
    static QList<Klant*> readTirecompanyObjectClients(Bandencentrale*);

    /**
     * @brief  Low Level write of the Bandencentrale object's Items
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObjectItems(Bandencentrale*);

    /**
     * @brief  Low Level write of the Bandencentrale object's Invoices
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObjectInvoices(Bandencentrale*);

    /**
     * @brief  Get current program executable directory
     * @param  None
     * @retval QDir     The current directory path
     */
    static QDir getProgramDirectory(void);

    /**
     * @brief  Check for a directory on the filesystem and make if necessary
     * @param  QString      The path of the folder you want to check
     * @retval bool         If making the folder was successfull
     */
    static bool checkMakeFolder(QString folder);

    /**
     * @brief  Get the folder name of bandencentrale
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldername(Bandencentrale*);

    /**
     * @brief  Get the folder name of bandencentrale
     * @param  int              Bandencentrale ID
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldername(int);

    /**
     * @brief  Get the folder name of bandencentrale Clients
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldernameKlanten(Bandencentrale*);

    /**
     * @brief  Get the file name of bandencentrale corporate Clients
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @param  Bedrijfsklant*   Ptr to the Bedrijfsklant
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFilenameKlantenCorporate(Bandencentrale*, Bedrijfsklant*);

    /**
     * @brief  Get the file name of bandencentrale personal Clients
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @param  Klant*           Ptr to the klant
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFilenameKlantenPersonal(Bandencentrale*, Klant*);

    /**
     * @brief  Get the folder name of bandencentrale Articles
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldernameArtikels(Bandencentrale*);

    /**
     * @brief  Get the folder name of bandencentrale Articles
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @param  Band*            Ptr to the band
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFilenameArtikelsBand(Bandencentrale*, Band*);

    /**
     * @brief  Get the folder name of bandencentrale Articles
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @param  Velg*            Ptr to the velg
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFilenameArtikelsVelg(Bandencentrale*, Velg*);

    /**
     * @brief  Get the folder name of bandencentrale Invoices
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldernameFacturen(Bandencentrale*);

    /**
     * @brief  Get the path name of bandencentrale
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Path name for the Bandencentrale object
     */
    static QString getBandencentraleFullPathname(Bandencentrale*);

    /**
     * @brief  Get the path name of bandencentrale
     * @param  int              Centrale ID
     * @retval QString          Path name for the Bandencentrale object
     */
    static QString getBandencentraleFullPathname(int);
};

QDataStream &operator<<(QDataStream &out, const Adres &ptr);
QDataStream &operator>>(QDataStream &in, Adres &ptr);

QDataStream &operator<<(QDataStream &out, const Bandencentrale &ptr);
QDataStream &operator>>(QDataStream &in, Bandencentrale &ptr);

QDataStream &operator<<(QDataStream &out, const Klant &ptr);
QDataStream &operator>>(QDataStream &in, Klant &ptr);

QDataStream &operator<<(QDataStream &out, const Klant *ptr);
QDataStream &operator>>(QDataStream &in, Klant **ptr);

QDataStream &operator<<(QDataStream &out, const Bedrijfsklant &ptr);
QDataStream &operator>>(QDataStream &in, Bedrijfsklant &ptr);

QDataStream &operator<<(QDataStream &out, const Bedrijfsklant *ptr);
QDataStream &operator>>(QDataStream &in, Bedrijfsklant **ptr);

QDataStream &operator<<(QDataStream &out, const Artikel &ptr);
QDataStream &operator>>(QDataStream &in, Artikel &ptr);

QDataStream &operator<<(QDataStream &out, const Velg &ptr);
QDataStream &operator>>(QDataStream &in, Velg &ptr);

QDataStream &operator<<(QDataStream &out, const Band &ptr);
QDataStream &operator>>(QDataStream &in, Band &ptr);

QDataStream &operator<<(QDataStream &out, const Factuur &ptr);
QDataStream &operator>>(QDataStream &in, Factuur &ptr);

QDataStream &operator<<(QDataStream &out, const ClientType &ptr);
QDataStream &operator>>(QDataStream &in, ClientType &ptr);

QDataStream &operator<<(QDataStream &out, const ArtikelType &ptr);
QDataStream &operator>>(QDataStream &in, ArtikelType &ptr);

QDataStream &operator<<(QDataStream &out, const Kleuren &ptr);
QDataStream &operator>>(QDataStream &in, Kleuren &ptr);

QDataStream &operator<<(QDataStream &out, const Seizoen &ptr);
QDataStream &operator>>(QDataStream &in, Seizoen &ptr);



#endif // DATABASEMANAGEMENT_H
