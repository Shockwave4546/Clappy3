#include "SetShoot.h"

SetShoot::SetShoot(Direction direction) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::gearArm.get());
	m_direction = direction;
	m_done = false;
}

// Called just before this Command runs the first time
void SetShoot::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SetShoot::Execute() {
	if (m_direction == Direction::FORWARD)
		Robot::gearArm->Forward();
	else
		Robot::gearArm->Reverse();
	m_done = true;
}

// Make this return true when this Command no longer needs to run execute()
bool SetShoot::IsFinished() {
	return m_done;
}

// Called once after isFinished returns true
void SetShoot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetShoot::Interrupted() {

}
