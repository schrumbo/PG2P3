#ifndef FILMSTUDIO_H
#define FILMSTUDIO_H

#include "drache.h"
#include <string>


struct ReiseInfo{
    int nummer;
    std::string name;
    std::string beginn;
    std::string ende;
};


class Filmstudio {
public:

    Filmstudio();
    ~Filmstudio();

    void einlesenJSON(const std::string& filename);
    void speichernJSON(const std::string& filename);

    Drache* sucheDrache(const std::string& name);
    void addDrache(Drache* d);
    bool loescheDrache(std::string name);

    std::vector<ReiseInfo> findeReiseplaeneAlsPlayer(const std::string& name);
    std::vector<ReiseInfo> findeReiseplaeneAlsPassagier(const std::string& name);

    // --------- getter ---------
    vector<Drache*>& getDrachenListe();
    Drachenreise* getDrachenreise(const int reiseNr);  // war getDrachenflug

private:
    vector<Drache*> drachenListe;
};

#endif // FILMSTUDIO_H
