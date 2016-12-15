#pragma once
#include "MovingObject.h"
#include "bullet.h"
#include <SFML\Graphics.hpp>
using namespace sf;

class EnemyPlayer :public MovingObject
{
private:
	Texture dead;
	Sprite s_dead;
	bullet eBullet;
		bool bulleton = false;
		Clock clock;
		int where = 0;

public:
	EnemyPlayer(String p, int x, int y) :MovingObject(p, x, y)
	{
	}
	
	void enemyAnalizer(){
		if (alive){
			if (Keyboard::isKeyPressed(Keyboard::Y)) alive = false; // press Y to kill
			if (clock.getElapsedTime().asMilliseconds() >= 500){
				where = rand() % 6;
				clock.restart();
			}
			switch (where){
			case 1:
				moveTo('l');
				break;
			case 2:
				moveTo('r');
				break;
			case 3:
				moveTo('u');
				break;
			case 4:
				moveTo('d');
				break;
			case 5:
				bulleton = true;
				bullet bul(getRot(), getSprite().getPosition());
				eBullet = bul;
				eBullet.setSprite('b');
				break;
			}
			if (bulleton){
				if (!eBullet.getLife()) bulleton = false;
				eBullet.go();
			}
		}
		else{
			dead.loadFromFile("images/tanks/deadblue00.png");
			s_dead.setTexture(dead);
			s_dead.setTextureRect(IntRect(75, 80, 90, 90));
			setSprite(s_dead);
		}
	}
	bool getBulleton(){
		return bulleton;
	}
	bullet getBullet(){
		return eBullet;
	}

};

