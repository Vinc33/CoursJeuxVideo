#include "AudioManager.h"
#include <iostream>

map<string, sf::Sound> AudioManager::sound = map<string, sf::Sound>();
map<string, sf::SoundBuffer> AudioManager::buff = map<string, sf::SoundBuffer>();
map<string, sf::Music> AudioManager::music = map<string, sf::Music>();

AudioManager::AudioManager() {}
AudioManager::~AudioManager() {}

void AudioManager::loadBuffer(string bufferName, string fileLocation)
{
    if (!AudioManager::buff[bufferName].loadFromFile(fileLocation))
        std::cout << "impossiple de charger l'audio" << std::endl;
}

void AudioManager::loadSound(string bufferName)
{
    AudioManager::sound[bufferName].setBuffer(AudioManager::buff[bufferName]);
}

void AudioManager::loadMusic(string musicName, string fileLocation)
{
    AudioManager::music[musicName].openFromFile(fileLocation);
}

