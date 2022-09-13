#include <iostream>
#include <string>
using namespace std;

const int MAX = 33;


class Trunfo{

    public:
        Trunfo();
        void Show();
        void Embaralhar(int em[], int MAX);
        void Partida(int opcao);
        //void Menu(cards D1);


    private:

    struct card
        {
            string model;
            string curb_weight;
            string engine_size;
            string horsepower;
            string price;
            string group;

        };

        typedef struct card cards;

        cards Cartas[MAX];
        cards Cartas2[MAX];
        cards Deck1[MAX];
        cards Deck2[MAX];
   
};