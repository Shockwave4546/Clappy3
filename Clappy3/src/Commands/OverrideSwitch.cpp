#include "OverrideSwitch.h"

OverrideSwitch::OverrideSwitch() {
	Requires(Robot::gearArm.get());
}

// Called just before this Command runs the first time
void OverrideSwitch::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void OverrideSwitch::Execute() {

	Robot::gearArm->OverrideSwitch();

}

// Make this return true when this Command no longer needs to run execute()
bool OverrideSwitch::IsFinished() {
	return m_done;
}

// Called once after isFinished returns true
void OverrideSwitch::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OverrideSwitch::Interrupted() {

}
