/*
 * Mat.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: root
 */

#include "math/Mat.h"

#include <assert.h>

#define ASSERT_SIZE(row, col) (assert(row >= 0 && row < R && col >= 0 && col < C))

namespace flashlib {

template<typename T, uint8_t R, uint8_t C>
Mat<T, R, C>::Mat() {
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] = 0;
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
Mat<T, R, C>::Mat(T elements[R][C]){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] = elements[i][j];
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
Mat<T, R, C>::~Mat() {
}

template<typename T, uint8_t R, uint8_t C>
T** Mat<T, R, C>::copy(){
	T** copy = new T[R][C];
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			copy[i][j] = this->elements[i][j];
		}
	}
	return copy;
}

template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::set(T val, uint8_t row, uint8_t col){
	ASSERT_SIZE(row, col);
	this->elements[row][col] = val;
}
template<typename T, uint8_t R, uint8_t C>
T Mat<T, R, C>::get(uint8_t row, uint8_t col){
	ASSERT_SIZE(row, col);
	return this->elements[row, col];
}

template<typename T, uint8_t R, uint8_t C>
T* Mat<T, R, C>::operator[](uint8_t idx){
	ASSERT_SIZE(idx, 0);
	return this->elements[idx];
}
template<typename T, uint8_t R, uint8_t C>
T& Mat<T, R, C>::operator()(uint8_t row, uint8_t col){
	ASSERT_SIZE(row, col);
	return this->elements[row][col];
}

template<typename T, uint8_t R, uint8_t C>
template<uint8_t C2>
Mat<T, C, C2>* Mat<T, R, C>::operator*(Mat<T, C, C2>& mat){
	Mat<T, C, C2>* matr = new Mat<T, C, C2>();
	for(uint8_t i = 0; i < C2; ++i){
		for(uint8_t j = 0; j < C; ++j){
			for(uint8_t k = 0; k < C; ++k)
				matr->elements[j][i] += (this->elements[j][k]) * (mat.elements[k][i]);
		}
	}
	return matr;
}

template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator+(Mat& mat){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] + mat.elements[i][j];
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator+(T scalar){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] + scalar;
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator-(Mat& mat){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] - mat.elements[i][j];
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator-(T scalar){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] - scalar;
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator*(T scalar){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] * scalar;
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator/(Mat& mat){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] / mat.elements[i][j];
		}
	}
	return matr;
}
template<typename T, uint8_t R, uint8_t C>
Mat* Mat<T, R, C>::operator/(T scalar){
	Mat* matr = new Mat*();

	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			matr->elements[i][j] = this->elements[i][j] / scalar;
		}
	}
	return matr;
}

template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator+=(Mat& mat){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] += mat.elements[i][j];
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator+=(T scalar){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] += scalar;
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator-=(Mat& mat){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] -= mat.elements[i][j];
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator-=(T scalar){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] -= scalar;
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator*=(T scalar){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] *= scalar;
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator/=(Mat& mat){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] /= mat.elements[i][j];
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator/=(T scalar){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] /= scalar;
		}
	}
}

template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator=(Mat& mat){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] = mat.elements[i][j];
		}
	}
}
template<typename T, uint8_t R, uint8_t C>
void Mat<T, R, C>::operator=(T elements[R][C]){
	for(uint8_t i = 0; i < R; ++i){
		for(uint8_t j = 0; j < C; ++j){
			this->elements[i][j] = elements[i][j];
		}
	}
}


} /* namespace flashlib */
