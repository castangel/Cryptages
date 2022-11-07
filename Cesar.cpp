#include "pch.h"


/// ########################### Cryptage césar ################################

void Cesar::cc(std::string file, std::string fileout)
{
    file += ".txt";
	std::cout << "cryptage cesar de " << file << " en cours...\n";
    fileout += ".txt";

    ifstream fichier(file, ios::in); // on ouvre le fichier en lecture
    ofstream fichierSortie(fileout, ios::out | ios::trunc);  //ouverture en écriture et on vide le contenu du fichier si jamais il est plein

    if (fichier)                     // si l'ouverture a réussi
    {
        string ligne;                    // déclaration d'une chaîne qui contiendra la ligne lue
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
        {
            for (int i = 0; i < ligne.size(); i++) { // pour i allant de 0 à la fin de la ligne
                int t = (ligne[i]);                  // t contient le caractère i de la ligne 

                if (t >= 'a' and t <= 'z')           // si t est une lettre minuscule 
                {
                    t += ckey;                       // on ajoute à t la clé césar
                    if (t > 122) {                   // si le résultat de la somme est  supérieur à 122 (qui correspond à z en ASCII)
                        t = t  - 26;                 // on enlève la longueur de l'alphabet
                    }                                
                }
                else if (t >= 'A' and t <= 'Z')     // si t est une lettre Majuscule 
                {
                    t += ckey;                      // on ajoute à t la clé césar
                    if (t > 91) {                   // si le résultat de la somme est supérieur à 91 (qui correspond à Z en ASCII)
                        t = t - 26;                 // on enlève la longueur de l'alphabet
                    }
                }

                ligne[i] = (char)t;                 // on change le caractère i de ligne par le nouveau
            }
            fichierSortie << ligne << "\n";         // on ajoute la ligne dans le fichier de sortie
        }

        fichier.close();
        fichierSortie.close();
        cout << "termine et enregistre dans "<< fileout << endl;
    }
    else  // sinon
        cerr << "Impossible d'ouvrir le fichier d'entrée !" << endl;

}

/// ########################### Décryptage césar ################################

void Cesar::cd(std::string file, std::string fileout)
{

    file += ".txt";
    std::cout << "decryptage cesar de " << file << "en cours...\n";
    fileout += ".txt";

    ifstream fichier(file, ios::in); // on ouvre le fichier en lecture
    ofstream fichierSortie(fileout, ios::out | ios::trunc);  // on ouvre le fichier en écriture et on vide le contenu du fichier si jamais il est plein

    if (fichier)                     // si l'ouverture a réussi
    {
        string ligne;                    // déclaration de ligne qui contiendra la ligne lue
        while (getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "ligne"
        {
            for (int i = 0; i < ligne.size(); i++) { // pour i allant de 0 à la fin de la ligne
                int t = (ligne[i]);                  // t contient le caractère i de la ligne 

                if (t >= 'a' and t <= 'z') // si t est une lettre minuscule
                {
                    t -= ckey;             // on enlève la clé césar
                    if (t < 97) {          // si t est inférieur à "a" 
                        t +=26;            // on ajoute la longueur de l'alphabet
                    }
                }
                else if (t >= 'A' and t <= 'Z') // si t est une lettre majuscule
                {
                    t -= ckey;                  // on enlève la clé césar
                    if (t < 65) {               // si t est inférieur à "A"
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
        cerr << "Impossible d'ouvrir le fichier d'entrée !" << endl;



}

void Cesar::setckey(int ckey)
{
    this->ckey = ckey;
}