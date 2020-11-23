#pragma once

#include <SFML/Graphics.hpp>

    class Collidable {
      public:
        Collidable(float width, float height);

        bool tryCollideWith(Collidable& other);
        sf::FloatRect getBox();

        virtual sf::Vector2f getPosition() = 0;
        virtual void onCollide(Collidable& other) = 0;
        virtual void render(sf::RenderWindow& window);
        virtual void update();;

      private:
        sf::Vector2f m_size;

    };