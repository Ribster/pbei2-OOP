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
    Factuur(int factuurnummer, int klant, QMap<int, int> artikelcount, double totaalprijs, double korting);
    // dtor
    virtual ~Factuur();

    // getters
    const int getFactuurnummer(void) const;
    const int getKlant(void) const;
    const QMap<int, int> getArtikels(void) const;
    const double getTotaalprijs(void) const;
    const double getKorting(void) const;

    // setters
    void setFactuurnummer(int);
    void setKlant(int);
    void setArtikels(QMap<int,int>);
    void setTotaalprijs(double);
    void setKorting(double);

private:
    int _Factuurnummer;
    int _Klant = 0;
    QMap<int, int> _ArtikelCount;
    double _Totaalprijs;
    double _Korting;
};

#endif // FACTUUR_H
