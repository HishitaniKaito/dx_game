#include <time.h>
#include<list>
#include <algorithm>
#include "game_main.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Player.h"
#include"Bullet.h"
#include"enemy.h"


float inter = 0.25f ;
float einter = 1.0f;
bool init = false;
Player* player = nullptr;
std::list<Bullet*> bullet;
std::list<Enemy*> enemy;
using namespace std;
tnl::Vector3 epos = { 500,-100,0 };
tnl::Vector3 v = {300,300,0};
float etimer = 0.0f;
float timer=0.0f;

void gameMain(float delta_time) 
{
	
	
	if (!init) {
		player = new Player();
		init = true;
	}
	if (tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_Z))
	{
		
		if (timer > inter)
		{
			timer = 0;
			bullet.emplace_back(new Bullet(player->pos_));
		}
	}
	if (etimer > einter)
	{
		etimer = 0;
		enemy.emplace_back(new Enemy(epos));
	}
	player->update(delta_time);
	
	auto it = bullet.begin();
	while (it != bullet.end())
	{
		(*it)->update(delta_time);
		if ((*it)->pos_.y < 0)
		{
			delete (*it);
			it = bullet.erase(it);
			continue;
		}
		it++;
	}
	auto eit = enemy.begin();
	while (eit != enemy.end())
	{
		(*eit)->update(delta_time);
		if ((*eit)->pos_.y > 300)
		{
			delete (*eit);
			eit = enemy.erase(eit);
			continue;
		}
		eit++;
	}
	player->draw();
	for (auto blt : bullet) 
	{
		blt->draw();
	}
	for (auto emy : enemy)
	{
		emy->draw();
	}
	/*
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		//DrawStringEx(200, 200, -1, "on key");
		v += tnl :: Vector3 :: left * 2.0f;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		//DrawStringEx(200, 200, -1, "on key");
		v += tnl :: Vector3 :: right * 2.0f;

	}
	if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
		//DrawStringEx(200, 200, -1, "on key");
		v += tnl :: Vector3 :: donw * 2.0f;

	}
	if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
		//DrawStringEx(200, 200, -1, "on key");
		v += tnl :: Vector3 :: up * 2.0f;

	}
	
	DrawCircle(v.x, v.y, 30, -1, false);
	DrawBoxEx(v,100,100);

	DrawStringEx(100, 100, -1, "hello world %d",a);
	a++;
	*/
}

