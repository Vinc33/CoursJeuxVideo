#pragma once

#include <SFML/Graphics.hpp>

    class Collidable {
      public:
        Collidable(float width, float height);
        Collidable();

        bool tryCollideWith(Collidable& other);
        sf::FloatRect getBox();

        virtual sf::Vector2f getPosition() = 0;
        virtual void onCollide(Collidable& other) = 0;

      private:
        sf::Vector2f m_size;
    };