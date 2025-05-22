#include "../include/Player.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funzione che mostra il regolamento del gioco
void mostraRegolamento() {
    cout << "\n===== REGOLAMENTO DEL GIOCO SUPERFARMERS =====\n" << endl;

    cout << "1. Il gioco può essere giocato da un massimo di sei giocatori." << endl;
    cout << "2. L'obiettivo è completare il tabellone raccogliendo almeno un esemplare" << endl;
    cout << "   di ogni tipo di animale: coniglio, pecora, maiale, mucca e cavallo." << endl;
    cout << "3. A ogni turno si lanciano due dadi speciali con raffigurati animali e predatori." << endl;
    cout << "4. Per ogni coppia di animali uguali ottenuti (esclusi mucca e cavallo)," << endl;
    cout << "   si ottiene un tassello dell'animale corrispondente." << endl;
    cout << "5. Se compare una volpe, il giocatore perde tutti i conigli tranne uno," << endl;
    cout << "   a meno che possieda un cane piccolo (che viene sacrificato per proteggerli)." << endl;
    cout << "6. Se compare un lupo, si perdono tutti gli animali eccetto i conigli e i cavalli," << endl;
    cout << "   a meno che si possieda un cane grande, che annulla l'effetto del lupo." << endl;
    cout << "7. A ogni turno è possibile effettuare scambi tra animali (dal tanto al poco" << endl;
    cout << "   o viceversa), ma non entrambe le direzioni nello stesso turno." << endl;
}

// Funzione che mostra gli scambi possibili tra animali
void mostraScambi() {
    cout << "\n===== SCAMBI POSSIBILI TRA ANIMALI =====\n" << endl;

    cout << "6 conigli    -> 1 pecora" << endl;
    cout << "1 maiale     -> 2 pecore" << endl;
    cout << "1 mucca      -> 3 maiali" << endl;
    cout << "1 cavallo    -> 2 mucche" << endl;
    cout << "1 pecora     -> 1 cane piccolo" << endl;
    cout << "1 mucca      -> 1 cane grande" << endl;
}

int main() {

	srand(time(NULL));
	int opzione;

	cout << "Benvenuto a Superfarmers" << endl;
	do{
	cout<<"Cosa vuoi fare?"<<endl;
	cout<<"1) Mostra scambi possibili"<<endl;
	cout<<"2) Mostra regolamento"<<endl;
	cout<<"3) Inizia partita"<<endl;
	cin>>opzione;
	if(opzione==1)mostraScambi();
	if(opzione==2)mostraRegolamento();
	}while(opzione!=3);

	//INIZIO PARTITA
	int n_players;
	string nome;
	string nomeanimali[5] {" conigli"," pecore"," maiali"," mucche"," cavalli"};

	//VARIABILI PER LO SCAMBIO TRA GIOCATORI
	char risposta;
	int a,b;//giocatori coinvolti nello scambio: a propone, b approva
	int tipoA,tipoB, nA,nB;




	cout<<"inserire tot giocatori"<<endl;
	cin>>n_players;
	Player giocatori[n_players];
	cout<<"inserire nome giocatori"<<endl;
	for(int i=0; i<n_players; i++) {
		cin>>nome;
		giocatori[i].SetNome(nome);
	}
	bool vittoria=false;
	int vincitore=0;
	bool check;
	string gioc_scelto;
	char scelta;
	int turno=0;//ATTENZIONE: indica il numero del giocatore che deve giocare
	while (vittoria==false) {
		check=false;
		cout<<"TURNO DI "<<giocatori[turno].GetNome()<<endl<<endl<<endl;
		cout<<"stampa inventario..."<<endl;
		giocatori[turno].Stampainventario();
		cout<<"lancio dei dadi"<<endl;
		giocatori[turno].TiroDadi();
		giocatori[turno].Stampainventario();
		cout<<endl<<endl<<endl;

		do{
		cout<<"inserire scelta:"<<endl;
		cout<<"A. effettuare uno scambio con la Riserva"<<endl;
		cout<<"B. effettuare uno scambio con un Giocatore"<<endl;
		cout<<"X. concludere il turno"<<endl;
		cin>>scelta;
		
		switch (scelta) {
		case'a':
			case'A':
					giocatori[turno].Scambio();
			break;
		case'b':
			case'B':
			a=turno;
					cout<<"inserire nome del giocatore "<<endl;
			do {
				cin>>gioc_scelto;
				for(b=0; b<n_players; b++) {
					if(giocatori[b].GetNome()==gioc_scelto) {
						check=true;
					}
					if (check==false) {
						cout<<"nome non valido, riprova"<<endl;
					}
				}
			} while(check==false);
			
			cout<<"avvio scambio tra "<<giocatori[a].GetNome();
			cout<<" e "<<giocatori[b].GetNome();
			cout<<endl<<endl<<endl;
			cout<<"INVENTARIO DI "<<giocatori[a].GetNome()<<endl;
			giocatori[a].Stampainventario();
			cout<<endl<<endl<<endl<<endl;
			cout<<"INVENTARIO DI "<<giocatori[b].GetNome()<<endl;
			giocatori[b].Stampainventario();
			cout<<"cosa vuoi cedere?: scegliere opzione"<<endl;
			cout<<"1: conigli"<<endl<<"2: pecore"<<endl<<"3: maiali"<<endl<<"4: mucche"<<endl<<"5: cavallo"<<endl;
			do {
				cin>>tipoA;
				tipoA--;
				if (giocatori[a].GetAnimale(tipoA)>0) {
					cout<<"possiedi "<<giocatori[a].GetAnimale(tipoA)<<nomeanimali[tipoA]<<endl;
					check=true;
				} else {
					cout<<"non ne possiedi al momento, inserire un'altra opzione"<<endl;
				}
			} while(check==false);
			check=false;
			cout<<"quanti ne vuoi cedere?"<<endl;
			do {
				cin>>nA;
				if (giocatori[a].GetAnimale(tipoA)>nA) {
					check=true;
				} else {
					cout<<"non ne possiedi abbastanza, inserisci un nuovo valore"<<endl;
				}
			} while(check==false);
			check=false;

			cout<<"cosa vuoi chiedere a "<<giocatori[b].GetNome()<<"?: scegliere opzione"<<endl;
			cout<<"1: conigli"<<endl<<"2: pecore"<<endl<<"3: maiali"<<endl<<"4: mucche"<<endl<<"5: cavallo"<<endl;
			do {
				cin>>tipoB;
				tipoB--;
				if (giocatori[b].GetAnimale(tipoB)>0) {
					cout<<"il giocatore ha "<<giocatori[a].GetAnimale(tipoA)<<nomeanimali[tipoB]<<endl;
					check=true;
				} else {
					cout<<"il giocatore non ne possiede al momento, inserire un'altra opzione"<<endl;
				}
			} while(check==false);
			check==false;
			cout<<"quanti ne vuoi chiedere?"<<endl;
			do {
				cin>>nB;
				if (giocatori[b].GetAnimale(tipoB)>nB) {
					check=true;
				} else {
					cout<<"il giocatore non ne possiede abbastanza, inserisci un nuovo valore da richiedere"<<endl;
				}
			} while(check==false);
			check==false;
			cout<<giocatori[b].GetNome()<<", accetti lo scambio di "<<nA<<nomeanimali[tipoA]<<" per "<<nB<<nomeanimali[tipoB]<<"? (y/n)"<<endl;
			cin>>risposta;
			if(risposta=='y'||risposta=='Y'){
				//ANIMALI CEDUTI DA A A B
				giocatori[a].AggiungiAnimale(-nA, tipoA);
				giocatori[b].AggiungiAnimale(nA, tipoA);
				//ANIMALI ACQUISITI DA A A B
				giocatori[a].AggiungiAnimale(nB, tipoB);
				giocatori[b].AggiungiAnimale(-nB, tipoB);
				cout<<"scambio effettuato! :3"<<endl;
			} else {
				cout<<"scambio annullato :["<<endl;
			}
			break;
		case 'X':
		case 'x':
			giocatori[turno].ConcludiTurno();
			cout<<"turno finito"<<endl;
			break;
		}
		
		}while(scelta!='x'&&scelta!='X');

		for(int i=0; i<n_players;){
			if(giocatori[i].GetAnimale(0)>0 && giocatori[i].GetAnimale(1) && giocatori[i].GetAnimale(2) &&giocatori[i].GetAnimale(3) &&giocatori[i].GetAnimale(4)>0){
				vittoria=true;
				vincitore=i;
				i++;
				}
			}




		turno++;
		if(turno>=n_players) {
			turno=0;
		}
	}
	cout<<"VINCE "<<giocatori[vincitore].GetNome()<<endl;


	cout << "Grazie per aver giocato a Superfarmers Semplificato. Arrivederci!" << endl;
	return 0;
}

