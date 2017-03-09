#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveTeleop.h"
#include "Commands/ToggleGearPCM.h"
#include "Commands/ToggleRobotDirection.h"
#include "Commands/ChangeGearArmPos.h"
#include "Commands/HomeGearArm.h"
#include "Commands/GrabGearFromGround.h"
#include "Commands/GrabGearFromRamp.h"
#include "Commands/MoveToGround.h"
#include "Commands/MoveToHook.h"
#include "Commands/SetShoot.h"

OI::OI() {

	m_controlConfig = ControlConfig::DISABLED;

	switch (m_controlConfig)
	{
	case ControlConfig::JOYSTICK:
	{
	    driveStick.reset(new Joystick(0));
	    gearStick.reset(new Joystick(1));
	    driveStickX = nullptr;
	    gearStickX = nullptr;

	    controlSwitchButton.reset(new JoystickButton(driveStick.get(), 1)); //Trigger
	    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

	    toggleGearPCMButton.reset(new JoystickButton(gearStick.get(), 1)); //Trigger
	    toggleGearPCMButton->WhenPressed(new ToggleGearPCM(PCMStatus::TOGGLE));

	    homeGearArmButton.reset(new JoystickButton(gearStick.get(), 3));
	    homeGearArmButton->WhenPressed(new HomeGearArm());

	    button4.reset(new JoystickButton(gearStick.get(), 4));	//Ground
	    button4->WhenPressed(new ChangeGearArmPos(Position::UP));

	    button5.reset(new JoystickButton(gearStick.get(), 5));  //Ramp
	    button5->WhenPressed(new ChangeGearArmPos(Position::DOWN));

	    button6 = nullptr;
	    button7 = nullptr;

	    break;
	}
	case ControlConfig::XBOXCONTOLLER:
	{
	    driveStickX.reset(new XboxController(0));
	    gearStickX.reset(new XboxController(1));
	    driveStick = nullptr;
	    gearStick = nullptr;

	    controlSwitchButton.reset(new JoystickButton(driveStickX.get(), 6)); //Rb
	    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

	    toggleGearPCMButton.reset(new JoystickButton(gearStickX.get(), 6)); //Rb
	    toggleGearPCMButton->WhenPressed(new ToggleGearPCM(PCMStatus::CLOSED));

	    homeGearArmButton.reset(new JoystickButton(gearStickX.get(), 5)); //Lb
	    homeGearArmButton->WhenPressed(new ToggleGearPCM(PCMStatus::OPENED));

	    button4.reset(new JoystickButton(gearStickX.get(), 1));	//Ground A
	    button4->WhenPressed(new SetShoot(Direction::FORWARD));

	    button5.reset(new JoystickButton(gearStickX.get(), 2));	//Hook B
	    button5->WhenPressed(new SetShoot(Direction::REVERSE));

	    button6 = nullptr;

	    button7 = nullptr;

	    break;
	}
	case ControlConfig::JDRIVE_XGEAR:
	{
		driveStick.reset(new Joystick(0));
		gearStickX.reset(new XboxController(1));
		driveStickX = nullptr;
		gearStick = nullptr;

	    controlSwitchButton.reset(new JoystickButton(driveStick.get(), 1)); //Trigger
	    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

	    toggleGearPCMButton.reset(new JoystickButton(gearStickX.get(), 6)); //Rb
	    toggleGearPCMButton->WhenPressed(new ToggleGearPCM(PCMStatus::TOGGLE));

	    homeGearArmButton.reset(new JoystickButton(gearStickX.get(), 5)); //Lb
	    homeGearArmButton->WhenPressed(new HomeGearArm());

	    button4.reset(new JoystickButton(gearStickX.get(), 1));	//Ground A
	    button4->WhenPressed(new MoveToGround());

	    button5.reset(new JoystickButton(gearStickX.get(), 2));	//Hook B
	    button5->WhenPressed(new MoveToHook());

	    button5.reset(new JoystickButton(gearStickX.get(), 2));  //Ramp B
	    button5->WhenPressed(new ChangeGearArmPos(Position::UP));

	    button6.reset(new JoystickButton(gearStickX.get(), 3)); //X
	    button6->WhenPressed(new GrabGearFromGround());

	    button7.reset(new JoystickButton(gearStickX.get(), 4)); //Y
	    button7->WhenPressed(new GrabGearFromRamp());

		break;
	}
	default:
	{
	    driveStickX = nullptr;
	    gearStickX = nullptr;
	    driveStick = nullptr;
	    gearStick = nullptr;

	    controlSwitchButton = nullptr;

	    toggleGearPCMButton = nullptr;

	    homeGearArmButton = nullptr;

	    button4 = nullptr;

	    button5 = nullptr;

	    button6 = nullptr;

	    button7 = nullptr;
	}
	}

}

std::shared_ptr<Joystick> OI::getDriveStick()
{
   return driveStick;
}

std::shared_ptr<Joystick> OI::getGearStick()
{
	return gearStick;
}

std::shared_ptr<XboxController> OI::getDriveStickX()
{
	return driveStickX;
}

std::shared_ptr<XboxController> OI::getGearStickX()
{
	return gearStickX;
}

int OI::getControlConfig()
{
	return m_controlConfig;
}
