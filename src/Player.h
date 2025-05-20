#ifndef PLAYER_H
#define PLAYER_H

#pragma once

class Player
{
    int Animali[4];
    bool CaneGrande;
    bool CanePiccolo;
    /*
    0)conigli
    1)capre
    2)maiali
    3)pecore
    4)cavalli
    5)mucche
    */
public:
    Player();
    void AggiungiConiglio(int);
    void AggiungiCapra(int);
    void AggiungiMaiale(int);
    void AggiungiPecora(int);
    void AggiungiCavallo(int);
    void AggiungiMucca(int);

    int GetConigli(int);
    int GetMaiali(int);
    int GetGetPecore(int);
    int GetCavalli(int);
    int GetMucche(int);

    void TiroDadi();

    void Scambio();

    void Stampainventario();


};

#endif