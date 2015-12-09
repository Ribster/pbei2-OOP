#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QVector>
#include <QDir>
#include <QtWidgets/QApplication>
#include <QString>
#include <QDataStream>

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

private:

    /**
     * @brief  Low Level write of the Bandencentrale object.
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObject(Bandencentrale*);

    /**
     * @brief  Low Level write of the Bandencentrale object's Clients
     * @param  Bandencentrale   The object that needs to be written
     * @retval bool             Wether the action was succesfull
     */
    static bool writeTirecompanyObjectClients(Bandencentrale*);

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
     * @brief  Get the folder name of bandencentrale Clients
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldernameKlanten(Bandencentrale*);

    /**
     * @brief  Get the folder name of bandencentrale Articles
     * @param  Bandencentrale*  Ptr to the bandencentrale object
     * @retval QString          Folder name for the Bandencentrale object
     */
    static QString getBandencentraleFoldernameArtikels(Bandencentrale*);

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
};

QDataStream &operator<<(QDataStream &out, const Adres &ptr);
QDataStream &operator>>(QDataStream &in, Adres &ptr);

QDataStream &operator<<(QDataStream &out, const Bandencentrale &ptr);
QDataStream &operator>>(QDataStream &in, Bandencentrale &ptr);

#endif // DATABASEMANAGEMENT_H
