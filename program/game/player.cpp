#include"Player.h"
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
}
void Player::draw()
{
	DrawBoxEx(pos_, BODY_WIDTH, BODY_HEIGHT);
}