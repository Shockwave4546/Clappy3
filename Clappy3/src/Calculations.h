/*
 * Calculations.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Garrick Craft
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

namespace calc
{
	double DriveSpeed(double input, double sens);
	double DriveMotorLeft(double y, double z);
	double DriveMotorRight(double y, double z);
	double TwistAxisScalar(double y, double z);
	double AutoZValue(double offset, double distanceRatio, double weight);
	double AutoYValue(double offset, double distanceRatio, double weight);
}

#endif /* CALCULATIONS_H_ */
