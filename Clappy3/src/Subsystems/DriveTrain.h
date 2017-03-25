#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

enum Direction
{
	FORWARD,
	REVERSE
};

enum Slow
{
	ACTIVATED,
	DEACTIVATED
};

enum DriveMotor
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
	Slow m_slow;

public:

	DriveTrain();

	void InitDefaultCommand();

	void ControlDriveTrain(double x, double y, double z, double sens);

	void StopMoving();

	void ChangeDirection();

	void SetDirection(Direction direction);

	void ToggleSlow();

	void SetSlow(Slow slow);


	int GetDirection();

	std::string GetDirectionS();

	std::string GetSlowS();

	double GetMotorD(DriveMotor motor);

};

#endif
