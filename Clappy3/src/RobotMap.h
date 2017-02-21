#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

class RobotMap {
public:

	static std::shared_ptr<SpeedController> driveTrainTopLeft;
	static std::shared_ptr<SpeedController> driveTrainTopRight;
	static std::shared_ptr<SpeedController> driveTrainBottomLeft;
	static std::shared_ptr<SpeedController> driveTrainBottomRight;
	static std::shared_ptr<SpeedController> driveTrainCenter;

	static std::shared_ptr<Compressor> gearPCMCompressor;
	static std::shared_ptr<DoubleSolenoid> gearPCMSolenoid;

	static std::shared_ptr<SpeedController> gearArmMotor;
	static std::shared_ptr<Encoder> gearArmEncoder;
	static std::shared_ptr<DigitalInput> gearArmSwitch;
	static std::shared_ptr<DoubleSolenoid> gearShootSolenoid;

	static std::shared_ptr<SpeedController> climbMotor;

	static void init();
};
#endif
