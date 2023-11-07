#pragma once
#include <vector>


using coordonnee= int;
enum etatcellule { vivant,mort };
enum class structure {oscillateurligne,floraison, planeur, oscillateurcroix};

class grille {

  private:
    std::vector <std::vector<etatcellule>> etat;

  public:
    grille(const coordonnee &largeur ,const coordonnee &hauteur);
    void vider();
    bool vivante(coordonnee i,coordonnee j);
    void generer(coordonnee i,coordonnee j);
    void tuer(coordonnee i,coordonnee j);
    void afficher();
    void ajouterstructure(structure s,coordonnee x,coordonnee y);
    unsigned int vivantes(coordonnee x,coordonnee y);
    void evolution(grille g);
};

