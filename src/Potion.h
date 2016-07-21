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

enum Command{
	nop,
	removeOther
};

class Potion {
public:
	Potion() {
	}
	virtual ~Potion() {
	}
	virtual operator std::string() const=0;
	virtual Command react(std::unique_ptr<Potion>& other) const{//return weather other should be removed
		return nop;
	}
	bool operator==(const Potion& other) const;
	virtual bool isEqualToPeer(const Potion& other) const {
		return true;
	}
};

#endif /* POTION_H_ */
