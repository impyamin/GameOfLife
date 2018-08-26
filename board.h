#ifndef BOARD_H
#define BOARD_H
#include <emptycell.h>
#include <livingcell.h>
#include "vector"
#include <iostream>


class Board
{
private:
    std::vector<std::vector<Cell*>>  _cellBoard ;
    sf::RenderWindow    *_window;
    Cell * cell;
    int _xMax ;
    int _yMax ;

public:
    Board();
    Board(unsigned long x, unsigned long y, sf::RenderWindow  *w);
    ~Board();
    unsigned long  getSize(){return this->_cellBoard.size();}
    sf::RenderWindow  * getWindow(){return  _window;}
    void drawBoard();
    std::vector<std::vector<Cell*>> getBoard(){return this->_cellBoard;}
    void beginProcess();
    void checkIfRemovable();
    void checkIsolation(unsigned long  i, unsigned long  j);
    int getXMax(){return this->_xMax;}
    int getYMax(){return this->_yMax;}
    void actualizeBoard();

};

#endif // BOARD_H
