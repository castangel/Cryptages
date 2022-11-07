#include "pch.h"

Cryptage::Cryptage(std::string f1, std::string f2)
{
	this->filein = f1;
	this->fileout = f2;

}

void Cryptage::cryptageXor()
{
	std::cout << "cryptage xor de ";
	x.xcd(this->filein, this->fileout);
}

void Cryptage::cryptageCesar()
{
	c.cc(this->filein, this->fileout);
}

void Cryptage::cryptageCesarXor()
{
	c.cc(this->filein, "temp");
	std::cout << "cryptage xor de ";
	x.xcd("temp", this->fileout);
	remove("temp.txt");

}

void Cryptage::decryptageXor() 
{
	std::cout << "decryptage xor de ";
	x.xcd(this->filein, this->fileout);	
}

void Cryptage::decryptageCesar()
{
	c.cd(this->filein, this->fileout);
}

void Cryptage::decryptageCesarXor()
{
	std::cout << "decryptage xor de ";
	x.xcd(this->filein, "temp");
	c.cd("temp", this->fileout);
	remove("temp.txt");
}

void Cryptage::setckey()
{
	int ckey;
	std::cout << "Entrez la cle cesar : ";
	std::cin >> ckey;
	std::cout << "\n";
	c.setckey(ckey);
}

void Cryptage::setxkey()
{
	std::string xkey;
	std::cout << "Entrez la cle XOR : ";
	std::cin >> xkey;
	std::cout << "\n";
	x.setxkey(xkey);
}