/*
 * Base.h
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#ifndef BASE_H_
#define BASE_H_

#include <Potion.h>

class Base: public Potion {
public:
	Base(std::string name);
	virtual ~Base() {
	}
	virtual operator std::string() const;
	virtual bool isEqualToPeer(const Potion& other) const;
private:
	const std::string name;
};

#endif /* BASE_H_ */
