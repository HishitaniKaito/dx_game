#pragma once
#include "../dxlib_ext/dxlib_ext.h"
#include"obj.h"

class Bullet:public Object 
{
public :
	
	const float BODY_RADIUS = 10;

	void update(float delta_time) override;
	void draw() override;
};