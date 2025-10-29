#pragma once
#include <vector>
#include <string>
#include <iostream>


enum StatoSemaforo
{
	ROSSO,
	GIALLO,
	VERDE
};

struct Punto
{
	int x;
	int y;
};


class Exercise
{
public:
#pragma region Esercizio Enum 

	StatoSemaforo statoAttuale;
	Exercise(StatoSemaforo stato);
	void PrintStatoSemaforo();

#pragma endregion

#pragma region Esercizio Operatori Aritmetici, Assegnazione e if/else

	int base = 12;
	int altezza = 5;

	void CalcolaArea();

#pragma endregion

#pragma region Ciclo for e Operatore Modulo %

	void NumeriPari();

#pragma endregion

#pragma region Ciclo while e Operatori di incremento
	int contatore = 5;
	int risultato = 1;

	void WhileFunction();
#pragma endregion

#pragma region Ciclo do-while per input utente

	bool continua = true;

	void DoWhileFunction();

#pragma endregion

#pragma region Operatori Relazionali e Logici

	int punti = 85, presenze = 90, requisitoMinimo = 90;

	void CheckPromozioneStudente();

#pragma endregion

#pragma region Ciclo for-each (Range-Based For Loop)

	std::vector<std::string> Colori = { "Rosso","Verde","Blu","Giallo" };
	void PrintColors();

#pragma endregion

#pragma region Ciclo for-each per Modifica (Riferimento)

	std::vector<int> prezzi = { 10, 25, 5, 40 };
	void CalculatePrices();

#pragma endregion

#pragma region Operatore Bitwise AND (&) per la Verifica

	int permessi = 0b0110;
	int MASCHERA_SCRITTURA = 0b0010;

	void CheckPermessi();

#pragma endregion

#pragma region Operatori Bitwise shift (<<,>>)

	int valoreIniziale = 13;
	void EsercizioOperatoriBitwiseShift();
#pragma endregion

#pragma region Dichiarazione e Assegnazione Base

	int numero = 42;
	int* p_Num = nullptr;

	void AsignPNum();

#pragma endregion

#pragma region Modifica Tramite Puntatore

	double prezzo = 99.90;
	double* p_prezzo = nullptr;

	void AsignPrezzo();

#pragma endregion

#pragma region Passaggio per Riferimento (Funzione)

	void DoubleInt(int* p_int);

#pragma endregion

#pragma region Scambio di Valori (Swap)

	void SwapValue(int* a, int* b);
	void SwapValue(int* a, int* b, char null);

#pragma endregion

#pragma region Puntatori e Stringhe (Array di Caratteri)

	char parola[10] = "puntatore";
	char* p_parola =nullptr;
	void ChangeParola();

#pragma endregion

#pragma region  Aritmetica dei Puntatori su Array

	int numeri[5] = { 1,3,5,7,9 };

	int* p_numeri = nullptr;

	void Print2ndArrayNum();

#pragma endregion

#pragma region Iterazione con Aritmetica dei Puntatori

	int voti[4] = { 22, 25, 30, 28 };
	void ForWithPointer();

#pragma endregion

#pragma region Allocazione Dinamica di Memoria

	void Esercizio8Puntatori();

#pragma endregion

#pragma region Accesso ai Membri di una Struttura (Operatore ->)

	void Esercizio9Puntatori();

#pragma endregion

#pragma region Puntatori a Puntatori (Doppia Indirezione)

	int a = 100;
	void Esercizio10Puntatori();

#pragma endregion



	~Exercise();
private:

};

