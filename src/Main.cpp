/*
 * Main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#include <string>
#include <iostream>
#include <Potion.h>
#include <Base.h>
#include <R.h>
#include <memory>

std::unique_ptr<Potion> make(Potion* x) {
	return static_cast<std::unique_ptr<Potion>>(x);
}

bool step(std::vector<std::unique_ptr<Potion>>&v) { //true if and only if the result is stable
	for (auto& reactant : v) {
		if (reactant->react(v)) {
			return false;
		}
	}
	return true;
}

void react(std::vector<std::unique_ptr<Potion>>&v) {
	while (!step(v))
		;
}

int main() {
	std::vector<std::unique_ptr<Potion>> v;
	v.push_back(make(new Base("foo")));
	v.push_back(make(new Base("bar")));
	v.push_back(make(new Base("A thing")));
	v.push_back(make(new Base("Another thing")));
	v.push_back(make(new R(new Base("foo"))));
	react(v);
	for (const std::unique_ptr<Potion>& i : v) {
		std::cout << static_cast<std::string>(*i) << " is still in v\n";
	}
	std::cout << "done\n";
	return 0;
}
