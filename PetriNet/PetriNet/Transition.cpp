#include "pch.h"
#include "Transition.h"
#include <algorithm>

float const LOCAL_INFINITY = 1000000000000000;

bool Transition::CheckTransitionIn() const
{
	for (auto* t : m_in)
	{
		if (!t->place->EnoughMarkers(t->value))
		{
			return false;
		}
	}
	return true;
}

bool Transition::CheckTransitionOut(double curTime) const
{
	double const minTime = GetMinTime();
	return minTime < curTime + FLT_EPSILON;
}

void Transition::TransitionsIn(double curTime)
{
	for (auto* t : m_in)
	{
		if (!t->inform)
		{
			t->place->RemoveMarkers(t->value);
		}
	}
	double const outTime = curTime + (m_generator ? m_generator->GetNext() : 0);
	m_outTimes.push_back(outTime);
}

void Transition::TransitionsOut()
{
	for (auto* t : m_out)
	{
		t->place->AddMarkers(t->value);
	}
	auto el = std::min_element(m_outTimes.begin(), m_outTimes.end());
	m_outTimes.erase(el);
}

double Transition::GetMinTime() const
{
	return *(std::min_element(m_outTimes.begin(), m_outTimes.end()));
}