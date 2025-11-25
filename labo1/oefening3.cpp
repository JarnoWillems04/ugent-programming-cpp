#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    char ch1 = 'x';
    string s1 = "" + ch1; //Hier wordt eigenlijk een pointer verschoven
    cout << "karakter " <<  ch1  << " omgezet: " <<  s1 << "." << endl;

    char ch2 = 'y';
    string s2;
    s2 += ch2; // Hier wordt er aan overloading gedaan en weet hij wat er moet gebeuren
    cout << "karakter " <<  ch2  << " omgezet: " <<  s2 << "." << endl;
}

/*
Het eerste stukje werkt niet. De reden: in de code
              "" + c
is de eerste term een (constante) c-string. Daar tel je met de +-operator een karakter bij.
Een c-string (= een pointer) + een char (eigenlijk een getal) willen we hier NIET.

Het tweede stukje werkt wel. De reden: de code
            string w = "";
zorgt ervoor dat de (constante) c-string "" omgezet wordt naar een standaardstring.
Als minstens 1 van beide termen een standaardstring is, kan de +-operator wel
gebruikt worden om strings aan elkaar te plakken.
*/
