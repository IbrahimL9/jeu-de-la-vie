#include "grille.hh"
#include <iostream>


grille::grille(const coordonnee &largeur ,const coordonnee &hauteur){
    etat.resize(hauteur, std::vector<etatcellule>(largeur, etatcellule::mort));
}

void grille::vider()
{
    for(coordonnee y(0);y<coordonnee(etat.size());++y){
            for(coordonnee x(0);x<coordonnee(etat[y].size());++x){
                if(etat[y][x]==etatcellule::vivant)
                    etat[y][x]=etatcellule::mort;
            }
    }
}

bool grille::vivante(coordonnee i, coordonnee j)
{
    if( ( (i>=0) and (i<coordonnee(etat.size()))) and ( (j>=0) and (j<coordonnee(etat[0].size())))){
        return (etat[i][j]==etatcellule::vivant);
    }
    return false;
}

void grille::generer(coordonnee i, coordonnee j)
{
    if( (i<coordonnee(etat.size())) and (j<coordonnee(etat[0].size())))
        etat[i][j]=etatcellule::vivant;
}

void grille::tuer(coordonnee i, coordonnee j)
{
    etat[i][j]=etatcellule::mort;
}

void grille::afficher()
{
    for(coordonnee y(0);y<coordonnee(etat.size());++y)
    {
        std::cout<<"|";
            for(coordonnee x(0);x<coordonnee(etat[y].size());++x){
                if(etat[y][x]==etatcellule::vivant)
                    std::cout<<"*|";
                else std::cout<<" |";
            }
            std::cout<<std::endl;
    }
}

void grille::ajouterstructure(structure s, coordonnee x, coordonnee y)
{
    switch (s) {
         case structure::oscillateurligne:
            generer(x,y);
            generer(x,y+1);
            generer(x,y+2);
         break;
         case structure::floraison:
            generer(x,y+1);
            generer(x,y+2);
            generer(x,y+3);
            generer(x+1,y);
            generer(x+1,y+2);
            generer(x+1,y+4);
            generer(x+2,y+1);
            generer(x+2,y+2);
            generer(x+2,y+3);
         break;
         case structure::planeur:
            generer(x,y);
            generer(x,y+1);
            generer(x,y+2);
            generer(x+1,y+2);
            generer(x+2,y+1);
         break;
         case structure::oscillateurcroix:
            generer(x,y+1);
            generer(x+1,y);
            generer(x+1,y+1);
            generer(x+1,y+2);
            generer(x+2,y+1);
         break;
    }
}

unsigned int grille::vivantes(coordonnee x,coordonnee y)
{
    unsigned int o(0);

    if(grille::vivante(x,y+1)) ++o;
    if(grille::vivante(x,y-1)) ++o;
    if(grille::vivante(x+1,y-1)) ++o;
    if(grille::vivante(x+1,y)) ++o;
    if(grille::vivante(x+1,y+1)) ++o;
    if(grille::vivante(x-1,y-1)) ++o;
    if(grille::vivante(x-1,y)) ++o;
    if(grille::vivante(x-1,y+1)) ++o;

    return o;
}

void grille::evolution(grille g)
{
    for(coordonnee x(0);x<coordonnee(g.etat.size());++x){
            for(coordonnee y(0);y<coordonnee(g.etat[x].size());++y)
            {
                if(g.etat[x][y]==etatcellule::mort){
                    if(grille::vivantes(x,y)==3)
                        generer(x,y);
                }
                else
                      if ((grille::vivantes(x,y)<2) or (grille::vivantes(x,y)>=4))
                              tuer(x,y);

            }
    }
}


































