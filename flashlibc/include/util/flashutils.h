/*
 * FlashUtil.h
 *
 *  Created on: Jun 20, 2017
 *      Author: root
 */

#ifndef INCLUDE_UTIL_FLASHUTILS_H_
#define INCLUDE_UTIL_FLASHUTILS_H_

namespace flashlib{

//--------------------------------------------------------------------
//----------------------------Time------------------------------------
//--------------------------------------------------------------------

extern void delayns(int nanos);
extern void delayus(int micros);
extern void delay(long millis);

extern long millis();
extern double secs();

//--------------------------------------------------------------------
//---------------------------Arrays-----------------------------------
//--------------------------------------------------------------------

template<class T>
extern int arr_indexOf(T arr[], int start = 0, int end, T val);
template<class T>
extern bool arr_contains(T arr[], int start = 0, int end, T val);
template<class T>
extern void arr_shiftL(T arr[], int start = 0, int end, int shiftAmount = 1);
template<class T>
extern void arr_shiftR(T arr[], int start = 0, int end, int shiftAmount = 1);
template<class T>
extern void arr_copy(T arr[], int start = 0, int length, int newSize = length);

//--------------------------------------------------------------------
//-----------------------Conversion-----------------------------------
//--------------------------------------------------------------------

template<typename T>
extern uint8_t* toBytes(T val);
template<typename T>
extern void fillBytes(uint8_t bytes[], int start = 0, T val);
template<typename T>
extern void fromBytes(uint8_t bytes[], int start = 0, T* val);

template<typename T>
extern uint8_t* fp_toBytes(T val);
template<typename T>
extern void fp_fillBytes(uint8_t bytes[], int start = 0, T val);
template<typename T>
extern void fp_fromBytes(uint8_t bytes[], int start = 0, T* val);

}; /* namespace flashlib */

#endif /* INCLUDE_UTIL_FLASHUTILS_H_ */
