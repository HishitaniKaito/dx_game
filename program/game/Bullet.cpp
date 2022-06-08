#include"Bullet.h"
void Bullet::update(float delta_time)
{
	pos_ += tnl::Vector3::up * -10.0f;
	if (pos_.y < 0)
	{
		alive = false;
	}
}
void Bullet::draw()
{
	DrawCircle(pos_.x,pos_.y,BODY_RADIUS,-1);
}