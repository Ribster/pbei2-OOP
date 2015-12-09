#ifndef BANDENCENTRALE_H
#define BANDENCENTRALE_H

#include <QString>
#include <QVector>
#include <QList>
#include <iostream>

#include "klant.h"
#include "artikel.h"
#include "globals.h"
#include "bedrijfsklant.h"
#include "velg.h"
#include "band.h"
#include "factuur.h"

class Bandencentrale final
{
public:
    // ctor
    Bandencentrale();
    Bandencentrale(Adres adr, QString naam, int clientID = 0, int workshopID = 0);
    // dtor
    virtual ~Bandencentrale();

    // GETTERS
    const QString getNaam(void) const;
    const Adres getAdres(void) const;
    QList<Klant*> getKlanten(void);
    QList<Artikel*> getArtikels(void);

    /**
     * @brief  Get the workshop Identifier
     * @param  None
     * @retval int      Return the ID of the workshop
     */
    const int getWorkshopID(void) const;

    /**
     * @brief  Get the client Identifier
     * @param  None
     * @retval int      Return the ID of the client
     */
    const int getClientID(void) const;

    // SETTERS
    void setNaam(QString);
    void setAdres(Adres&);
    void setKlanten(QList<Klant*>);
    void setArtikels(QList<Artikel*>);

    // FUNCTIONS
    /**
     * @brief  Add a client
     * @param  Klant    The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    bool addClient(Klant&);

    /**
     * @brief  Get new client Identification
     * @param  None
     * @retval int      Increment the current maximum client ID and return unique ID
     */
    int getNewClientID(void);

    /**
     * @brief  Print the whole client list
     * @param  None
     * @retval None
     */
    void printClientList(void);

    // CONVERSION
    /**
     * @brief  Converting the base class to the subclass
     * @param  Klant            Give the base class
     * @retval Bedrijfsklant    Return the subclass
     */
    Bedrijfsklant* getBedrijfsklant(Klant*);

private:

    QString _Naam;
    Adres _Adres;
    QList<Klant*> _Klanten;
    QList<Artikel*> _Artikels;
    QList<Factuur*> _Facturen;
    int _maxClientID = 0;
    int _tireWorkshopID = 0;
};

#endif // BANDENCENTRALE_H
