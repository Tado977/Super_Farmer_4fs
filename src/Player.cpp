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

// STAMPA IVENTARIO:
Void Player::Stampainventario{
    string Nomianimali[6]:
{
"conigli";
"capre";
"maiali"
"pecore";
"cavalli";
"mucche";
};
cout<<"inventario del giocatore"<<endl;
for (int i=0; i<6; i++)
{ cout<<"il numero di animali è"<<nomeanimali[i]: <<:<<animali[i];

// FUNZIONE SCAMBIO
void Player::Scambi{
    int risposta,risposta1,risp;
    cout<<"si vuole fare uno scambio dal tanto al poco o dal poco al tanto (1 o 2)?"<<endl;
    cin>>risposta;
    if (risposta =1){
        cout<<"quale scambio si vuole fare(1,2,3)"<<endl;
 cout<<"6 conigli per una pecora"<<endl;}
 cout<<"1 maiale per due pecore"<<endl;}
 cout<<"1 mucca per tre maiali"<<endl;}
cin>>risposta1;
    if (risposta1 = 1){
        do {
            cout<<" si è scambiati sei conigli per una pecora;
                animali[1] = animali[1]-6;
                animali[2] = animali[2]+1;
        }while (animali[1]=6 ||animali[2]<6)
if (risposta1 = 2){
        do {
            cout<<" si è scambiati 1 maiale per due pecore;
                animali[2] = animali[2]+2;
                animali[3] = animali[3]-1;
        }while (animali[3]>1|| animali[2]<3)
if (risposta1 = 3){
        do {
            cout<<" si è scambiati 1 mucca per tre maiali;
                animali[4] = animali[4]-1;
                animali[3] = animali[3]+3;
        }while (animali[3]<1 || animali[4]>1)        
}else {
cout<<"quale scambio si vuole fare(1,2,3)"<<endl;  
 cout<<"1 cavallo per due mucche"<<endl;}
 cout<<"1 pecora per un cane piccolo"<<endl;}
 cout<<"1 mucca per un cane grande"<<endl;}
cin>>risp;
   if (risp = 1){
        do {
            cout<<" si è scambiati 1 cavallo per due mucche;
                animali[5] = animali[5]-1;
                animali[4] = animali[4]+2;
        }while (animali[1]>1 ||animali[4]<2)
if (risp = 2){
        do {
            cout<<" si è scambiati 1 pecora cane piccolo ;
                Canepiccolo ==false;
                animali[2] = animali[2]-1;
        }while (animali[2]>1|| Canepiccolo==false)
if (risp = 3){
        do {
            cout<<" si è scambiati 1 mucca cane grande;
                animali[4] = animali[4]-1;
                Canegrande==true;
        }while (animali[4]>1 || Canegrande==false )









