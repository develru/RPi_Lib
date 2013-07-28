/*
 * gpioclass.h
 *
 *  Created on: Jul 27, 2013
 *      Author: develru
 */

#ifndef GPIOCLASS_H_
#define GPIOCLASS_H_

#include <string>

namespace rpi_lib {

class GPIOClass {
public:
	GPIOClass();
	GPIOClass(std::string io);
	int export_gpio();
	int unexport_gpio();
	int set_direction(std::string direction);
	int set_value(std::string value);
	int get_value(std::string &value);
	~GPIOClass();

	const std::string& get_gpio_num() const {
		return m_gpioNum;
	}

private:
	std::string m_gpioNum;
};

} /* namespace rpi_lib */
#endif /* GPIOCLASS_H_ */
