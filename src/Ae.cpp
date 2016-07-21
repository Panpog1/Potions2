/*
 * Ae.cpp
 *
 *  Created on: Jul 20, 2016
 *      Author: patrick
 */

#include <typeinfo>
#include "Ae.h"
#include "E.h"
#include "Commands.h"

Command Ae::react(std::unique_ptr<Potion>& other) const {
	if (typeid(*other) != typeid(E&)) {
		return Command::NOP;
	}
	auto foo = dynamic_cast<E*>(other.get());
	other = std::move(foo->of);
	return Command::RECALCULATE;
}
