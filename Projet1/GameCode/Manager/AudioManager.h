#pragma once
#include <SFML/Audio.hpp>
#include <string>
#include <map>

using namespace std;
using namespace sf;

class AudioManager
{

public:
	
	AudioManager();
	~AudioManager();

	static void loadBuffer(string  bufferName, string fileLocation);
	static void loadSound(string bufferName);
	static void loadMusic(string  musicName, string fileLocation);

	static map<string, Sound> sound;
	static map<string, SoundBuffer> buff;
	static map<string, Music> music;

private:
	 

	


};

