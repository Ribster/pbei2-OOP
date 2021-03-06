#ifndef ARTIKEL_H
#define ARTIKEL_H

#include <QString>

#include "globals.h"

class Artikel
{
public:
    // ctor
    Artikel(QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal, int artikelID, bool verwijderd);
    // dtor
    virtual ~Artikel();

    // getters
    virtual QString getNaam(void) const;
    virtual QString getFabrikant(void) const;
    virtual double getPrijs(void) const;
    virtual double getDiameter(void) const;
    virtual ArtikelType getType(void) const;
    virtual int getAantal(void) const;
    virtual int getArtikelID(void) const;
    bool getVerwijderd(void) const;

    // setters
    virtual void setNaam(QString);
    virtual void setFabrikant(QString);
    virtual void setPrijs(double);
    virtual void setDiameter(double);
    virtual void setType(ArtikelType);
    virtual void setAantal(int);
    virtual void setArtikelID(int);
    void setVerwijderd(bool);

protected:
    QString _Naam;
    QString _Fabrikant;
    double _Prijs;
    double _Diameter;
    ArtikelType _Type;
    int _Aantal = 0;
    int _ArtikelID = 0;
    bool _Verwijderd = false;
};

#endif // ARTIKEL_H
