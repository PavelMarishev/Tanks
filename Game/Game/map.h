#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

const int X = 16;
const int Y = 9;


Texture grass;
Texture breakableWall;
Texture wall;
Texture barricade;

Sprite s_grass;
struct WalRec
{
	Sprite s_wall;
	bool alive;
};

WalRec walRec[30];
Sprite* s_wall = new Sprite[6];

Sprite* s_barricade = new Sprite[9];
int wallHealt[31];

String penemy = "images/tanks/tankblue00.png";
String pgrass = "images/ground/ground1.png";
String pplayer = "images/tanks/tankred00.png";
String pbreakableWall = "images/ground/ground18.png";
String pwall = "images/ground/ground6.png";
String pbarricade = "images/ground/ground17.png";

String Map[Y]{
		"1111111111111111",
		"111w11w11w1w111w",
		"1w1w11wbbw1w111w",
		"1w1w11w11w1w111w",
		"11111iiiiii11111",
		"b1wwiiwwwiiww11b",
		"11111111w1111111",
		"1w1w11111bb11111",
		"1w1w11w111111111",
};

