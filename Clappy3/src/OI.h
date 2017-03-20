#ifndef OI_H
#define OI_H

#include "WPILib.h"

enum ControlConfig
{
	JOYSTICK,
	XBOXCONTOLLER,
	DISABLED
};

class OI {
private:

	std::shared_ptr<Joystick> driveStick;
	std::shared_ptr<Joystick> gearStick;
	std::shared_ptr<JoystickButton> drivetriggerRb;
	std::shared_ptr<JoystickButton> triggerRb;
	std::shared_ptr<JoystickButton> triggerLb;
	std::shared_ptr<JoystickButton> button4a;
	std::shared_ptr<JoystickButton> button5b;
	std::shared_ptr<JoystickButton> button6x;
	std::shared_ptr<JoystickButton> button7y;

	std::shared_ptr<XboxController> driveStickX;
	std::shared_ptr<XboxController> gearStickX;

	ControlConfig m_driveConfig;
	ControlConfig m_gearConfig;

public:
	OI();

	std::shared_ptr<Joystick> getDriveStick();
	std::shared_ptr<Joystick> getGearStick();

	std::shared_ptr<XboxController> getDriveStickX();
	std::shared_ptr<XboxController> getGearStickX();

	ControlConfig getDriveConfig();
	ControlConfig getGearConfig();

	void RumbleDriveGamepad(double value);
	void RumbleGearGamepad(double value);
	void StopDriveGamepadRumble();
	void StopGearGamepadRumble();
};

#endif
