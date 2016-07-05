/*
 * Potion.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#include <Potion.h>
#include <typeinfo>
#include <iostream>


bool Potion::operator==(const Potion& other) const{
	if  (!( typeid(*this) == typeid(other))){
		return false;
	}
	return isEqualToPeer(other);
}
