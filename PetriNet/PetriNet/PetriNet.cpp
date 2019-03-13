// PetriNet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "PetriSim.h"

int main()
{
	std::vector<Place> places
	{
		Place(6),
		Place(1005),
		Place(),
		Place(),
		Place()
	};

	Exponential exp(3.25);
	std::vector<Transition> transitions
	{
		Transition(&exp)
	};

	std::vector<ArcIn> arcIns
	{
		ArcIn(&places[0], &transitions[0], 2U, true),
		ArcIn(&places[1], &transitions[0], 10U)
	};

	std::vector<ArcOut> arcOut
	{
		ArcOut(&transitions[0], &places[2], 2),
		ArcOut(&transitions[0], &places[3]),
		ArcOut(&transitions[0], &places[4], 5)
	};

	PetriSim sim(arcIns, arcOut, places, transitions);
	sim.RunSimulation(); 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
