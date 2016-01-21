#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <vector>
#include <queue>

#include "findpath.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class engine
{
    public:
        engine();
        ~engine();

    private:
        void gameLoop();
        void checkInputs();
        sf::RenderWindow window;
        void render();
        std::vector<sf::FloatRect> maze;
        sf::Texture mapTexture;
        sf::Sprite mapSprite;
        sf::Texture einsteinTexture;
        sf::Sprite einsteinSprite;
        bool resolveCollisions(int x, int y);
        bool arrived;
        int currentMoveX;
        int currentMoveY;
        std::vector<sf::CircleShape> points;
        void populateMap();
        unsigned int score;
        sf::Font font;
        unsigned int lives;
        void moveEnemy();
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;
        std::queue<MapSearchNode> path;
        int newX;
        int newY;

};

#endif // MAIN_H_INCLUDED
