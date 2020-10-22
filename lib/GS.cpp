#include "GS.h"

double ArgMaxEl(std::vector<double> a)
{
	double max = a[0];
	int k = 0;
	int i = 1;
	while (i < a.size())
	{
		if (a[i] > max)
		{
			max = a[i];
			k = i;
		}
		i++;
	}
	return k;
}

double GlobalSearch(FRandom f, double a, double b)
{
	std::vector <pair<double, double>> exp;
	std::vector <double> R;
	double r = 3; // çàäàííûé ïàðàìåòð ìåòîäà
	double M = 0;
	double m;
	double e = 0.02;
	pair<double, double> p1(a, f.GetFuncValue(a));
	pair<double, double> p2(b, f.GetFuncValue(b));
	exp.insert(exp.begin(), p1);
	exp.push_back(p2);
	int k = 2;
	double t = 0;
	while ((exp[t + 1].first - exp[t].first) > e)
	{
		for (int i = 0; i < k - 1; i++)
		{
			int tmpM = abs((exp[i + 1].second - exp[i].second) / (exp[i + 1].first - exp[i].first));
			if (M < tmpM)
				M = tmpM;
		}
		if (M == 0)
			m = 1;
		else
			m = r * M;
		for (int i = 0; i < k - 1; i++)
		{
			R.push_back(m * (exp[i + 1].first - exp[i].first) + ((exp[i + 1].second - exp[i].second) * (exp[i + 1].second - exp[i].second)) / (m * (exp[i + 1].first - exp[i].first)) - 2 * (exp[i + 1].second + exp[i].second));
		}
		t = ArgMaxEl(R);
		R.clear();
		double c = (exp[t + 1].first + exp[t].first) / 2 - (exp[t + 1].second - exp[t].second) / (2 * m);
		pair<double, double> p(c, f.GetFuncValue(c));
		exp.push_back(p);
		sort(exp.begin(), exp.end());
		k++;
	}
	return exp[t].second;
}

int GlobalSearchCounter(FRandom f, double a, double b)
{
	std::vector <pair<double, double>> exp;
	std::vector <double> R;
	double r = 3; // çàäàííûé ïàðàìåòð ìåòîäà
	double M = 0;
	double m;
	double e = 0.02;
	pair<double, double> p1(a, f.GetFuncValue(a));
	pair<double, double> p2(b, f.GetFuncValue(b));
	exp.insert(exp.begin(), p1);
	exp.push_back(p2);
	int k = 2;
	double t = 0;
	while ((exp[t + 1].first - exp[t].first) > e)
	{
		for (int i = 0; i < k - 1; i++)
		{
			int tmpM = abs((exp[i + 1].second - exp[i].second) / (exp[i + 1].first - exp[i].first));
			if (M < tmpM)
				M = tmpM;
		}
		if (M == 0)
			m = 1;
		else
			m = r * M;
		for (int i = 0; i < k - 1; i++)
		{
			R.push_back(m * (exp[i + 1].first - exp[i].first) + ((exp[i + 1].second - exp[i].second) * (exp[i + 1].second - exp[i].second)) / (m * (exp[i + 1].first - exp[i].first)) - 2 * (exp[i + 1].second + exp[i].second));
		}
		t = ArgMaxEl(R);
		R.clear();
		double c = (exp[t + 1].first + exp[t].first) / 2 - (exp[t + 1].second - exp[t].second) / (2 * m);
		pair<double, double> p(c, f.GetFuncValue(c));
		exp.push_back(p);
		sort(exp.begin(), exp.end());
		k++;
	}
	return k;
}

pair<double, double> GlobalSearchMultivariate(double a1, double b1, double a2, double b2)
{
	
}
