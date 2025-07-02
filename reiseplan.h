#ifndef REISEPLAN_H
#define REISEPLAN_H

#include "drachenreise.h"
#include <vector>
#include <string>

class Reiseplan {

public:
    Reiseplan(std::string start="unbekannt", std::string ziel="unbekannt");
    Reiseplan(const json& j);
    ~Reiseplan();

    json to_json() const;
    void addReise(Drachenreise* r);
    void addPassagier(std::string name);

    bool loescheDrachenreise(int reiseNummer);
    bool loeschePassagier(std::string name);
    double berechnePreisFuerPassagier(std::string passagier);
    double berechneGesamtpreis();

    // --------- getter ---------
    std::string getStartOrt() const;
    std::string getZielOrt() const;
    double getGesamtpreis() const;
    int getReiseplanNummer() const;
    std::string& getName();
    vector<Drachenreise*>& getReiseabschnitte();
    vector<std::string>& getPassagiere();
    std::string getPlanBeginn();
    std::string getPlanEnde();


private:
    static int naechsteNummer;
    int reiseplanNummer;
    std::string name;
    std::string startOrt;
    std::string zielOrt;
    std::vector<Drachenreise*> reisen;
    vector<std::string> passagierListe;
};

#endif // REISEPLAN_H
