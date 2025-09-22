#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> Boris;
    queue<int> Nursik;

    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        Boris.push(card);
    }

    for (int i = 0; i < 5; i++) {
        int card;
        cin >> card;
        Nursik.push(card);
    }

    int moves = 0;
    const int MAX_MOVES = 1000000;

    while (!Boris.empty() && !Nursik.empty() && moves < MAX_MOVES) {
        int bCard = Boris.front();
        int nCard = Nursik.front();
        Boris.pop();
        Nursik.pop();

        bool bWins = false;
        bool nWins = false;

       
        if (bCard == 0 && nCard == 9) {
            bWins = true;
        } else if (nCard == 0 && bCard == 9) {
            nWins = true;
        } else if (bCard > nCard) {
            bWins = true;
        } else {
            nWins = true;
        }

        if (bWins) {
            
            Boris.push(bCard);
            Boris.push(nCard);
        } else if (nWins) {

            Nursik.push(bCard);
            Nursik.push(nCard);
        }

        moves++;
    }

    if (Boris.empty()) {
        cout << "Nursik " << moves << endl;
    } else if (Nursik.empty()) {
        cout << "Boris " << moves << endl;
    } else {
        cout << "blin nichya" << endl;
    }

    return 0;
}