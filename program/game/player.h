#pragma once
#include"../dxlib_ext/dxlib_ext.h"
#include"obj.h"

class Player: public Object {
public :

	static constexpr float START_POS_X = 300;
	static constexpr float START_POS_Y = 500;

	static constexpr int BODY_WIDTH = 100;
	static constexpr int BODY_HEIGHT = 100;

	static constexpr float START_SPEED = 5.0f;

	void update(float delta_time)override;

	void draw()override;
};