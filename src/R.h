/*
 * R.h
 *
 *  Created on: Jun 23, 2016
 *      Author: PJ
 */

#ifndef R_H_
#define R_H_

#include <Potion.h>
#include <memory>

class R: public Potion {
public:
	explicit R(Potion* target);
	virtual ~R();
	virtual operator std::string() const;
	virtual bool react(std::vector<std::unique_ptr<Potion>>& reactants);
	virtual bool isEqualToPeer(const Potion& other);
private:
	bool react_test(std::unique_ptr<Potion>&);
	std::unique_ptr<Potion> target;
};

#endif /* R_H_ */
