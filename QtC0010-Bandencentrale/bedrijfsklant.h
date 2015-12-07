#ifndef BEDRIJFSKLANT_H
#define BEDRIJFSKLANT_H

#include <QString>

#include "globals.h"
#include "klant.h"

class Bedrijfsklant final : public Klant
{
public:
    // ctor
    Bedrijfsklant(QString naam, Adres adres, double smallKorting, double bigKorting, QString btwnummer, bool volumekorting, bool bedrijfskorting, bool verwijderd);
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
    bool _Bedrijfskorting;
    bool _Volumekorting;

};

#endif // BEDRIJFSKLANT_H
