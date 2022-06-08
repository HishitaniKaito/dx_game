#include <time.h>
#include<list>
#include <algorithm>
#include "game_main.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Player.h"
#include"Bullet.h"
#include"enemy.h"
#include"obj.h"


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
	timer += delta_time;
	etimer += delta_time;
	if (!init) {
		player = Object::Create<Player>
			(
				{
					Player::START_POS_X,
					Player::START_POS_Y,
					0
				},10);
		init = true;
	}
	if (tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_Z))
	{
		
		if (timer > inter)
		{
			timer = 0;
			bullet.emplace_back(Object::Create<Bullet>(player->pos_,10));
		}
	}
	if (etimer > einter)
	{
		etimer = 0;
		enemy.emplace_back(Object::Create<Enemy>(tnl::Vector3(500,-100,0),5));
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
}

