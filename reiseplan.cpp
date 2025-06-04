#include "reiseplan.h"
#include "drachenflug.h"
#include "nachtlager.h"

int Reiseplan::naechsteNummer = 1;

Reiseplan::Reiseplan(string start, std::string ziel)
    : reiseplanNummer(naechsteNummer++), startOrt(start), zielOrt(ziel) {
    name = "Reiseplan " + to_string(reiseplanNummer);
}

Reiseplan::Reiseplan(const json& j) {
    reiseplanNummer = j["reiseplanNummer"];
    name = j["name"];
    passagierListe = j["passagiere"];

    if (reiseplanNummer >= naechsteNummer) {
        naechsteNummer = reiseplanNummer + 1;
    }

    for (const auto& r : j["reiseabschnitte"]) {
        std::string typ = r["typ"];
        Drachenreise* rObj = nullptr;
        if (typ == "drachenflug") {
            rObj = new Drachenflug(r);
        } else if (typ == "nachtlager") {
            rObj = new Nachtlager(r);
        }
        if (rObj) {
            rObj->setReiseplan(this);  // <<< WICHTIG: setze den Rückverweis
            reisen.push_back(rObj);
        }
    }
}

json Reiseplan::to_json() const {
    json j;
    j["reiseplanNummer"] = reiseplanNummer;
    j["passagiere"] = passagierListe;
    j["name"] = name;
    j["reiseabschnitte"] = json::array();

    for (const auto& reise : reisen) {
        j["reiseabschnitte"].push_back(reise->to_json());  // Polymorphe Methode in Drachenflug/Nachtlager
    }

    return j;
}

Reiseplan::~Reiseplan() {
    for (auto* r : reisen) {
        delete r;
    }
    reisen.clear();
}


void Reiseplan::addReise(Drachenreise* reise) {
    reise->setReiseplan(this);  // Setzt die Rückreferenz: Drachenreise soll ihren Reiseplan kennen
    reisen.push_back(reise);
}


void Reiseplan::addPassagier(string name) {
    passagierListe.push_back(name);
}

bool Reiseplan::loescheDrachenreise(int reiseNummer) {
    auto it = std::find_if(reisen.begin(), reisen.end(),[reiseNummer](const Drachenreise* r) { return r->getReiseNummer() == reiseNummer; });

    if (it != reisen.end()) {
        delete *it;
        reisen.erase(it);
        return true;
    }
    return false;
}

bool Reiseplan::loeschePassagier(std::string name) {
    auto it = std::find(passagierListe.begin(), passagierListe.end(), name);
    if (it != passagierListe.end()) {
        passagierListe.erase(it);
        return true;
    }
    return false;
}








// --------- getter ---------
int Reiseplan::getReiseplanNummer() const { return reiseplanNummer; }
string& Reiseplan::getName() { return name; }
string Reiseplan::getZielOrt() const { return zielOrt; }
vector<string>& Reiseplan::getPassagiere() { return passagierListe; }
vector<Drachenreise*>& Reiseplan::getReiseabschnitte() { return reisen; }

std::string Reiseplan::getPlanBeginn(){
    if (!reisen.empty()) {
        return reisen.front()->getAbfahrt();
    }
    return "";
}

std::string Reiseplan::getPlanEnde(){
    if (!reisen.empty()) {
        return reisen.back()->getAnkunft();
    }
    return "";
}




