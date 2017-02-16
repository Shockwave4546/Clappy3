#include "OI.h"
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/DriveTeleop.h"
#include "Commands/ToggleGearPCM.h"
#include "Commands/ToggleRobotDirection.h"
#include "Commands/ControlGearArm.h"
#include "Commands/HomeGearArm.h"
#include "Commands/ControlShoot.h"

OI::OI() {

    driveStick.reset(new Joystick(0));
    gearStick.reset(new Joystick(1));
    
    controlSwitchButton.reset(new JoystickButton(driveStick.get(), 1));
    controlSwitchButton->WhenPressed(new ToggleRobotDirection());

    toggleGearPCMButton.reset(new JoystickButton(gearStick.get(), 1));
    toggleGearPCMButton->WhenPressed(new ToggleGearPCM());

    controlGearArmButton.reset(new JoystickButton(gearStick.get(), 2));
    controlGearArmButton->WhenPressed(new ControlGearArm(Position::JOYSTICK));

    button4.reset(new JoystickButton(gearStick.get(), 4));
    button4->WhenPressed(new ControlGearArm(Position::GROUND));

    button5.reset(new JoystickButton(gearStick.get(), 5));
    button5->WhenPressed(new ControlGearArm(Position::RAMP));

    button6.reset(new JoystickButton(gearStick.get(), 6));
    button6->WhenPressed(new ControlGearArm(Position::HOOK));

    button7.reset(new JoystickButton(gearStick.get(), 7));
    button7->WhenPressed(new ControlShoot(ShootPosition::DOWN));

    button8.reset(new JoystickButton(gearStick.get(), 8));
    button8->WhenPressed(new ControlShoot(ShootPosition::UP));

    homeGearArmButton.reset(new JoystickButton(gearStick.get(), 3));
    homeGearArmButton->WhenPressed(new HomeGearArm());

}

std::shared_ptr<Joystick> OI::getDriveStick()
{
   return driveStick;
}

std::shared_ptr<Joystick> OI::getGearStick()
{
	return gearStick;
}

