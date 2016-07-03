/*
 * Potion.h
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#ifndef POTION_H_
#define POTION_H_
#include <string>
#include <vector>
#include <memory>

class Potion {
public:
	Potion() {
	}
	virtual ~Potion() {
	}
	virtual operator std::string() const=0;
	virtual bool react(std::vector<std::unique_ptr<Potion>> & reactants) { //return whether anything happened
		return false;
	}
	bool operator==(const Potion& other);
	virtual bool isEqualToPeer(const Potion& other) {
		return true;
	}
};

#endif /* POTION_H_ */
