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

std::unique_ptr<Potion> make(Potion* x) {
	return static_cast<std::unique_ptr<Potion>>(x);
}

bool step(std::vector<std::unique_ptr<Potion>>&v) { //true if and only if the result is stable
	for (auto& r1 : v) {
		for (uint i = 0; i < v.size(); i++) {
			Command command = r1->react(v[i]);
			if (command == removeOther) {
				v.erase(v.begin() + i);
				return false;
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
		if (i++ > 1000) {
			print(v);
			throw std::runtime_error("react in loop?");
		}
	}
}

int main() {
	std::vector<std::unique_ptr<Potion>> v;
	if (true) {
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
		//v.push_back(make(new E(new Base("bar"))));
		//std::cout <<static_cast<std::string>(*make(new E(new Base("bar"))));
		react(v);
		print(v);
	} else {
		v.push_back(make(new R(new Base("foo"))));
		v.push_back(make(new E(new Base("foo"))));
		react(v);
		print(v);
	}
	return 0;
}
