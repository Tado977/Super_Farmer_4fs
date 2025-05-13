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
    // Coniglio (1-4)
    (dado1 >= 1 && dado1 <= 4 && dado2 >= 1 && dado2 <= 4) 
)
{
    AggiungiConiglio((2+Animali[0]/2));
}
if (
    // Capra (5)
    (dado1 == 5 && dado2 == 5) 
)
{
    AggiungiCapra((2+Animali[1]/2));
}
if (
    // Maiale (6-7 sul dado1, 7 su dado2)
    ((dado1 == 6 || dado1 == 7) && dado2 == 6) 
)
{
    AggiungiMaiale((2+Animali[2]/2));
}
if (
    // Pecora (8-9 dado1, 8 dado2)
    ((dado1 == 8 || dado1 == 9) && dado2 == 8) 
)
{
    AggiungiPecora((2+Animali[3]/2)); 
}
if (
    // Mucca (12 dado1, 9-10 dado2)
    (dado1 == 12 && (dado2 == 9 || dado2 == 10)) 
)
{
    AggiungiMucca((2+Animali[5]/2));
}
if (
    // Cavallo (10 dado1, 11 dado2)
    (dado1 == 10 && dado2 == 11)
)
{
    AggiungiCavallo((2+Animali[4]/2));
}

// ANIMALI DIVERSI:
}