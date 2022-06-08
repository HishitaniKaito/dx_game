#include"Player.h"
#include"Bullet.h"

extern float timer;
extern float inter;
extern std::list<Object*> object;

void Player :: update(float delta_time)
{
	tnl::Vector3 mv;
	if (tnl::Input::IsKeyDown(eKeys::KB_LEFT)) {
		mv += tnl::Vector3::left;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_RIGHT)) {
		mv += tnl::Vector3::right;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_UP)) {
		mv += tnl::Vector3::donw;
	}
	if (tnl::Input::IsKeyDown(eKeys::KB_DOWN)) {
		mv += tnl::Vector3::up;
	}
	mv.normalize();
	pos_ += mv * speed_;
	timer += delta_time;
	if (tnl::Input::IsKeyDown(tnl::Input::eKeys::KB_Z))
	{
		
		if (timer > inter)
		{
			timer = 0;
			object.emplace_back(Object::Create<Bullet>(pos_,10));
		}
	}
}
void Player::draw()
{
	DrawBoxEx(pos_, BODY_WIDTH, BODY_HEIGHT);
}