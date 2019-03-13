#include "pch.h"
#include "PetriSim.h"

bool PetriSim::IsValid() const
{
	return true;
}

v<Transition*> PetriSim::GetActiveTransitions() const
{
	v<Transition*> result;
	for (auto& t : m_transitions)
	{
		if (t.CheckTransitionIn())
		{
			result.push_back(&t);
		}
	}
	return result;
}

void PetriSim::InitSim()
{
	for (auto& arc : m_inArcs)
	{
		arc.transition->AddArcIn(&arc);
	}

	for (auto& arc : m_outArcs)
	{
		arc.transition->AddArcOut(&arc);
	}
}

bool PetriSim::MoveTime()
{
	m_currentTime = std::numeric_limits<double>::infinity();
	for (auto const tran : m_transitions)
	{
		double const curMinTime = tran.GetMinTime();
		if (curMinTime < m_currentTime)
		{
			m_currentTime = curMinTime;
		}
	}

	return m_currentTime != std::numeric_limits<double>::infinity();
}

void PetriSim::RunSimulation()
{
	InitSim();
	InitPrint();
	Print();
	Input();
	while (MoveTime())
	{
		Output();
		Print();
		Input();
	}
}

void PetriSim::InitPrint()
{
	printf("|  Time  |");
	size_t const sizeOfPlaces = m_places.size();
	for (size_t i = 0; i < sizeOfPlaces; ++i)
	{
		printf("Point%2d|", i);
	}
	printf("\n");
}

void PetriSim::Print()
{
	printf("|%8.4f|", m_currentTime);
	for (auto& p : m_places)
	{
		printf("%7d|", p.GetMarkers());
	}
	printf("\n");
}

bool PetriSim::Input()
{
	v<Transition*> res = GetActiveTransitions();
	if (res.empty())
	{
		return false;
	}
	while (!res.empty())
	{
		Transition* current = res.front();
		current->TransitionsIn(m_currentTime);
		res = GetActiveTransitions();
	}
	return true;
}

void PetriSim::Output()
{
	for (auto& tran : m_transitions)
	{
		while (tran.CheckTransitionOut(m_currentTime))
		{
			tran.TransitionsOut();
		}
	}
}