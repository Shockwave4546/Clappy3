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
