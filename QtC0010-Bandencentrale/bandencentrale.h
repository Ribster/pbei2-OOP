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

class Bandencentrale final
{
public:
    // ctor
    Bandencentrale();
    // dtor
    virtual ~Bandencentrale();

    // GETTERS
    QString getNaam(void);
    Adres getAdres(void);
    QList<Klant*> getKlanten(void);
    QList<Artikel*> getArtikels(void);

    // SETTERS
    void setNaam(QString);
    void setAdres(Adres);
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
    int _maxClientID = 0;
};

#endif // BANDENCENTRALE_H
