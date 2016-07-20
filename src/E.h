/*
 * E.h
 *
 *  Created on: Jul 1, 2016
 *      Author: mint
 */

#ifndef E_H_
#define E_H_

#include "Potion.h"

class E: public Potion {//E for essence
public:
	explicit E(Potion* of);
	virtual bool isEqualToPeer(const Potion& other) const;
	virtual operator std::string()const;
private:
	std::unique_ptr<Potion> of;
};

#endif /* E_H_ */
