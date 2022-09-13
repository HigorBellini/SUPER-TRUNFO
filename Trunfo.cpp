#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "Trunfo.h"
using namespace std;

ifstream dados("cards.csv");

 Trunfo::Trunfo(){   

    int rodar;
    int em[MAX]; 

    while(dados.good()){

        for(int i = 0; i< MAX; i++){

        getline(dados, Cartas[i].model, ',');
        getline(dados, Cartas[i].curb_weight, ',');
        getline(dados, Cartas[i].engine_size, ',');
        getline(dados, Cartas[i].horsepower, ',');
        getline(dados, Cartas[i].price, ',');
        getline(dados, Cartas[i].group, '\n');

        }
    }
    for(int i = 0; i<MAX; i++){

        em[i] = i + 1;
        
    }

    Embaralhar(em, MAX);

    for (int i = 0; i < MAX; i++){
        
        rodar = em[i];
                
        Cartas2[i].model = Cartas[rodar].model;
        Cartas2[i].curb_weight = Cartas[rodar].curb_weight;
        Cartas2[i].engine_size = Cartas[rodar].engine_size;
        Cartas2[i].horsepower = Cartas[rodar].horsepower;
        Cartas2[i].price = Cartas[rodar].price;
        Cartas2[i].group = Cartas[rodar].group;
    }

    for(int i=0; i < 16; i++){


        Deck1[i].model = Cartas2[i].model;
        Deck1[i].curb_weight = Cartas2[i].curb_weight;
        Deck1[i].engine_size = Cartas2[i].engine_size;
        Deck1[i].horsepower = Cartas2[i].horsepower;
        Deck1[i].price = Cartas2[i].price;
        Deck1[i].group = Cartas2[i].group;
    }
    
    for(int i=0; i < 16; i++){

        Deck2[i].model = Cartas2[i+16].model;
        Deck2[i].curb_weight = Cartas2[i+16].curb_weight;
        Deck2[i].engine_size = Cartas2[i+16].engine_size;
        Deck2[i].horsepower = Cartas2[i+16].horsepower;
        Deck2[i].price = Cartas2[i+16].price;
        Deck2[i].group = Cartas2[i+16].group;


    }
}


void Trunfo::Show(){    

    for(int i=1; i < MAX; i++){

        cout << Cartas[i].model << "  ";
        cout << Cartas[i].curb_weight << "  ";
        cout << Cartas[i].engine_size << "  ";
        cout << Cartas[i].horsepower << "  ";
        cout << Cartas[i].price << "  ";
        cout << Cartas[i].group << "  ";
        cout << endl ;
    }
    cout << endl << endl;

   cout << "Deck1: " << endl;

    for(int i=0; i < 16; i++){
    
        cout << Deck1[i].model << " ";
        cout << Deck1[i].curb_weight << " ";
        cout << Deck1[i].engine_size << " ";
        cout << Deck1[i].horsepower << " ";
        cout << Deck1[i].price << " " ;
        cout << Deck1[i].group << " ";
        cout << endl;

    }
    
    cout << endl;
    cout << "Deck2: " << endl;

    for(int i=0; i < 16; i++){

        cout << Deck2[i].model << " ";
        cout << Deck2[i].curb_weight << " ";
        cout << Deck2[i].engine_size << " ";
        cout << Deck2[i].horsepower << " ";
        cout << Deck2[i].price << " " ;
        cout << Deck2[i].group << " ";
        cout << endl;

    }

    cout<<endl<<endl;
    
}

void Trunfo::Embaralhar(int em[], int MAX){

    int x;
    srand(time(NULL));


    for(x=1; x<MAX;x++){

        int sorteio;
        sorteio = rand() % MAX;

        int var = em[x];

        em[x] = em[sorteio];

        em[sorteio] = var;
    }
}


void Trunfo::Partida(int opcao){

    cout<<"Digite um numero"<<endl;
    cin>>opcao;

switch(opcao){

    case 1: //comparando as cartas na opção engine_size

        stringstream text_stream(Deck1[MAX].engine_size);  //converter string pra int
            string temp;                                   
             vector<int> numbers;
            while (std::getline(text_stream, temp, ',')){
                numbers.push_back(stoi(temp));
            }

        for(int i=0; i<MAX; i++){
            if((Deck1[i].group == "1A") && (Deck2[i].group == "2A" || "3A" || "4A" || "5A" || "6A" || "7A" || "8A")){
                
                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "2A") && (Deck2[i].group == "3A" || "4A" || "5A" || "6A" || "7A" || "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "3A") && (Deck2[i].group == "4A" || "5A" || "6A" || "7A" || "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "4A") && (Deck2[i].group == "5A" || "6A" || "7A" || "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "5A") && (Deck2[i].group == "6A" || "7A" || "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "6A") && (Deck2[i].group == "7A" || "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if((Deck1[i].group == "7A" && Deck2[i].group == "8A")){

                cout<<"Jogador 2 GANHOU"<<endl;

            }else if(Deck1[i].engine_size > Deck2[i].engine_size){

                cout<<"Jogador 1 GANHOU"<< " " << Deck1[i].engine_size << "//" << Deck2[i].engine_size<<endl;

            }else if(Deck1[i].engine_size < Deck2[i].engine_size){

                cout<<"Jogador 2 GANHOU"<< " " << Deck1[i].engine_size << "//" << Deck2[i].engine_size<<endl;

            }

        }
    break;

  
}




}

