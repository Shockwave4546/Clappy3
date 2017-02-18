#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveTeleop.h"
#include "Commands/ToggleGearPCM.h"
#include "Commands/ToggleRobotDirection.h"
#include "Commands/ChangeGearArmPos.h"
#include "Commands/HomeGearArm.h"

OI::OI() {

	m_controlConfig = ControlConfig::JOYSTICK;

	if (m_controlConfig == ControlConfig::JOYSTICK)
	{
	    driveStick.reset(new Joystick(0));
	    gearStick.reset(new Joystick(1));
	    driveStickX = nullptr;
	    gearStickX = nullptr;

	    controlSwitchButton.reset(new JoystickButton(driveStick.get(), 1));
	    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

	    toggleGearPCMButton.reset(new JoystickButton(gearStick.get(), 1));
	    toggleGearPCMButton->WhenPressed(new ToggleGearPCM());

	    homeGearArmButton.reset(new JoystickButton(gearStick.get(), 3));
	    homeGearArmButton->WhenPressed(new HomeGearArm());

	    button4.reset(new JoystickButton(gearStick.get(), 4));	//Ground
	    button4->WhenPressed(new ChangeGearArmPos(90));

	    button5.reset(new JoystickButton(gearStick.get(), 5));  //Ramp
	    button5->WhenPressed(new ChangeGearArmPos(45));

	    button6.reset(new JoystickButton(gearStick.get(), 6));  //Hook
	    button6->WhenPressed(new ChangeGearArmPos(0));
	}
	else
	{
	    driveStickX.reset(new XboxController(0));
	    gearStickX.reset(new XboxController(1));
	    driveStick = nullptr;
	    gearStick = nullptr;

	    /*
	    controlSwitchButton.reset(new JoystickButton(driveStickX.get(), 6)); //Rb
	    controlSwitchButton->WhenPressed(new ToggleRobotDirection());
	*/
	    toggleGearPCMButton.reset(new JoystickButton(gearStickX.get(), 6)); //Rb
	    toggleGearPCMButton->WhenPressed(new ToggleGearPCM());

	    homeGearArmButton.reset(new JoystickButton(gearStickX.get(), 5)); //Lb
	    homeGearArmButton->WhenPressed(new HomeGearArm());

	    button4.reset(new JoystickButton(gearStickX.get(), 1));	//Ground A
	    button4->WhenPressed(new ChangeGearArmPos(90));

	    button5.reset(new JoystickButton(gearStickX.get(), 2));  //Ramp B
	    button5->WhenPressed(new ChangeGearArmPos(45));

	    button6.reset(new JoystickButton(gearStickX.get(), 4));  //Hook Y
	    button6->WhenPressed(new ChangeGearArmPos(0));

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

bool OI::getControlConfig()
{
	return static_cast<bool>(m_controlConfig);
}
