/*
 * gpioclass.cpp
 *
 *  Created on: Jul 27, 2013
 *      Author: develru
 */

#include "gpioclass.h"
#include <fstream>
#include <iostream>

namespace rpi_lib {

GPIOClass::GPIOClass() {
	m_gpioNum = "4";

}

GPIOClass::GPIOClass(std::string io) {
	m_gpioNum = io;
}

int GPIOClass::export_gpio() {
	std::string export_string = "/sys/class/gpio/export";
	std::ofstream ex_gpio(export_string.c_str());
	if (ex_gpio < 0) {
		std::cerr << "OPERATION FAILED: Unable to export GPIO" << m_gpioNum << "!"  << std::endl;
		return -1;
	}

	ex_gpio << m_gpioNum;
	ex_gpio.close();
	return 0;
}

int GPIOClass::unexport_gpio() {
	std::string unexport_string = "/sys/class/gpio/unexport";
	std::ofstream unex_gpio(unexport_string.c_str());
	if (unex_gpio < 0) {
		std::cerr << "OPERATION FAILED: Unable to unexport GPIO"
				<< m_gpioNum << "!" << std::endl;
		return 1;
	}

	unex_gpio << m_gpioNum;
	unex_gpio.close();
	return 0;
}

int GPIOClass::set_direction(std::string direction) {
	std::string direction_path = "/sys/class/gpio/gpio" + m_gpioNum +
			"/direction";
	std::ofstream direction_gpio(direction_path.c_str());

	if (direction_gpio < 0) {
		std::cerr << "OPERATION FAILED: Unable to set the direction for GPIO"
				<< m_gpioNum << "!" << std::endl;
		return -1;
	}

	direction_gpio << direction;
	direction_gpio.close();
	return 0;
}

int GPIOClass::write_value(std::string value) {
	std::string value_path = "/sys/class/gpio/gpio" + m_gpioNum + "/value";
	std::ofstream gpio_value(value_path.c_str());

	if (gpio_value < 0) {
		std::cerr << "OPERATION FAILED: Unable to write the value for GPIO"
						<< m_gpioNum << "!" << std::endl;
		return -1;
	}

	gpio_value << value;
	gpio_value.close();
	return 0;
}

int GPIOClass::read_value(std::string& value) {
	//TODO: Implement it
	return 0;
}

GPIOClass::~GPIOClass() {
	// TODO Auto-generated destructor stub
}

} /* namespace rpi_lib */
