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
            this->delay = delay / 1000.0;
        }

        sf::IntRect bounds; // The area in a texture of the frame
        float delay;     // Time delay to next frame
    };

    Animation(std::string spriteName , unsigned frameWidth, unsigned frameHeight);

    void addFrame(unsigned index, float delay);
    const sf::IntRect& getFrame();
    const std::string& getSpriteName() { return spriteAssetName; }

private:
    float currentTime;
    std::vector<Frame> tabFrames;
    std::string spriteAssetName;

    unsigned frameIndex = 0; 
    const unsigned FRAME_WIDTH;
    const unsigned FRAME_HEIGHT;

};

