#include "player.h"


Player::Player()
{
    points=0;
    lives=9;

}

void Player::addpoint(){
    this->points++;
}

void Player::lifedown(){
    this->lives--;
}


