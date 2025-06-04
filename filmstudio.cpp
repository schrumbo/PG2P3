#include "filmstudio.h"
#include "drachenart.h"
#include <fstream>
#include <QMessageBox>
#include <QString>

using namespace std;

Filmstudio::Filmstudio() {
    //einlesenJSON("filmstudio.json");     // ***** Aufgabe 8e: Auslagern in das Menü der GUI *****
}

Filmstudio::~Filmstudio() {
    for (auto d : drachenListe)
        delete d;
    drachenListe.clear();
}


Drache* Filmstudio::sucheDrache(const string& name) {
    for (auto d : drachenListe) {
        if (d->getDrachenName() == name) {
            return d;
        }
    }
    return nullptr;
}

vector<Drache*>& Filmstudio::getDrachenListe() {
    return drachenListe;
}

Drachenreise* Filmstudio::getDrachenreise(const int reiseNr) {
    for (Drache* d : drachenListe) {
        for (Reiseplan* plan : d->getReiseplaene()) {
            for (Drachenreise* r : plan->getReiseabschnitte()) {
                if (r->getReiseNummer() == reiseNr) {
                    return r;
                }
            }
        }
    }
    return nullptr;
}

void Filmstudio::addDrache(Drache* d) {
    drachenListe.push_back(d);
}


// ***** Aufgabe 8f: mit Exceptionhandling *****
void Filmstudio::einlesenJSON(const std::string& filename) {
    drachenListe.clear();
    std::ifstream file(filename);
    if (!file.is_open()) {
        // ohne Exception wäre hier eine Mitteilung dafür per QMessageBox und analog dazu unten:
        // QMessageBox::critical(nullptr, "Fehler", "Konnte die Datei nicht öffnen: " + QString::fromStdString(filename));
        throw std::runtime_error("Konnte Datei nicht öffnen: " + filename);
    }

    json j;
    file >> j;

    for (const auto& dracheJson : j) {
        std::string art;
        try {
            art = dracheJson.at("drachenArt").get<std::string>();
        } catch (const json::exception& e) {
            // Exception wird gefangen und an die GUI weitergegeben, damit hier keine QMessageBox der GUI
            // ohne Exception wäre hier die das try und catch nicht und die Mitteilung dafür per QMessageBox
            throw std::runtime_error("Fehlendes oder ungültiges Feld 'drachenArt': " + std::string(e.what()));
        }

        Drache* d = nullptr;

        if (art == "Nachtschatten")
            d = new Nachtschatten(dracheJson);
        else if (art == "Tagschatten")
            d = new Tagschatten(dracheJson);
        else if (art == "ToedlicherNadder")
            d = new ToedlicherNadder(dracheJson);
        else if (art == "Skrill")
            d = new Skrill(dracheJson);
        else
            throw std::runtime_error("Unbekannte Drachenart: " + art);

        drachenListe.push_back(d);
    }
}


void Filmstudio::speichernJSON(const std::string& filename) {
    json j;

    for (auto d : drachenListe) {
        j.push_back(d->to_json());
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        QMessageBox::critical(nullptr, "Fehler", "Konnte Datei " + QString::fromStdString(filename) + " nicht öffnen!");
    }

    file << j.dump(4);
    file.close();

    if (!file) {
        QMessageBox::critical(nullptr, "Fehler", "Konnte nicht in Datei " + QString::fromStdString(filename) + " schreiben!");
    }
}


bool Filmstudio::loescheDrache(std::string name){
    auto it = std::find_if(drachenListe.begin(), drachenListe.end(), [&name](const Drache* d) {return d->getDrachenName() == name;});
    if(it != drachenListe.end()){
        delete *it;
        drachenListe.erase(it);
        return true;
    }
    return false;
}


std::vector<ReiseInfo> Filmstudio::findeReiseplaeneAlsPlayer(const std::string& name){


}
std::vector<ReiseInfo> Filmstudio::findeReiseplaeneAlsPassagier(const std::string& name) {

}


