#include "livingcell.h"

LivingCell::LivingCell()
    :Cell()
{
    this->_shape.setFillColor(COLOR);
    this->setRemovable(false);
    this->setBirthable(false);
}

LivingCell::~LivingCell()
{

}

void LivingCell::setPos(sf::Vector2f v)
{
    this->_shape.setPosition(v.x,v.y);
}

void LivingCell::setColor(sf::Color c)
{
    this->_shape.setFillColor(c);
}

sf::Vector2f LivingCell::getPos()
{
    return this->_shape.getPosition();
}
