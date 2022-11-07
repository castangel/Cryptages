#include "pch.h"
void Xor::xcd(std::string file, std::string fileout)
{
    string cle = xkey;
    file += ".txt";   
    fileout += ".txt";
	std::cout  << file << " en cours...\n";

    int j = 0;
    
    ifstream fichier(file, ios::in);                        // on ouvre le fichier en lecture
    ofstream fichierSortie(fileout, ios::out | ios::trunc); // on ouvre le fichier en �criture et on le vide s'il est plein

    if (fichier)                         // si l'ouverture a r�ussi
    {
        string ligne;                    // d�claration d'une cha�ne qui contiendra la ligne lue
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne du fichier dans "ligne"
        {
            for (int i = 0; i < ligne.size(); i++) {    // pour i allant de 0 � la longueur de la ligne
                int t = (ligne[i]);                     // t correspond au caract�re i de la ligne
                int r = cle[j];                         // r correspond au caract�re j de la cl�

                if (j < cle.size()) {                   // si j est inf�reieur � la longueur de la cl�        
                    j += 1;                             // on incr�mente j
                }
                else { j = 0; }                         // sinon on le remet � 0

                int rxor = t ^ r;                       // on fait un xor des caract�res t et r 
                fichierSortie << (char)rxor;            // on le sauvegarde dans le fichier de sortie sous forme de caract�re

            }
            fichierSortie << "\n";                      // on fait un saut de ligne entre chaque ligne
        }

        fichier.close();
        fichierSortie.close();
        cout << "Termine et enregistre dans " << fileout << endl;
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier d'entr�e !" << endl;
}

void Xor::setxkey(std::string xkey)
{
    this->xkey = xkey;
}