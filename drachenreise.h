#ifndef DRACHENREISE_H
#define DRACHENREISE_H

#include <string>
#include "json.hpp"

class Reiseplan;  // Vorwärtsdeklaration

using namespace std;
using json = nlohmann::json;


class Drachenreise {
public:
    Drachenreise(std::string abf, std::string ank, double p);
    Drachenreise(const json& j);
    virtual ~Drachenreise() = default;          // virtual notwendig für delete aller Objekte (default um als Standardversion zu verwenden)

    virtual json to_json() const = 0;           // macht Basisklasse Drachenreise abstrakt
    virtual std::string getTyp() const = 0;     // Gibt "drachenflug" oder "nachtlager" zurück, muss überschrieben werden

    json to_json_base() const;

    // --------- getter ---------
    int getReiseNummer() const;
    std::string getAbfahrt() const;
    std::string getAnkunft() const;
    double getPreis() const;
    Reiseplan *getReiseplan() const;            // getter da Drachenreise Reiseplan kennen soll

    // --------- setter ---------
    void setReiseplan(Reiseplan* plan);         // setter da Drachenreise Reiseplan kennen soll

protected:
    static int naechsteNummer;
    int reiseNummer;
    std::string abfahrt;
    std::string ankunft;
    double preis;
    Reiseplan* reiseplan = nullptr;             //  jede Drachenreise soll ihren Reiseplan kennen
};

#endif // DRACHENREISE_H
