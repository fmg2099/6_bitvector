// 6_Bitvector.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Bitvector.h"
#include <fstream>


int main()
{
	//Bitvector *misbits = new Bitvector(65);
	Bitvector misbits(65);
	std::cout << "se pidieron 65 bits, se otorgan " << misbits.getsize() << "\n";
	
	
	misbits.setval(1, 0);
	misbits.setval(1, 8);
	misbits.setval(1, 16);
	/*
	misbits.setval(1, 3);
	//misbits->binaryprint();
	misbits.setval(1, 15);
	misbits.setval(0, 63);
	misbits.setval(1, 64);
	misbits.binaryprint();
	printf("valor de 63: %x \n", misbits[63] );
	*/
	misbits.binaryprint();
	//Guardar a memoria persistente
	std::fstream savefile;
	savefile.open("data.bin", std::fstream::out | 
								std::fstream::binary);
	if (savefile.is_open())
	{
		savefile.write((const char*)misbits.getArray(), 4 * 3);
		char* buffer = new char[1];
		*buffer = 0;
		//savefile.write( buffer , 1);

		savefile.close();
	}
	else
	{
		std::cout << "savefile not found\n";
	}

	system("pause");
	return 0;
}
