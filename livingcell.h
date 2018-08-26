#ifndef LIVINGCELL_H
#define LIVINGCELL_H
#include <cell.h>

class LivingCell : public Cell
{
private :
    const sf::Color COLOR =  sf::Color::Blue;
public:
    LivingCell();
    ~LivingCell() override;
    sf::Vector2f getPos()override;
    void setPos(sf::Vector2f) override;
    sf::RectangleShape getCell() override {return this->_shape;}
    bool isClicked(sf::Vector2f) override {}
    void setColor(sf::Color) override;
    sf::Color getColor() override {return this->_shape.getFillColor();}
    void setRemovable(bool b) override {this->_isRemovable = b;}\
    bool isRemovable()override {return this->_isRemovable;}
    void setBirthable(bool b ) override {this->_isBirthable = b;}
    bool isBirthable() override{return this->_isBirthable;}



};

#endif // LIVINGCELL_H
