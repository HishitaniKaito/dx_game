#include <time.h>
#include<list>
#include <algorithm>
#include "game_main.h"
#include "../dxlib_ext/dxlib_ext.h"
#include"Player.h"
#include"Bullet.h"
#include"enemy.h"
#include"obj.h"

float inter = 0.25f;
float einter = 1.0f;
bool init = false;
std::list<Object*> object;
float etimer = 0.0f;
float timer=0.0f;

void gameMain(float delta_time) 
{
	timer += delta_time;
	etimer += delta_time;
	if (!init) {
		object.emplace_back(Object::Create<Player>
			(
				{
					Player::START_POS_X,
					Player::START_POS_Y,
					0
				},10));
		init = true;
	}
	if (etimer > einter)
	{
		etimer = 0;
		object.emplace_back(Object::Create<Enemy>(tnl::Vector3(500,-100,0),5));
	}


	auto objit = object.begin();
	while (objit != object.end())
	{
		(*objit)->update(delta_time);
		if (!(*objit)->alive)
		{
			delete (*objit);
			objit = object.erase(objit);
			continue;
		}
		objit++;
	}
	for (auto obj : object)
	{
		obj->draw();
	}
}

