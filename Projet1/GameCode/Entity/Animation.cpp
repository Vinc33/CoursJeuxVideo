#include "Animation.h"
#include "Manager/TimeManager.h"

Animation::Animation(unsigned frameWidth, unsigned frameHeight)
    : FRAME_WIDTH(frameWidth)
    , FRAME_HEIGHT(frameHeight)
    , currentTime(0)
{}

void Animation::addFrame(unsigned index, float delay)
{
    sf::IntRect bounds;
    bounds.top = 0;
    bounds.height = FRAME_HEIGHT;
    bounds.width = FRAME_WIDTH;
    bounds.left = index * FRAME_WIDTH;

    tabFrames.emplace_back(bounds, delay);
}

const sf::IntRect& Animation::getFrame()
{
    currentTime += TimeManager::DeltaTime;
    if (TimeManager::DeltaTime >= tabFrames[frameIndex].delay) {
        currentTime = 0;
        frameIndex++;
        if (frameIndex == tabFrames.size())
            frameIndex = 0;
    }
    return tabFrames[frameIndex].bounds;
}