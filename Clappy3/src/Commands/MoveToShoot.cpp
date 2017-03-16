#include "MoveToShoot.h"

MoveToShoot::MoveToShoot() {
	Requires(Robot::gearArm.get());

}

void MoveToShoot::Initialize() {

}

void MoveToShoot::Execute() {

	if (Robot::gearArm->GetIdealPosition() == Position::GROUND)
	{
		Robot::gearArm->CloseShoot();
		Robot::gearArm->ControlGearArmMotor(0.5);
		frc::Wait(1.5);
		Robot::gearArm->StopGearArmMotor();
		Robot::gearArm->OpenShoot();
		Robot::gearArm->ControlGearArmMotor(-0.5);
		frc::Wait(0.5);
	}
	else if (Robot::gearArm->GetIdealPosition() == Position::SWITCH)
	{
		Robot::gearArm->OpenShoot();
		Robot::gearArm->ControlGearArmMotor(-0.5);
		frc::Wait(0.5);
		Robot::gearArm->StopGearArmMotor();
	}

	Robot::gearArm->SetIdealPosition(Position::SHOOT);
}

bool MoveToShoot::IsFinished() {
	return Robot::gearArm->GetIdealPosition() == Position::SHOOT;
}

void MoveToShoot::End() {

}

void MoveToShoot::Interrupted() {

}
