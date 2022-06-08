#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Object
{
public :
	Object(const tnl::Vector3& pos, const float speed)
	{
		speed_ = speed;
		pos_ = pos;
	}
	float speed_ = 0;
	tnl::Vector3 pos_;
};
