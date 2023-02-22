#pragma once
typedef char byte;
typedef unsigned long int uint32;

class Bitvector
{
	//el tamano es de multiplos de 8 
	size_t m_size;
	uint32 m_array=0; //entero de 32 bits


public:

	Bitvector(size_t newsize)
	{
		//hay que calcular el tamano como multiplo de 32		
		int realzise = newsize + 32- (newsize % 32);
		m_size = realzise;
	}

	size_t getsize()
	{
		return m_size;
	}

	//operator []
	bool operator[](int index)
	{
		getval(index);
	}

	//notacion con operadores
	//getter
	bool getval(int index)
	{
		return (m_array >> index) & 1;
	}
	//setter
	void setval(bool b, int index)
	{
		uint32 fullb = b;
		printf("antes   %x \n", fullb);

		if (b)
		{
			m_array = m_array | (1 << index);
		}
		else
		{
			m_array = m_array & ~(1 << index);
		}
		printf("desp   %x \n", fullb);

	}

	//imprimir en binario
	void binaryprint()
	{
		std::cout << "0b";
		for(int i =31; i>=0; i--)
		{
			uint32 b = (m_array >> i) & 1  ;
			std::cout << (b ? "1" : "0") ;
		}
		std::cout << "\n";
	}
};

