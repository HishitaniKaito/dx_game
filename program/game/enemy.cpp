#include"enemy.h"
void Enemy::update(float delta_time)
{
	pos_ += tnl::Vector3::up * 10.0f;
	if (pos_.y > 600)
	{
		alive = false;
	}
}
void Enemy::draw()
{
	DrawCircle(pos_.x, pos_.y, BODY_RADIUS, -1);
}