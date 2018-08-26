#ifndef EMPTYCELL_H
#define EMPTYCELL_H
#include <cell.h>


class EmptyCell : public Cell
{

private :
    const sf::Color COLOR = sf::Color::White;
public:
    EmptyCell();
    ~EmptyCell() override;
    sf::Vector2f getPos()override;
    void setPos(sf::Vector2f) override;
    sf::RectangleShape getCell() override {return this->_shape;}
    bool isClicked(sf::Vector2f) override ;
    void setColor(sf::Color c) override;
    sf::Color getColor() override {return this->_shape.getFillColor();}
    void setRemovable(bool b) override {}
    bool isRemovable() override{return false ;}
    void setBirthable(bool b ) override {this->_isBirthable = b;}
    bool isBirthable() override{return this->_isBirthable;}

};


#endif // EMPTYCELL_H
