#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Calculations.h"
#include "../Commands/DriveTeleop.h"
#include "../Robot.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {

    topLeft = RobotMap::driveTrainTopLeft;
    topRight = RobotMap::driveTrainTopRight;
    bottomLeft = RobotMap::driveTrainBottomLeft;
    bottomRight = RobotMap::driveTrainBottomRight;
    center = RobotMap::driveTrainCenter;

    m_direction = Direction::FORWARD;
    m_slow = Slow::DEACTIVATED;

}

void DriveTrain::InitDefaultCommand() {

	SetDefaultCommand(new DriveTeleop());
	m_direction = Direction::FORWARD;
	m_slow = Slow::DEACTIVATED;

}

void DriveTrain::ControlDriveTrain(double x, double y, double z, double sens)
{
	if (m_slow == Slow::ACTIVATED)
	{
		z = 0;
		Robot::oi->RumbleDriveGamepad(0.5);
	}
	else
		Robot::oi->StopDriveGamepadRumble();
	right_res = calc::DriveSpeed(calc::DriveMotorRight(y, z), sens);
	left_res = calc::DriveSpeed(calc::DriveMotorLeft(y, z), sens);
	if (m_direction == Direction::FORWARD)
	{
		/*
		if (right_res < 0)
			right_res *= 0.9;
		if (left_res > 0)
			left_res *= 0.9;
			*/
		topLeft->Set(left_res);
		topRight->Set(right_res);
		bottomLeft->Set(left_res);
		bottomRight->Set(right_res);
		//center->Set(x);
	}
	else
	{
		/*
		if (right_res > 0)
			right_res *= 0.9;
		if (left_res < 0)
			left_res *= 0.9;
			*/
		topLeft->Set(-right_res);
		topRight->Set(-left_res);
		bottomLeft->Set(-right_res);
		bottomRight->Set(-left_res);
		//center->Set(-x);
	}

	SmartDashboard::PutNumber("topLeft", left_res);//topLeft->Get());
	SmartDashboard::PutNumber("topRight", right_res);//topRight->Get());
	SmartDashboard::PutNumber("bottomLeft", bottomLeft->Get());
	SmartDashboard::PutNumber("bottomRight", bottomRight->Get());
	SmartDashboard::PutNumber("center", center->Get());
	SmartDashboard::PutNumber("y", y);
	SmartDashboard::PutNumber("z", z);

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

void DriveTrain::ToggleSlow()
{
	if (m_slow == Slow::ACTIVATED)
		m_slow = Slow::DEACTIVATED;
	else
		m_slow = Slow::ACTIVATED;
}

void DriveTrain::SetDirection(Direction direction)
{
	m_direction = direction;
}

void DriveTrain::SetSlow(Slow slow)
{
	m_slow = slow;
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

std::string DriveTrain::GetSlowS()
{
	return (m_slow == Slow::DEACTIVATED) ? "Deactivated" : "Activated";
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




