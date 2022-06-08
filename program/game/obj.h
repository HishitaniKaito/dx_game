#pragma once
#include "../dxlib_ext/dxlib_ext.h"

class Object
{
public :
	
	template< class T >
	static T* Create(const tnl::Vector3& pos, const float speed)
	{
		T* new_obj = new T();
		new_obj->pos_ = pos;
		new_obj->speed_ = speed;
		return new_obj;
	}

	bool alive = true;
	float speed_ = 0;
	tnl::Vector3 pos_;

	virtual void update(float delta_time) {};
	virtual void draw() {};
};
