#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

enum class Direction
{
	FORWARD,
	REVERSE
};

enum class DriveMotor
{
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
	CENTER
};

/**
 *
 *
 * @author Garrick Craft
 */
class DriveTrain: public Subsystem {
private:

	std::shared_ptr<SpeedController> topLeft;
	std::shared_ptr<SpeedController> topRight;
	std::shared_ptr<SpeedController> bottomLeft;
	std::shared_ptr<SpeedController> bottomRight;
	std::shared_ptr<SpeedController> center;
	Direction m_direction;

public:

	DriveTrain();

	void InitDefaultCommand();

	void SetMotorSpeed(DriveMotor motor, double speed);

	void StopMoving();

	void ChangeDirection();

	void SetDirection(Direction direction);

	int GetDirection();

	std::string GetDirectionS();

	double GetMotorD(DriveMotor motor);

};

#endif
