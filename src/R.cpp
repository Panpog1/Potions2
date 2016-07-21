/*
 * R.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#include "R.h"
#include <memory>
#include <iostream>
#include <algorithm>

R::R(Potion* target) {
	this->target = std::unique_ptr<Potion>(target);
}

R::operator std::string() const {
	return "R" + static_cast<std::string>(*target);
}

Command R::react(std::unique_ptr<Potion>& other) const{
	return (*other == *target)?removeOther:nop;
}


bool R::isEqualToPeer(const Potion& other) const {
	return target == dynamic_cast<const R&>(other).target;
}
