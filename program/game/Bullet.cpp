#include"Bullet.h"

void Bullet::update(float delta_time)
{
	pos_ += tnl::Vector3::up * -10.0f;
}
void Bullet::draw()
{
	DrawCircle(pos_.x,pos_.y,BODY_RADIUS,-1);
}