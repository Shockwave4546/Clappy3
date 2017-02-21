#ifndef Climber_H
#define Climber_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Climber : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<SpeedController> climbMotor;

public:
	Climber();
	void InitDefaultCommand();

	void SetMotorSpeed(double speed);
	void StopMotor();
};

#endif  // Climber_H
