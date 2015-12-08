#ifndef BEDRIJFSKLANT_H
#define BEDRIJFSKLANT_H

#include <QString>

#include "globals.h"
#include "klant.h"

class Bedrijfsklant final : public Klant
{
public:
    // ctor
    Bedrijfsklant(QString naam, Adres adres, double smallKorting, double bigKorting, QString btwnummer, double volumekorting, double bedrijfskorting, bool verwijderd, int klantenID = 0);
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

    /**
     * @brief  Print the current client to the output terminal
     * @param  None
     * @retval None
     */
    void print(void) override;

private:
    QString _BTWnummer;
    double _Bedrijfskorting;
    double _Volumekorting;

};

#endif // BEDRIJFSKLANT_H
