#pragma once
#include"../dxlib_ext/dxlib_ext.h"

class Player {
public :
	Player() {
		speed = START_SPEED;
		pos_ = { START_POS_X,START_POS_Y,0 };
	}

	const float START_POS_X = 300;
	const float START_POS_Y = 500;

	const int BODY_WIDTH = 100;
	const int BODY_HEIGHT = 100;

	const float START_SPEED = 5.0f;

	float speed = 0;

	tnl::Vector3 pos_;

	void update(float delta_time);

	void draw();
};