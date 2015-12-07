#ifndef ARTIKEL_H
#define ARTIKEL_H

#include <QString>

#include "globals.h"

class Artikel
{
public:
    // ctor
    Artikel();
    // dtor
    virtual ~Artikel();

    // getters
    virtual QString getNaam(void);
    virtual QString getFabrikant(void);
    virtual double getPrijs(void);
    virtual double getDiameter(void);
    virtual ArtikelType getType(void);
    virtual int getAantal(void);

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
