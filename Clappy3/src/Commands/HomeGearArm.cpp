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

	Robot::gearArm->ControlGearArmMotor(0.0);
	Robot::gearArm->Zero();

	m_done = true;
}


bool HomeGearArm::IsFinished() {
	return m_done;
}


void HomeGearArm::End() {
	Robot::gearArm->ControlGearArmMotor(0.0);
}


void HomeGearArm::Interrupted() {
	Robot::gearArm->ControlGearArmMotor(0.0);
}
