# Multiple Vererbung — Beispiele
Die beiden Verzeichnisse zeigen zwei Programmiersprachen dabei, wie Multiple 
Vererbung funktioniert. 

## Disclaimer
Natürlich wurde bei beiden Beispielen, um klar zu machen, worum es geht, auf
für Produktionscode unerlässliche Form teils verzichtet. 

## C++
In C++ ist die multiple Vererbung erlaubt; sie erzeugt
in verschiedenen Namensräumen gleichnamige Felder, die durch Qualifikation 
mit einem Namensraum und dem Namensraum-Operator `::` disambiguiert werden 
können. 

## Python
In Python verstehen sich die "Basisklassen" eher als *Mixins*. Es wird nur
in einem einzelnen Namensraum ein Datenfeld erzeugt, auch wenn es dieses
Datenfeld mehrfach gibt. Es muss also besonders darauf geachtet werden, 
dass Methoden, die in der Klassenliste weiter links stehen, Präzedenz haben;
dies kann auch zu schwer zu findenden Bugs führen, wenn eine Methode einer
weiter rechts stehenden "Basisklasse" (eines weiter rechts stehenden Mixins)
mit einem Datenfeld interagieren möchte, das nicht mehr der Kontrolle der 
eigenen Klasse unterliegt.

## MI vs. Mixins
Hier zeigt sich außerdem der grundlegende Unterschied zwischen MI und Mixins. 
Die Eigenschaften von Mixins werden in ihre "erbenden" Klassen 
"hineingemischt". Eine "echte" Mehrfachvererbung muss den Zugriff auf die
mit der Instanz mitgeführten Basisklassen-Eigenschaften auch bei einer 
Namenskollision ermöglichen. 

Suggestions welcome.
