#include "HomeGearArm.h"
#include "../RobotMap.h"

HomeGearArm::HomeGearArm() {

	Requires(Robot::gearArm.get());
	m_done = false;

}


void HomeGearArm::Initialize() {

}


void HomeGearArm::Execute() {

	while (!Robot::gearArm->GetHomeSwitch())
	{
		Robot::gearArm->ControlGearArmMotor(0.3);
	}

	Robot::gearArm->StopGearArmMotor();
	Robot::gearArm->Zero();
	Robot::gearArm->SetGearPIDSetpoint(0);

	m_done = true;
}


bool HomeGearArm::IsFinished() {
	return m_done;
}


void HomeGearArm::End() {

}


void HomeGearArm::Interrupted() {
	Robot::gearArm->SetGearPIDSetpoint(Robot::gearArm->GetDegreesD());
}
