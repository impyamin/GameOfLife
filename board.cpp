#include "board.h"



Board::Board()
{


}

Board::Board(unsigned long x, unsigned long y, sf::RenderWindow *w)
{
    this->_xMax = x ;
    this->_yMax = y;
    this->_window = w ;
    float xShift =0;
    float yShift =0;
    for(unsigned int i=0;i<x;i++)
    {
        std::vector<Cell*> line ;
        for(unsigned int  j=0;j<y;j++)
        {
            EmptyCell *c = new EmptyCell();
            c->setPos({xShift,yShift});
            line.push_back(c);
            xShift +=20;
        }
        this->_cellBoard.push_back(line);
        xShift = 0;
        yShift += 20;
    }

}

Board::~Board(){
    for(unsigned long  i = 0 ;i < this->_cellBoard.size();i++)
    {
        for(unsigned long j=0;j<this->_cellBoard.at(i).size();j++)
        {
            _cellBoard.at(i).at(i)->~Cell();
        }
    }
}

void Board::drawBoard()
{
    for(unsigned int i = 0 ;i < this->_cellBoard.size();i++)
    {
        for(unsigned int j=0;j<this->_cellBoard.at(i).size();j++)
        {
            this->getWindow()->draw(_cellBoard.at(i).at(j)->getCell());
        }
    }

}

void Board::beginProcess()
{
    for(unsigned int i = 0 ;i < this->_cellBoard.size();i++)
    {
        for(unsigned int j=0;j<this->_cellBoard.at(i).size();j++)
        {
            if(this->getBoard().at(i).at(j)->getColor() == sf::Color::Red)
            {
                LivingCell *c = new LivingCell();
                c->setPos(_cellBoard.at(i).at(j)->getPos());
                this->getBoard().at(i).at(j)->~Cell();
                this->_cellBoard.at(i).at(j) = c;
                drawBoard();
            }
        }
    }
}

void Board::checkIfRemovable()
{
    for(unsigned int i = 0 ;i < this->_cellBoard.size();i++)
    {
        for(unsigned int j=0;j<this->_cellBoard.at(i).size();j++)
        {

            checkIsolation(i,j);

        }
    }
    actualizeBoard();
}

void Board::checkIsolation(unsigned long i, unsigned long j)
{
    int neighbours=0;


        if( j > 0 &&  this->getBoard().at(i).at(j-1)->getColor() == sf::Color::Blue)
            neighbours++;
        if( j+1 < this->getYMax() && this->getBoard().at(i).at(j+1)->getColor() == sf::Color::Blue)
            neighbours++;
        if(j > 0 && i > 0 && this->getBoard().at(i-1).at(j-1)->getColor() == sf::Color::Blue )
            neighbours++;
        if(j+1 < this->getXMax() && i > 0  &&  this->getBoard().at(i-1).at(j+1)->getColor() == sf::Color::Blue )
            neighbours++;
        if( i+1 < this->getYMax() &&  this->getBoard().at(i+1).at(j)->getColor() == sf::Color::Blue)
            neighbours++;
        if(i > 0 &&  this->getBoard().at(i-1).at(j)->getColor() == sf::Color::Blue )
            neighbours++;
        if(j > 0 && i+1 < this->getYMax() && this->getBoard().at(i+1).at(j-1)->getColor() == sf::Color::Blue )
            neighbours++;
        if(j+1 < this->getYMax() && i +1 <this->getYMax() &&  this->getBoard().at(i+1).at(j+1)->getColor() == sf::Color::Blue )
            neighbours++;


    if (neighbours != 2 && neighbours !=3 && this->getBoard().at(i).at(j)->getColor() == sf::Color::Blue)
    {
        this->getBoard().at(i).at(j)->setRemovable(true);
    }

    if(neighbours == 3 && this->getBoard().at(i).at(j)->getColor() == sf::Color::White)
    {
        this->getBoard().at(i).at(j)->setBirthable(true);
    }



}

void Board::actualizeBoard()
{
    for(unsigned int i = 0 ;i < this->_cellBoard.size();i++)
    {
        for(unsigned int j=0;j<this->_cellBoard.at(i).size();j++)
        {
            if(this->getBoard().at(i).at(j)->isRemovable())
            {

                EmptyCell *e = new EmptyCell();
                e->setPos(_cellBoard.at(i).at(j)->getPos());
                this->getBoard().at(i).at(j)->~Cell();
                this->_cellBoard.at(i).at(j) = e;

            }
            if(this->getBoard().at(i).at(j)->isBirthable())
            {

                LivingCell *c = new LivingCell();
                c->setPos(_cellBoard.at(i).at(j)->getPos());
                this->getBoard().at(i).at(j)->~Cell();
                this->_cellBoard.at(i).at(j) = c;

            }

        }
    }
}
