#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveTeleop.h"
#include "Commands/ToggleGearPCM.h"
#include "Commands/ToggleRobotDirection.h"
#include "Commands/ChangeGearArmPos.h"
#include "Commands/HomeGearArm.h"

OI::OI() {

    driveStick.reset(new Joystick(0));
    gearStick.reset(new Joystick(1));
    
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

std::shared_ptr<Joystick> OI::getDriveStick()
{
   return driveStick;
}

std::shared_ptr<Joystick> OI::getGearStick()
{
	return gearStick;
}

