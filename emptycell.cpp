#include "emptycell.h"

EmptyCell::EmptyCell()
    :Cell()
{
    this->_shape.setFillColor(COLOR);
    this->setRemovable(false);
    this->setBirthable(false);

}

EmptyCell::~EmptyCell()
{

}

sf::Vector2f EmptyCell::getPos()
{
    return this->_shape.getPosition();
}

void EmptyCell::setPos(sf::Vector2f v)
{    
    this->_shape.setPosition(v.x,v.y);
}

bool EmptyCell::isClicked(sf::Vector2f m_pos)
{
    if(this->getPos().x <= m_pos.x && this->getPos().x +20  > m_pos.x
            && this->getPos().y <= m_pos.y && this->getPos().y +20  > m_pos.y )    
        return true ;

    else return false;
}

void EmptyCell::setColor(sf::Color c)
{
    this->_shape.setFillColor(c);
}



