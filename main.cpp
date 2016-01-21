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
    mapSprite.setPosition(sf::Vector2f(256, 320));
    mapSprite.setOrigin(sf::Vector2f(256, 320));

    if(!einsteinTexture.loadFromFile("einstein.png"))
    {
        window.close();
    }

    if(!enemyTexture.loadFromFile("bohr.png"))
    {
        window.close();
    }

    if(!font.loadFromFile("Inconsolata.otf"))
    {
        window.close();
    }

    arrived = true;
    score = 0;
    lives = 3;
    currentMoveX = 0;
    currentMoveY = 0;

    einsteinSprite.setTexture(einsteinTexture);
    einsteinSprite.setPosition(sf::Vector2f(256, 320));

    enemySprite.setTexture(enemyTexture);
    enemySprite.setPosition(sf::Vector2f(64, 512));

    populateMap();

    gameLoop();
}

void engine::populateMap()
{
    maze.clear();
    points.clear();

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

        if(lives > 0)
        {
            checkInputs();

            moveEnemy();

            resolveEnemyCollisions();

            render();
        }
        else if(lives == 0 || score == 42)
        {
            window.clear(sf::Color::Black);

            sf::Text text;
            text.setFont(font);
            if(score == 42)
            {
                text.setString("You Win!\nPress enter to restart");
            }
            else
            {
                std::stringstream scoreStream;
                scoreStream << "You Lose! Score: " << score << "\nPress enter to restart";
                text.setString(scoreStream.str());
            }
            text.setCharacterSize(24);
            text.setColor(sf::Color::White);
            text.setPosition(sf::Vector2f(220, 320));

            window.draw(text);

            window.display();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
            {
                arrived = true;
                lives = 3;
                score = 0;
                populateMap();
                einsteinSprite.setPosition(sf::Vector2f(256, 320));
                enemySprite.setPosition(sf::Vector2f(64, 512));
                while(!path.empty())
                {
                    path.pop();
                }
            }
        }
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

    einsteinSprite.move(sf::Vector2f(currentMoveX, currentMoveY));
    resolveCollisions(currentMoveX, currentMoveY);
    if((int)einsteinSprite.getPosition().x % 64 == 0 && (int)einsteinSprite.getPosition().y % 64 == 0)
    {
        arrived = true;
        currentMoveX = 0;
        currentMoveY = 0;
    }
}

bool engine::resolveCollisions(int x, int y)
{
    bool returning = false;
    sf::FloatRect einstein = einsteinSprite.getGlobalBounds();
    if(!arrived)
    {
        for(std::vector<sf::FloatRect>::iterator it = maze.begin(); it != maze.end(); ++it)
        {
            if((*it).intersects(einstein))
            {
                einsteinSprite.move(-x*2, -y*2);
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
                if(it == points.end())
                {
                    break;
                }
            }
        }
    }

    return returning;
}

void engine::resolveEnemyCollisions()
{
    sf::FloatRect einstein = einsteinSprite.getGlobalBounds();
    sf::FloatRect enemy = enemySprite.getGlobalBounds();
    if(einstein.intersects(enemy))
    {
        lives--;
        einsteinSprite.setPosition(sf::Vector2f(256, 320));
        enemySprite.setPosition(sf::Vector2f(64, 512));
        while(!path.empty())
        {
            path.pop();
        }
        arrived = true;
    }
}

void engine::render()
{
    window.clear(sf::Color::Black);

    mapSprite.setOrigin(einsteinSprite.getPosition());
    mapSprite.setPosition(einsteinSprite.getPosition());

    if(currentMoveX != 0)
    {
        mapSprite.setScale(sf::Vector2f(0.87, 1));
    }
    else if(currentMoveY != 0)
    {
        mapSprite.setScale(sf::Vector2f(1, 0.87));
    }

    window.draw(mapSprite);
    mapSprite.setScale(sf::Vector2f(1, 1));

    for(std::vector<sf::CircleShape>::iterator it = points.begin(); it != points.end(); ++it)
    {
        sf::Vector2f originalPosition = (*it).getPosition();
        if(currentMoveX != 0)
        {
            int distance = einsteinSprite.getPosition().x - (*it).getPosition().x;
            (*it).setScale(sf::Vector2f(0.87, 1));
            (*it).move(sf::Vector2f(distance - (distance * 0.87), 0));
            window.draw(*it);
            (*it).setPosition(originalPosition);
        }
        else if(currentMoveY != 0)
        {
            int distance = einsteinSprite.getPosition().y - (*it).getPosition().y;
            (*it).setScale(sf::Vector2f(1, 0.87));
            (*it).move(sf::Vector2f(0, distance - (distance * 0.87)));
            window.draw(*it);
            (*it).setPosition(originalPosition);
        }
        else
        {
            window.draw(*it);
        }
        (*it).setScale(sf::Vector2f(1, 1));
    }

    window.draw(einsteinSprite);

    sf::Vector2f originalPosition = enemySprite.getPosition();
    if((enemyMoveX < 0 && currentMoveX > 0) || (enemyMoveX > 0 && currentMoveX < 0))
    {
        enemySprite.setScale(sf::Vector2f(0.20, 1));
        int distance = einsteinSprite.getPosition().x - enemySprite.getPosition().x;
        enemySprite.move(sf::Vector2f(distance - (distance * 0.20), 0));
        window.draw(enemySprite);
        enemySprite.setPosition(originalPosition);
    }
    else if((enemyMoveY < 0 && currentMoveY > 0) || (enemyMoveY > 0 && currentMoveY < 0))
    {
        enemySprite.setScale(sf::Vector2f(1, 0.20));
        int distance = einsteinSprite.getPosition().y - enemySprite.getPosition().y;
        enemySprite.move(sf::Vector2f(0, distance - (distance * 0.20)));
        window.draw(enemySprite);
        enemySprite.setPosition(originalPosition);
    }
    else if(currentMoveX == 0 && enemyMoveX != 0)
    {
        enemySprite.setScale(sf::Vector2f(0.87, 1));
        int distance = einsteinSprite.getPosition().x - enemySprite.getPosition().x;
        enemySprite.move(sf::Vector2f(distance - (distance * 0.87), 0));
        window.draw(enemySprite);
        enemySprite.setPosition(originalPosition);
    }
    else if(currentMoveY == 0 && enemyMoveY != 0)
    {
        enemySprite.setScale(sf::Vector2f(1, 0.87));
        int distance = einsteinSprite.getPosition().y - enemySprite.getPosition().y;
        enemySprite.move(sf::Vector2f(0, distance - (distance * 0.87)));
        window.draw(enemySprite);
        enemySprite.setPosition(originalPosition);
    }
    else
    {
        window.draw(enemySprite);
    }
    enemySprite.setScale(sf::Vector2f(1, 1));

    sf::Text text;
    text.setFont(font);
    std::stringstream scoreStream;
    scoreStream << "Lives: " << lives << " Score: " << score;
    text.setString(scoreStream.str());
    text.setCharacterSize(24);
    text.setColor(sf::Color::White);
    text.setPosition(sf::Vector2f(420, 600));

    window.draw(text);

    window.display();
}

void engine::moveEnemy()
{
    if(path.empty())
    {
        newX = 0;
        newY = 0;
        AStarSearch<MapSearchNode> astarsearch;

        // Create a start state
        MapSearchNode nodeStart;
        nodeStart.x = static_cast<int>(enemySprite.getPosition().x) / 64;
        nodeStart.y = static_cast<int>(enemySprite.getPosition().y) / 64;

        // Define the goal state
        MapSearchNode nodeEnd;
        nodeEnd.x = static_cast<int>(einsteinSprite.getPosition().x) / 64;
        nodeEnd.y = static_cast<int>(einsteinSprite.getPosition().y) / 64;

        // Set Start and goal states
        astarsearch.SetStartAndGoalStates(nodeStart, nodeEnd);

        unsigned int SearchState;
        do
        {
            SearchState = astarsearch.SearchStep();
        }
        while(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING);

        if(SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED)
        {
            MapSearchNode *node = astarsearch.GetSolutionStart();

            while(true)
            {
                path.push(*node);

                node = astarsearch.GetSolutionNext();

                if(!node)
                {
                    break;
                }
            }

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();
        }
        else
        {
            while(!path.empty())
            {
                path.pop();
            }
        }

        astarsearch.EnsureMemoryFreed();
    }
    else
    {
        MapSearchNode node = path.front();
        if(newX == 0 && newY == 0)
        {
            newX = node.x * 64;
            newY = node.y * 64;
        }
        else
        {
            if(newX < enemySprite.getPosition().x)
            {
                enemySprite.move(sf::Vector2f(-1, 0));
                enemyMoveX = -1;
                enemyMoveY = 0;
            }
            else if(newX > enemySprite.getPosition().x)
            {
                enemySprite.move(sf::Vector2f(1, 0));
                enemyMoveX = 1;
                enemyMoveY = 0;
            }
            else if(newY < enemySprite.getPosition().y)
            {
                enemySprite.move(sf::Vector2f(0, -1));
                enemyMoveX = 0;
                enemyMoveY = -1;
            }
            else if(newY > enemySprite.getPosition().y)
            {
                enemySprite.move(sf::Vector2f(0, 1));
                enemyMoveX = 0;
                enemyMoveY = 1;
            }
            else
            {
                newX = 0;
                newY = 0;
                path.pop();
            }
        }
    }
}
