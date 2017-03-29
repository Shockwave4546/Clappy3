#ifndef GearArm_H
#define GearArm_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include <string>

enum Position
{
	GROUND,
	SHOOT,
	SWITCH,
	NOT_INITIALIZED,
	MOVING
};

/**
 *
 *
 * @author Garrick Craft
 */
class GearArm : public Subsystem {
private:

	std::shared_ptr<SpeedController> gearArmMotor;
	std::shared_ptr<Encoder> encoder;
	std::shared_ptr<DigitalInput> homeSwitch;
	std::shared_ptr<DoubleSolenoid> solenoid;
	Position m_idealPosition;
	bool s_override{ false };
	inline bool SolenoidP();

public:

	GearArm();

	void InitDefaultCommand();

	void ControlGearArmMotor(double speed);
	void SetIdealPosition(Position position);
	void StopGearArmMotor();

	void OverrideSwitch();


	void OpenShoot();
	void CloseShoot();
	bool ShootOpened();
	void Rumble();

	bool Override();
	bool GetHomeSwitch();
	Position GetIdealPosition();

};

#endif
