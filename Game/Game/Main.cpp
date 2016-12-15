#include <SFML/Graphics.hpp>
#include "map.h"
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include "PlayersAndEnemies.h"


using namespace sf;

void mapInit(){ //инициализация спрайтов карты
	grass.loadFromFile(pgrass);
	s_grass.setTexture(grass);
	barricade.loadFromFile(pbarricade);
	wall.loadFromFile(pwall);
	breakableWall.loadFromFile(pbreakableWall);

	for (int i = 0; i < 30; i++){
		wallHealt[i] = 3;
		walRec[i].s_wall.setTexture(breakableWall);
		walRec[i].alive = true;
		if (i < 6)s_wall[i].setTexture(wall);
		if (i<9)s_barricade[i].setTexture(barricade);
	}
}




int bWallCounter = 0;//счетчики для прохождения по каждому спрайту определенного типа
int wallCounter = 0;
int barricadeCounter = 0;

Texture tower;
Sprite s_tower;


int main(){
	RenderWindow window(VideoMode(1024, 576), "Tanks");
	Texture mapTexture;
	Sprite mapSprite;
	mapInit();


	while (window.isOpen()){
		Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		
		for (int i = 0; i < Y; i++){
			for (int j = 0; j < X; j++){
			 	s_grass.setPosition(j * 64, i * 64);// отрисовка спрайтов согласно карте и "живым" стенам
			    window.draw(s_grass);
				switch (Map[i][j]){
				case'i': 
					if (barricadeCounter > 8)barricadeCounter = 0;
					s_barricade[barricadeCounter].setPosition(j * 64, i * 64);
					window.draw(s_barricade[barricadeCounter]);
					barricadeCounter++;
					break;
				case'w':
					if (bWallCounter > 29) bWallCounter = 0;
					walRec[bWallCounter].s_wall.setPosition(j * 64, i * 64);
					if (wallHealt[bWallCounter] <= 0){
						walRec[bWallCounter].alive = false;
						walRec[bWallCounter].s_wall.setTexture(grass);
					}
					window.draw(walRec[bWallCounter].s_wall);
					bWallCounter++;
					break;
				case 'b':
					if (wallCounter > 5) wallCounter = 0;
					s_wall[wallCounter].setPosition(j * 64, i * 64);
					window.draw(s_wall[wallCounter]);
					wallCounter++;
					break;
				}
			}
		}

		enemy.enemyAnalizer();
		enemy2.enemyAnalizer();
		enemy3.enemyAnalizer();

		player.playerMoving();

		window.draw(player.getSprite());
		window.draw(enemy.getSprite());
		window.draw(enemy2.getSprite());
		window.draw(enemy3.getSprite());

		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		player.turUpd(pos);
		window.draw(player.getTurr().getSprite());

		if (enemy.getBulleton()){
			window.draw(enemy.getBullet().getBullet());
		}

		if (player.getBulleton()){
			window.draw(player.getBullet().getBullet());
		}


		
	

		window.display();


	}
	return 0;
}