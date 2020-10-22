#pragma once
#include "FRandom.h"

double ArgMaxEl(std::vector<double> a);

double GlobalSearch(FRandom f, double a, double b);

double GlobalSearchMultivariate(FRandom f, double a, double b);

int GlobalSearchCounter(FRandom f, double a, double b);

