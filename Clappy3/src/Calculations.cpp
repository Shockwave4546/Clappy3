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
	double DriveSpeed(double input, double sens)
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

	double AutoZValue(double offset, double distanceWeight, double functionWeight)
	{
		return (2 * functionWeight * distanceWeight / (1 + std::exp(-5 * offset))) - functionWeight * distanceWeight;
	}

	double AutoYValue(double offset, double distanceWeight, double functionWeight)
	{
		return (offset < 1) ? functionWeight * distanceWeight * std::pow(offset + 1, 2) : functionWeight * distanceWeight * std::pow(offset - 1, 2);
	}

	double DistanceWeight(double distance, double minimum)
	{
		return 2 / (1 + std::exp(3 - 3 * distance/(minimum == 0) ? 1 : minimum)) - 1;
	}
}

