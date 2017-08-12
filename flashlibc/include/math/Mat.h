/*
 * Mat.h
 *
 *  Created on: Aug 12, 2017
 *      Author: root
 */

#ifndef INCLUDE_MATH_MAT_H_
#define INCLUDE_MATH_MAT_H_

#include <stdint.h>

namespace flashlib {

template<typename T, uint8_t R, uint8_t C>
class Mat {
public:
	Mat();
	Mat(T elements[R][C]);
	~Mat();

	uint8_t rows(){
		return R;
	}
	uint8_t cols(){
		return C;
	}

	T** copy();

	void set(T val, uint8_t row, uint8_t col);
	T get(uint8_t row, uint8_t col);

	T* operator[](uint8_t idx);
	T& operator()(uint8_t row, uint8_t col);

	template<uint8_t C2>
	Mat<T, C, C2>* operator*(Mat<T, C, C2>& mat);

	Mat* operator+(Mat& mat);
	Mat* operator+(T scalar);
	Mat* operator-(Mat& mat);
	Mat* operator-(T scalar);
	Mat* operator*(T scalar);
	Mat* operator/(Mat& mat);
	Mat* operator/(T scalar);

	void operator+=(Mat& mat);
	void operator+=(T scalar);
	void operator-=(Mat& mat);
	void operator-=(T scalar);
	void operator*=(T scalar);
	void operator/=(Mat& mat);
	void operator/=(T scalar);

	void operator=(Mat& mat);
	void operator=(T elements[R][C]);

private:
	T elements[R][C];
};


typedef Mat<float, 2, 2> mat2f;
typedef Mat<float, 3, 3> mat3f;
typedef Mat<float, 4, 4> mat4f;
typedef Mat<double, 2, 2> mat2d;
typedef Mat<double, 3, 3> mat3d;
typedef Mat<double, 4, 4> mat4d;


} /* namespace flashlib */

#endif /* INCLUDE_MATH_MAT_H_ */
