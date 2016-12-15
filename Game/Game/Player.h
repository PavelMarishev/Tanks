#pragma once
#include "MovingObject.h"
#include <SFML\Graphics.hpp>
#include "bullet.h"
#include "PTurret.h"
using namespace sf;

class Player :public MovingObject
{
private:
	bullet pBullet;
	bool bulleton = false;
	Texture dead;
	Sprite s_dead;
	PTurret turr;
public:
	Player(String p, int x, int y) :MovingObject(p, x, y)
	{

	}
	void turUpd(Vector2f pos){
	
		float dX = pos.x - 125;
		float dY = pos.y - 125;
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
		turr.update(getSprite().getPosition(), rotation);

		
	}
	void playerMoving(){
		if (alive){

			
		

			if (Keyboard::isKeyPressed(Keyboard::A)){ moveTo('l'); }
			else
			{
				if (Keyboard::isKeyPressed(Keyboard::D)){ moveTo('r'); }
				else{
					if (Keyboard::isKeyPressed(Keyboard::W)){ moveTo('u'); }
					else{
						if (Keyboard::isKeyPressed(Keyboard::S)){ moveTo('d'); }
					}
				}
			}
			if (Keyboard::isKeyPressed(Keyboard::U)){ //press U to die 
				alive = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				bulleton = true;
				bullet bul(getRot(), getSprite().getPosition());
				pBullet = bul;
				pBullet.setSprite('r');// не знаю почему без нее не выводило текстуру хотя в пуле.h есть ее загрузка
			}
			if (bulleton){
				if (!pBullet.getLife()) bulleton = false;
				pBullet.go();
			}
		}
		else{
			dead.loadFromFile("images/tanks/deadred00.png");
			s_dead.setTexture(dead);
			s_dead.setTextureRect(IntRect(75, 80, 90, 90));
			setSprite(s_dead);
		}
	}
	bool getBulleton(){
		return bulleton;
	}
	bullet getBullet(){
		return pBullet;
	}
	PTurret getTurr(){
		return turr;
	}
};


