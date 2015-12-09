#ifndef BAND_H
#define BAND_H

#include "artikel.h"
#include "globals.h"

class Band final : public Artikel
{
public:
    // ctor
    Band(double breedte, double hoogte, char snelheidsindex, Seizoen seizoen, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal);
    // dtor
    virtual ~Band();

    // getters
    const double getBreedte(void) const;
    const double getHoogte(void) const;
    const char getSnelheidsindex(void) const;
    const Seizoen getSeizoen(void) const;

    // setters
    void setBreedte(double);
    void setHoogte(double);
    void setSnelheidsindex(char);
    void setSeizoen(Seizoen);

private:
    double _Breedte;
    double _Hoogte;
    char _Snelheidsindex;
    Seizoen _Seizoen;
};

#endif // BAND_H
