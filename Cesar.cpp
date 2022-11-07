#include "pch.h"


/// ########################### Cryptage c�sar ################################

void Cesar::cc(std::string file, std::string fileout)
{
    file += ".txt";
	std::cout << "cryptage cesar de " << file << " en cours...\n";
    fileout += ".txt";

    ifstream fichier(file, ios::in); // on ouvre le fichier en lecture
    ofstream fichierSortie(fileout, ios::out | ios::trunc);  //ouverture en �criture et on vide le contenu du fichier si jamais il est plein

    if (fichier)                     // si l'ouverture a r�ussi
    {
        string ligne;                    // d�claration d'une cha�ne qui contiendra la ligne lue
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            for (int i = 0; i < ligne.size(); i++) { // pour i allant de 0 � la fin de la ligne
                int t = (ligne[i]);                  // t contient le caract�re i de la ligne 

                if (t >= 'a' and t <= 'z')           // si t est une lettre minuscule 
                {
                    t += ckey;                       // on ajoute � t la cl� c�sar
                    if (t > 122) {                   // si le r�sultat de la somme est  sup�rieur � 122 (qui correspond � z en ASCII)
                        t = t  - 26;                 // on enl�ve la longueur de l'alphabet
                    }                                
                }
                else if (t >= 'A' and t <= 'Z')     // si t est une lettre Majuscule 
                {
                    t += ckey;                      // on ajoute � t la cl� c�sar
                    if (t > 91) {                   // si le r�sultat de la somme est sup�rieur � 91 (qui correspond � Z en ASCII)
                        t = t - 26;                 // on enl�ve la longueur de l'alphabet
                    }
                }

                ligne[i] = (char)t;                 // on change le caract�re i de ligne par le nouveau
            }
            fichierSortie << ligne << "\n";         // on ajoute la ligne dans le fichier de sortie
        }

        fichier.close();
        fichierSortie.close();
        cout << "termine et enregistre dans "<< fileout << endl;
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier d'entr�e !" << endl;

}

/// ########################### D�cryptage c�sar ################################

void Cesar::cd(std::string file, std::string fileout)
{

    file += ".txt";
    std::cout << "decryptage cesar de " << file << "en cours...\n";
    fileout += ".txt";

    ifstream fichier(file, ios::in); // on ouvre le fichier en lecture
    ofstream fichierSortie(fileout, ios::out | ios::trunc);  // on ouvre le fichier en �criture et on vide le contenu du fichier si jamais il est plein

    if (fichier)                     // si l'ouverture a r�ussi
    {
        string ligne;                    // d�claration de ligne qui contiendra la ligne lue
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "ligne"
        {
            for (int i = 0; i < ligne.size(); i++) { // pour i allant de 0 � la fin de la ligne
                int t = (ligne[i]);                  // t contient le caract�re i de la ligne 

                if (t >= 'a' and t <= 'z') // si t est une lettre minuscule
                {
                    t -= ckey;             // on enl�ve la cl� c�sar
                    if (t < 97) {          // si t est inf�rieur � "a" 
                        t +=26;            // on ajoute la longueur de l'alphabet
                    }
                }
                else if (t >= 'A' and t <= 'Z') // si t est une lettre majuscule
                {
                    t -= ckey;                  // on enl�ve la cl� c�sar
                    if (t < 65) {               // si t est inf�rieur � "A"
                        t +=26;                 // on ajoute la longuer de l'alphabet
                    }
                }

                ligne[i] = (char)t;
            }
            fichierSortie << ligne << "\n";
        }

        fichier.close();
        fichierSortie.close();
        cout << "decryptage termine et enregistre dans " << fileout << endl;
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier d'entr�e !" << endl;



}

void Cesar::setckey(int ckey)
{
    this->ckey = ckey;
}