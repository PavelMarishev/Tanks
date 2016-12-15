#pragma once
#include <SFML\Graphics.hpp>
#include "PlayersAndEnemies.h"
using namespace sf;
class bullet
{
private:
	Texture objTexture;
	Sprite objSprite;
	Vector2f pos;
	Vector2f speed;
	bool life = true;
public:
	bullet(){
	}
	bullet(char rotation,Vector2f appear)
	{
		objTexture.loadFromFile("images/bullets/bullet00.png");
		objSprite.setTexture(objTexture);
		objSprite.setOrigin(19, 4.5);
		objSprite.setPosition(appear);
		switch (rotation){
		case'r':
			objSprite.setRotation(0);
			speed = Vector2f(1, 0);
			break;
		case'l':
			objSprite.setRotation(180);
			speed = Vector2f(-1, 0);
			break;
		case'u':
			objSprite.setRotation(270);
			speed = Vector2f(0, -1);
			break;
		case'd':
			objSprite.setRotation(90);
			speed = Vector2f(0, 1);
			break;
		}
		
	}
	void go(){
		for (int i = 0; i < 30; i++){
			if ((objSprite.getGlobalBounds().intersects(walRec[i].s_wall.getGlobalBounds()))&&(walRec[i].alive)){ life = false;
			wallHealt[i]--;
			}
			if ((i < 6) && objSprite.getGlobalBounds().intersects(s_wall[i].getGlobalBounds()))life = false;
			if ((objSprite.getPosition().x < 0) || ((objSprite.getPosition().x>1024))) life = false;
			if ((objSprite.getPosition().y < 0) || ((objSprite.getPosition().y>576))) life = false;
//			if (objSprite.getGlobalBounds().intersects(player.getSprite().getGlobalBounds())) {
		//		life = false;
		//		player.healt--;
		//	}
		//	if (objSprite.getGlobalBounds().intersects(enemy.getSprite().getGlobalBounds())){
			//	life = false;
			//	enemy.healt--;
		//	}
			
		}
		if(life){
			objSprite.move(speed);
		}
	}
	Sprite getBullet(){
		return objSprite;
	}
	
	void setSprite(char color){
		switch (color){
		case 'r':
			objTexture.loadFromFile("images/bullets/bullet00.png");
			objSprite.setTexture(objTexture);
			objSprite.setOrigin(19, 4.5);
			break;
		case 'b':
			objTexture.loadFromFile("images/bullets/bullet02.png");
			objSprite.setTexture(objTexture);
			objSprite.setOrigin(19, 4.5);
			break;
		}
	}
	bool getLife(){
		return life;
	}
		
	

};

