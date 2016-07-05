/*
 * Base.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#include <Base.h>
#include <iostream>

Base::Base(std::string name) :
		name(name) {
}

Base::operator std::string() const {
	return "\"" + name + "\"";
}

bool Base::isEqualToPeer(const Potion& other) const {
	std::string o = dynamic_cast<const Base&>(other).name;
	return name == o;
}

