/*
 * Vector.cpp
 *
 *  Created on: Aug 12, 2017
 *      Author: root
 */

#include "Vector.h"

#include <math.h>
#include <assert.h>

namespace flashlib {

template<typename T, uint8_t S>
Vector<T, S>::Vector() {
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = 0;
}
template<typename T, uint8_t S>
Vector<T, S>::Vector(T elements[S]) {
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = elements[i];
}
template<typename T, uint8_t S>
Vector<T, S>::~Vector() {

}

template<typename T, uint8_t S>
T Vector<T, S>::length(){
	T result = 0;
	for(uint8_t i = 0; i < S; ++i)
		result += (this->elements[i] * this->elements[i]);
	return sqrt(result);
}
template<typename T, uint8_t S>
T Vector<T, S>::azimuth(){
	if(S < 2) return 0;
	return atan2(elements[VEC_Y], elements[VEC_X]);
}
template<typename T, uint8_t S>
T Vector<T, S>::inclination(){
	if(S < 3) return 90;
	T angle = acos(elements[VEC_Z] / length());
	return angle < 0? -angle : angle;
}

template<typename T, uint8_t S>
Vector* Vector<T, S>::cross(Vector& vec){
	if(S < 2)
		return nullptr;


	Vector* vecr = new Vector();

	if(S < 3){
		T result = elements[VEC_X] * vec.elements[VEC_X] - elements[VEC_Y] * vec.elements[VEC_Y];
		for(uint8_t i = 0; i < S; ++i)
			vecr->elements[i] = result;
		return vecr;
	}

	(*vecr)[VEC_X] =   elements[VEC_Y] * vec.elements[VEC_Z] - elements[VEC_Z] * vec.elements[VEC_Y];
	(*vecr)[VEC_Y] = -(elements[VEC_Z] * vec.elements[VEC_X] - elements[VEC_X] * vec.elements[VEC_Z]);
	(*vecr)[VEC_Z] =   elements[VEC_X] * vec.elements[VEC_Y] - elements[VEC_Y] - vec.elements[VEC_X];
	return vecr;
}
template<typename T, uint8_t S>
T Vector<T, S>::dot(Vector& vec){
	T res = 0;
	for(uint8_t i = 0; i < S; ++i)
		res += elements[i] * vec.elements[i];
	return res;
}
template<typename T, uint8_t S>
T Vector<T, S>::angleTo(Vector& vec){
	return acos(dot(vec) / (length() * vec.length()));
}

template<typename T, uint8_t S>
Vector* Vector<T, S>::abs(){
	Vector* vec = new Vector*();
	for(uint8_t i = 0; i < S; ++i)
		vec->elements[i] = fabs(elements[i]);
	return vec;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::singular(){
	Vector* vec = new Vector*();
	for(uint8_t i = 0; i < S; ++i)
		vec->elements[i] = (elements[i] != 0)? (elements[i] > 0? 1 : 0) : 0;
	return vec;
}

template<typename T, uint8_t S>
T& Vector<T, S>::operator[](uint8_t idx){
	assert(idx >= 0 && idx < S);
	return elements[idx];
}

template<typename T, uint8_t S>
Vector* Vector<T, S>::operator+(Vector& vec){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] + vec.elements[i];
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator+(T scalar){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] + scalar;
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator-(Vector& vec){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] - vec.elements[i];
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator-(T scalar){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] - scalar;
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator*(Vector& vec){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] * vec.elements[i];
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator*(T scalar){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] * scalar;
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator/(Vector& vec){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] / vec.elements[i];
	return vecr;
}
template<typename T, uint8_t S>
Vector* Vector<T, S>::operator/(T scalar){
	Vector* vecr = new Vector();
	for(uint8_t i = 0; i < S; ++i)
		vecr->elements[i] = this->elements[i] / scalar;
	return vecr;
}

template<typename T, uint8_t S>
void Vector<T, S>::operator+=(Vector& vec){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] + vec.elements[i];
}
template<typename T, uint8_t S>
void Vector<T, S>::operator+=(T scalar){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] + scalar;
}
template<typename T, uint8_t S>
void Vector<T, S>::operator-=(Vector& vec){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] - vec.elements[i];
}
template<typename T, uint8_t S>
void Vector<T, S>::operator+=(T scalar){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] - scalar;
}
template<typename T, uint8_t S>
void Vector<T, S>::operator*=(Vector& vec){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] * vec.elements[i];
}
template<typename T, uint8_t S>
void Vector<T, S>::operator+=(T scalar){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] * scalar;
}
template<typename T, uint8_t S>
void Vector<T, S>::operator/=(Vector& vec){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] / vec.elements[i];
}
template<typename T, uint8_t S>
void Vector<T, S>::operator+=(T scalar){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = this->elements[i] / scalar;
}

template<typename T, uint8_t S>
void Vector<T, S>::operator=(Vector& vec){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = vec.elements[i];
}
template<typename T, uint8_t S>
void Vector<T, S>::operator=(T elements[S]){
	for(uint8_t i = 0; i < S; ++i)
		this->elements[i] = elements[i];
}


template<typename T>
static Vector<T, 2>* polar(T magnitude, T azimuth){
	Vector<T, 2>* vec = new Vector<T, 2>();
	vec[VEC_X] = magnitude * cos(azimuth);
	vec[VEC_Y] = magnitude * sin(azimuth);
	return vec;
}
template<typename T>
static Vector<T, 3>* polar(T magnitude, T azimuth, T inclination){
	Vector<T, 3>* vec = new Vector<T, 2>();
	vec[VEC_X] = magnitude * sin(inclination) * cos(azimuth);
	vec[VEC_Y] = magnitude * sin(inclination) * sin(azimuth);
	vec[VEC_Z] = magnitude * cos(inclination);
	return vec;
}

} /* namespace flashlib */
