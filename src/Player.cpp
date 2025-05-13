#include "Player.h"
    /*
    0)conigli
    1)capre
    2)maiali
    3)pecore
    4)cavalli
    5)volpi
    6)mucche
    */
Player::Player()
{
    for(int i=0;i<7;i++)
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

void Player::AggiungiVolpe(int n)
{
    Animali[5]=+n;
}

void Player::AggiungiMucca(int n)
{
    Animali[6]=+n;
}