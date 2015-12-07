#ifndef VELG_H
#define VELG_H

#include "artikel.h"
#include "globals.h"

class Velg final : public Artikel
{
public:
    // ctor
    Velg();
    // dtor
    virtual ~Velg();

    // getters
    double getBreedte(void);
    Kleuren getKleur(void);
    bool getAluminium(void);

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
