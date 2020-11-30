#pragma once
#include <string>
#include <map>
#include "Entity/Animation.h"


using std::string;

struct AnimInfo
{
	string path;
	string name;
	int width;
	int height;
	unsigned nbFrame;
	int delay;
};


class AnimFactory
{
public:
		AnimFactory(){}
		~AnimFactory();
		static void initFactory();
		static Animation* getAnim(string animName);

private:

		static void loadAnim(const string& fileName);
		static std::map<string, Animation*> animationInfo;

};

