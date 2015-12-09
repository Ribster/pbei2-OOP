#ifndef VELG_H
#define VELG_H

#include "artikel.h"
#include "globals.h"

class Velg final : public Artikel
{
public:
    // ctor
    Velg(double breedte, Kleuren kleur, bool aluminium, QString naam, QString fabrikant, double prijs, double diameter, ArtikelType type, int aantal);
    // dtor
    virtual ~Velg();

    // getters
    const double getBreedte(void) const;
    const Kleuren getKleur(void) const;
    const bool getAluminium(void) const;

    // setters
    void setBreedte(double);
    void setKleur(Kleuren);
    void setAluminium(bool);

private:
    double _Breedte;
    Kleuren _Kleur;
    bool _Aluminium;
};

#endif // VELG_H
