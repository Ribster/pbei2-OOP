#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QVector>
#include <QDir>
#include <QtWidgets/QApplication>
#include <QString>

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

};

#endif // DATABASEMANAGEMENT_H
