#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

enum class RobotError
{
	POINTER_IS_NULL = 5
};

class RobotMap {
public:

	static std::shared_ptr<SpeedController> driveTrainTopLeft;
	static std::shared_ptr<SpeedController> driveTrainTopRight;
	static std::shared_ptr<SpeedController> driveTrainBottomLeft;
	static std::shared_ptr<SpeedController> driveTrainBottomRight;
	static std::shared_ptr<SpeedController> driveTrainCenter;

	static std::shared_ptr<Compressor> gearPCMCompressor;
	static std::shared_ptr<Solenoid> gearPCMSolenoid;

	static std::shared_ptr<SpeedController> gearArmMotor;
	static std::shared_ptr<Encoder> gearArmEncoder;
	static std::shared_ptr<DigitalInput> gearArmSwitch;
	static std::shared_ptr<SpeedController> shootMotor;
	static std::shared_ptr<DigitalInput> shootLowerLimit;
	static std::shared_ptr<DigitalInput> shootUpperLimit;


	static void init();
};
#endif
