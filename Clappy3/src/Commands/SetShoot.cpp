#include "../Commands/SetShoot.h"

#include <thread>
#include <chrono>

SetShoot::SetShoot(Direction direction) {
	Requires(Robot::gearArm.get());
	m_direction = direction;
}

void SetShoot::Initialize() {

	if (m_direction == Direction::FORWARD)
	{
		if (Robot::gearArm->GetHomeSwitch())
			Robot::gearArm->OpenShoot();
		else
		{
			Robot::oi->RumbleGearGamepad(1);
			frc::Wait(0.5);
			Robot::oi->StopGearGamepadRumble();
		}
	}
	else
	{
		if (Robot::gearArm->GetHomeSwitch())
			Robot::gearArm->CloseShoot();
		else
		{
			Robot::oi->RumbleGearGamepad(1);
			frc::Wait(0.5);
			Robot::oi->StopGearGamepadRumble();
		}
	}

}

void SetShoot::Execute() {

	m_done = true;

}

bool SetShoot::IsFinished() {
	return m_done;
}

void SetShoot::End() {

}

void SetShoot::Interrupted() {

}
