#pragma once

class IGenerator
{
public:
	virtual double GetNext() {
		return 1;
	};
	virtual void PrintLaw() {};
};

class Exponential : public IGenerator
{
public: 
	Exponential(double lambda)
		: m_lambda(lambda) {}

	double GetNext() override;
	void PrintLaw() override;

private:
	double m_lambda;
};

class Erlang : public IGenerator
{
public:
	Erlang(double lambda, double k)
		: m_lambda(lambda)
		, m_k(k) {}

	double GetNext() override;
	void PrintLaw() override;

private:
	double m_lambda;
	double m_k;
};

class Uniform : public IGenerator
{
public:
	Uniform(double l, double r)
		: m_l(l)
		, m_r(r) {}

	double GetNext() override;
	void PrintLaw() override;

private:
	double m_l;
	double m_r;
};

namespace Generator
{
	double GetNext(double m);
	double Erlang(double a, size_t k);
}