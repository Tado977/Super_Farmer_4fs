#include "Player.h"
#include "cstdlib"
#include "ctime"
using namespace std;

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

// STAMPA IVENTARIO:
Void Player::Stampainventario{
    string Nomianimali[6]:
{
"conigli"
"pecore";
"maiali"
"cavalli";
"mucche";
};
cout<<"inventario del giocatore"<<endl;
for (int i=0; i<6; i++)
{ cout<<"il numero di animali è"<<nomeanimali[i]: <<:<<animali[i];

// FUNZIONE SCAMBIO
void Player::Scambio{
    int risposta1;
    do{
 cout<<"quale scambio si vuole fare(1,2,3,4,5,6)"<<endl;
 cout<<"6 conigli per una pecora : inserire 1"<<endl;}
 cout<<"1 maiale per due pecore: inserire 2"<<endl;}
 cout<<"1 mucca per tre maiali: inserire 3"<<endl;}
 cout<<"1 cavallo per due mucche: inserire 4"<<endl;}
 cout<<"1 pecora per un cane piccolo: inserire 5"<<endl;}
 cout<<"1 mucca per un cane grande: inserire 6"<<endl;}
 cout<<"1 pecora per 6 conigli : inserire 7"<<endl;}
 cout<<"due pecore per un maiale: inserire 8"<<endl;}
 cout<<"tre maiali e 1 mucca: inserire 9"<<endl;}
 cout<<"due mucche per un cavallo: inserire 10"<<endl;}
 cout<<"cane piccolo per una pecora: inserire 11"<<endl;}
 cout<<"cane grande per una mucca: inserire 12"<<endl;}
cin>>risposta1;
}while(risposta1>12)
    if (risposta1 = 1){
            cout<<" si è scambiati sei conigli per una pecora;
                animali[0] = animali[0]-6;
                animali[1] = animali[1]+1;
    }
if (risposta1 = 2){
            cout<<" si è scambiati 1 maiale per due pecore;
                animali[1] = animali[1]+2;
                animali[2] = animali[2]-1;
if (risposta1 = 3){
            cout<<" si è scambiati 1 mucca per tre maiali;
                animali[3] = animali[3]-1;
                animali[2] = animali[2]+3;
if (risposta1 = 4){
     cout<<" si è scambiati 1 cavallo per due mucche;
                animali[4] = animali[4]-1;
                animali[3] = animali[3]+2;
}
if (risposta1 = 5){
        do {
            cout<<" si è scambiati 1 pecora cane piccolo ;
                Canepiccolo ==false;
                animali[1] = animali[1]-1;
        }while (animali[2]>1|| Canepiccolo==false)
if (risp = 6){
        do {
            cout<<" si è scambiati 1 mucca cane grande;
                animali[3] = animali[3]-1;
                Canegrande==true;
        }while (animali[3]>1 || Canegrande==false)
}
if (risposta1 = 7){
            cout<<" si è scambiati sei conigli per una pecora;
                animali[0] = animali[0]-6;
                animali[1] = animali[1]+1;
    }
if (risposta1 = 8){
            cout<<" si è scambiati 1 maiale per due pecore;
                animali[1] = animali[1]+2;
                animali[2] = animali[2]-1;
if (risposta1 = 9){
            cout<<" si è scambiati 1 mucca per tre maiali;
                animali[3] = animali[3]-1;
                animali[2] = animali[2]+3;
if (risposta1 = 10){
     cout<<" si è scambiati 1 cavallo per due mucche;
                animali[4] = animali[4]-1;
                animali[3] = animali[3]+2;
}
if (risposta1 = 11){
        do {
            cout<<" si è scambiati 1 pecora cane piccolo ;
                Canepiccolo ==false;
                animali[1] = animali[1]-1;
        }while (animali[2]>1|| Canepiccolo==false)
if (risp = 12){
        do {
            cout<<" si è scambiati 1 mucca cane grande;
                animali[3] = animali[3]-1;
                Canegrande==true;
        }while (animali[3]>1 || Canegrande==false)
}









