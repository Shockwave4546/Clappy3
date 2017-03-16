#include "Climber.h"

#include "../Commands/ControlClimbmotor.h"
#include "../RobotMap.h"

Climber::Climber() : Subsystem("Climber") {

	climbMotor = RobotMap::climbMotor;

}

void Climber::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new ControlClimbmotor());
}

void Climber::SetMotorSpeed(double speed)
{
	climbMotor->Set(speed);
}

void Climber::StopMotor()
{
	climbMotor->StopMotor();
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
