#include "collidable.h"

    Collidable::Collidable(float width, float height)
        : m_size(width, height)
    { }

    bool Collidable::tryCollideWith(Collidable& other)
    {
        if (getBox().intersects(other.getBox())) {
            onCollide(other);
            other.onCollide(*this);
            return true;
        }
        return false;
    }

    sf::FloatRect Collidable::getBox()
    {
        return {getPosition().x, getPosition().y, m_size.x, m_size.y};
    }

    void Collidable::render(sf::RenderWindow &window)
    {

    }

    int Collidable::update()
    {
        return 0;
    }
