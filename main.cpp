#include <iostream>
#include <SFML/Graphics.hpp>

#include <board.h>
using namespace std;

int main()
{


    sf::RenderWindow  *window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "Game Of Life");
    Board *board = new Board(40,40,window);
    sf::Vector2i mousPos = sf::Mouse::getPosition(*window);



    while (board->getWindow()->isOpen())
    {
        sf::Event event;
        while (board->getWindow()->pollEvent(event))
        {
            switch(event.type)
            {
            case sf::Event::KeyPressed :
                if(event.key.code == sf::Keyboard::Enter)
                    board->beginProcess();
                else if (event.key.code == sf::Keyboard::Space)
                    board->checkIfRemovable();
                break;

            case sf::Event::MouseButtonPressed :
                for(unsigned int i =0;i< board->getBoard().size();i++)
                {
                    for (unsigned int j=0;j<board->getBoard().at(i).size();j++)
                    {
                        if(board->getBoard().at(i).at(j)->isClicked((sf::Vector2f)sf::Mouse::getPosition(*window)))
                            board->getBoard().at(i).at(j)->setColor(sf::Color::Red);
                    }
                }
                break;
            case  sf::Event::Closed :
                board->getWindow()->close();
                break;
            default :
                break;
            }
        }
        board->getWindow()->clear(sf::Color::Black);
        board->drawBoard();
        board->getWindow()->display();
    }

    return 0;
}

