#ifndef NACHTLAGER_H
#define NACHTLAGER_H

#include "drachenreise.h"

class Nachtlager : public Drachenreise {
public:
    Nachtlager(std::string abf, std::string ank, double p, std::string ort, std::string typ, int ruhe);
    Nachtlager(const json& j);

    json to_json() const override;
    std::string getTyp() const override;

    // --------- getter ---------
    int getLagerID() const;
    std::string getLagerOrt() const;
    std::string getUnterkunftsTyp() const;
    double getRuheLevel() const;

    //SETTER

    void setLagerOrt(const string& ort);
    void setAbfahrt(const string& abf);
    void setAnkunft(const string& ank);
    void setPreis(double p);
    void setRuheLevel(double ruhe);
    void setUnterkunftsTyp(const string& typ);

private:
    static int naechsteLagerID;
    std::string lagerOrt;
    std::string unterkunftsTyp;
    double ruheLevel;
    int lagerID;
};

#endif // NACHTLAGER_H
