#include "MoveToHook.h"

MoveToHook::MoveToHook() {
	Requires(Robot::gearArm.get());
}

void MoveToHook::Initialize() {

}

void MoveToHook::Execute() {

	if (Robot::gearArm->GetIdealPosition() == Position::GROUND)
	{
		Robot::gearArm->CloseShoot();
		Robot::gearArm->ControlGearArmMotor(0.5);
		frc::Wait(2);
	}
	else if (Robot::gearArm->GetIdealPosition() == Position::SHOOT)
	{
		Robot::gearArm->ControlGearArmMotor(0.5);
		frc::Wait(1);
	}
	Robot::gearArm->StopGearArmMotor();
	Robot::gearArm->SetIdealPosition(Position::SWITCH);

}

bool MoveToHook::IsFinished() {
	return Robot::gearArm->GetIdealPosition() == Position::SWITCH;
}

void MoveToHook::End() {

}

void MoveToHook::Interrupted() {

}
