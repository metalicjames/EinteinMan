#include <sstream>

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

    if(!font.loadFromFile("Inconsolata.otf"))
    {
        window.close();
    }

    arrived = true;
    score = 0;

    einsteinSprite.setTexture(einsteinTexture);
    einsteinSprite.setPosition(sf::Vector2f(256, 320));

    populateMap();

    gameLoop();
}

void engine::populateMap()
{
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

    sf::CircleShape shape(3);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(sf::Vector2f(86, 90));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 154));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 410));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(86, 538));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(150, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(150, 346));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(150, 410));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(150, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 90));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 154));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(214, 538));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(278, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(278, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 90));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 154));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(352, 538));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 90));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 154));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 346));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 410));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 474));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(416, 538));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(480, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(480, 538));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 90));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 154));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 218));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 282));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 346));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 410));
    points.push_back(shape);

    shape.setPosition(sf::Vector2f(554, 474));
    points.push_back(shape);

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
    bool returning = false;
    sf::FloatRect einstein = einsteinSprite.getGlobalBounds();
    for(std::vector<sf::FloatRect>::iterator it = maze.begin(); it != maze.end(); ++it)
    {
        if((*it).intersects(einstein))
        {
            einsteinSprite.move(-x, -y);
            returning = true;
            break;
        }
    }

    for(std::vector<sf::CircleShape>::iterator it = points.begin(); it != points.end(); ++it)
    {
        sf::FloatRect point = (*it).getGlobalBounds();
        if(einstein.intersects(point))
        {
            score++;
            it = points.erase(it);
        }
    }

    return returning;
}

void engine::render()
{
    window.clear(sf::Color::Black);

    window.draw(mapSprite);

    for(std::vector<sf::CircleShape>::iterator it = points.begin(); it != points.end(); ++it)
    {
        window.draw(*it);
    }

    window.draw(einsteinSprite);

    sf::Text text;
    text.setFont(font);
    std::stringstream scoreStream;
    scoreStream << "Score: " << score;
    text.setString(scoreStream.str());
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setPosition(sf::Vector2f(520, 600));

    window.draw(text);

    window.display();
}
