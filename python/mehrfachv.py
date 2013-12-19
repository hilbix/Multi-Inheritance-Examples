#!/usr/bin/python2.7
# -*- Encoding: utf-8 -*-
from __future__ import print_function

class Person(object):
    def __init__(self, name):
        self.name = name

class Clubmitglied(Person):
    def __init__(self, name, kennziffer):
        Person.__init__(self, name)
        self.kennziffer = kennziffer

    def get_kennziffer(self):
        return self.kennziffer

class Angestellter(Person):
    def __init__(self, name, kennziffer):
        Person.__init__(self, name)
        self.kennziffer = kennziffer

    def get_kennziffer(self):
        return self.kennziffer

class Schnittmenge(Angestellter, Clubmitglied):
    def __init__(self, name, angest_kennziffer, club_kennziffer):
        Angestellter.__init__(self, name, angest_kennziffer)
        Clubmitglied.__init__(self, name, club_kennziffer)

    # hier machen wir den Versuch, durch das Qualifizieren der jeweils gemeinten
    # Klasse zu disambiguieren. Funktioniert leider nicht: es gibt nur ein
    # einziges "self", und auf dem gibt es nur ein einziges Feld mit dem Namen
    # "kennziffer".
    def get_club_kennziffer(self):
        return Clubmitglied.get_kennziffer(self)

    def get_ange_kennziffer(self):
        return Angestellter.get_kennziffer(self)


if __name__ == "__main__":
    herr_meier = Schnittmenge("Andreas Meier", 1, 123)
    print("Name: %s\nClubmitglied:%d\nPersonalnummer:%d" % (
        herr_meier.name,
        # und sogar mit den Qualifikationen (siehe Zeilen 35 und 38)
        # funktioniert es nicht. Die Variable "kennziffer" ist nur einmal auf
        # der Instanz vorhanden. Beide Funktionen zeigen dasselbe Ergebnis!
        herr_meier.get_club_kennziffer(),
        herr_meier.get_ange_kennziffer()))