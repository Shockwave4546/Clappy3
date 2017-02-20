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
	double HorizontalDistanceFromCameraGround(double ph);
	double HorizontalDistanceFromCameraTape(double ph);
	double GearArmSpeed(double difference);
	double DriveMotorSpeed(double scalar, double input, double sens);
	double DriveMotorLeft(double y, double z);
	double DriveMotorRight(double y, double z);
	double TwistAxisScalar(double y, double z);

	const double pi{ 3.14159265359 };
	const double cameraHeight{ 0 };
	const double tapeHeight{ 0 };
	const double angleOffset{ 0 };
	const double pMax{ 0 };
	const double vFOV{ 33.6 }; 			//68.5 * sin(29.4)
}



#endif /* CALCULATIONS_H_ */
