#ifndef OI_H
#define OI_H

#include "WPILib.h"

enum class ControlConfig
{
	JOYSTICK,
	XBOXCONTOLLER
};

class OI {
private:

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<Joystick> gearStick;
	std::shared_ptr<JoystickButton> controlSwitchButton;
	std::shared_ptr<JoystickButton> toggleGearPCMButton;
	std::shared_ptr<JoystickButton> homeGearArmButton;
	std::shared_ptr<JoystickButton> button4;
	std::shared_ptr<JoystickButton> button5;
	std::shared_ptr<JoystickButton> button6;

	std::shared_ptr<XboxController> driveStickX;
	std::shared_ptr<XboxController> gearStickX;

	ControlConfig m_controlConfig;

public:
	OI();

	std::shared_ptr<Joystick> getDriveStick();
	std::shared_ptr<Joystick> getGearStick();

	std::shared_ptr<XboxController> getDriveStickX();
	std::shared_ptr<XboxController> getGearStickX();

	bool getControlConfig();
};

#endif
