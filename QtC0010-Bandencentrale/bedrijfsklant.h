#ifndef BEDRIJFSKLANT_H
#define BEDRIJFSKLANT_H

#include <QString>

#include "globals.h"
#include "klant.h"

class Bedrijfsklant final : public Klant
{
public:
    // ctor
    Bedrijfsklant();
    // dtor
    virtual ~Bedrijfsklant();

    // getters
    QString getBTWnummer(void);
    bool getVolumekorting(void);
    bool getBedrijfskorting(void);
    bool getVerwijderd(void);

    // setters
    void setBTWnummer(QString);
    void setVolumekorting(bool);
    void setBedrijfskorting(bool);
    void setVerwijderd(bool);

private:
    QString _BTWnummer;
    bool _Volumekorting;
    bool _Bedrijfskorting;
    bool _Verwijderd;
};

#endif // BEDRIJFSKLANT_H
