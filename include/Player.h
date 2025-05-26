
using namespace std;
#include <string>
class Player
{
    int Animali[5];
    bool CaneGrande;
    bool CanePiccolo;
    string Nome;
public:
    Player();
    void AggiungiConiglio(int);
    void AggiungiCapra(int);
    void AggiungiMaiale(int);
    void AggiungiPecora(int);
    void AggiungiCavallo(int);
    void AggiungiMucca(int);

    int GetConigli();
    int GetMaiali();
    int GetPecore();
    int GetCavalli();
    int GetMucche();

    void TiroDadi();

    void Scambio();

    void Stampainventario();

    
    int GetAnimale(int tipo);
    void AggiungiAnimale(int n, int tipo);
    void ConcludiTurno();
    string GetNome()
    {
    return Nome;
    }
    void SetNome(string n)
    {
    Nome=n;
    }
};

