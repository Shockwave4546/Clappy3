/*
 * Calculations.h
 *
 *  Created on: Feb 19, 2017
 *      Author: Garrick Craft
 */

#ifndef CALCULATIONS_H_
#define CALCULATIONS_H_

namespace Calculations
{
	double HorizontalDistanceFromCamera(double cameraHeight, double centerOffset, double vFOV, double pMax, double ph);
	double GearArmSpeed(double difference);
	double DriveMotorSpeed(double scalar, double input, double sens);
	double TwistAxisScalar(double y, double z);

	const double pi{ 3.14159265359 };
}



#endif /* CALCULATIONS_H_ */
