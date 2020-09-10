#include "Ship.h"
using namespace std;

Ship::Ship(){
  shipnumber = 0;
  hit = 0;
}
Ship::~Ship(){

}
void Ship::setShipNumber(int shipnum){
  int num = shipnum;
  for (int i=0; i< num; i++){
    shipnumber = shipnumber+shipnum;
    shipnum--;
  }
}
int Ship::getShipNumber(){
  return shipnumber;
}
/*
bool Ship::checkPosition(int row, int col, int sizeofship, string direction){
  if (direction == "up" && col+sizeofship <= 10){
    return true;
  }
  else if (direction == "right" && row+sizeofship <= 10){
    return true;
  }
  else if (direction == "down" && col-sizeofship >= 0){
    return true;
  }
  else if (direction == "left" && row-sizeofship >= 0){
    return true;
  }
  else{
    return false;
  }
}
*/
void Ship::setHit(){
  hit++;
}
int Ship::getHit(){
  return hit;
}
bool Ship::isSunk(){
  if (hit == shipnumber){
    return true;
  }
  else{
    return false;
  }
}
