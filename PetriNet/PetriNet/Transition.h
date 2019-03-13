#pragma once
#include <vector>
#include "ArcIn.h"
#include "ArcOut.h"
#include "Generator.h"
#include <limits>

extern float const LOCAL_INFINITY;

class Transition
{
public:
	Transition(IGenerator* generator)
		: m_generator(generator)
		{ m_outTimes.push_back(std::numeric_limits<double>::infinity()); }

	bool CheckTransitionIn() const;
	bool CheckTransitionOut(double curTime) const;
	void TransitionsIn(double curTime);
	void TransitionsOut();
	void AddArcIn(ArcIn* arc) { m_in.push_back(arc); }
	void AddArcOut(ArcOut* arc) { m_out.push_back(arc); }
	double GetMinTime() const;

private:
	std::vector<double> m_outTimes;
	std::vector<ArcIn*> m_in;
	std::vector<ArcOut*> m_out;
	IGenerator* m_generator;
};