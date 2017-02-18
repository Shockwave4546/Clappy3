#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());
	m_done = false;
}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {
	Robot::gearArm->MoveToTargetPosition();
}

bool ControlGearArm::IsFinished() {
	return false;
}

void ControlGearArm::End() {

}

void ControlGearArm::Interrupted() {
	Robot::gearArm->StopGearArmMotor();
}
