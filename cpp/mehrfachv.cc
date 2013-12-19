// Importe und Deklarationen.
#include <string>
#include <iostream>

// Die folgende Zeile deklariert ein paar Sachen automatisch, damit klar wird,
// was ich meine. Es geht um das Qualifizieren einer Variablen, siehe unten,
// in main().
using namespace std;

//
// nachfolgend: eine Basisklasse.
//
class Person {
public:
    Person(string name) {
        this->name = name;
    }
    string name;
};

//
// nachfolgend: erbt von der Basisklasse
//
class Angestellter: virtual public Person {
public:
    Angestellter(int kennziffer, string name)
    : Person(name) {
        this->kennziffer = kennziffer;
    }
    int kennziffer;
};

//
// auch hier: Erbt von der Basisklasse
//
class Clubmitglied: virtual public Person {
public:
    Clubmitglied(int kennziffer, string name)
    : Person(name) {
        this->kennziffer = kennziffer;
    }
    int kennziffer;
};

//
// erbt von BEIDEN Subklassen. Wir haben hier eine Diamantenstruktur:
//                              Person
//                                /\
//                               /  \
//                              /    \
//                             /      \
//                   Clubmitglied    Angestellter
//                             \      /
//                              \    /
//                               \  /
//                                \/
//                           Schnittmenge
//
class Schnittmenge: virtual public Clubmitglied, virtual public Angestellter {
public:
    Schnittmenge(string name, int clubkennziffer, int angestelltenkennziffer)
    : Clubmitglied(clubkennziffer, name),
    Angestellter(angestelltenkennziffer, name),
    Person(name) {
    }
};

//
// ---------------------------- Hauptprogramm ----------------------------------
//
int main(int argc, char ** argv) {
    Schnittmenge herr_meier = Schnittmenge("Klaus Meier", 100, 1230);
    cout
    // nicht ambig: "name" ist von "Person" abstammend.
    << "Name: " << herr_meier.name << endl
    // muss disambiguiert werden: "kennziffer" von "Clubmitglied"
    << "Clubmitgliedsnummer " << herr_meier.Clubmitglied::kennziffer << endl
    // ebenso mit dieser "kennziffer", die von "Angestellter" vererbt wurde.
    << "Mitarbeiternummer " << herr_meier.Angestellter::kennziffer
    << endl;
}