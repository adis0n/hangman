#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#include <iostream>
#include <string>
#include <cstring>
#include <QPixmap>

using namespace std;

class Player
{
public:
    Player();
    void lifedown();
    void setword(string word);
    void addpoint();
    int lives;
    int points;
    char letter;
    string nick;
};

#endif // PLAYER_H
