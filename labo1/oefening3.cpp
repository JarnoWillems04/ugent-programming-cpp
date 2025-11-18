#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    char ch1 = 'x';
    std::string s1 = "" + ch1; //Hier wordt eigenlijk een pointer verschoven
    std::cout << "karakter " <<  ch1  << " omgezet: " <<  s1 << "." << std::endl;

    char ch2 = 'y';
    std::string s2;
    s2 += ch2; // Hier wordt er aan overloading gedaan en weet hij wat er moet gebeuren
    std::cout << "karakter " <<  ch2  << " omgezet: " <<  s2 << "." << std::endl;
}
