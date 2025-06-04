#include "drachenflug.h"

int Drachenflug::naechsteFlugNummer = 1;

Drachenflug::Drachenflug(string abf, string ank, string z, double e)
    : Drachenreise(abf, ank, /*preis=*/e * 0.75), ziel(z), entfernung(e), flugNummer(naechsteFlugNummer++) {  // preis wird aus km * 0.75 berechnet
}


Drachenflug::Drachenflug(const json& j) : Drachenreise(j) {
    flugNummer = j["flugNummer"];
    ziel = j["ziel"];
    entfernung = j["entfernung"];

    if (flugNummer >= naechsteFlugNummer)
        naechsteFlugNummer = flugNummer + 1;
}


json Drachenflug::to_json() const {
    json j = to_json_base();  // gemeinsame Felder werden in neuer Basisklasse behandelt
    j["typ"] = "drachenflug";
    j["flugNummer"] = flugNummer;
    j["ziel"] = ziel;
    j["entfernung"] = entfernung;
    return j;
}


// --------- getter ---------
string Drachenflug::getTyp() const { return "drachenflug"; }
int Drachenflug::getFlugNummer() const { return flugNummer; }
string Drachenflug::getZiel() const { return ziel; }
double Drachenflug::getEntfernung() const { return entfernung; }

// --------- setter ---------
void Drachenflug::setZiel(const string& newZiel) { ziel = newZiel; }
void Drachenflug::setEntfernung(double newEntfernung) { entfernung = newEntfernung; }
