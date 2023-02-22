// 6_Bitvector.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Bitvector.h"



int main()
{

	Bitvector *misbits = new Bitvector(34);

	std::cout << "se pidieron 34 bits, se otorgan " << misbits->getsize() << "\n";


	misbits->binaryprint();
	misbits->setval(1, 0);
	misbits->setval(0, 1);
	misbits->setval(1, 2);
	misbits->setval(1, 3);
	misbits->binaryprint();
	misbits->setval(1, 15);
	misbits->binaryprint();
}
