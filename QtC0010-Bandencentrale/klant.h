#ifndef KLANT_H
#define KLANT_H

#include <QString>
#include <QTextStream>

#include "globals.h"

class Bedrijfsklant;

class Klant
{
public:
    // ctor
    Klant(QString naam, Adres adres, double smallKorting, double bigKorting, bool verwijderd, ClientType klantentype = ClientType_Personal, int klantenID = 0);
    // dtor
    virtual ~Klant();

    // getters
    const QString getNaam(void) const;
    const Adres getAdres(void) const;
    const double getSetKorting(void) const;
    const bool getBedrijf(void) const;
    const double getSetkorting2(void) const;

    /**
     * @brief  Getting the unique client identifier; Initialized to zero.
     * @param  None
     * @retval int      Client identification, if zero, uninitialized
     */
    const int getClientID(void) const;

    /**
     * @brief  Getting the deleted flag
     * @param  None
     * @retval bool     Wether the client is deleted or not
     */
    const bool getDeleted(void) const;

    /**
     * @brief  Getting the client type
     * @param  None
     * @retval ClientType   The type of client
     */
    const ClientType getClientType(void) const;

    // setters
    void setNaam(QString);
    void setAdres(Adres);
    void setSetkorting(double);
    void setBedrijf(bool);
    void setSetkorting2(double);

    /**
     * @brief  Set the client ID
     * @param  int      New identifier
     * @retval None
     */
    void setClientID(int);

    /**
     * @brief  Print the current client to the output terminal
     * @param  None
     * @retval None
     */
    virtual void print(void);

    /**
     * @brief  Print the passed address to the output terminal
     * @param  Adres&   The structure that needs to be printed
     * @retval None
     */
    void printAddress(Adres&);

protected:
    QString _Naam;
    Adres _Adres;
    double _Setkorting = 0.0;
    double _Setkorting2 = 0.0;
    bool _Bedrijf = false;
    bool _Verwijderd = false;
    ClientType _ClientType = ClientType_Personal;
    int _KlantID = 0;
};

#endif // KLANT_H
