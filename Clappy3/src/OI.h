#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<Joystick> gearStick;
	std::shared_ptr<JoystickButton> controlSwitchButton;
	std::shared_ptr<JoystickButton> toggleGearPCMButton;
	std::shared_ptr<JoystickButton> homeGearArmButton;
	std::shared_ptr<JoystickButton> controlGearArmButton;
	std::shared_ptr<JoystickButton> button4;
	std::shared_ptr<JoystickButton> button5;
	std::shared_ptr<JoystickButton> button6;
	std::shared_ptr<JoystickButton> button7;
	std::shared_ptr<JoystickButton> button8;


public:
	OI();

	std::shared_ptr<Joystick> getDriveStick();
	std::shared_ptr<Joystick> getGearStick();

};

#endif
