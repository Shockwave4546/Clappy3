#include "../Commands/ControlGearArm.h"

#include "../Calculations.h"

ControlGearArm::ControlGearArm() {
	Requires(Robot::gearArm.get());
	gearStick = Robot::oi->getGearStickX();
}

ControlGearArm::ControlGearArm(double speed, double timeout)
{
	Requires(Robot::gearArm.get());
	gearStick = nullptr;
	m_speed = speed;
	m_timeout = timeout;
}
void ControlGearArm::Initialize() {
	if (m_timeout > 0)
		SetTimeout(m_timeout);
}

void ControlGearArm::Execute() {

	if (gearStick != nullptr)
		Robot::gearArm->ControlGearArmMotor(-gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand));
	else
		Robot::gearArm->ControlGearArmMotor(m_speed);
	if (Robot::gearArm->GetHomeSwitch())
	{
		gearStick->SetRumble(XboxController::RumbleType::kLeftRumble, 0.5);
		gearStick->SetRumble(XboxController::RumbleType::kRightRumble, 0.5);
	}
	else
	{
		gearStick->SetRumble(XboxController::RumbleType::kLeftRumble, 0);
		gearStick->SetRumble(XboxController::RumbleType::kRightRumble, 0);
	}

}

bool ControlGearArm::IsFinished() {
	return IsTimedOut();
}

void ControlGearArm::End() {
	Robot::gearArm->StopGearArmMotor();
}

void ControlGearArm::Interrupted() {
	Robot::gearArm->StopGearArmMotor();
}
