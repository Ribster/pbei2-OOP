#ifndef ARTIKEL_H
#define ARTIKEL_H

#include <QString>

#include "globals.h"

class Artikel
{
public:
    // ctor
    Artikel(QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal);
    // dtor
    virtual ~Artikel();

    // getters
    virtual const QString getNaam(void) const;
    virtual const QString getFabrikant(void) const;
    virtual const double getPrijs(void) const;
    virtual const double getDiameter(void) const;
    virtual const ArtikelType getType(void) const;
    virtual const int getAantal(void) const;

    // setters
    virtual void setNaam(QString);
    virtual void setFabrikant(QString);
    virtual void setPrijs(double);
    virtual void setDiameter(double);
    virtual void setType(ArtikelType);
    virtual void setAantal(int);

protected:
    QString _Naam;
    QString _Fabrikant;
    double _Prijs;
    double _Diameter;
    ArtikelType _Type;
    int _Aantal;
};

#endif // ARTIKEL_H
