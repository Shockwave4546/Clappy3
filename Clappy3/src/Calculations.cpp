/*
 * Calculations.cpp
 *
 *  Created on: Feb 19, 2017
 *      Author: Garrick Craft
 */

#include "Calculations.h"

#include <cmath>

namespace calc
{
	double DriveMotorSpeed(double input, double sens)
	{
		return (2 / (1 + std::exp(sens * input))) - 1;
	}

	double DriveMotorLeft(double y, double z)
	{
		return y - z;
	}

	double DriveMotorRight(double y, double z)
	{
		return y + z;
	}

	double TwistAxisScalar(double y, double z)
	{
		return std::abs((2 / (1 + std::exp((y==0) ? z/0.01 : z/y)) - 1));
	}
}

