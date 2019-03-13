#pragma once
#include "Place.h"
#include "Transition.h"
#include "ArcIn.h"
#include "ArcOut.h"
#include <vector>

#define v std::vector

class PetriSim
{
public:
	PetriSim(v<ArcIn>& in, v<ArcOut>& out, v<Place>& place, v<Transition>& transition)
		: m_inArcs(in)
		, m_outArcs(out)
		, m_places(place)
		, m_transitions(transition) 
		, m_currentTime(0) {}

	bool IsValid() const;
	void RunSimulation();

private:
	void Print();
	void InitPrint();
	void InitSim();
	bool Input();
	void Output();
	bool MoveTime();
	v<Transition*> GetActiveTransitions() const;

	double m_currentTime;
	v<ArcIn>& m_inArcs;
	v<ArcOut>& m_outArcs;
	v<Place>& m_places;
	v<Transition>& m_transitions;
};