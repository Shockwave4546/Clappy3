#include "../Commands/DriveTeleop.h"
#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Calculations.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

    topLeft = RobotMap::driveTrainTopLeft;
    topRight = RobotMap::driveTrainTopRight;
    bottomLeft = RobotMap::driveTrainBottomLeft;
    bottomRight = RobotMap::driveTrainBottomRight;
    center = RobotMap::driveTrainCenter;

    m_direction = Direction::FORWARD;

}

void DriveTrain::InitDefaultCommand() {

	SetDefaultCommand(new DriveTeleop(Robot::oi->getDriveConfig()));

}

void DriveTrain::ControlDriveTrain(double x, double y, double z, double sens=1)
{
	if (m_direction == Direction::FORWARD)
	{
		topLeft->Set(calc::DriveSpeed(calc::DriveMotorLeft(y, z), sens));
		topRight->Set(calc::DriveSpeed(calc::DriveMotorRight(y, z), sens));
		bottomLeft->Set(calc::DriveSpeed(calc::DriveMotorLeft(y, z), sens));
		bottomRight->Set(calc::DriveSpeed(calc::DriveMotorRight(y, z), sens));
		center->Set(x);
	}
	else
	{
		topLeft->Set(calc::DriveSpeed(-calc::DriveMotorRight(y, z), sens));
		topRight->Set(calc::DriveSpeed(-calc::DriveMotorLeft(y, z), sens));
		bottomLeft->Set(calc::DriveSpeed(-calc::DriveMotorRight(y, z), sens));
		bottomRight->Set(calc::DriveSpeed(-calc::DriveMotorLeft(y, z), sens));
		center->Set(-x);
	}
}

void DriveTrain::StopMoving()
{
	topLeft->StopMotor();
	topRight->StopMotor();
	bottomLeft->StopMotor();
	bottomRight->StopMotor();
	center->StopMotor();
}

void DriveTrain::ChangeDirection()
{
	if (m_direction == Direction::FORWARD)
		m_direction = Direction::REVERSE;
	else
		m_direction = Direction::FORWARD;
}

void DriveTrain::SetDirection(Direction direction)
{
	m_direction = direction;
}






int DriveTrain::GetDirection()
{
	return m_direction;
}

std::string DriveTrain::GetDirectionS()
{
	if (m_direction == Direction::FORWARD)
		return "Forward";
	else
		return "Reverse";
}

double DriveTrain::GetMotorD(DriveMotor motor)
{
	switch(motor)
	{
	case DriveMotor::TOP_LEFT:
		return topLeft->Get();
	case DriveMotor::TOP_RIGHT:
		return topRight->Get();
	case DriveMotor::BOTTOM_LEFT:
		return bottomLeft->Get();
	case DriveMotor::BOTTOM_RIGHT:
		return bottomRight->Get();
	case DriveMotor::CENTER:
		return center->Get();
	default:
		return 0.0;
	}
}




