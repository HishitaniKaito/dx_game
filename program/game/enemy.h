#pragma once
#include"../dxlib_ext/dxlib_ext.h"

class Enemy
{
public:
	Enemy()
	{
		pos_ = { 500,500, 0 };
	}
	Enemy(const tnl::Vector3& pos)
	{
		pos_ = pos;
	}
	tnl::Vector3 pos_;
	const float BODY_RADIUS = 10;

	void update(float delta_time);
	void draw();
};
