#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct cards {
    string cardName[52];
    int cardValue[52]{};
};

struct game {

    string table[5];
    string p1[2];
    int p1_Sum;
    string p2[2];
    int p2_Sum;
    string p3[2];
    int p3_Sum;
    string p4[2];
    int p4_Sum;
};

void fillCards(cards& c) {

    // Aces
    c.cardName[0] = "Ace Pique";   c.cardValue[0] = 11;
    c.cardName[1] = "Ace Trefle";  c.cardValue[1] = 11;
    c.cardName[2] = "Ace Carro";   c.cardValue[2] = 11;
    c.cardName[3] = "Ace Coeur";   c.cardValue[3] = 11;

    // Kings
    c.cardName[4] = "King Pique";   c.cardValue[4] = 10;
    c.cardName[5] = "King Trefle";  c.cardValue[5] = 10;
    c.cardName[6] = "King Carro";   c.cardValue[6] = 10;
    c.cardName[7] = "King Coeur";   c.cardValue[7] = 10;

    // Queens
    c.cardName[8] = "Queen Pique";   c.cardValue[8] = 10;
    c.cardName[9] = "Queen Trefle";  c.cardValue[9] = 10;
    c.cardName[10] = "Queen Carro";  c.cardValue[10] = 10;
    c.cardName[11] = "Queen Coeur";  c.cardValue[11] = 10;

    // Jacks
    c.cardName[12] = "Jack Pique";   c.cardValue[12] = 10;
    c.cardName[13] = "Jack Trefle";  c.cardValue[13] = 10;
    c.cardName[14] = "Jack Carro";   c.cardValue[14] = 10;
    c.cardName[15] = "Jack Coeur";   c.cardValue[15] = 10;

    // 10 → 2
    int index = 16;
    for(int num = 10; num >= 2; num--) {
        c.cardName[index] = to_string(num) + " Pique";   c.cardValue[index++] = num;
        c.cardName[index] = to_string(num) + " Trefle";  c.cardValue[index++] = num;
        c.cardName[index] = to_string(num) + " Carro";   c.cardValue[index++] = num;
        c.cardName[index] = to_string(num) + " Coeur";   c.cardValue[index++] = num;
    }
}

void distribute(cards& c, game& g);
void turns(cards& c, game& g);


int main() {
    srand(time(0));
    cards c;
    game g;
    fillCards(c);
    distribute(c, g);
    turns(c, g);

    return 0;

}
void distribute(cards& c, game& g) {
    bool used[52] = {false};
    string command;

    cout << "-----Table hand-----"<<endl;
    for(int i = 0; i < 4; i++) {

        int r;

        do {
            r = rand() % 52;
        } while(used[r]);

        used[r] = true;

        g.table[i] = c.cardName[r];
        cout <<g.table[i] << endl;

    }

    cout << "-----P1 hand-----"<<endl;
    g.p1_Sum = 0;
    for(int i = 0; i < 2; i++) {

        int r;

        do {
            r = rand() % 52;
        } while(used[r]);

        used[r] = true;

        g.p1[i] = c.cardName[r];
        g.p1_Sum += c.cardValue[r];
        cout<<g.p1[i] << endl;
        cout<<"P1 pick a card or ignore : "<<endl;
        cin >> command;
        if (command == "pick") {
                g.p1_Sum = g.p1_Sum + c.cardValue[r];
        }
        if (g.p1_Sum > 21 && g.p1_Sum <= 31) {
            g.p1_Sum = g.p1_Sum - 10;
        }
    }
    cout<<"P1 sum is : "<<g.p1_Sum << endl;

    cout << "-----P2 hand-----"<<endl;
    g.p2_Sum = 0;
    for(int i = 0; i < 2; i++) {

        int r;

        do {
            r = rand() % 52;
        } while(used[r]);

        used[r] = true;

        g.p2[i] = c.cardName[r];
        g.p2_Sum += c.cardValue[r];
        if (g.p2_Sum > 21 && g.p2_Sum <= 31) {
            g.p2_Sum = g.p2_Sum - 10;
        }
        cout << g.p2[i] << endl;
    }
    cout<<"P2 sum is : "<<g.p2_Sum << endl;

    cout << "-----P3 hand-----"<<endl;
    g.p3_Sum = 0;
    for(int i = 0; i < 2; i++) {

        int r;

        do {
            r = rand() % 52;
        } while(used[r]);

        used[r] = true;

        g.p3[i] = c.cardName[r];
        g.p3_Sum += c.cardValue[r];
        if (g.p3_Sum > 21 && g.p3_Sum <= 31) {
            g.p3_Sum = g.p3_Sum - 10;
        }
        cout<<g.p3[i] << endl;
    }
    cout<<"P3 sum is : "<<g.p3_Sum << endl;

    cout<<"-----P4 hand-----"<<endl;
    g.p4_Sum = 0;
    for(int i = 0; i < 2; i++) {

        int r;

        do {
            r = rand() % 52;
        } while(used[r]);

        used[r] = true;

        g.p4[i] = c.cardName[r];
        g.p4_Sum += c.cardValue[r];
        if (g.p4_Sum > 21 && g.p4_Sum <= 31) {
            g.p4_Sum = g.p4_Sum - 10;
        }
        cout <<g.p4[i] << endl;
    }
    cout<<"P4 sum is : "<< g.p4_Sum << endl;






}


void turns(cards& c, game& g) {
    string command;
    distribute(c, g);





}