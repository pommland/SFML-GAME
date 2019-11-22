#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "SFML/Audio.hpp"
#include "Projectile.h"
#include "wall.h"
#include <fstream>

int counter;
float playerAttack = 1; 

static const float VIEW_HEIGHT = 600.0F;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);

	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int keepItem = 0;
int stateChange = 0;
//int randombox1B2X();
//int randombox1B1objX[9];
//int x;
//int x = rand() % 9;

int PXbox1B2;
unsigned int PYbox1B2;

int PXredplus1B2;
unsigned int PYredplus1B2;

int PXgreenplus1B3;
unsigned int PYgreenplus1B3;


int randombox1B2X()
{
	int randombox1B2objX[8] = { 288,320,352,384,416,448,480,512 };

	PXbox1B2 = rand() % 8;
	return randombox1B2objX[PXbox1B2];
}

int randombox1B2Y()
{
	int randombox1B2objY[9] = { -1416,-1384,-1352,-1320,-1288,-1256,-1224,-1192 };
	
	PYbox1B2 = rand() % 9 ;
	return randombox1B2objY[PYbox1B2];
	
}


int randomredplus1B2X()
{
	int randomredplus1B2objX[8] = { 288,320,352,384,416,448,480,512 };

	PXredplus1B2 = rand() % 8;
	return randomredplus1B2objX[PXredplus1B2];
}

int randomredplus1B2Y()
{
	int randomredplus1B2objY[9] = { -1416,-1384,-1352,-1320,-1288,-1256,-1224,-1192 };

	PYredplus1B2 = rand() % 9;
	return randomredplus1B2objY[PYredplus1B2];
	
}


int randomgreenplus1B3X()
{
	int randomgreenplus1B3objX[14] = { 128,160,192,244,256,288,320,352,384,416,448,480,512,544 };

	PXgreenplus1B3 = rand() % 14;
	return randomgreenplus1B3objX[PXgreenplus1B3];
}

int randomgreenplus1B3Y()
{
	int randomredplus1B2objY[2] = { -2702,-2736 };

	PYredplus1B2 = rand() % 2;
	return randomredplus1B2objY[PYredplus1B2];

}



int mode = 1;

int main()
{
	srand(time(NULL));
	printf("value from function %d\n", randombox1B2X());
	printf("value from function %d", randombox1B2Y());
	
	printf("value from function %d\n", randomredplus1B2X());
	printf("value from function %d", randomredplus1B2Y());


	printf("value from function %d\n", randomgreenplus1B3X());
	printf("value from function %d", randomgreenplus1B3Y());

	//printf("value from function %d", x);
//	printf("value from function %d", y);
	//printf("%d\n",x);
	//printf("%d", randombox1B1objX[x]);

	
	sf::RectangleShape menuPicobj;
	sf::Texture menuPicobjTexture;
	if (!menuPicobjTexture.loadFromFile("menuPic.png")) cout << "sscasca" << endl;
	menuPicobj.setTexture(&menuPicobjTexture);
	menuPicobj.setSize(sf::Vector2f(600,600));
	menuPicobj.setOrigin(0.0f,0.0f);

	vector<Wall>::const_iterator iter15;
	vector<Wall> wallArray;

	//class Wall wall1;
	//wall1.rect.setPosition(-64, -64);

	//wallArray.push_back(wall1);

	sf::RenderWindow window(sf::VideoMode(544, 416), "Svival", sf::Style::Close | sf::Style::Resize);
	window.setFramerateLimit(70);
	
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

	sf::RectangleShape background1;
	sf::Texture backgroundTexture1;

	backgroundTexture1.loadFromFile("G1.png");
	
	background1.setSize(
		sf::Vector2f(544.0f , 416.0f)
	);
	background1.setTexture(&backgroundTexture1);
	background1.setPosition(0.0f, 0.0f);
	
	/////
	sf::RectangleShape warpPoint1;
	warpPoint1.setPosition(512.f, 35.f);
	warpPoint1.setSize({32.f, 2.f});
	warpPoint1.setFillColor(sf::Color::Transparent);
	warpPoint1.setOutlineColor(sf::Color::Red);
	warpPoint1.setOutlineThickness(-1.f);
	/////

	/*WALL*/
	Wall wallB1obj;
	sf::Texture wallB1objTexture;

	wallB1objTexture.loadFromFile("wall1.png");

	wallB1obj.rect.setSize(
		sf::Vector2f(544.0f, 32.0f)
	);
	wallB1obj.rect.setTexture(&wallB1objTexture);
	wallB1obj.rect.setPosition(0.0f, 0.0f);
	wallArray.push_back(wallB1obj);

	Wall downB1;
	downB1.rect.setSize(sf::Vector2f{608,32});
	downB1.rect.setFillColor(sf::Color(190, 190, 190));
	downB1.rect.setPosition(sf::Vector2f{ -32,450 });
	wallArray.push_back(downB1);



	Wall leftB1;
	leftB1.rect.setSize(sf::Vector2f{ 32,448 });
	leftB1.rect.setFillColor(sf::Color(190, 190, 190));
	leftB1.rect.setPosition(sf::Vector2f{ -32,0 });
	wallArray.push_back(leftB1);
	

	Wall rightB1;
	rightB1.rect.setSize(sf::Vector2f{ 32,448 });
	rightB1.rect.setFillColor(sf::Color(190, 190, 190));
	rightB1.rect.setPosition(sf::Vector2f{ 544,0 });
	wallArray.push_back(rightB1);

	sf::RectangleShape background2;
	sf::Texture backgroundTexture2;

	backgroundTexture2.loadFromFile("G2.png");

	background2.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background2.setTexture(&backgroundTexture2);
	background2.setPosition(0.0f, -1448.f);




	/////
	sf::RectangleShape warpPoint2;
	warpPoint2.setPosition(512.f, -1413.f);
	warpPoint2.setSize({ 32.f, 2.f });
	warpPoint2.setFillColor(sf::Color::Transparent);
	warpPoint2.setOutlineColor(sf::Color::Red);
	warpPoint2.setOutlineThickness(-1.f);
	/////




	/*WALL*/
	Wall wallB2obj;
	sf::Texture wallB2objTexture;

	wallB2objTexture.loadFromFile("wall2.png");

	wallB2obj.rect.setSize(
		sf::Vector2f(544.0f, 32.0f)
	);
	wallB2obj.rect.setTexture(&wallB2objTexture);
	wallB2obj.rect.setPosition(0.0f, -1448.0f);
	wallArray.push_back(wallB2obj);



	Wall downB2;
	downB2.rect.setSize(sf::Vector2f{ 608,32 });
	downB2.rect.setFillColor(sf::Color(190, 190, 190));
	downB2.rect.setPosition(sf::Vector2f{ -32,-1000 });
	wallArray.push_back(downB2);



	Wall leftB2;
	leftB2.rect.setSize(sf::Vector2f{ 32,416 });
	leftB2.rect.setFillColor(sf::Color(190, 190, 190));
	leftB2.rect.setPosition(sf::Vector2f{ -32,-1416 });
	wallArray.push_back(leftB2);


	Wall rightB2;
	rightB2.rect.setSize(sf::Vector2f{ 32,416 });
	rightB2.rect.setFillColor(sf::Color(190, 190, 190));
	rightB2.rect.setPosition(sf::Vector2f{ 544,-1416 });
	wallArray.push_back(rightB2);





	sf::RectangleShape background3;
	sf::Texture backgroundTexture3;

	backgroundTexture3.loadFromFile("G3.png");

	background3.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background3.setTexture(&backgroundTexture3);
	background3.setPosition(0.0f, -2896.f);


	/////
	sf::RectangleShape warpPoint3;
	warpPoint3.setPosition(512.f, -2860.f);
	warpPoint3.setSize({ 32.f, 2.f });
	warpPoint3.setFillColor(sf::Color::Transparent);
	warpPoint3.setOutlineColor(sf::Color::Red);
	warpPoint3.setOutlineThickness(-1.f);
	/////




	/*WALL*/
	Wall wallB3obj;
	sf::Texture wallB3objTexture;

	wallB3objTexture.loadFromFile("wall3.png");

	wallB3obj.rect.setSize(
		sf::Vector2f(544.0f, 32.0f)
	);
	wallB3obj.rect.setTexture(&wallB3objTexture);
	wallB3obj.rect.setPosition(0.0f, -2896.0f);
	wallArray.push_back(wallB3obj);



	Wall downB3;
	downB3.rect.setSize(sf::Vector2f{ 608,32 });
	downB3.rect.setFillColor(sf::Color(190, 190, 190));
	downB3.rect.setPosition(sf::Vector2f{ -32,-2448 });
	wallArray.push_back(downB3);



	Wall leftB3;
	leftB3.rect.setSize(sf::Vector2f{ 32,416 });
	leftB3.rect.setFillColor(sf::Color(190, 190, 190));
	leftB3.rect.setPosition(sf::Vector2f{ -32,-2864 });
	wallArray.push_back(leftB3);


	Wall rightB3;
	rightB3.rect.setSize(sf::Vector2f{ 32,416 });
	rightB3.rect.setFillColor(sf::Color(190, 190, 190));
	rightB3.rect.setPosition(sf::Vector2f{ 544,-2864 });
	wallArray.push_back(rightB3);




	sf::RectangleShape background4;
	sf::Texture backgroundTexture4;

	backgroundTexture4.loadFromFile("G4.1.png");

	background4.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background4.setTexture(&backgroundTexture4);
	background4.setPosition(0.0f, -4344.f);




	/*WALL*/
	Wall wallB4obj;
	sf::Texture wallB4objTexture;

	wallB4objTexture.loadFromFile("wall4.png");

	wallB4obj.rect.setSize(
		sf::Vector2f(544.0f, 32.0f)
	);
	wallB4obj.rect.setTexture(&wallB4objTexture);
	wallB4obj.rect.setPosition(0.0f, -4344.0f);
	wallArray.push_back(wallB4obj);



	Wall downB4;
	downB4.rect.setSize(sf::Vector2f{ 608,32 });
	downB4.rect.setFillColor(sf::Color(190, 190, 190));
	downB4.rect.setPosition(sf::Vector2f{ -32,-3896 });
	wallArray.push_back(downB4);



	Wall leftB4;
	leftB4.rect.setSize(sf::Vector2f{ 32,416 });
	leftB4.rect.setFillColor(sf::Color(190, 190, 190));
	leftB4.rect.setPosition(sf::Vector2f{ -32,-4312 });
	wallArray.push_back(leftB4);


	Wall rightB4;
	rightB4.rect.setSize(sf::Vector2f{ 32,416 });
	rightB4.rect.setFillColor(sf::Color(190, 190, 190));
	rightB4.rect.setPosition(sf::Vector2f{ 544,-4312 });
	wallArray.push_back(rightB4);



	sf::RectangleShape background5;
	sf::Texture backgroundTexture5;

	backgroundTexture5.loadFromFile("Map049.png");

	background5.setSize(
		sf::Vector2f(736.0f, 1024.0f)
	);
	background5.setTexture(&backgroundTexture5);
	background5.setPosition(2000.0f, 0.f);

	Wall wallG5obj;
	wallG5obj.rect.setSize(sf::Vector2f{ 736,288 });
	wallG5obj.rect.setFillColor(sf::Color::Transparent);
	wallG5obj.rect.setPosition(sf::Vector2f{ 2000,0 });
	wallArray.push_back(wallG5obj);


	Wall downB5P1;
	downB5P1.rect.setSize(sf::Vector2f{ 288,96 });
	downB5P1.rect.setFillColor(sf::Color::Transparent);
	downB5P1.rect.setPosition(sf::Vector2f{ 2032,864 });
	wallArray.push_back(downB5P1);

	Wall downB5P2;
	downB5P2.rect.setSize(sf::Vector2f{ 288,96 });
	downB5P2.rect.setFillColor(sf::Color::Transparent);
	downB5P2.rect.setPosition(sf::Vector2f{ 2416,864 });
	wallArray.push_back(downB5P2);



	Wall leftB5;
	leftB5.rect.setSize(sf::Vector2f{ 32,672 });
	leftB5.rect.setFillColor(sf::Color::Transparent);
	leftB5.rect.setPosition(sf::Vector2f{ 2000,288 });
	wallArray.push_back(leftB5);


	Wall rightB5;
	rightB5.rect.setSize(sf::Vector2f{ 32,672 });
	rightB5.rect.setFillColor(sf::Color::Red);
	rightB5.rect.setPosition(sf::Vector2f{ 2704,288 });
	wallArray.push_back(rightB5);








	//

	sf::RectangleShape wallblackF1obj;
	sf::Texture wallblackF1objTexture;
	wallblackF1objTexture.loadFromFile("wallblack.png");

	wallblackF1obj.setTexture(&wallblackF1objTexture);
	wallblackF1obj.setSize(sf::Vector2f(544.f, 33.f));
	wallblackF1obj.setPosition(0.f, -3928.f);



	sf::RectangleShape wallblackB3obj;
	sf::Texture wallblackB3objTexture;
	wallblackB3objTexture.loadFromFile("wallblack.png");

	wallblackB3obj.setTexture(&wallblackB3objTexture);
	wallblackB3obj.setSize(sf::Vector2f(544.f, 33.f));
	wallblackB3obj.setPosition(0.f, -2480.f);



	sf::RectangleShape wallblackB2obj;
	sf::Texture wallblackB2objTexture;
	wallblackB2objTexture.loadFromFile("wallblack.png");

	wallblackB2obj.setTexture(&wallblackB2objTexture);
	wallblackB2obj.setSize(sf::Vector2f(544.f, 33.f));
	wallblackB2obj.setPosition(0.f, -1032.f);
	
	sf::RectangleShape wallblackB1obj;
	sf::Texture wallblackB1objTexture;
	wallblackB1objTexture.loadFromFile("wallblack.png");

	wallblackB1obj.setTexture(&wallblackB1objTexture);
	wallblackB1obj.setSize(sf::Vector2f(544.f, 33.f));
	wallblackB1obj.setPosition(0.f, 416.f);

	sf::Font font;
	font.loadFromFile("Elianto-Regular.ttf");
	



	/*sf::Texture HPbar;
HPbar.loadFromFile("hp.png");
sf::Sprite hpbar;

int MyHP = 620000;
hpbar.setTexture(HPbar);
sf::RectangleShape HP(sf::Vector2f(MyHP / 250, 30));
HP.setPosition(sf::Vector2f(60, 33));

HP.setFillColor(sf::Color::Red);
HP.setSize(sf::Vector2f(MyHP / 260, 36));
hpbar.setPosition(60, 33);
	sf::





	/*--------------------------------------------OBJ   B1----------------------------------------------------*/



	/*
	sf::RectangleShape background1;
	sf::Texture backgroundTexture1;

	backgroundTexture1.loadFromFile("G1.png");
	
	background1.setSize(
		sf::Vector2f(544.0f , 416.0f)
	);
	background1.setTexture(&backgroundTexture1);
	background1.setPosition(0.0f, 0.0f);
	*/

	/*BOX1*/
	sf::RectangleShape box1B1obj;
	sf::Texture box1B1objTexture;
	sf::Texture box1B1objTexture1;

	box1B1objTexture.loadFromFile("box1.png");
	box1B1objTexture1.loadFromFile("def.png");

	box1B1obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	box1B1obj.setTexture(&box1B1objTexture);
	box1B1obj.setPosition(502.f, 35.f);

	

	
	/*SOFA*/
	Wall doublesofa1B1obj;
	sf::Texture doublesofa1B1objTexture;

	doublesofa1B1objTexture.loadFromFile("doublesofa.png");

	doublesofa1B1obj.rect.setSize(
		sf::Vector2f(64.0f, 96.0f)
	);
	doublesofa1B1obj.rect.setTexture(&doublesofa1B1objTexture);
	doublesofa1B1obj.rect.setPosition(85.0f, 96.f);

	wallArray.push_back(doublesofa1B1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall  doublesofa2B1obj;
	sf::Texture doublesofa2B1objTexture;

	doublesofa2B1objTexture.loadFromFile("doublesofa.png");

	doublesofa2B1obj.rect.setSize(
		sf::Vector2f(64.0f, 96.0f)
	);
	doublesofa2B1obj.rect.setTexture(&doublesofa2B1objTexture);
	doublesofa2B1obj.rect.setPosition(85.f, 270.f);
	wallArray.push_back(doublesofa2B1obj);


	/*BED*/
	Wall weightbed1B1obj;
	sf::Texture weightbed1B1objTexture;

	weightbed1B1objTexture.loadFromFile("weightbed.png");

	weightbed1B1obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed1B1obj.rect.setTexture(&weightbed1B1objTexture);
	weightbed1B1obj.rect.setPosition(192.f, 104.f);
	wallArray.push_back(weightbed1B1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed2B1obj;
	sf::Texture weightbed2B1objTexture;

	weightbed2B1objTexture.loadFromFile("weightbed.png");

	weightbed2B1obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed2B1obj.rect.setTexture(&weightbed2B1objTexture);
	weightbed2B1obj.rect.setPosition(192.f, 256.f);

	wallArray.push_back(weightbed2B1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed3B1obj;
	sf::Texture weightbed3B1objTexture;

	weightbed3B1objTexture.loadFromFile("weightbed.png");

	weightbed3B1obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed3B1obj.rect.setTexture(&weightbed3B1objTexture);
	weightbed3B1obj.rect.setPosition(340.f, 96.f);
	wallArray.push_back(weightbed3B1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed4B1obj;
	sf::Texture weightbed4B1objTexture;

	weightbed4B1objTexture.loadFromFile("weightbed.png");

	weightbed4B1obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed4B1obj.rect.setTexture(&weightbed4B1objTexture);
	weightbed4B1obj.rect.setPosition(340.f, 256.f);
	wallArray.push_back(weightbed4B1obj);
	/*--------------------------------------------------------------------------------------------------------*/




	/*--------------------------------------------OBJ   B2----------------------------------------------------*/

	/*sf::RectangleShape background2;
	sf::Texture backgroundTexture2;

	backgroundTexture2.loadFromFile("G2.png");

	background2.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background2.setTexture(&backgroundTexture2);
	background2.setPosition(0.0f, -416.f);*/

	/*BOX1*/
	sf::RectangleShape box1B2obj;
	sf::Texture box1B2objTexture;
	sf::Texture box1B2objTexture1;

	box1B2objTexture.loadFromFile("box1.png");
	box1B2objTexture1.loadFromFile("def.png");

	box1B2obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	box1B2obj.setTexture(&box1B2objTexture);
	box1B2obj.setPosition(sf::Vector2f(randombox1B2X(), randombox1B2Y()));
	//box1B2obj.setOrigin(box1B2obj.getSize() / 2.0f);

	/*BED*/
	Wall weightbed1B2obj;
	sf::Texture weightbed1B2objTexture;

	weightbed1B2objTexture.loadFromFile("weightbed.png");

	weightbed1B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed1B2obj.rect.setTexture(&weightbed1B2objTexture);
	weightbed1B2obj.rect.setPosition(0.f, -1416.f);
	wallArray.push_back(weightbed1B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed2B2obj;
	sf::Texture weightbed2B2objTexture;

	weightbed2B2objTexture.loadFromFile("weightbed.png");

	weightbed2B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed2B2obj.rect.setTexture(&weightbed2B2objTexture);
	weightbed2B2obj.rect.setPosition(96.f, -1416.f);
	wallArray.push_back(weightbed2B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed3B2obj;
	sf::Texture weightbed3B2objTexture;

	weightbed3B2objTexture.loadFromFile("weightbed.png");

	weightbed3B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed3B2obj.rect.setTexture(&weightbed3B2objTexture);
	weightbed3B2obj.rect.setPosition(320.f, -1128.f);
	wallArray.push_back(weightbed3B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall weightbed4B2obj;
	sf::Texture weightbed4B2objTexture;

	weightbed4B2objTexture.loadFromFile("weightbed.png");

	weightbed4B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	weightbed4B2obj.rect.setTexture(&weightbed4B2objTexture);
	weightbed4B2obj.rect.setPosition(416.f, -1128.f);
	wallArray.push_back(weightbed4B2obj);

	/*FRONTSOFA*/
	Wall frontsofa1B2obj;
	sf::Texture frontsofa1B2objTexture;

	frontsofa1B2objTexture.loadFromFile("frontsofa.png");

	frontsofa1B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	frontsofa1B2obj.rect.setTexture(&frontsofa1B2objTexture);
	frontsofa1B2obj.rect.setPosition(192.f, -1416.f);
	wallArray.push_back(frontsofa1B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall frontsofa2B2obj;
	sf::Texture frontsofa2B2objTexture;

	frontsofa2B2objTexture.loadFromFile("frontsofa.png");

	frontsofa2B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	frontsofa2B2obj.rect.setTexture(&frontsofa2B2objTexture);
	frontsofa2B2obj.rect.setPosition(128.f, -1224.f);
	wallArray.push_back(frontsofa2B2obj);
	/*BACKSOFA*/
	//sf::RectangleShape backsofa1B2obj;
	//sf::Texture backsofa1B2objTexture;

	//backsofa1B2objTexture.loadFromFile("backsofa.png");

	//backsofa1B2obj.setSize(
		//sf::Vector2f(96.0f, 64.0f)
	//);
	//backsofa1B2obj.setTexture(&backsofa1B2objTexture);
	//backsofa1B2obj.setPosition(192.f, -1320.f);
	//////////////////////////////////////////////////////////////////////////////////
	Wall backsofa2B2obj;
	sf::Texture backsofa2B2objTexture;

	backsofa2B2objTexture.loadFromFile("backsofa.png");

	backsofa2B2obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	backsofa2B2obj.rect.setTexture(&backsofa2B2objTexture);
	backsofa2B2obj.rect.setPosition(64.f, -1096.f);
	wallArray.push_back(backsofa2B2obj);

	/*BACKCHAIR*/
	Wall backchair1B2obj;
	sf::Texture backchair1B2objTexture;

	backchair1B2objTexture.loadFromFile("backchair.png");

	backchair1B2obj.rect.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	backchair1B2obj.rect.setTexture(&backchair1B2objTexture);
	backchair1B2obj.rect.setPosition(64.f, -1352.f);
	wallArray.push_back(backchair1B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall backchair2B2obj;
	sf::Texture backchair2B2objTexture;

	backchair2B2objTexture.loadFromFile("backchair.png");

	backchair2B2obj.rect.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	backchair2B2obj.rect.setTexture(&backchair2B2objTexture);
	backchair2B2obj.rect.setPosition(160.f, -1352.f);
	wallArray.push_back(backchair2B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall backchair3B2obj;
	sf::Texture backchair3B2objTexture;

	backchair3B2objTexture.loadFromFile("backchair.png");

	backchair3B2obj.rect.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	backchair3B2obj.rect.setTexture(&backchair3B2objTexture);
	backchair3B2obj.rect.setPosition(32.f, -1096.f);
	wallArray.push_back(backchair1B2obj);

	/*TABLE*/
	Wall table1B2obj;
	sf::Texture table1B2objTexture;

	table1B2objTexture.loadFromFile("table.png");

	table1B2obj.rect.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	table1B2obj.rect.setTexture(&table1B2objTexture);
	table1B2obj.rect.setPosition(192.f, -1352.f);
	wallArray.push_back(table1B2obj);
	//////////////////////////////////////////////////////////////////////////////////

	/*REDPLUS*/
	sf::RectangleShape redplus1B2obj;
	sf::Texture redplus1B2objTexture;
	sf::Texture redplus1B2objTexture1;

	redplus1B2objTexture.loadFromFile("redplus.png");
	redplus1B2objTexture1.loadFromFile("groundbox.png");

	redplus1B2obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	redplus1B2obj.setTexture(&redplus1B2objTexture);
	redplus1B2obj.setPosition(sf::Vector2f( randomredplus1B2X(),randomredplus1B2Y() ));
	//////////////////////////////////////////////////////////////////////////////////

	/*BED*/
	Wall bed1B2obj;
	sf::Texture bed1B2objTexture;

	bed1B2objTexture.loadFromFile("bed.png");

	bed1B2obj.rect.setSize(
		sf::Vector2f(32.0f, 64.0f)
	);
	bed1B2obj.rect.setTexture(&bed1B2objTexture);
	bed1B2obj.rect.setPosition(96.f, -1256.f);
	wallArray.push_back(bed1B2obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall bed2B2obj;
	sf::Texture bed2B2objTexture;

	bed2B2objTexture.loadFromFile("bed.png");

	bed2B2obj.rect.setSize(
		sf::Vector2f(32.0f, 64.0f)
	);
	bed2B2obj.rect.setTexture(&bed2B2objTexture);
	bed2B2obj.rect.setPosition(288.f, -1128.f);
	wallArray.push_back(bed1B2obj);
	//////////////////////////////////////////////////////////////////////////////////

	/*LONGLEFTSINK*/
	Wall longleftsink1B2obj;
	sf::Texture longleftsink1B2objTexture;

	longleftsink1B2objTexture.loadFromFile("longleftsink.png");

	longleftsink1B2obj.rect.setSize(
		sf::Vector2f(32.0f, 96.0f)
	);
	longleftsink1B2obj.rect.setTexture(&longleftsink1B2objTexture);
	longleftsink1B2obj.rect.setPosition(0.f, -1160.f);
	wallArray.push_back(longleftsink1B2obj);
	//////////////////////////////////////////////////////////////////////////////////

	/*BLOODCHAIR*/
	Wall bloodchair1B2obj;
	sf::Texture bloodchair1B2objTexture;

	bloodchair1B2objTexture.loadFromFile("bloodchair.png");

	bloodchair1B2obj.rect.setSize(
		sf::Vector2f(64.0f, 32.0f)
	);
	bloodchair1B2obj.rect.setTexture(&bloodchair1B2objTexture);
	bloodchair1B2obj.rect.setPosition(224.f, -1128.f);
	wallArray.push_back(bloodchair1B2obj);
	//////////////////////////////////////////////////////////////////////////////////

	/*RIGHTCHAIR*/
	Wall rightchair1B2obj;
	sf::Texture rightchair1B2objTexture;

	rightchair1B2objTexture.loadFromFile("rightsink.png");

	rightchair1B2obj.rect.setSize(
		sf::Vector2f(32.0f, 64.0f)
	);
	rightchair1B2obj.rect.setTexture(&rightchair1B2objTexture);
	rightchair1B2obj.rect.setPosition(512.f, -1128.f);
	wallArray.push_back(rightchair1B2obj);
	//////////////////////////////////////////////////////////////////////////////////


	/*--------------------------------------------------------------------------------------------------------*/



	/*--------------------------------------------OBJ   B3----------------------------------------------------*/
	/*sf::RectangleShape background3;
	sf::Texture backgroundTexture3;

	backgroundTexture3.loadFromFile("G3.png");

	background3.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background3.setTexture(&backgroundTexture3);
	background3.setPosition(0.0f, -832.f);*/

	/*FRONTSOFASPECIAL-FRONTSOFA*/
	Wall frontsofaspecial1B3obj;
	sf::Texture frontsofaspecial1B3objTexture;

	frontsofaspecial1B3objTexture.loadFromFile("frontsofaspecial1.png");

	frontsofaspecial1B3obj.rect.setSize(
		sf::Vector2f(352.0f, 64.0f)
	);
	frontsofaspecial1B3obj.rect.setTexture(&frontsofaspecial1B3objTexture);
	frontsofaspecial1B3obj.rect.setPosition(192.f, -2800.f);
	wallArray.push_back(frontsofaspecial1B3obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall tableSP2B3obj;
	sf::Texture tableSP2B3objTexture;

	tableSP2B3objTexture.loadFromFile("tableSP2.png");

	tableSP2B3obj.rect.setSize(
		sf::Vector2f(320.0f, 32.0f)
	);
	tableSP2B3obj.rect.setTexture(&tableSP2B3objTexture);
	tableSP2B3obj.rect.setPosition(170.f, -2672.f);
	wallArray.push_back(tableSP2B3obj);
	//////////////////////////////////////////////////////////////////////////////////
	//Wall frontsofaspecial3B3obj;
	//sf::Texture frontsofaspecial3B3objTexture;

	//frontsofaspecial3B3objTexture.loadFromFile("frontsofaspecial3.png");

	//frontsofaspecial3B3obj.rect.setSize(
		//sf::Vector2f(64.0f, 64.0f)
	//);
	//frontsofaspecial3B3obj.rect.setTexture(&frontsofaspecial3B3objTexture);
	//frontsofaspecial3B3obj.rect.setPosition(96.f, -2768.f);
	//wallArray.push_back(frontsofaspecial3B3obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall frontsofa1B3obj;
	sf::Texture frontsofa1B3objTexture;

	frontsofa1B3objTexture.loadFromFile("frontsofa.png");

	frontsofa1B3obj.rect.setSize(
		sf::Vector2f(96.0f, 64.0f)
	);
	frontsofa1B3obj.rect.setTexture(&frontsofa1B3objTexture);
	frontsofa1B3obj.rect.setPosition(0.f, -2768.f);
	wallArray.push_back(frontsofa1B3obj);
	/*LEFT/RIGHTSOFASPECIAL-DOUBLESOFA*/
	//Wall leftsofaspecial1B3obj;
	//sf::Texture leftsofaspecial1B3objTexture;

	//leftsofaspecial1B3objTexture.loadFromFile("leftsofaspecial1.png");

	//leftsofaspecial1B3obj.rect.setSize(
		//sf::Vector2f(32.0f, 96.0f)
	//);
	//leftsofaspecial1B3obj.rect.setTexture(&leftsofaspecial1B3objTexture);
	//leftsofaspecial1B3obj.rect.setPosition(138.f, -2704.f);
	//wallArray.push_back(leftsofaspecial1B3obj);
	//////////////////////////////////////////////////////////////////////////////////
	//Wall rightsofaspecial1B3obj;
	//sf::Texture rightsofaspecial1B3objTexture;

	//rightsofaspecial1B3objTexture.loadFromFile("rightsofaspecial1.png");

	//rightsofaspecial1B3obj.rect.setSize(
	//	sf::Vector2f(32.0f, 96.0f)
	//);
	//rightsofaspecial1B3obj.rect.setTexture(&rightsofaspecial1B3objTexture);
	//rightsofaspecial1B3obj.rect.setPosition(480.f, -2704.f);
	//////////////////////////////////////////////////////////////////////////////////
	Wall doublesofashort1B3obj;
	sf::Texture doublesofashort1B3objTexture;

	doublesofashort1B3objTexture.loadFromFile("doublesofashort.png");

	doublesofashort1B3obj.rect.setSize(
		sf::Vector2f(64.0f, 64.0f)
	);
	doublesofashort1B3obj.rect.setTexture(&doublesofashort1B3objTexture);
	doublesofashort1B3obj.rect.setPosition(64.f, -2640.f);
	wallArray.push_back(doublesofashort1B3obj);
	/*BACKSPECIALSOFA*/
	Wall backsofaspecial1B3obj;
	sf::Texture  backsofaspecial1B3objTexture;

	backsofaspecial1B3objTexture.loadFromFile("backsofaspecial1.png");

	backsofaspecial1B3obj.rect.setSize(
		sf::Vector2f(480.0f, 64.0f)
	);
	backsofaspecial1B3obj.rect.setTexture(&backsofaspecial1B3objTexture);
	backsofaspecial1B3obj.rect.setPosition(64.f, -2576.f);
	wallArray.push_back(backsofaspecial1B3obj);

	/*GREENPLUS*/
	sf::RectangleShape greenplus1B3obj;
	sf::Texture greenplus1B3objTexture;
	sf::Texture greenplus1B3objTexture1;

	greenplus1B3objTexture.loadFromFile("greenplus.png");
	greenplus1B3objTexture1.loadFromFile("groundbox.png");

	greenplus1B3obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	greenplus1B3obj.setTexture(&greenplus1B3objTexture);
	greenplus1B3obj.setPosition(randomgreenplus1B3X(), randomgreenplus1B3Y());
	/*--------------------------------------------------------------------------------------------------------*/

	/*--------------------------------------------OBJ   B4----------------------------------------------------*/

	/*sf::RectangleShape background4;
	sf::Texture backgroundTexture4;

	backgroundTexture4.loadFromFile("G4.1.png");

	background4.setSize(
		sf::Vector2f(544.0f, 416.0f)
	);
	background4.setTexture(&backgroundTexture4);
	background4.setPosition(0.0f, -1248.f);*/

	/*REDPLUS*/
	sf::RectangleShape redplus1F1obj;
	sf::Texture redplus1F1objTexture;
	sf::Texture redplus1F1objTexture1;

	redplus1F1objTexture.loadFromFile("redplus.png");
	redplus1F1objTexture1.loadFromFile("groundbox.png");

	redplus1F1obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	redplus1F1obj.setTexture(&redplus1F1objTexture);
	redplus1F1obj.setPosition(448.f, -4312.f);

	/*TABLESP*/
	Wall tableSP1F1obj;
	sf::Texture  tableSP1F1objTexture;

	tableSP1F1objTexture.loadFromFile("tableSP1.png");

	tableSP1F1obj.rect.setSize(
		sf::Vector2f(480.0f, 32.0f)
	);
	tableSP1F1obj.rect.setTexture(&tableSP1F1objTexture);
	tableSP1F1obj.rect.setPosition(64.f, -3992.f);
	wallArray.push_back(tableSP1F1obj);
	//////////////////////////////////////////////////////////////////////////////////
	//Wall tableSP2P1F1obj;
	//sf::Texture  tableSP2P1F1objTexture;

	//tableSP2P1F1objTexture.loadFromFile("tableSP2.png");

	//tableSP2P1F1obj.rect.setSize(
		//sf::Vector2f(320.f, 32.f)
	//);
	//tableSP2P1F1obj.rect.setTexture(&tableSP2P1F1objTexture);
	//tableSP2P1F1obj.rect.setPosition(64.f, -4280.f);
	//////////////////////////////////////////////////////////////////////////////////
	Wall tableSP2P2F1obj;
	sf::Texture  tableSP2P2F1objTexture;

	tableSP2P2F1objTexture.loadFromFile("tableSP2.png");

	tableSP2P2F1obj.rect.setSize(
		sf::Vector2f(320.f, 32.f)
	);
	tableSP2P2F1obj.rect.setTexture(&tableSP2P2F1objTexture);
	tableSP2P2F1obj.rect.setPosition(128.f, -4216.f);

	wallArray.push_back(tableSP2P2F1obj);
	//////////////////////////////////////////////////////////////////////////////////
	//Wall tableSP2P3F1obj;
	//sf::Texture  tableSP2P3F1objTexture;

	//tableSP2P3F1objTexture.loadFromFile("tableSP2.png");

	//tableSP2P3F1obj.rect.setSize(
		//sf::Vector2f(320.f, 32.f)
	//);
	//tableSP2P3F1obj.rect.setTexture(&tableSP2P3F1objTexture);
	//tableSP2P3F1obj.rect.setPosition(64.f, -4152.f);
	//////////////////////////////////////////////////////////////////////////////////
	Wall tableSP2P4F1obj;
	sf::Texture  tableSP2P4F1objTexture;

	tableSP2P4F1objTexture.loadFromFile("tableSP2.png");

	tableSP2P4F1obj.rect.setSize(
		sf::Vector2f(320.f, 32.f)
	);
	tableSP2P4F1obj.rect.setTexture(&tableSP2P4F1objTexture);
	tableSP2P4F1obj.rect.setPosition(128.f, -4088.f);
	wallArray.push_back(tableSP2P4F1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall tableSP3F1obj;
	sf::Texture  tableSP3F1objTexture;

	tableSP3F1objTexture.loadFromFile("tableSP3.png");

	tableSP3F1obj.rect.setSize(
		sf::Vector2f(32.0f, 288.0f)
	);
	tableSP3F1obj.rect.setTexture(&tableSP3F1objTexture);
	tableSP3F1obj.rect.setPosition(37.f, -4248.f);
	wallArray.push_back(tableSP3F1obj);
	//////////////////////////////////////////////////////////////////////////////////
	//Wall tableSP4F1obj;
	//sf::Texture  tableSP4F1objTexture;

	//tableSP4F1objTexture.loadFromFile("tableSP5.png");

	//tableSP4F1obj.rect.setSize(
		//sf::Vector2f(32.0f, 256.0f)
	//);
	//tableSP4F1obj.rect.setTexture(&tableSP4F1objTexture);
	//tableSP4F1obj.rect.setPosition(480.f, -4312.f);
	//wallArray.push_back(tableSP4F1obj);
	//////////////////////////////////////////////////////////////////////////////////
	Wall tableSP5F1obj;
	sf::Texture  tableSP5F1objTexture;

	tableSP5F1objTexture.loadFromFile("tableSP5.png");

	tableSP5F1obj.rect.setSize(
		sf::Vector2f(32.0f, 256.0f)
	);
	tableSP5F1obj.rect.setTexture(&tableSP5F1objTexture);
	tableSP5F1obj.rect.setPosition(416.f, -4312.f);
	wallArray.push_back(tableSP5F1obj);
	/*--------------------------------------------------------------------------------------------------------*/

	

	/*--------------------------------------------OBJ   G5----------------------------------------------------*/
	/*box1G5*/
	sf::RectangleShape box1G5obj;
	sf::Texture box1G5objTexture;
	sf::Texture box1G5objTexture1;

	box1G5objTexture.loadFromFile("box1.png");
	box1G5objTexture1.loadFromFile("beZom.png");

	box1G5obj.setSize(
		sf::Vector2f(32.0f, 32.0f)
	);
	box1G5obj.setTexture(&box1G5objTexture);
	box1G5obj.setPosition(2350.f, 560.f);
	/*--------------------------------------------------------------------------------------------------------*/



	
	


	sf::SoundBuffer playerBuffer;

	sf::Sound playerSound;
	playerBuffer.loadFromFile("grass_0.wav");
	playerSound.setBuffer(playerBuffer);
	playerSound.play();




	sf::SoundBuffer playerAttackSound;
	sf::Sound playerAttackSoundobj;
	playerAttackSound.loadFromFile("Explosion6.wav");
	playerAttackSoundobj.setBuffer(playerAttackSound);
	




	sf::Music music;
	music.setVolume(15.0f);
	music.openFromFile("SF8T1_BGM14_Field_Castle.ogg");
	music.play();



	//sf::SoundBuffer Buffer;
	//sf::Sound Sound;
	//Buffer.loadFromFile("hasune.ogg");
	//Sound.setBuffer(playerBuffer);
	//Sound.play();



	int select = 0;

	sf::Texture playerTexture;
	sf::Texture playerTexture1;
	//sf::Texture playerTexture2;
	sf::Texture playerTexture2;
	Player player;
	playerTexture.loadFromFile("PomLongSwordtry2.png");
	//playerTexture1.loadFromFile("PomHaveClothestry2.png");
	playerTexture1.loadFromFile("PomHaveClothestry2.png");
	playerTexture2.loadFromFile("PomZombieMode.png");
	player.sprite.setTexture(playerTexture); 


	sf::Texture enemyTexture;
	sf::Texture enemyTexture2;
	sf::Texture enemyTexture3;
	sf::Texture enemyTexture4;

	Enemy enemy;
	enemyTexture.loadFromFile("Zombie_Level1.png");
	enemyTexture2.loadFromFile("Zombie level3.png");
	enemyTexture3.loadFromFile("Zombie level2.png");
	enemyTexture4.loadFromFile("miniboss.png");
	enemy.sprite.setTexture(enemyTexture); 
	 
	float deltatime = 0.0f;
	sf::Clock clock;

	std::vector<std::string> menuitem = { "Play", "Score", "Quit" };
	Projectile bullet;


	///////////////
	int enemy_move = 0;
	vector<Enemy> enemyArray;
	
	enemy.rect.setPosition({150, 200});
	enemy.enemyAttack = 0.1;
	enemyArray.push_back(enemy);
	
	enemy.rect.setPosition({ 200, 200 });
	enemyArray.push_back(enemy);

	enemy.rect.setPosition({ 270, 350 });
	enemyArray.push_back(enemy);

	enemy.rect.setPosition({ 340, 350 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 400, 375 });
	enemyArray.push_back(enemy);



	enemy.sprite.setTexture(enemyTexture2);
	enemy.hp = 35;
	enemy.enemyAttack = 0.1;


	enemy.rect.setPosition({ 32, -1300 });
	enemyArray.push_back(enemy);

	enemy.rect.setPosition({ 96, -1210 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 256, -1300 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 288, -1204 });
	enemyArray.push_back(enemy);

	enemy.rect.setPosition({ 288, -1224 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 320, -1354 });
	enemyArray.push_back(enemy);



	enemy.sprite.setTexture(enemyTexture3);
	enemy.hp = 35;
	enemy.enemyAttack = 0.1;

	enemy.rect.setPosition({ 70, -2750 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 198, -2690 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 255, -2760 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 285, -2690 });
	enemyArray.push_back(enemy);


	enemy.sprite.setTexture(enemyTexture4);
	enemy.hp = 70;
	enemy.enemyAttack = 0.3;

	enemy.rect.setPosition({ 98, -4300 });
	enemyArray.push_back(enemy);


	enemy.rect.setPosition({ 160, -4200 });
	enemyArray.push_back(enemy);



	enemy.rect.setPosition({ 470, -4150 });
	enemyArray.push_back(enemy);









//	enemy.rect.setPosition({ 320, -1200 });
//	enemyArray.push_back(enemy);



//	enemy.rect.setPosition({ 288, -1170 });
//	enemyArray.push_back(enemy);


	//enemy.rect.setPosition({ 288, -1096 });
	//enemyArray.push_back(enemy);


	///////////////

	///////save/menu////////
	string str = "";
	sf::Text displayscore(str, font);
	displayscore.setCharacterSize(20);
	displayscore.setFillColor(sf::Color::Black);

	ofstream filewriter;
	

	std::map<int, std::string> scores;
	std::ifstream filereader;

	std::string word;
	///////////////////////

	sf::Text Keepscore;
	Keepscore.setString("Score : ");
	Keepscore.setFont(font);
	Keepscore.setFillColor(sf::Color::Black);
	Keepscore.setCharacterSize(20);
	Keepscore.setPosition(0.0f,0.0f);

	sf::Clock Clockscore;
	float score = 0;

	bool isdeadmusicplay = false;

	while (window.isOpen())
	{ 
		deltatime = clock.restart().asSeconds();
		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::KeyPressed:
				if (mode == 1) {
					if (evnt.key.code == 22) {
						select--;
						if (select == -1)
							select = 2;
					}
					if (evnt.key.code == 18) {
						select++;
						if (select == 3)
							select = 0;
					}
					if (evnt.key.code == 58) {
						if (select == 0) {
							mode = 0;
						}
						if (select == 1) {
							mode = 3;
						}
						if (select == 2) {
							window.close();
						}
					}
				}
				else if (mode == 0) {
					if (evnt.key.code == 4) {
						bullet.rect.setPosition(player.rect.getPosition().x + 7, player.rect.getPosition().y + 13);
						bullet.direction = player.direction;
						bullet.currentframe = 0;
					}
				}
				else if (mode == 3) {
					if (evnt.key.code == 58) {
						mode = 1;
					}
				}
				break;

			case sf::Event::TextEntered:
				if (mode == 2) {
					if (evnt.key.code == 13) {
						filewriter.open("save.txt");
						cout << str << endl;
						filewriter << str << "," << to_string(score) << "\n";
						str = "";
						displayscore.setString(str);
						filewriter.close();
						mode = 1;
					}
					else {
						str += evnt.key.code;
						displayscore.setString(str);
					}
				}
				break;
			case sf::Event::Closed:
				window.close();
				break;
			
			case sf::Event::Resized:
				ResizeView(window, view);
				break;
			}
		}


		Keepscore.setPosition(player.rect.getPosition().x - window.getSize().x/2, player.rect.getPosition().y - window.getSize().y/2);
		if (player.myHP <= 0 && !isdeadmusicplay) {
			music.stop();
			music.openFromFile("deadsound.ogg");
			music.play();
			isdeadmusicplay = true;
			
			Keepscore.setString("You died!!");
		}
		else if (player.myHP > 0 && !isdeadmusicplay) {
			/////score///////
			score += Clockscore.getElapsedTime().asSeconds();
			Clockscore.restart();
			Keepscore.setString("Score: " + to_string(static_cast<int> (score * 100)));
			/////////////
		}


		//player collides with wall
		counter = 0;
		for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
		{
			//std::cout << "drawyo" << std::endl;
			if (player.rect.getGlobalBounds().intersects(iter15->rect.getGlobalBounds())) {
				if (player.direction == 1)//up
				{
					player.canMoveUp = false;
					player.rect.move(0, 5);
				}
				else if (player.direction == 2)//down
				{
					player.canMoveDown = false;
					player.rect.move(0, -5);
				}
				else if (player.direction == 3)//left
				{
					player.canMoveLeft = false;
					player.rect.move(5, 0);
				}
				else if (player.direction == 4)//right
				{
					player.canMoveRight = false;
					player.rect.move(-5, 0);
				}
				else
				{

				}
			}
			counter++;
		}
		
		if (enemy_move == 25) {
			enemy_move = 0;
			for (vector<Enemy>::iterator e = enemyArray.begin(); e != enemyArray.end(); e++) {
				e->direction = rand() % 10;
			}
		}
		enemy_move++;

		for (auto& e : enemyArray) {
			if (player.rect.getGlobalBounds().intersects(e.rect.getGlobalBounds())) {
				player.myHP -= e.enemyAttack;
				if (player.myHP <= 0)
				{
					player.myHP = 0;
				}
			}
		}

		if (player.rect.getGlobalBounds().intersects(warpPoint1.getGlobalBounds())) {
			player.rect.setPosition({ 491, -1073 });
		}

		if (player.rect.getGlobalBounds().intersects(warpPoint2.getGlobalBounds())) {
			player.rect.setPosition({ 491, -2523 });
		}

		if (player.rect.getGlobalBounds().intersects(warpPoint3.getGlobalBounds())) {
			player.rect.setPosition({ 491, -3973 });
		}


		if (player.rectfoot.getGlobalBounds().intersects(box1B2obj.getGlobalBounds())) {
			player.sprite.setTexture(playerTexture1);
			box1B2obj.setTexture(&box1B2objTexture1);
			player.activeItem2 = player.iconobj4;

			
		}


		if (player.rectfoot.getGlobalBounds().intersects(box1G5obj.getGlobalBounds())) {
			player.sprite.setTexture(playerTexture2);
			box1G5obj.setTexture(&box1G5objTexture1);
			//player.activeItem2 = player.iconobj4;
			player.activeItem = player.iconobj5;
			player.activeItem2 = player.iconobj6;


		}




		if (player.rectfoot.getGlobalBounds().intersects(redplus1B2obj.getGlobalBounds())) {
			if (keepItem == 0 && stateChange == 0 ) {
				redplus1B2obj.setTexture(&redplus1B2objTexture1);
				player.myHP += 10;
				if (player.myHP >= 45)
				{
					player.myHP = 45;
				}
				keepItem = 1;
				stateChange = 1;
			}
		}

		if (player.rectfoot.getGlobalBounds().intersects(greenplus1B3obj.getGlobalBounds())) {
			greenplus1B3obj.setTexture(&greenplus1B3objTexture1);
			player.myHP = 45;
		}
		if (player.rectfoot.getGlobalBounds().intersects(redplus1F1obj.getGlobalBounds())) {
			redplus1F1obj.setTexture(&redplus1F1objTexture1);
			player.myHP += 30;
		}

		if (player.rectfoot.getGlobalBounds().intersects(box1B1obj.getGlobalBounds())) {
			
			box1B1obj.setTexture(&box1B1objTexture1);
			player.activeItem = player.iconobj2;


			player.absAttack = 128;
			player.topAttack = 9;
			player.downAttack = 11;
			player.leftAttack = 10;
			player.rightAttack = 12;		
			playerAttack = 3;
			std::cout << playerAttack << std::endl;
		}
		
		if (bullet.currentframe == bullet.lifetime) {
			bullet.rect.setPosition(player.rect.getPosition().x+7, player.rect.getPosition().y+13);
			
			bullet.direction == 0;
		}
		else {
			bullet.update();
			for (vector<Enemy>::iterator e = enemyArray.begin(); e != enemyArray.end(); e++) {
				if (bullet.rect.getGlobalBounds().intersects(e->rect.getGlobalBounds())) {
					std::cout << "oraoraoraoaroa" << std::endl;
					bullet.currentframe = bullet.lifetime;
					e->hp-=playerAttack;
					cout << e->hp << endl;
					//bullet.direction == 0;
					
				}
			}
		}

		for (vector<Enemy>::iterator e = enemyArray.begin(); e != enemyArray.end(); e++) {
			//if (distance player and enemy < 3) { e->aggressive = true; }
			counter = 0;
			for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
			{
				//std::cout << "drawyo" << std::endl;
				if (e->rect.getGlobalBounds().intersects(iter15->rect.getGlobalBounds())) {
					if (e->direction == 1)//up
					{
						e->canMoveUp = false;
						e->rect.move(0, 1);
					}
			
					else		 if (e->direction == 2)//down
					{
						e->canMoveDown = false;
						e->rect.move(0, -1);
					}






					else	 if (e->direction == 3)//left
					{
						e->canMoveLeft = false;
						e->rect.move(1, 0);
					}

					else		 if (e->direction == 4)//right
					{
						e->canMoveRight = false;
						e->rect.move(-1, 0);
					}
					else
					{

					}
				}
				counter++;
			}
		//	if(e->rect.getPosition().x - player.rect.getPosition().x )
			if (e->aggressive) {
				if (player.rect.getPosition().x > e->rect.getPosition().x) {
					e->direction = 4;
				}
				else	 if (player.rect.getPosition().x < e->rect.getPosition().x) {
					e->direction = 3;
				}
				 else	 if (player.rect.getPosition().y > e->rect.getPosition().y) {
					e->direction = 2;
				}
				 else	 if (player.rect.getPosition().y < e->rect.getPosition().y) {
					e->direction = 1;
				}
			}
			e->updateCollision();
			if (e->hp <= 0) {
				score += 1000;
				enemyArray.erase(e);
				break;
			}
		}

		///////////////////////// MENU ///////////////////
		sf::Text gameName;
		gameName.setCharacterSize(16);
		gameName.setFillColor(sf::Color::Black);
		gameName.setFont(font);
		gameName.setString("Zubaibaru");
		
		//////////////////////////////////////////////////
		
		
		
		window.clear(sf::Color(0,0,0)); 

		
		if (mode == 0) {
			//window.draw(backgroundTexture);
			window.draw(background1);
			window.draw(background2);
			window.draw(background3);
			window.draw(background4);
			window.draw(background5);

			window.draw(downB1.rect);
			window.draw(leftB1.rect);
			window.draw(rightB1.rect);

			window.draw(downB2.rect);
			window.draw(leftB2.rect);
			window.draw(rightB2.rect);

			window.draw(downB3.rect);
			window.draw(leftB3.rect);
			window.draw(rightB3.rect);

			window.draw(downB4.rect);
			window.draw(leftB4.rect);
			window.draw(rightB4.rect);

			window.draw(downB5P1.rect);
			window.draw(downB5P2.rect);
			window.draw(leftB5.rect);
			window.draw(rightB5.rect);

			window.draw(wallB1obj.rect);
			window.draw(wallB2obj.rect);
			window.draw(wallB3obj.rect);
			window.draw(wallB4obj.rect);
			window.draw(wallG5obj.rect);

			window.draw(doublesofa1B1obj.rect);
			window.draw(doublesofa2B1obj.rect);
			window.draw(weightbed1B1obj.rect);
			window.draw(weightbed2B1obj.rect);
			window.draw(weightbed3B1obj.rect);
			window.draw(weightbed4B1obj.rect);

			window.draw(box1B1obj);


			window.draw(box1B2obj);

			window.draw(weightbed1B2obj.rect);
			window.draw(weightbed2B2obj.rect);
			window.draw(weightbed3B2obj.rect);
			window.draw(weightbed4B2obj.rect);
			window.draw(frontsofa1B2obj.rect);
			window.draw(frontsofa2B2obj.rect);

			//window.draw(backsofa1B2obj);
			window.draw(backsofa2B2obj.rect);

			window.draw(backchair1B2obj.rect);
			window.draw(backchair2B2obj.rect);
			window.draw(backchair3B2obj.rect);

			window.draw(table1B2obj.rect);
			window.draw(redplus1B2obj);
			window.draw(bed1B2obj.rect);
			window.draw(bed2B2obj.rect);
			window.draw(longleftsink1B2obj.rect);
			window.draw(bloodchair1B2obj.rect);
			window.draw(rightchair1B2obj.rect);

			window.draw(frontsofaspecial1B3obj.rect);
			window.draw(tableSP2B3obj.rect);
			//window.draw(frontsofaspecial3B3obj.rect);
			window.draw(frontsofa1B3obj.rect);
			//window.draw(leftsofaspecial1B3obj.rect);
			//window.draw(rightsofaspecial1B3obj.rect);
			window.draw(doublesofashort1B3obj.rect);
			window.draw(backsofaspecial1B3obj.rect);
			window.draw(greenplus1B3obj);

			window.draw(redplus1F1obj);
			window.draw(tableSP1F1obj.rect);
			//window.draw(tableSP2P1F1obj.rect);
			window.draw(tableSP2P2F1obj.rect);
			//window.draw(tableSP2P3F1obj.rect);
			window.draw(tableSP2P4F1obj.rect);
			window.draw(tableSP3F1obj.rect);
			//window.draw(tableSP4F1obj.rect);
			window.draw(tableSP5F1obj.rect);

			window.draw(box1G5obj);

			window.draw(warpPoint1);
			window.draw(warpPoint2);
			window.draw(warpPoint3);


			

			window.draw(bullet.rect);
			view.setCenter(player.GetPosotion());
			player.updateCollision();
			player.updateMovement(&mode);
			enemy.updateCollision();
			player.updateStopMovement();
			player.updateKeyTime(deltatime);


			window.draw(player.activeItem);
			window.draw(player.activeItem2);
			//window.draw(player.iconobj2);

			window.draw(player.HPbarobj);
			window.draw(player.hp);



			window.draw(player.sprite);// window.draw(enemy.sprite);
			window.draw(player.rect);
			for (auto& e : enemyArray) {
				window.draw(e.sprite);
				window.draw(e.rect);
			}
			window.draw(player.rectfoot);
			window.draw(player.rectcentral);
			window.draw(player.rectfrontAttack);
			window.draw(player.rectdownAttack);
			window.draw(player.rectleftAttack);
			window.draw(player.rectrightAttack);
			window.draw(wallblackF1obj);
			//window.draw(wallblackF1obj);
			window.draw(wallblackB3obj);
			window.draw(wallblackB2obj);
			window.draw(wallblackB1obj);
			window.setView(view);

			//bullet.rect.setPosition(player.rect.getPosition());
			//menu.draw(window);

			
			//draw wall
			counter = 0;
			for (iter15 = wallArray.begin(); iter15 != wallArray.end(); iter15++)
			{
				//std::cout << "draw" << std::endl;
				window.draw(wallArray[counter].rect);
				counter++;
			}

			window.draw(Keepscore);


		}
		else if (mode == 1) {
			view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
			window.setView(view);
			window.draw(gameName);
			window.draw(menuPicobj);
			for (int button = 0; button < 3; button++) {
				sf::Text text(menuitem[button], font);
				text.setCharacterSize(20);
				text.setFillColor(sf::Color::Black);
				if(button == select) text.setFillColor(sf::Color::Blue);
				text.setPosition(0, 40 + 30 * button);
				window.draw(text);
			}
		}
		else if (mode == 2) {
			view.setCenter(window.getSize().x / 2, window.getSize().y / 2);
			window.setView(view);

			window.draw(displayscore);
		}
		else if (mode == 3) {
		window.setView(sf::View());
			sf::Text text("Enter to go back", font);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::Black);

			filereader.open("save.txt");
			do {
				filereader >> word;
				auto first_token = word.substr(0, word.find(','));
				auto second_token = std::stoi(word.substr(word.find(',') + 1, word.length()));
				scores[second_token] = first_token;
			} while (filereader.good());
			filereader.close();
			
			std::map<int, std::string>::iterator end = scores.end();
			std::map<int, std::string>::iterator beg = scores.begin();
			end--;
			beg--;
			int currentDisplay = 0;
			for (std::map<int, std::string>::iterator it = end; it != beg; it--) {
				text.setString(it->second);
				text.setPosition(350, 400 + 40 * currentDisplay);
				window.draw(text);
				text.setString(std::to_string(it->first));
				text.setPosition(700, 400 + 40 * currentDisplay);
				window.draw(text);
				currentDisplay++;
				if (currentDisplay == 5) {
					break;
				}
			}
			currentDisplay = 0;
			text.setString("Enter to go back");
			text.setPosition(350, 650);
			window.draw(text);
			}
		window.display(); 
	}
	
		return 0;
}


/* moving scakl move scale
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
{
	player.move(-0.1f, 0.0f);

}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
{
	player.move(0.1f, 0.0f);

}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
{
	player.move(0.1f, -0.1f);

}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
{
	player.move(-0.1f, 0.1f);

}*/



		/*case sf::Event::Resized:
				printf("New window width: %i New window height: %i\n", evnt.size.width, evnt.size.height);
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128) 
				{
					printf("%c", evnt.text.unicode);
				
			
		}*/

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.setPosition((float)mousePos.x, (float)mousePos.y);

		}*/