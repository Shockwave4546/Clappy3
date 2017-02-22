#include "Drive.h"
#include "../Calculations.h"

Drive::Drive() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrain.get());
	SetTimeout(0.5);
}

// Called just before this Command runs the first time
void Drive::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
	Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_LEFT, Calculations::DriveMotorLeft(-0.5, 0));
	Robot::driveTrain->SetMotorSpeed(DriveMotor::TOP_RIGHT, Calculations::DriveMotorRight(-0.5, 0));
	Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_LEFT, Calculations::DriveMotorLeft(-0.5, 0));
	Robot::driveTrain->SetMotorSpeed(DriveMotor::BOTTOM_RIGHT, Calculations::DriveMotorRight(-0.5, 0));
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() {
	return IsTimedOut();
}

// Called once after isFinished returns true
void Drive::End() {
	Robot::driveTrain->StopMoving();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {

}
