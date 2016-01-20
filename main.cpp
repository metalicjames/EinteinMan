#include "main.h"

int main()
{
    engine Engine;

    return 0;
}

engine::engine()
{
    window.create(sf::VideoMode(640, 640), "EinsteinMan", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(120);

    if(!mapTexture.loadFromFile("map.png"))
    {
        window.close();
    }
    mapSprite.setTexture(mapTexture);
    mapSprite.setPosition(sf::Vector2f(0, 0));

    if(!einsteinTexture.loadFromFile("einstein.png"))
    {
        window.close();
    }

    arrived = true;

    einsteinSprite.setTexture(einsteinTexture);
    einsteinSprite.setPosition(sf::Vector2f(256, 320));

    sf::FloatRect boundingBox;
    boundingBox.top = 0;
    boundingBox.left = 0;
    boundingBox.width = 64;
    boundingBox.height = 640;
    maze.push_back(boundingBox);

    boundingBox.width = 640;
    boundingBox.height = 64;
    maze.push_back(boundingBox);

    boundingBox.top = 576;
    maze.push_back(boundingBox);

    boundingBox.top = 0;
    boundingBox.left = 576;
    boundingBox.width = 64;
    boundingBox.height = 640;
    maze.push_back(boundingBox);

    boundingBox.top = 64;
    boundingBox.left = 128;
    boundingBox.width = 64;
    boundingBox.height = 192;
    maze.push_back(boundingBox);

    boundingBox.left = 256;
    maze.push_back(boundingBox);

    boundingBox.left = 448;
    boundingBox.height = 128;
    maze.push_back(boundingBox);

    boundingBox.top = 320;
    boundingBox.left = 64;
    boundingBox.width = 64;
    boundingBox.height = 64;
    maze.push_back(boundingBox);

    boundingBox.top = 512;
    boundingBox.left = 128;
    maze.push_back(boundingBox);

    boundingBox.left = 256;
    maze.push_back(boundingBox);

    boundingBox.left = 512;
    maze.push_back(boundingBox);

    boundingBox.top = 384;
    boundingBox.left = 256;
    maze.push_back(boundingBox);

    boundingBox.top = 256;
    boundingBox.left = 448;
    boundingBox.height = 256;
    maze.push_back(boundingBox);

    boundingBox.top = 320;
    boundingBox.left = 192;
    boundingBox.height = 128;
    maze.push_back(boundingBox);

    boundingBox.top = 320;
    boundingBox.left = 320;
    boundingBox.height = 128;
    maze.push_back(boundingBox);

    gameLoop();
}

engine::~engine()
{

}

void engine::gameLoop()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        checkInputs();
        render();

    }
}

void engine::checkInputs()
{
    if(arrived)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            currentMoveX = -1;
            arrived = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            currentMoveX = 1;
            arrived = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            currentMoveY = -1;
            arrived = false;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            currentMoveY = 1;
            arrived = false;
        }
    }
    else
    {
        einsteinSprite.move(sf::Vector2f(currentMoveX, currentMoveY));
        resolveCollisions(currentMoveX, currentMoveY);

        if((int)einsteinSprite.getPosition().x % 64 == 0 && (int)einsteinSprite.getPosition().y % 64 == 0)
        {
            arrived = true;
            currentMoveX = 0;
            currentMoveY = 0;
        }
    }
}

bool engine::resolveCollisions(int x, int y)
{
    sf::FloatRect einstein = einsteinSprite.getGlobalBounds();
    for(std::vector<sf::FloatRect>::iterator it = maze.begin(); it != maze.end(); ++it)
    {
        if((*it).intersects(einstein))
        {
            einsteinSprite.move(-x, -y);
            return true;
        }
    }

    return false;
}

void engine::render()
{
    window.clear(sf::Color::Black);

    window.draw(mapSprite);
    window.draw(einsteinSprite);

    window.display();
}
