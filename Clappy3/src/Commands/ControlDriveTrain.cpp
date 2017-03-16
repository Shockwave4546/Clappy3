#include "ControlDriveTrain.h"


ControlDriveTrain::ControlDriveTrain(double x, double y, double z, double timeout) {
	Requires(Robot::driveTrain.get());
	m_X = x;
	m_Y = y;
	m_Z = z;
	m_timeout = timeout;
}

// Called just before this Command runs the first time
void ControlDriveTrain::Initialize() {
	SetTimeout(m_timeout);
}

// Called repeatedly when this Command is scheduled to run
void ControlDriveTrain::Execute() {
	Robot::driveTrain->ControlDriveTrain(m_X, m_Y, m_Z, 1);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlDriveTrain::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void ControlDriveTrain::End() {
	Robot::driveTrain->StopMoving();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlDriveTrain::Interrupted() {
	Robot::driveTrain->StopMoving();
}
