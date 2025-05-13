#include "Player.h"
#include "cstdlib"
#include "ctime"
using namespace std;

    /*
    0)conigli
    1)capre
    2)maiali
    3)pecore
    4)cavalli
    5)mucche
    */
Player::Player()
{
    srand(time(NULL));
    CaneGrande=false;
    CanePiccolo=false;
    for(int i=0;i<6;i++)
        Animali[i]=0;
}

void Player::AggiungiConiglio(int n)
{
    Animali[0]=+n;
}

void Player::AggiungiCapra(int n)
{
    Animali[1]=+n;
}

void Player::AggiungiMaiale(int n)
{
    Animali[2]=+n;
}

void Player::AggiungiPecora(int n)
{
    Animali[3]=+n;
}

void Player::AggiungiCavallo(int n)
{
    Animali[4]=+n;
}

void Player::AggiungiMucca(int n)
{
    Animali[5]=+n;
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
    5)Capra
    6)Maiale
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
    5)Capra
    6)Capra
    7)Maiale
    8)Pecora
    9)Mucca
    10)Mucca
    11)Cavallo
    12)Lupo
    */

// animali uguali casi:
if (
    // Coniglio (1-4)
    (dado1 >= 1 && dado1 <= 4 && dado2 >= 1 && dado2 <= 4) ||

    // Capra (5)
    (dado1 == 5 && dado2 == 5) ||

    // Maiale (6-7 sul dado1, 7 su dado2)
    ((dado1 == 6 || dado1 == 7) && dado2 == 6) ||

    // Pecora (8-9 dado1, 8 dado2)
    ((dado1 == 8 || dado1 == 9) && dado2 == 8) ||

    // Mucca (12 dado1, 9-10 dado2)
    (dado1 == 12 && (dado2 == 9 || dado2 == 10)) ||

    // Cavallo (10 dado1, 11 dado2)
    (dado1 == 10 && dado2 == 11)
)
 {
    // Logica di riproduzione per animali uguali
}

}