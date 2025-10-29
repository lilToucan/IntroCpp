#include "Exercize.h"
#include <math.h>

Exercise::Exercise(StatoSemaforo stato)
{
	statoAttuale = stato;
}

void Exercise::CalcolaArea()
{
	int area = base * altezza; // Calcola l'area del rettangolo

	area *= 2; // Raddoppia il valore di area usando l'operatore di assegnazione composto

	if (area > 100)
		std::cout << "L'area raddoppiata supera i 100." << "\n";
	else
		std::cout << "L'area raddoppiata e' 100 o meno." << "\n";
	

}

void Exercise::NumeriPari()
{
	for (int i = 1; i <= 20; i++)
	{
		if (i % 2 != 0)
			continue;

		std::cout << "il numero: " << i << " e' pari \n";
	}
}

void Exercise::WhileFunction()
{
	while (contatore < 0)
	{
		risultato *= contatore;
		contatore--;
	}

	std::cout << "il risultato e': " << risultato << "\n";

}

void Exercise::DoWhileFunction()
{
	char YN;

	do
	{
		std::cout << "Continua il ciclo \n";
		std::cout << "inserisci N per fermare: ";
		std::cin >> YN;

		if (YN == 'N' || YN == 'n')
			continua = false;

	} while (continua);
}

void Exercise::CheckPromozioneStudente()
{
	if (punti > requisitoMinimo && presenze > 80)
		std::cout << "Promosso";

	std::cout << "Non Promosso";
}

void Exercise::PrintColors()
{
	for (std::string& color : Colori)
	{
		std::cout << "il colore e': " << color << "\n";
	}
}

void Exercise::CalculatePrices()
{
	for (int& price : prezzi)
	{
		price = static_cast<int>(trunc(price * 1.1f));
	}

	for (int& price : prezzi)
	{
		std::cout << "il prezzo nuovo e': " << price << "\n";
	}
}

void Exercise::CheckPermessi()
{
	if (permessi & MASCHERA_SCRITTURA)
		std::cout << "Il permesso di scrittura e' attivo \n";
	else
		std::cout << "Il permesso di scrittura NON e' attivo \n";
}

void Exercise::EsercizioOperatoriBitwiseShift()
{
	int valMult = valoreIniziale << 3;
	std::cout << "il numero moltipicato e': " << (valMult) << "\n";
	std::cout << "il numero diviso e': " << (valMult >> 2) << "\n";
}

void Exercise::AsignPNum()
{
	p_Num = &numero;

	std::cout << "numero variabile normale: " << numero << "\n";
	std::cout << "numero puntatore: " << *p_Num << "\n";

	delete p_Num;
	p_Num = nullptr;
}

void Exercise::AsignPrezzo()
{
	p_prezzo = &prezzo;
	*p_prezzo = 149.99;
	std::cout << "il prezzo e': " << prezzo << "\n";
	delete p_prezzo;
	p_prezzo = nullptr;
}

void Exercise::DoubleInt(int* p_int)
{
	*p_int *= 2;

}

void Exercise::SwapValue(int* a, int* b)
{
	int x = *a;
	*a = *b;
	*b = x;
}

void Exercise::SwapValue(int* a, int* b, char null)
{
	
	int* x = a;
	a = b;
	b = x;


}

void Exercise::ChangeParola()
{
	p_parola = parola;
	*p_parola = 'c';
	// *parola= *(parola +1);
	std::cout << "la parola ora e': " << parola << "\n";
	delete p_parola;
}

void Exercise::Print2ndArrayNum()
{
	p_numeri = numeri;
	std::cout << "il terzo numero e': " << *(p_numeri + 2) << "\n";
	delete p_numeri;
	p_numeri = nullptr;

}

void Exercise::ForWithPointer()
{
	int* p_voto = voti;

	for (int i = 0; i < 4; i++)
	{
		std::cout << "voto = " << *p_voto << "\n";
		p_voto++;
	}

	delete p_voto;
}

void Exercise::Esercizio8Puntatori()
{
	int* x = new int(24);
	*x = 123;
	std::cout << x << "\n";
	delete x;
	x = nullptr;
}

void Exercise::Esercizio9Puntatori()
{
	Punto* p_punto = new Punto();
	p_punto->x = 10;
	p_punto->y = 5;

	std::cout << "x= " << p_punto->x << "\n" << "y= " << p_punto->y << "\n";
	
	delete p_punto;
	p_punto = nullptr;

}

void Exercise::Esercizio10Puntatori()
{
	int* p1 = &a;
	int** p2 = &p1;

	std::cout << "a= " << **p2 << "\n";
	std::cout << "indirizzo di a= " << p1 << "\n";
	std::cout << "indirizzo di p1= " << p2 << "\n";

	delete p1;
	delete p2;
	p1 = nullptr;
	p2 = nullptr;
}

Exercise::~Exercise()
{
}

void Exercise::PrintStatoSemaforo()
{
	switch (statoAttuale)
	{
	case ROSSO:
		std::cout << "STOP!Attendere." << "\n";
		break;
	case GIALLO:
		std::cout << "Attenzione! Prepararsi." << "\n";
		break;
	case VERDE:
		std::cout << "VIA! Si pu� procedere." << "\n";
		break;
	default:
		break;
	}
}
