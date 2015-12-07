#ifndef KLANT_H
#define KLANT_H

#include <QString>

#include "globals.h"

class Klant
{
public:
    // ctor
    Klant();
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

private:
    QString _Naam;
    Adres _Adres;
    double _Setkorting;
    bool _Bedrijf;
    double _Setkorting2;
};

#endif // KLANT_H
