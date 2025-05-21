#ifndef PLAYER_H
#define PLAYER_H

#pragma once

#include <string>
class Player
{
    int Animali[5];
    bool CaneGrande;
    bool CanePiccolo;
    string Nome;
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

#endif