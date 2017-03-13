#include "ControlGearArm.h"

#include "../Calculations.h"

ControlGearArm::ControlGearArm() {

	Requires(Robot::gearArm.get());
	//m_targetPosition = 0;
	gearStick = Robot::oi->getGearStickX();

}

void ControlGearArm::Initialize() {

}

void ControlGearArm::Execute() {

	Robot::gearArm->ControlGearArmMotor(-gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand));



	/*
		(gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand) < 0) ? ((!Robot::gearArm->GetHomeSwitch()) ? Robot::gearArm->ControlGearArmMotor(-gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand)) : Robot::gearArm->StopGearArmMotor()) : Robot::gearArm->ControlGearArmMotor(-0.5
				* gearStick->GetY(frc::Joystick::JoystickHand::kLeftHand));

		m_targetPosition = Robot::gearArm->GetTargetPositionD();

		if (Robot::gearArm->GetDegreesD() < m_targetPosition)
		{
			Robot::gearArm->ControlGearArmMotor(-Calculations::GearArmSpeed(Robot::gearArm->GetDegreesD() - m_targetPosition));
		}
		if (Robot::gearArm->GetDegreesD() > m_targetPosition)
		{
			Robot::gearArm->ControlGearArmMotor(Calculations::GearArmSpeed(Robot::gearArm->GetDegreesD() - m_targetPosition));
		}
		*/
}

bool ControlGearArm::IsFinished() {
	return false;
}

void ControlGearArm::End() {

}

void ControlGearArm::Interrupted() {
	Robot::gearArm->StopGearArmMotor();
}
