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
    int getFactuurnummer(void) const;
    int getKlant(void) const;
    QMap<int, int> getArtikels(void) const;
    double getTotaalprijs(void) const;
    double getKorting(void) const;

    // setters
    void setFactuurnummer(int);
    void setKlant(int);
    void setArtikels(QMap<int,int>);
    void setTotaalprijs(double);
    void setKorting(double);

    void print(void);

private:
    int _Factuurnummer;
    int _Klant = 0;
    QMap<int, int> _ArtikelCount;
    double _Totaalprijs;
    double _Korting;
};

#endif // FACTUUR_H
