#include "MoveToGround.h"

MoveToGround::MoveToGround() {
	Requires(Robot::gearArm.get());
}

void MoveToGround::Initialize() {

}

void MoveToGround::Execute() {

	if (Robot::gearArm->GetIdealPosition() != Position::GROUND)
	{
		if (Robot::gearArm->GetIdealPosition() == Position::SHOOT)
		{
			Robot::gearArm->ControlGearArmMotor(0.5);
			frc::Wait(0.5);
			Robot::gearArm->StopGearArmMotor();
		}
		Robot::gearArm->CloseShoot();
		Robot::gearArm->ControlGearArmMotor(-0.5);
		frc::Wait(1);
		Robot::gearArm->SetIdealPosition(Position::GROUND);
	}

}

bool MoveToGround::IsFinished() {
	return Robot::gearArm->GetIdealPosition() == Position::GROUND;
}

void MoveToGround::End() {

}

void MoveToGround::Interrupted() {

}
