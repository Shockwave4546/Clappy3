#include "../Commands/DriveTeleop.h"
#include "DriveTrain.h"
#include "../RobotMap.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

    topLeft = RobotMap::driveTrainTopLeft;
    topRight = RobotMap::driveTrainTopRight;
    bottomLeft = RobotMap::driveTrainBottomLeft;
    bottomRight = RobotMap::driveTrainBottomRight;
    center = RobotMap::driveTrainCenter;

    m_direction = Direction::FORWARD;

}

void DriveTrain::InitDefaultCommand() {

	SetDefaultCommand(new DriveTeleop());

}

void DriveTrain::SetMotorSpeed(DriveMotor motor, double speed)
{
	switch (motor)
	{
	case DriveMotor::TOP_LEFT:
		topLeft->Set(speed);
		break;
	case DriveMotor::TOP_RIGHT:
		topRight->Set(speed);
		break;
	case DriveMotor::BOTTOM_LEFT:
		bottomLeft->Set(speed);
		break;
	case DriveMotor::BOTTOM_RIGHT:
		bottomRight->Set(speed);
		break;
	case DriveMotor::CENTER:
		center->Set(speed);
		break;
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




