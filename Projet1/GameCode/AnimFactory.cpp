#include "AnimFactory.h"
#include <vector>
#include <iostream>
#include "./Config/Utils.h"

std::map<string, Animation*> AnimFactory::animationInfo = std::map<string, Animation*>();


AnimFactory::~AnimFactory()
{
	for (auto it = animationInfo.begin(); it != animationInfo.end(); ++it)
		delete it->second;
}

void AnimFactory::initFactory()
{
	loadAnim( "Scripts/animSetup.txt" );
}

Animation* AnimFactory::getAnim(string animName)
{
	return 0;
}


void AnimFactory::loadAnim(const string& fileName)
{
	string fileInfo = Utils::readFromFile(fileName);
	std::vector<string> info = Utils::split(fileInfo, '|');
	for each (string infoMap in info)
	{
		// Name assetLocation largeur hauteur nbFrame|
		std::vector<string> animInfo = Utils::split(infoMap, ' ');

		try {
			AnimInfo anim ;
			anim.name  = animInfo[0];
			anim.path = animInfo[1];
			//string to int  => stoi
			anim.width = std::stoi(animInfo[2]);
			anim.height = std::stoi(animInfo[3]);
			anim.nbFrame = std::stoi(animInfo[4]);
			anim.delay = std::stoi(animInfo[5]);
			Animation* animation = new Animation(anim.width, anim.height);
			
			for (int i = 0; i < anim.nbFrame; i++)
			{
				animation->addFrame(i, anim.delay);
			}

			animationInfo.insert( {anim.name,animation } );
		}
		catch (const std::exception& e)
		{
			std::cout << "erreur dans le loading des animations ";
		}
	}
}

