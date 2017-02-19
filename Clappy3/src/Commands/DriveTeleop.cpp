#include "DriveTeleop.h"
#include <cmath>

DriveTeleop::DriveTeleop(): Command() {

	Requires(Robot::driveTrain.get());

	m_controlConfig = Robot::oi->getControlConfig();

	m_X = 0.0;
	m_Y = 0.0;
	m_Z = 0.0;
	m_scalar = 1.0;
	m_sens = 0.0;

	if (m_controlConfig == ControlConfig::JOYSTICK || m_controlConfig == ControlConfig::JDRIVE_XGEAR)
	{
		driveStick = Robot::oi->getDriveStick();
		driveStickX = nullptr;
	}
	else
	{
		driveStickX = Robot::oi->getDriveStickX();
		driveStick = nullptr;
	}

}

void DriveTeleop::Initialize() {

}

void DriveTeleop::Execute() {

	if (m_controlConfig == ControlConfig::JOYSTICK || m_controlConfig == ControlConfig::JDRIVE_XGEAR)
	{
		m_sens = -0.5 * driveStick->GetRawAxis(3) + 0.5;
		m_X = driveStick->GetRawAxis(0);
		m_Y = driveStick->GetRawAxis(1);
		m_Z = 0.5 * -driveStick->GetRawAxis(2);
	}
	else
	{
		m_sens = 1;
		m_X = driveStickX->GetX(XboxController::kLeftHand);
		m_Y = driveStickX->GetY(XboxController::kLeftHand);
		m_Z = 0.5 * -driveStickX->GetX(XboxController::kRightHand);
	}

	m_Z *= std::abs((2 / (1 + std::exp((m_Y==0) ? m_Z/0.01 : m_Z/m_Y)) - 1));

	if (Robot::driveTrain->GetDirection() == Direction::FORWARD)
	{
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::CENTER, DriveTeleop::CalculateSpeed(m_scalar, m_X));

	}
	else
	{
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_LEFT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Right()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, DriveTeleop::CalculateSpeed(m_scalar, DriveTeleop::Left()));
		Robot::driveTrain->SetMotorSpeed(DriveMotor::CENTER, DriveTeleop::CalculateSpeed(m_scalar, -m_X));

	}
}

bool DriveTeleop::IsFinished() {
    return false;
}

void DriveTeleop::End() {

}

void DriveTeleop::Interrupted() {
	Robot::driveTrain->StopMoving();
}

inline double DriveTeleop::CalculateSpeed(double scalar, double input)
{
	return (2 * scalar / (1 + std::exp(m_sens * input))) - scalar;
}

inline double DriveTeleop::Left()
{
	return -(m_Y + m_Z);
}

inline double DriveTeleop::Right()
{
	return m_Y - m_Z;
}
