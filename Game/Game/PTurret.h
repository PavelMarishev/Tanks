#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
class PTurret
{
public:
	Texture turret;
	Sprite s_turret;
	PTurret()
	{
		turret.loadFromFile("images/tanks/gunred00.png");
		s_turret.setTexture(turret);
		s_turret.setOrigin(125, 125);
		s_turret.setScale(0.7, 0.7);

	}
	void update(Vector2f here,float rot){
		s_turret.setPosition(here);
		s_turret.setRotation(rot);
	}
	
	Sprite getSprite(){
		return s_turret;
	}


};

