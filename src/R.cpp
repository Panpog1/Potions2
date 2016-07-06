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
	this->target=std::unique_ptr<Potion>(target);
}

R::operator std::string() const {
	return "R" + static_cast<std::string>(*target);
}
bool R::react_test(const std::unique_ptr<Potion>& p) const {
	Potion& r = *p;
	const Potion& t = *target;
	bool b = r == t;
	return b;
}
bool R::react(std::vector<std::unique_ptr<Potion>>& v) const {
	auto s = v.size();
	v.erase(
			std::remove_if(v.begin(), v.end(),
					[this](std::unique_ptr<Potion>& p)->bool {
						return react_test(p);
					}));
	return v.size() < s; //v.size() changed if and only if something was removed.
}
bool R::isEqualToPeer(const Potion& other) const{
	return target == dynamic_cast<const R&>(other).target;
}
