#ifndef KLANT_H
#define KLANT_H

#include <QString>

#include "globals.h"

class Klant
{
public:
    // ctor
    Klant(QString naam, Adres adres, double smallKorting, double bigKorting, bool verwijderd);
    // dtor
    virtual ~Klant();

    // getters
    QString getNaam(void);
    Adres getAdres(void);
    double getSetKorting(void);
    bool getBedrijf(void);
    double getSetkorting2(void);

    // setters
    void setNaam(QString);
    void setAdres(Adres);
    void setSetkorting(double);
    void setBedrijf(bool);
    void setSetkorting2(double);

protected:
    QString _Naam;
    Adres _Adres;
    double _Setkorting;
    bool _Bedrijf;
    double _Setkorting2;
    bool _Verwijderd;
};

#endif // KLANT_H
