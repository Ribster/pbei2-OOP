#ifndef BAND_H
#define BAND_H

#include "artikel.h"
#include "globals.h"

class Band final : public Artikel
{
public:
    // ctor
    Band();
    // dtor
    virtual ~Band();

    // getters
    double getBreedte(void);
    double getHoogte(void);
    char getSnelheidsindex(void);
    Seizoen getSeizoen(void);

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
