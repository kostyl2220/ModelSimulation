#pragma once

#include "Place.h"
#include "Transition.h"

struct ArcOut
{
	Place* place;
	Transition* transition;
	size_t value;

	ArcOut(Transition* t, Place* p, size_t v = 1)
		: place(p)
		, transition(t) 
		, value(v) {}
};