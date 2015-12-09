#ifndef DATABASEMANAGEMENT_H
#define DATABASEMANAGEMENT_H

#include <QVector>

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

};

#endif // DATABASEMANAGEMENT_H
