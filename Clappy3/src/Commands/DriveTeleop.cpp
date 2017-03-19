#include "DriveTeleop.h"

#include "../Calculations.h"

DriveTeleop::DriveTeleop(): Command() {

	Requires(Robot::driveTrain.get());

	driveStick = Robot::oi->getDriveStick();
	driveStickX = Robot::oi->getDriveStickX();

}

void DriveTeleop::Initialize() {

}

void DriveTeleop::Execute() {

	if (driveStick != nullptr)
	{
		m_sens = (-0.5 * driveStick->GetRawAxis(3) + 0.5) * 5;
		m_X = -driveStick->GetRawAxis(0);
		m_Y = -driveStick->GetRawAxis(1);
		m_Z = 0.5 * -driveStick->GetRawAxis(2);
		m_Z *= calc::TwistAxisScalar(m_Y, m_Z);
	}

	if (driveStickX != nullptr)
	{
		m_sens = 5;
		m_X = -driveStickX->GetX(XboxController::kLeftHand);
		m_Y = -driveStickX->GetY(XboxController::kLeftHand);
		m_Z = -driveStickX->GetX(XboxController::kRightHand);
	}

	Robot::driveTrain->ControlDriveTrain(m_X, m_Y, m_Z, m_sens);

}

bool DriveTeleop::IsFinished() {
    return false;
}

void DriveTeleop::End() {

}

void DriveTeleop::Interrupted() {
	Robot::driveTrain->StopMoving();
}


