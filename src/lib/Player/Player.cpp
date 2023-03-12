#include <bits/stdc++.h>
#include "Player.hpp"
using namespace std;

int Player::playerCount_ = 0;
Player::Player(string nickname): nickname_(nickname){
    this->point_ = 0;
    playerCount_++;
    this->id_ = playerCount_;
    //To do: adding deck & ability
}

Player::Player(const Player &other){
    this->nickname_ = other.nickname_;
    this->point_ = other.point_;
    playerCount_++;
    this->id_ = playerCount_;
    //To do: adding deck & ability
}

Player::~Player(){
    playerCount_--;
}

void Player::setNickname(string nickname){
    this->nickname_ = nickname;
}

void Player::setPoint(int point){
    this->point_ = point;
}

void Player::addPoint(int pointVal){
    this->point_ += pointVal;
}  

string Player::getNickname() const{
    return this->nickname_;
}

int Player::getPoint() const{
    return this->point_;
}

int Player::getPlayerCount(){
    return playerCount_;
}