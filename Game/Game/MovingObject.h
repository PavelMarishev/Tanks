#pragma once
#include <SFML\Graphics.hpp>
#include "bullet.h"
using namespace sf;

class MovingObject
{
private:
	char rot = 'r';
	Texture objTexture;
	Sprite objSprite;
	Vector2f pos;
	bool canGo = true;

public :

	int healt = 3;
	bool alive = true;
	

public:
	MovingObject(String p,int x,int y){
		pos.x = x;
		pos.y = y;

		objTexture.loadFromFile(p);
		objSprite.setTexture(objTexture);
		objSprite.setTextureRect(IntRect(75, 80, 90, 90));

		objSprite.setScale(0.5,0.5);
		objSprite.setOrigin(45, 45);
		objSprite.setRotation(270);
		objSprite.setPosition(pos);
		
	}
	MovingObject(){

	}
	Sprite moveTo(char rotation){
		rot = rotation;
		canGo = true;
		
		for (int i = 0; i < 30; i++){
			if ((objSprite.getGlobalBounds().intersects(walRec[i].s_wall.getGlobalBounds()))&&(walRec[i].alive)) canGo = false;
			if ((i < 6) && objSprite.getGlobalBounds().intersects(s_wall[i].getGlobalBounds()))canGo = false;
			if ((i<9) && objSprite.getGlobalBounds().intersects(s_barricade[i].getGlobalBounds()))canGo = false;
			if ((objSprite.getPosition().x < 0) || ((objSprite.getPosition().x>1024))) canGo = false;
			if ((objSprite.getPosition().y < 0) || ((objSprite.getPosition().y>576))) canGo = false;
		}
		if (canGo){
			pos = objSprite.getPosition();
			switch (rot){
			case'r':
				objSprite.setRotation(0);
				objSprite.move(0.2, 0);
				break;
			case'l':
				objSprite.move(-0.2, 0);
				objSprite.setRotation(180);
				break;
			case'u':
				objSprite.move(0, -0.2);
				objSprite.setRotation(270);
				break;
			case'd':
				objSprite.move(0, 0.2);
				objSprite.setRotation(90);
				break;
			}
		}
		else{
			objSprite.setPosition(pos);

		}
		return objSprite;
		
	}
	Sprite getSprite(){ return objSprite; }
	void setSprite(Sprite s){
		float rota = objSprite.getRotation();
		Vector2f posa = objSprite.getPosition();
		objSprite = s;
		objSprite.setScale(0.5, 0.5);
		objSprite.setOrigin(45, 45);
		objSprite.setPosition(posa);
		objSprite.setRotation(rota);
	}
	char getRot(){
		return rot;
	}

};

