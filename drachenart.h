#ifndef DRACHENART_H
#define DRACHENART_H

#include "drache.h"

class Nachtschatten : public Drache {
public:
    // ***** Aufgabe 8b: zu ändernder Konstruktor ersetzt alten Konstruktor Nachtschatten() *****
    Nachtschatten(std::string dName, std::string mPlayer, std::string dArt = "Nachtschatten",
                  double g = 160.0, double a = 6.5, double e = 1.75, double dPreis = 5100.0)
        : Drache(dName, mPlayer, dArt, g, a, e, dPreis) { }


    Nachtschatten(const json& j) : Drache(j) { }

    std::string getDrachenArt() const { return "Nachtschatten"; }
};


class Tagschatten : public Drache {
public:

    Tagschatten(std::string dName, std::string mPlayer, std::string dArt = "Tagschatten",
                double g = 170.0, double a = 8.75, double e = 2.25, double dPreis = 3500) : Drache (dName, mPlayer, dArt, g, a, e, dPreis){}

    Tagschatten(const json& j) : Drache(j) {}

    std::string getDrachenArt() const override {
        return drachenArt;
    }
};

class ToedlicherNadder : public Drache {
public:

    ToedlicherNadder(std::string dName, std::string mPlayer, std::string dArt = "ToedlicherNadder",
                     double g = 140.0, double a = 9.5, double e = 1.5, double dPreis = 3750) : Drache (dName, mPlayer, dArt, g, a, e, dPreis){}


    ToedlicherNadder(const json& j) : Drache(j) {}

    std::string getDrachenArt() const override {
        return drachenArt;
    }
};

class Skrill : public Drache {
public:


    Skrill(std::string dName, std::string mPlayer, std::string dArt = "Skrill",
           double g = 190.0, double a = 7.25, double e = 3.5, double dPreis = 4200) : Drache (dName, mPlayer, dArt, g, a, e, dPreis){}

    Skrill(const json& j) : Drache(j) {}

    std::string getDrachenArt() const override {
        return drachenArt;
    }
};

#endif // DRACHENART_H
