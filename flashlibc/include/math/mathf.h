/*
 * Mathf.h
 *
 *  Created on: Jun 20, 2017
 *      Author: root
 */

#ifndef INCLUDE_MATH_MATHF_H_
#define INCLUDE_MATH_MATHF_H_

namespace flashlib{

//--------------------------------------------------------------------
//--------------------------Helpers-----------------------------------
//--------------------------------------------------------------------

template<typename T>
class Function{
	public:
		virtual ~Function() = 0;
		virtual T f(T x) = 0;
};

typedef Function<double> funcd;
typedef Function<float> funcf;

//--------------------------------------------------------------------
//--------------------------General-----------------------------------
//--------------------------------------------------------------------

extern void constrain(double& value, double min, double max);
extern bool constrained(double value, double min, double max);

extern void translateAngle(double& angle);

extern double roundDecimal(double val, int decimalPlaces = 2);

extern double roundToMultiplier(double val, double multiplier, bool up = true);

extern double root(double result, double exponent);

//--------------------------------------------------------------------
//--------------------------Derivatives-------------------------------
//--------------------------------------------------------------------

extern double derive(funcd& func, double x);

extern double forwardDifference(funcd& func, double x, double changeConst = 1e-8);
extern double backwardDifference(funcd& func, double x, double changeConst = 1e-8);
extern double centralDifference(funcd& func, double x, double changeConst = 1e-8);
extern double centralDifference2(funcd& func, double x, double changeConst = 1e-8);

//--------------------------------------------------------------------
//----------------------------Integrate-------------------------------
//--------------------------------------------------------------------

extern double integrate(funcd& func, double min, double max);

extern double trapezoidalRule(funcd& func, double min, double max, int trapezoids = 100);
extern double simpsonsRule(funcd& func, double min, double max, int slices = 10);

} /* namespace flashlib */

#endif /* INCLUDE_MATH_MATHF_H_ */
