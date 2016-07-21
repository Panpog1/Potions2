/*
 * Ae.h
 *
 *  Created on: Jul 20, 2016
 *      Author: patrick
 */

#ifndef AE_H_
#define AE_H_

#include "Potion.h"

class Ae: public Potion {
public:
	Ae() {
	}
	virtual Command react(std::unique_ptr<Potion>& other) const;
	virtual operator std::string() const {
		return "Ae";
	}
};

#endif /* AE_H_ */
