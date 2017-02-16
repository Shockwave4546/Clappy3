#include "ControlGearArm.h"

ControlGearArm::ControlGearArm(Position position) {

	Requires(Robot::gearArm.get());

	m_position = position;
	m_done = false;

}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {
	switch (m_position)
	{
	case Position::GROUND:
		Robot::gearArm->MoveTo(90.0);
		break;
	case Position::RAMP:
		Robot::gearArm->MoveTo(45.0);
		break;
	case Position::HOOK:
		Robot::gearArm->MoveTo(0.0);
		break;
	case Position::JOYSTICK:
		Robot::gearArm->MoveTo(SmartDashboard::GetNumber("gy", Robot::gearArm->GetDegreesD()));
	}
	m_done = true;
}

bool ControlGearArm::IsFinished() {
	return m_done;
}

void ControlGearArm::End() {
	Robot::gearArm->ControlGearArmMotor(0.0);
}

void ControlGearArm::Interrupted() {
	Robot::gearArm->ControlGearArmMotor(0.0);
}
