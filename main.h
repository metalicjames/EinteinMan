#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <vector>

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
        class character;
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

};

#endif // MAIN_H_INCLUDED
