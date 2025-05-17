#include "Player.h"
#include "cstdlib"
#include "ctime"
using namespace std;


class Player {
private:
    int Animali[5];
    bool CanePiccolo;
    bool CaneGrande;

public:
    Player();
    void AggiungiConiglio(int n);
    void AggiungiMaiale(int n);
    void AggiungiPecora(int n);
    void AggiungiCavallo(int n);
    void AggiungiMucca(int n);
    void TiroDadi();
    void Stampainventario();
    void Scambio();
};

#endif
    /*
    0)conigli
    1)maiali
    2)pecore
    3)cavalli
    4)mucche
    */
Player::Player()
{
    srand(time(NULL));
    CaneGrande=false;
    CanePiccolo=false;
    for(int i=0;i<5;i++)
        Animali[i]=0;
}

void Player::AggiungiConiglio(int n)
{
    Animali[0]=+n;
}

void Player::AggiungiMaiale(int n)
{
    Animali[1]=+n;
}

void Player::AggiungiPecora(int n)
{
    Animali[2]=+n;
}

void Player::AggiungiCavallo(int n)
{
    Animali[3]=+n;
}

void Player::AggiungiMucca(int n)
{
    Animali[4]=+n;
}

void Player::TiroDadi()
{
    int dado1, dado2;
    dado1=rand()%12+1;
    /*
    dado1:
    1)Coniglio
    2)Coniglio
    3)Coniglio
    4)Coniglio
    5)Coniglio
    6)Coniglio
    7)Maiale
    8)Pecora
    9)Pecora
    10)Cavallo
    11)Volpe
    12)Mucca
    */
    dado2=rand()%12+1;
    /*
    dado1:
    1)Coniglio
    2)Coniglio
    3)Coniglio
    4)Coniglio
    5)Coniglio
    6)Coniglio
    7)Maiale
    8)Pecora
    9)Pecora
    10)Mucca
    11)Cavallo
    12)Lupo
    */
//VOLPE E LUPO:
if(dado2==12)
{
    if(CaneGrande==false)
    {
    for(int i=1;i<6;i++)
    Animali[i]=0;
    }
    else
    {
        CaneGrande=false;
    }
    if(dado1!=11){
        return;
    }
}
if(dado1==11)
{
    if(CanePiccolo==false)
    {
    Animali[0]=0;
    }
    else
    {
        CanePiccolo=false;
    }
    if(dado2==12){
        return;
    }
}
// ANIMALI UGUALI:
if (
    // Coniglio (1-6)
    (dado1 >= 1 && dado1 <= 6 && dado2 >= 1 && dado2 <= 6) 
)
{
    AggiungiConiglio((2+Animali[0]/2));
    return;
}

if (
    // Maiale (7 sul dado1, 7 su dado2)
    (dado1 == 7 && dado2 == 7) 
)
{
    AggiungiMaiale((2+Animali[1]/2));
    return;
}
if (
    // Pecora (8-9 dado1, 8-9 dado2)
    ((dado1 == 8 || dado1 == 9) && (dado2 == 8 || dado2 == 9)) 
)
{
    AggiungiPecora((2+Animali[2]/2)); 
    return;
}
if (
    // Mucca (10 dado1, 12 dado2)
    (dado1 == 10 && dado2 == 12) 
)
{
    AggiungiMucca((2+Animali[4]/2));
    return;
}
if (
    // Cavallo (10 dado1, 11 dado2)
    (dado1 == 10 && dado2 == 11)
)
{
    AggiungiCavallo((2+Animali[3]/2));
    return;
}
//ANIMALI DIVERSI
if(dado1>=1 || dado1<=6)
{
    AggiungiConiglio(Animali[0]/2);
}
if(dado2>=1 || dado2<=6)
{
    AggiungiConiglio(Animali[0]/2);
}
if(dado1==7)
{
    AggiungiMaiale(Animali[1]/2);
}
if(dado2==7)
{
    AggiungiMaiale(Animali[1]/2);
}
if(dado1==8 || dado1==8)
{
    AggiungiPecora(Animali[2]/2);
}
if(dado2==8 || dado2==8)
{
    AggiungiPecora(Animali[2]/2);
}
if(dado1==12 || dado2==10)
{
    AggiungiMucca(Animali[4]/2);
}
if(dado1==10 || dado2==11)
{
    AggiungiCavallo(Animali[3]/2);
}

void Player::Stampainventario() {
    // Inizio della stampa inventario
    cout << "==============================" << endl;
    cout << "   INVENTARIO DEL GIOCATORE   " << endl;
    cout << "==============================" << endl;

    // Nomi degli animali ordinati secondo l'indice dell'array animali[]
    string Nomianimali[5] = {
        "conigli",
        "pecore",
        "maiali",
        "mucche",
        "cavalli"
    };

    // Ciclo per stampare tutti gli animali base
    for (int i = 0; i < 5; i++) {
        cout << "- Il numero di " << Nomianimali[i] << " è: " << animali[i] << endl;
    }

    cout << "------------------------------" << endl;

    // Stato dei cani
    if (Canepiccolo) {
        cout << "- Possiedi un cane piccolo." << endl;
    } else {
        cout << "- Non possiedi un cane piccolo." << endl;
    }

    if (Canegrande) {
        cout << "- Possiedi un cane grande." << endl;
    } else {
        cout << "- Non possiedi un cane grande." << endl;
    }
    cout << "------------------------------" << endl;
    cout << "Fine inventario." << endl << endl;
}
// FUNZIONE SCAMBIO
void Player::Scambio() {
    int risposta1, risp;

    // Inizio funzione di scambio
  cout <<   "==============================" << endl;
    cout << "   MERCATO DI SCAMBIO   " << endl;
    cout << "==============================" << endl;
    do {
        cout << "Si vuole fare uno scambio dal tanto al poco o dal poco al tanto? (1 o 2): ";
        cin >> risp;
    } while (risp != 1 && risp != 2);

    if (risp == 1) {
        cout << "Hai scelto: dal tanto al poco." << endl;
        cout << "6 conigli per una pecora: inserire 1" << endl;
        cout << "1 maiale per due pecore: inserire 2" << endl;
        cout << "1 mucca per tre maiali: inserire 3" << endl;
        cout << "1 cavallo per due mucche: inserire 4" << endl;
        cout << "1 pecora per un cane piccolo: inserire 5" << endl;
        cout << "1 mucca per un cane grande: inserire 6" << endl;

        cin >> risposta1;

        if (risposta1 == 1) {
            cout << "Si è scambiati sei conigli per una pecora" << endl;
            animali[0] -= 6;
            animali[1] += 1;
        }
        else if (risposta1 == 2) {
            cout << "Si è scambiato 1 maiale per due pecore" << endl;
            animali[2] -= 1;
            animali[1] += 2;
        }
        else if (risposta1 == 3) {
            cout << "Si è scambiato 1 mucca per tre maiali" << endl;
            animali[3] -= 1;
            animali[2] += 3;
        }
        else if (risposta1 == 4) {
            cout << "Si è scambiato 1 cavallo per due mucche" << endl;
            animali[4] -= 1;
            animali[3] += 2;
        }
        else if (risposta1 == 5) {
            if (animali[1] >= 1 && !Canepiccolo) {
                cout << "Si è scambiato 1 pecora per un cane piccolo" << endl;
                animali[1] -= 1;
                Canepiccolo = true;
            } else {
                cout << "Scambio non valido: hai già un cane piccolo o non hai abbastanza pecore." << endl;
            }
        }
        else if (risposta1 == 6) {
            if (animali[3] >= 1 && !Canegrande) {
                cout << "Si è scambiato 1 mucca per un cane grande" << endl;
                animali[3] -= 1;
                Canegrande = true;
            } else {
                cout << "Scambio non valido: hai già un cane grande o non hai abbastanza mucche." << endl;
            }
        }
    } else {
        cout << "Hai scelto: dal poco al tanto." << endl;
        cout << "1 pecora per 6 conigli: inserire 7" << endl;
        cout << "2 pecore per un maiale: inserire 8" << endl;
        cout << "3 maiali per una mucca: inserire 9" << endl;
        cout << "2 mucche per un cavallo: inserire 10" << endl;
        cout << "Cane piccolo per una pecora: inserire 11" << endl;
        cout << "Cane grande per una mucca: inserire 12" << endl;

        do {
            cin >> risposta1;
        } while (risposta1 < 7 || risposta1 > 12);

        if (risposta1 == 7) {
            cout << "Si è scambiato 1 pecora per 6 conigli" << endl;
            animali[1] -= 1;
            animali[0] += 6;
        }
        else if (risposta1 == 8) {
            cout << "Si è scambiato 2 pecore per un maiale" << endl;
            animali[1] -= 2;
            animali[2] += 1;
        }
        else if (risposta1 == 9) {
            cout << "Si è scambiato 3 maiali per una mucca" << endl;
            animali[2] -= 3;
            animali[3] += 1;
        }
        else if (risposta1 == 10) {
            cout << "Si è scambiato 2 mucche per un cavallo" << endl;
            animali[3] -= 2;
            animali[4] += 1;
        }
        else if (risposta1 == 11) {
            if (Canepiccolo) {
                cout << "Si è scambiato un cane piccolo per una pecora" << endl;
                animali[1] += 1;
                Canepiccolo = false;
            } else {
                cout << "Non possiedi un cane piccolo da scambiare." << endl;
            }
        }
        else if (risposta1 == 12) {
            if (Canegrande) {
                cout << "Si è scambiato un cane grande per una mucca" << endl;
                animali[3] += 1;
                Canegrande = false;
            } else {
                cout << "Non possiedi un cane grande da scambiare." << endl;
            }
        }
    }
}




