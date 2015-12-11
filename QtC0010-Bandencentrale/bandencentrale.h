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
    QString getNaam(void) const;
    Adres getAdres(void) const;
    QList<Klant*> getKlanten(void);
    QList<Artikel*> getArtikels(void);
    QList<Factuur*> getFacturen(void);

    /**
     * @brief  Get the workshop Identifier
     * @param  None
     * @retval int      Return the ID of the workshop
     */
    int getWorkshopID(void) const;

    /**
     * @brief  Get the client Identifier
     * @param  None
     * @retval int      Return the ID of the client
     */
    int getClientID(void) const;

    /**
     * @brief  Get the Item Identifier
     * @param  None
     * @retval int      Return the ID of the item
     */
    int getItemID(void) const;

    /**
     * @brief  Get the Invoice Identifier
     * @param  None
     * @retval int      Return the ID of the invoice
     */
    int getInvoiceID(void) const;

    // SETTERS
    void setNaam(QString);
    void setAdres(Adres&);
    void setKlanten(QList<Klant*>);
    void setArtikels(QList<Artikel*>);
    void setFacturen(QList<Factuur*>);

    // FUNCTIONS
    /**
     * @brief  Add a client
     * @param  Klant    The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    bool addClient(Klant&);

    /**
     * @brief  Add an Item
     * @param  Klant    The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    bool addArtikel(Artikel&);

    /**
     * @brief Remove artikel based on artikel ID
     * @param int   artikelID
     * @return bool if removed successfully
     */
    bool removeArtikel(int artikelID);

    /**
     * @brief  Add an Invoice
     * @param  Klant    The object that needs to be written
     * @retval bool     Wether the action was succesfull
     */
    bool addFactuur(Factuur&);

    /**
     * @brief  Get new client Identification
     * @param  None
     * @retval int      Increment the current maximum client ID and return unique ID
     */
    int getNewClientID(void);

    /**
     * @brief  Get new Item Identification
     * @param  None
     * @retval int      Increment the current maximum client ID and return unique ID
     */
    int getNewArtikelID(void);

    /**
     * @brief  Get new Factuur Identification
     * @param  None
     * @retval int      Increment the current maximum client ID and return unique ID
     */
    int getNewFactuurID(void);

    /**
     * @brief  Print the whole client list
     * @param  None
     * @retval None
     */
    void printClientList(void);

    /**
     * @brief  Print the whole Item list
     * @param  None
     * @retval None
     */
    void printItemList(void);

    /**
     * @brief  Print the whole Invoice list
     * @param  None
     * @retval None
     */
    void printInvoiceList(void);

    /**
     * @brief  Print the bandencentrale information
     * @param  None
     * @retval None
     */
    void print(void);

    // CONVERSION
    /**
     * @brief  Converting the base class to the subclass
     * @param  Klant            Give the base class
     * @retval Bedrijfsklant    Return the subclass
     */
    Bedrijfsklant* getBedrijfsklant(Klant*);

    /**
     * @brief  Converting the base class to the subclass
     * @param  Artikel          Give the base class
     * @retval Velg             Return the subclass
     */
    Velg* getVelg(Artikel*);

    /**
     * @brief  Converting the base class to the subclass
     * @param  Artikel          Give the base class
     * @retval Band             Return the subclass
     */
    Band* getBand(Artikel*);

private:

    QString _Naam;
    Adres _Adres;
    QList<Klant*> _Klanten;
    QList<Artikel*> _Artikels;
    QList<Factuur*> _Facturen;
    int _maxClientID = 0;
    int _maxItemID = 0;
    int _maxInvoiceID = 0;
    int _tireWorkshopID = 0;
};

#endif // BANDENCENTRALE_H
