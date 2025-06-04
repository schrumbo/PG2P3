#include "drache.h"
#include "reiseplan.h"


// ***** Aufgabe 8b: Konstruktor anpassen *****
Drache::Drache(std::string dN, std::string mP, std::string dA, double g, double a, double e, double dP)
    : drachenName(dN), meinPlayer(mP), drachenArt(dA), geschwindigkeit(g), ausdauer(a), erholung(e), drachenPreis(dP)
{}

Drache::Drache(const json& j) {
    drachenName   = j["drachenName"];
    meinPlayer    = j["meinPlayer"];
    drachenArt    = j["drachenArt"];
    geschwindigkeit = j["geschwindigkeit"];
    ausdauer      = j["ausdauer"];
    erholung      = j["erholung"];
    drachenPreis  = j["drachenPreis"];

    if (j.contains("reiseplaene")) {
        for (const auto& rp : j["reiseplaene"]) {
            reiseplaene.push_back(new Reiseplan(rp));
        }
    }
}


Drache::~Drache() {
    for (auto* r : reiseplaene) {
        delete r;
    }
    reiseplaene.clear();
}

json Drache::to_json() const {
    json j;
    j["drachenName"] = drachenName;
    j["meinPlayer"] = meinPlayer;
    j["drachenArt"] = drachenArt;
    j["geschwindigkeit"] = geschwindigkeit;
    j["ausdauer"] = ausdauer;
    j["erholung"] = erholung;
    j["drachenPreis"] = drachenPreis;

    j["reiseplaene"] = json::array();
    for (const auto& plan : reiseplaene) {
        j["reiseplaene"].push_back(plan->to_json());
    }

    return j;
}

// --------- Reisen verwalten ---------

void Drache::addReiseplan(Reiseplan* rp) {
    reiseplaene.push_back(rp);
}


Reiseplan* Drache::findeReiseplan(string name) {
    for (Reiseplan* rp : reiseplaene) {
        if (rp->getName() == name) return rp;
    }
    return nullptr;
}

bool Drache::loescheReiseplan(std::string name){
    auto it = std::find_if(reiseplaene.begin(), reiseplaene.end(),[&name](Reiseplan* r) { return r->getName() == name; });

    if (it != reiseplaene.end()) {
        delete *it;
        reiseplaene.erase(it);
        return true;
    }
    return false;
}



// --------- getter ---------
string Drache::getDrachenName() const { return drachenName; }
string Drache::getMeinPlayer() const { return meinPlayer; }
//string Drache::getDrachenArt() const { return drachenArt; }
double Drache::getGeschwindigkeit() const { return geschwindigkeit; }
double Drache::getAusdauer() const { return ausdauer; }
double Drache::getErholung() const { return erholung; }
double Drache::getDrachenPreis() const { return drachenPreis; }
vector<Reiseplan*>& Drache::getReiseplaene() { return reiseplaene; }

// --------- setter ---------
void Drache::setDrachenName(const string& newDrachenName) { drachenName = newDrachenName; }
void Drache::setMeinPlayer(const string& newMeinPlayer) { meinPlayer = newMeinPlayer; }
