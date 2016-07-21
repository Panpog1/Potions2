/*
 * Main.cpp
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#include <string>
#include <iostream>
#include <exception>
#include "Potion.h"
#include "Base.h"
#include "R.h"
#include "E.h"
#include "Ae.h"

std::unique_ptr<Potion> make(Potion* x) {
	return static_cast<std::unique_ptr<Potion>>(x);
}

bool step(std::vector<std::unique_ptr<Potion>>&v) { //true if and only if the result is stable
	for (auto& r1 : v) {
		for (uint i = 0; i < v.size(); i++) {
			switch (r1->react(v[i])) {
			case Command::REMOVE_OTHER:
				v.erase(v.begin() + i);
			case Command::RECALCULATE:
				return false;
			case Command::NOP:
				break;
			}
		}
	}
	return true;
}

void print(const std::vector<std::unique_ptr<Potion> >& v) {
	std::cout << "size = " << v.size() << std::endl;
	for (const std::unique_ptr<Potion>& i : v) {
		std::cout << static_cast<std::string>(*i) << " is still in v\n";
	}
	std::cout << "done" << std::endl;
}

void react(std::vector<std::unique_ptr<Potion>>&v) {
	int i = 0;
	while (!step(v)) {
		if (++i > 1000) {
			print(v);
			throw std::runtime_error("react in loop?");
		}
	}
}

int main() {
	std::vector<std::unique_ptr<Potion>> v;
	if (R(new Base("foo")) == E(new Base("foo")))
		std::cout << "fail 1";
	if (Base("foo") == E(new Base("foo")))
		std::cout << "fail 2";
	v.push_back(make(new Base("foo")));
	v.push_back(make(new Base("bar")));
	v.push_back(make(new Base("A thing")));
	v.push_back(make(new Base("Another thing")));
	v.push_back(make(new R(new Base("foo"))));
	v.push_back(make(new E(new Base("foo"))));
	v.push_back(make(new E(new Base("bar"))));
	v.push_back(make(new Ae));
	react(v);
	print(v);
	return 0;
}
