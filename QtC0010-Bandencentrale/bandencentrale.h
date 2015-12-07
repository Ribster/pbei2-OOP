#ifndef BANDENCENTRALE_H
#define BANDENCENTRALE_H

#include <QString>
#include <QVector>

#include "klant.h"
#include "artikel.h"
#include "globals.h"

class Bandencentrale final
{
public:
    // ctor
    Bandencentrale();
    // dtor
    virtual ~Bandencentrale();

    // getters
    QString getNaam(void);
    Adres getAdres(void);
    QVector<Klant*> getKlanten(void);
    QVector<Artikel*> getArtikels(void);

    // setters
    void setNaam(QString);
    void setAdres(Adres);
    void setKlanten(QVector<Klant*>);
    void setArtikels(QVector<Artikel*>);

private:
    QString _Naam;
    Adres _Adres;
    QVector<Klant*> _Klanten;
    QVector<Artikel*> _Artikels;
};

#endif // BANDENCENTRALE_H
