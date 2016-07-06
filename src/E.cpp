/*
 * E.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: mint
 */

#include "E.h"
#include <string>

E::E(Potion* of) {
	this->of = std::unique_ptr<Potion>(of);
}

bool E::isEqualToPeer(const Potion& other) const {
	return this->of == static_cast<const E&>(other).of;
}

E::operator std::string()const{
	return "E"+static_cast<std::string>(*of);
}


