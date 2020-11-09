#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Animation
{
public:
    struct Frame 
    {  
        Frame(const sf::IntRect& bnds, float delay): bounds(bnds)
        {
            this->delay = delay;
        }

        sf::IntRect bounds; // The area in a texture of the frame
        float delay;     // Time delay to next frame
    };

    Animation(unsigned frameWidth, unsigned frameHeight);

    void addFrame(unsigned index, float delay);
    const sf::IntRect& getFrame();

private:
    int currentTime;
    std::vector<Frame> tabFrames;

    unsigned frameIndex = 0; 
    const unsigned FRAME_WIDTH;
    const unsigned FRAME_HEIGHT;

};

