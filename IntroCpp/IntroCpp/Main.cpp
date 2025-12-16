#include <iostream>
#include <String>

#include "DelegateClass.h"
#include "IntroCPP.h"
#include "Puntatori.h"
#include "Weapon.h"
#include "Exercize.h"
#include "StaticClass.h"

using namespace std;

/*

*/
struct Studente
{
    int anni;
    float mediaVoti;
    string nome;

    // Default Constructor
    Studente() : anni(0), mediaVoti(.0f), nome("")
    {
        cout << "STUDENTE INIZIALIZZATO " << endl;
    }

    // Custom Constructor
    Studente(const string& newNome, int newAnni, float newMediaVoti)
    {
        anni = newAnni;
        nome = newNome;
        mediaVoti = newMediaVoti;
    }
};

void Lezione2()
{
    Puntatore p = Puntatore();

    p.IntPointerFunction();

    Weapon* sword = new Weapon("Sword", MELEE, 100);

    //	int* newInt = new int(42);

    sword->PrintInfo();

    delete sword;
    sword = nullptr;

    //if (sword == nullptr) 
    //	return;
}

void OldMain()
{
    // Print Hello World to the console
    cout << "Hello, C++ World!" << endl;
#pragma region Base types


    // Base type c++

    // Integer
    int numeroIntero = -3; // numero intero con segno
    unsigned int numeroInteroPositivo = 5; // numero intero senza segno

    // Floating point, con precisione singola
    float numeroDecimale = 3.14f; // numero decimale a precisione singola
    float numeroDecimalePiccolo = .2f; // numero decimale pi� piccolo di 1

    // Floating point, con precisione doppia
    double numeroDecimaleDoppiaPrecisione = 3.141592653589793; // numero decimale a precisione doppia

    // Carattere singolo
    char carattere = 'A'; // singolo carattere racchiuso tra apici singoli

    // Booleano
    bool valoreBooleano = true; // valore booleano, pu� essere true o false
    bool altroValoreBooleano = false;

    // Stampa i valori delle variabili
    cout << "--- ESEMPI DI VARIABILI: ---" << endl;


    cout << "Intero: (int)" << numeroIntero << endl;
    cout << "Intero positivo: (unsigned int)" << numeroInteroPositivo << endl;
    cout << "Decimale (float): " << numeroDecimale << endl;
    cout << "Decimale piccolo (float): " << numeroDecimalePiccolo << endl;
    cout << "Decimale doppia precisione (double): " << numeroDecimaleDoppiaPrecisione << endl;
    cout << "Carattere (char): " << carattere << endl;
    cout << "Booleano (bool): " << valoreBooleano << endl;
    cout << "Altro Booleano (bool): " << altroValoreBooleano << endl;

    cout << "---------------------------" << endl;

    cout << "--- DIMENSIONE IN BYTE DEI TIPI: ---" << endl;

    cout << "Dimensione :" << sizeof(int) << " byte per il tipo int" << endl;
    cout << "Dimensione :" << sizeof(unsigned int) << " byte per il tipo unsigned int" << endl;
    cout << "Dimensione :" << sizeof(float) << " byte per il tipo float" << endl;
    cout << "Dimensione :" << sizeof(double) << " byte per il tipo double" << endl;
    cout << "Dimensione :" << sizeof(char) << " byte per il tipo char" << endl;
    cout << "Dimensione :" << sizeof(bool) << " byte per il tipo bool" << endl;


    cout << "---------------------------" << endl;
#pragma endregion

#pragma region Tipi composti


    // tipi composti: array, struct, class

    // Array

    int arrayDiInteri[5] = {1, 2, 3, 4, 5}; // array di 5 interi
    char arrayDiCharaceter[5] = {'H', 'E', 'L', 'L', 'O'};
    float arrayDiFloat[5] = {3.0f, 2.5f, 1.5f, .6f, .4f};
    bool arrayDiBool[5] = {true, true, false, true, false};

    string arrayDiIntString = "";
    string arrayDiFloatString = "";
    string arrayDiBoolString = "";

    for (int i = 0; i < 5; i++)
    {
        arrayDiIntString.append(to_string(arrayDiInteri[i]));
        arrayDiFloatString.append(to_string(arrayDiFloat[i]));
        arrayDiBoolString.append(to_string(arrayDiBool[i]));
    }

    cout << "Array di Interi: " << arrayDiIntString << "\n";
    cout << "Array di Character: " << arrayDiCharaceter << "\n";
    cout << "Array di float: " << arrayDiFloatString << "\n";
    cout << "Array di bool: " << arrayDiBoolString << "\n";


    // String
    string testo = "Esempio di stringa in C++";
    string arrayDiStringhe[4] = {"Ciao", "Come va", "Leo", "Matteo"};

    //Struct Studente

    Studente randomStudente;

    Studente randomCustomStudente(testo, 21, .4);

    randomStudente.nome = "Random";
    randomStudente.anni = 20;
    randomStudente.mediaVoti = 8.4f;

    // Class

    Rettangolo rettangolo(5, 10);

    int area = rettangolo.calcoloArea();
    rettangolo.PrintInfo();


    Weapon uzi("Uzi", RANGED, 3);
    uzi.DealDamage();
    uzi.PrintInfo();


    // Stampare dimensioni delle diverse classi create, degli array e delle stringhe
#pragma endregion
}

void Esercizi()
{
    // esercizi

    Exercise ex(ROSSO);

    ex.PrintStatoSemaforo();
    ex.CalcolaArea();
    ex.NumeriPari();
    ex.WhileFunction();
    ex.DoWhileFunction();
    ex.CheckPromozioneStudente();
    ex.PrintColors();
    ex.CalculatePrices();
    ex.CheckPermessi();
    ex.EsercizioOperatoriBitwiseShift();
    ex.AsignPNum();
    ex.AsignPrezzo();

    int intToDuble = 5;
    int* p_intToDuble = &intToDuble;
    ex.DoubleInt(p_intToDuble);
    std::cout << "int doubled is: " << intToDuble << "\n";
    delete p_intToDuble;
    p_intToDuble = nullptr;

    int a = 10;
    int b = 20;
    int* pa = &a;
    int* pb = &b;


    ex.SwapValue(pa, pb);
    std::cout << "a= " << a << "\n"<< "b= " << b << "\n";
    // ex.SwapValue(pa,pb,'d');
    // std::cout << "pa= " << pa << " &A= " << &a << "\n";
    // std::cout << "pb= " << pb << " &B= " << &b <<  "\n";

    delete pa;
    delete pb;
    pa = nullptr;
    pb = nullptr;

    ex.ChangeParola();
    ex.Print2ndArrayNum();
    ex.ForWithPointer();
    ex.Esercizio8Puntatori();
    ex.Esercizio9Puntatori();
    ex.Esercizio10Puntatori();
}

int main()
{
    //Esercizi();

    // StaticClass* a = new StaticClass();
    // StaticClass* b = new StaticClass();
    // StaticClass* c = new StaticClass();
    //
    // delete a;
    // a = nullptr;

DelegateClass* randomDel = new DelegateClass();
    randomDel->FunctionToTest();
    
    
    cin.get();

    return 0;
}
