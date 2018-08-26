#ifndef CELL_H
#define CELL_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Cell
{
protected:
    sf::Vector2f _pos;
    const sf::Vector2f SIZE = {18,18};
    sf::RectangleShape _shape;
    const sf::Color OUTLINE_COLOR = sf::Color::Black;
    const int OUTLINE_THICKNESS = 2;
    bool _isRemovable;
    bool _isBirthable;
public:
    Cell();
    virtual ~Cell(){}
    virtual sf::Vector2f getPos() =0;
    virtual void setPos(sf::Vector2f) = 0;
    virtual sf::RectangleShape  getCell() =0;
    virtual bool isClicked(sf::Vector2f) =0;
    virtual void setColor(sf::Color) =0;
    virtual sf::Color getColor() =0 ;
    virtual void setRemovable(bool b) = 0;
    virtual bool isRemovable() =0;
    virtual void setBirthable(bool b) =0;
    virtual bool isBirthable() =0;
};

#endif // CELL_H
