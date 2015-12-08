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
    QString getNaam(void);
    Adres getAdres(void);
    double getSetKorting(void);
    bool getBedrijf(void);
    double getSetkorting2(void);

    /**
     * @brief  Getting the unique client identifier; Initialized to zero.
     * @param  None
     * @retval int      Client identification, if zero, uninitialized
     */
    int getClientID(void);

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
    double _Setkorting;
    double _Setkorting2;
    bool _Bedrijf;
    bool _Verwijderd;
    ClientType _ClientType;
    int _KlantID;
};

#endif // KLANT_H
