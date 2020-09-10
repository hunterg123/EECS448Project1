#ifndef SHIP_H
#define SHIP_H
#include <string>
#include <iostream>

class Ship{
private:
  int shipnumber;
  int hit;
public:
  Ship();
  ~Ship();
  void setShipNumber(int shipnum);
  int getShipNumber();
  //bool checkPosition(int row, int col, int sizeofship, std::string direction);
  void setHit();
  int getHit();
  bool isSunk();
};
#endif
