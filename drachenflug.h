#ifndef DRACHENFLUG_H
#define DRACHENFLUG_H

#include "drachenreise.h"

class Drachenflug : public Drachenreise {
public:

    Drachenflug(std::string abf, std::string ank, std::string z, double e);
    Drachenflug(const json& j);

    json to_json() const override;
    std::string getTyp() const override;

    // --------- getter ---------
    int getFlugNummer() const;
    std::string getZiel() const;
    double getEntfernung() const;

    // --------- setter ---------
    void setZiel(const std::string& newZiel);
    void setEntfernung(double newEntfernung);

private:
    std::string ziel;
    double entfernung;
    int flugNummer;
    static int naechsteFlugNummer;
};

#endif // DRACHENFLUG_H
