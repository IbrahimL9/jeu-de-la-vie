#include <iostream>
#include "grille.hh"

using namespace std;

int main()
{
    grille g(14,7);
    //err
    coordonnee x=2;
    coordonnee y=4;
    g.ajouterstructure(structure::planeur,x,y);
    g.afficher();
    std::cout<<std::endl;
    g.evolution(g);
    g.afficher();
    std::cout<<std::endl;
    std::string s;
    while (s.empty()) {
        std::getline(std::cin, s);
        g.evolution(g);
        g.afficher();
        std::cout<<std::endl;
    }

}
