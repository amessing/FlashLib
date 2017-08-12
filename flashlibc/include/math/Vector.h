/*
 * Vector.h
 *
 *  Created on: Aug 12, 2017
 *      Author: root
 */

#ifndef INCLUDE_MATH_VECTOR_H_
#define INCLUDE_MATH_VECTOR_H_

#include <stdint.h>

#define VEC_X 0
#define VEC_Y 1
#define VEC_Z 2

namespace flashlib {

template<typename T, uint8_t S>
class Vector {
public:
	Vector();
	Vector(T elements[S]);
	~Vector();

	inline uint8_t size(){
		return S;
	}

	T length();
	T azimuth();
	T inclination();

	Vector* cross(Vector& vec);
	T dot(Vector& vec);
	T angleTo(Vector& vec);

	Vector* abs();
	Vector* singular();

	T& operator[](uint8_t idx);

	Vector* operator+(Vector& vec);
	Vector* operator+(T scalar);
	Vector* operator-(Vector& vec);
	Vector* operator-(T scalar);
	Vector* operator*(Vector& vec);
	Vector* operator*(T scalar);
	Vector* operator/(Vector& vec);
	Vector* operator/(T scalar);


	void operator+=(Vector& vec);
	void operator+=(T vec);
	void operator-=(Vector& vec);
	void operator-=(T vec);
	void operator*=(Vector& vec);
	void operator*=(T vec);
	void operator/=(Vector& vec);
	void operator/=(T vec);

	void operator=(Vector& vec);
	void operator=(T elements[S]);

	template<typename T>
	static Vector<T, 2>* polar(T magnitude, T azimuth);
	template<typename T>
	static Vector<T, 3>* polar(T magnitude, T azimuth, T inclination);

private:
	T elements[S];
};


typedef Vector<float, 4> vec4f;
typedef Vector<float, 3> vec3f;
typedef Vector<float, 2> vec2f;
typedef Vector<double, 4> vec4d;
typedef Vector<double, 3> vec3d;
typedef Vector<double, 2> vec2d;

} /* namespace flashlib */

#endif /* INCLUDE_MATH_VECTOR_H_ */
