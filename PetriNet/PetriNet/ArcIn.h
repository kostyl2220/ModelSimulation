#pragma once
#include "Place.h"

class Transition;

struct ArcIn
{
public:
	ArcIn(Place* p, Transition* t, size_t v = 1, bool i = false)
		: place(p)
		, transition(t) 
		, value(v)
		, inform(i) {}

	ArcIn(Place* p, Transition* t, bool i)
		: place(p)
		, transition(t)
		, value(1)
		, inform(i) {}

	Place* place;
	Transition* transition;
	size_t value;
	bool inform;
};