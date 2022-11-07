#pragma once
#include "pch.h"
class Cryptage
{
private : 
	Xor x;
	Cesar c;
	std::string filein;
	std::string fileout;
public :
	Cryptage(std::string f1, std::string f2);
	void cryptageXor();
	void cryptageCesar();
	void cryptageCesarXor();
	void decryptageXor();
	void decryptageCesar();
	void decryptageCesarXor();
	void setckey();
	void setxkey();

};

