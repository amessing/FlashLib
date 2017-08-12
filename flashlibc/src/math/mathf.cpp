/*
 * Mathf.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: root
 */

#include "mathf.h"

#include <math.h>
#include <assert.h>

namespace flashlib {

//--------------------------------------------------------------------
//--------------------------General-----------------------------------
//--------------------------------------------------------------------

void constrain(double& value, double min, double max){
	if(value > max)
		value = max;
	if(value < min)
		value = min;
}
bool constrained(double value, double min, double max){
	return value >= min && value <= max;
}

void translateAngle(double& angle){
	angle %= 360;
	if(angle < 0)
		angle += 360;
}

double roundDecimal(double val, int decimalPlaces = 2){
	double multiplier = pow(10, decimalPlaces);
	return round(val * multiplier) / multiplier;
}

double roundToMultiplier(double val, double multiplier, bool up = true){
	double rounded = multiplier * round(val / multiplier);
	if(rounded < val && up)
		rounded += multiplier;
	else if(rounded > val && !up)
		rounded -= multiplier;
	return rounded;
}

double root(double result, double exponent){
	assert(result > 0);

	if(result == 0)
		return 0;
	if(exponent == 0)
		return 1;

	double x1 = result;
	double x2 = result / exponent;
	while(fabs(x1 - x2) > 1e-8){
		x1 = x2;
		x2 = ((exponent - 1.0) * x2 + result / pow(x2, exponent - 1.0)) / exponent;
	}

	return x2;
}

//--------------------------------------------------------------------
//--------------------------Derivatives-------------------------------
//--------------------------------------------------------------------

double derive(funcd& func, double x){
	return centralDifference(func, x);
}

double forwardDifference(funcd& func, double x, double changeConst = 1e-8){
	return (func.f(x + changeConst) - func.f(x)) / changeConst;
}
double backwardDifference(funcd& func, double x, double changeConst = 1e-8){
	return (func.f(x) - func.f(x - changeConst)) / changeConst;
}
double centralDifference(funcd& func, double x, double changeConst = 1e-8){
	return (func.f(x + changeConst) - func.f(x - changeConst)) / (2.0 * changeConst);
}
double centralDifference2(funcd& func, double x, double changeConst = 1e-8){
	return (func.f(x + changeConst) - 2 * func.f(x) + func.f(x - changeConst)) / (changeConst * changeConst);
}

//--------------------------------------------------------------------
//----------------------------Integrate-------------------------------
//--------------------------------------------------------------------

double integrate(funcd& func, double min, double max){
	return simpsonsRule(func, min, max);
}

double trapezoidalRule(funcd& func, double min, double max, int trapezoids = 100){
	double h = (max - min) / trapezoids;
	double s = 0.5 * (func.f(min) + func.f(max));
	for(int i = 1; i < trapezoids; ++i)
		s += func.f(min + i * h);
	return (s * h);
}
double simpsonsRule(funcd& func, double min, double max, int slices = 10){
	double h = (max - min) / slices;
	double s = func.f(min) + func.f(max), s1 = 0.0, s2 = 0.0;
	for(int i = 1; i < slices; ++i){
		s1 += func.f(min + (2 * i - 1) * h);
		if(i < slices / 2)
			s2 += func.f(min + 2 * i * h);
	}
	return (1 / 3.0) * h * (s + 4 * s1 + 2 * s2);
}

} /* namespace flashlib */
