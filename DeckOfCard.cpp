#include <cstring>

#include <iostream>

using namespace std;

int deck[5][14];

struct Card
{
    int row;
    int column;
} Card[53];

void shuffle()
{
    int row;
    int column;
    for (int card = 1; card <= 52; card++)
    {
        do
        {
            row = rand() % 4 + 1;
            column = rand() % 13 + 1;
        } while (deck[row][column] != 0);
        Card[card] = {row, column};
        deck[row][column] = 1;
    }
}

int main()
{
    shuffle();
    for (int i = 1; i <= 52; i++)
        cout << Card[i].row << " " << Card[i].column << endl;
    return 0;
}
