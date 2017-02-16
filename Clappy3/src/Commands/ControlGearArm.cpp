#include "ControlGearArm.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());

}

void ControlGearArm::Initialize() {

	Robot::gearArm->SetGearPIDSetpoint(Robot::gearArm->GetTargetPosition());
	Robot::gearArm->EnableGearPID();

}

void ControlGearArm::Execute() {

}

bool ControlGearArm::IsFinished() {
	return false;
}

void ControlGearArm::End() {

}

void ControlGearArm::Interrupted() {
	Robot::gearArm->DisableGearPID();
}
