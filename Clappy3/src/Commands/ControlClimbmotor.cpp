#include "ControlClimbmotor.h"
#include "../Robot.h"
ControlClimbmotor::ControlClimbmotor() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::climber.get());
	if (Robot::oi->getControlConfig() == ControlConfig::JDRIVE_XGEAR || Robot::oi->getControlConfig() == ControlConfig::XBOXCONTOLLER)
	{
		gearStickX = Robot::oi->getGearStickX();
		gearStick = nullptr;
	}
	else
	{
		gearStick = Robot::oi->getGearStick();
		gearStickX = nullptr;
	}
}

// Called just before this Command runs the first time
void ControlClimbmotor::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ControlClimbmotor::Execute() {

	if (gearStickX != nullptr)
		Robot::climber->SetMotorSpeed(gearStickX->GetY(Joystick::JoystickHand::kLeftHand));
	else
		Robot::climber->SetMotorSpeed(gearStick->GetY());

}

// Make this return true when this Command no longer needs to run execute()
bool ControlClimbmotor::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ControlClimbmotor::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlClimbmotor::Interrupted() {

}
