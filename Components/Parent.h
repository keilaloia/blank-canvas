#pragma once
#include "Transform.h"
#include "Collider.h"
#include "Rigidbody.h"
#include "sfwdraw.h"
#include "health.h"

class Parent
{
public:
	Transform			transform;
	collider			Collider;
	RigidBody			rigidbody;
	Health				health;

	Parent();

	bool ishit;

	float maxspeed; 
	float turnspeed;
	float startspeed;


	vec2 forcepower;

	float firingTimer;

	void update(float deltaTime, class Gamestate &gs);
	void draw(const mat3 &camera);
};