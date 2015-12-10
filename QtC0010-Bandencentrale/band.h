#ifndef BAND_H
#define BAND_H

#include <QChar>

#include "artikel.h"
#include "globals.h"

class Band final : public Artikel
{
public:
    // ctor
    Band(double breedte, double hoogte, QChar snelheidsindex, Seizoen seizoen, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal, int artikelID);
    // dtor
    virtual ~Band();

    // getters
    double getBreedte(void) const;
    double getHoogte(void) const;
    QChar getSnelheidsindex(void) const;
    Seizoen getSeizoen(void) const;

    // setters
    void setBreedte(double);
    void setHoogte(double);
    void setSnelheidsindex(char);
    void setSeizoen(Seizoen);

    void print(void);

private:
    double _Breedte;
    double _Hoogte;
    QChar _Snelheidsindex;
    Seizoen _Seizoen;
};

#endif // BAND_H
