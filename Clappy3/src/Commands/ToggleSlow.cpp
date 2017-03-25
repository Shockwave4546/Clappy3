#include "ToggleSlow.h"

ToggleSlow::ToggleSlow() {
	Requires(Robot::driveTrain.get());
}

// Called just before this Command runs the first time
void ToggleSlow::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ToggleSlow::Execute() {
	Robot::driveTrain->ToggleSlow();
	m_done = true;
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleSlow::IsFinished() {
	return m_done;
}

// Called once after isFinished returns true
void ToggleSlow::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleSlow::Interrupted() {

}
