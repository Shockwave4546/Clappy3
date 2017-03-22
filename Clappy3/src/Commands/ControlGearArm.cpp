#include "../Commands/ControlGearArm.h"

#include "../Calculations.h"

ControlGearArm::ControlGearArm() {
	Requires(Robot::gearArm.get());
	gearStick = Robot::oi->getGearStickX();
	m_timer = std::time(nullptr);
}

ControlGearArm::ControlGearArm(double speed, double timeout)
{
	Requires(Robot::gearArm.get());
	gearStick = nullptr;
	m_speed = speed;
	m_timeout = timeout;
	m_timer = std::time(nullptr);
}
void ControlGearArm::Initialize() {
	if (m_timeout > 0)
		SetTimeout(m_timeout);
}

void ControlGearArm::Execute() {

	if (gearStick != nullptr)
		Robot::gearArm->ControlGearArmMotor(0.5 * -gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand));
	else
		Robot::gearArm->ControlGearArmMotor(m_speed);
	if (Robot::gearArm->GetHomeSwitch() && gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand) < 0)
	{
		if (current_time > 0)
		{
			if (static_cast<int>(m_timer) > current_time + 2)
				Robot::oi->RumbleGearGamepad(0.5);
		}
	}
	else
	{
		current_time = -1;
		Robot::oi->StopGearGamepadRumble();
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
