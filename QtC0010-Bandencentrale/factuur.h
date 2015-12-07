#ifndef FACTUUR_H
#define FACTUUR_H

#include <QString>
#include <QVector>

#include "klant.h"
#include "artikel.h"

class Factuur final
{
public:
    // ctor
    Factuur();
    // dtor
    virtual ~Factuur();

    // getters
    int getFactuurnummer(void);
    Klant* getKlant(void);
    QVector<Artikel*> getArtikels(void);
    double getTotaalprijs(void);
    double getKorting(void);

    // setters
    void setFactuurnummer(int);
    void setKlant(Klant*);
    void setArtikels(QVector<Artikel*>);
    void setTotaalprijs(double);
    void setKorting(double);

private:
    int _Factuurnummer;
    Klant* _Klant;
    QVector<Artikel*> _Artikels;
    double _Totaalprijs;
    double _Korting;
};

#endif // FACTUUR_H
