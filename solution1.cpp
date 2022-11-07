#include "pch.h"

int main()
{
	//####### variables #############
	std::string stop="y";
    int choix;
	std::string filein;
	std::string fileout;
	int ckey = 3;
	std::string xkey = "CLE";

	//####### Programme #############

	while (stop == "y") { // tant que l'utilisateur veut faire du cryptage/decryptage (stop=="y")

		std::cout << "Tapez 1 pour effectuer du cryptage sinon 2 pour du decryptage : ";
		std::cin >> choix; std::cout << "\n";

		std::cout << "Donnez le nom du fichier d'entree : ";
		std::cin >> filein; std::cout << "\n";

		// vérification que le fichier existe 
		ifstream fichierverif;
		fichierverif.open((filein+".txt"));

		// si il existe 
		if (fichierverif) {

			std::cout << "Donnez le nom du fichier de sortie : ";
			std::cin >> fileout; std::cout << "\n";

			Cryptage obj(filein, fileout); // on créé un objet de type Cryptage

			switch (choix) 
			{

			case 1: // si choix == 1
				std::cout << "Tapez 1 si vous voulez effectuer un cryptage cesar, 2 pour un xor sinon 3 pour les deux : ";
				std::cin >> choix; // l'utilisateur tape son choix
				std::cout << "\n";

				switch (choix) {
				case 1:// si choix == 1
					obj.setckey();
					obj.cryptageCesar();
					break;
				case 2:// si choix == 2
					obj.setxkey();
					obj.cryptageXor();
					break;
				case 3:// si choix == 3
					obj.setckey();
					obj.setxkey();
					obj.cryptageCesarXor();
					break;
				}
				break;

			case 2:// si choix == 2
				std::cout << "Tapez 1 si vous voulez effectuer un decryptage cesar, 2 pour un xor sinon 3 pour les deux : ";
				std::cin >> choix;
				std::cout << "\n";
				switch (choix) {
				case 1:// si choix == 1
					obj.setckey();
					obj.decryptageCesar();
					break;
				case 2:// si choix == 2
					obj.setxkey();
					obj.decryptageXor();
					break;
				case 3:// si choix == 3
					obj.setckey();
					obj.setxkey();
					obj.decryptageCesarXor();
					break;
				}
				break;

			default:
				std::cout << "Entree incorrecte";
				break;
			}
		}
		else { // sinon si le fichier ne s'ouvre pas 
			cout << "Le fichier n'existe pas !";
		}
		choix = 0;
		cout << endl << endl  << "Voulez vous decrypter/crypter a nouveau y/n ?" ;
		cin >> stop;
		cout << endl << endl;
	}

}
