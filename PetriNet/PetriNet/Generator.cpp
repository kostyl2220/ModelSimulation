#include "pch.h"
#include "Generator.h"
#include <math.h>
#include <random>

double const MAX_TIME = 1000000;

namespace Generator
{
	double GetNext(double m)
	{
		return -m * log((double)rand() / (RAND_MAX));
	}

	double Erlang(double a, size_t k)
	{
		double nums = 1;
		for (int i = 0; i < k; i++) 
		{ 
			nums *= (double)rand() / (RAND_MAX);
		}

		double const res = -a * log(nums);
		return res;
	}

	double GetRand()
	{
		double ran;
		do 
		{
			ran = ((double)rand() / (RAND_MAX));
		} 
		while (ran < FLT_EPSILON || ran + FLT_EPSILON > 1);
		return ran;
	}
}

double Exponential::GetNext()
{
	double res;
	do
	{
		res = -m_lambda * log(Generator::GetRand());
	} 
	while (res > MAX_TIME);
	return res;
}

void Exponential::PrintLaw()
{
	printf("Create time lambda = %.2f for exponential\n", m_lambda);
}

double Erlang::GetNext()
{
	double res;
	do 
	{
		double nums = 1;
		for (int i = 0; i < m_k; i++)
		{
			nums *= Generator::GetRand();
		}
		res = -m_lambda * log(nums);
	} 
	while (res > MAX_TIME);
	return res;
}

double Uniform::GetNext()
{
	double res;
	do
	{
		double const ran = (double)rand() / (RAND_MAX);
		res = m_l + (m_r - m_l) * ran;
	} 
	while (res > MAX_TIME);
	return res;
}

void Uniform::PrintLaw()
{
	printf("Create time left = %.2f, right %.2f for uniform\n", m_l, m_r);
}

void Erlang::PrintLaw()
{
	printf("Create time lambda = %.2f, k = %d for Erlang\n", m_lambda, m_k);
}