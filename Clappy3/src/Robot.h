#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/GearPCM.h"
#include "Subsystems/GearArm.h"
#include "OI.h"
#include "Subsystems/Climber.h"
#include <networktables/NetworkTable.h>

#include "Commands/AutonomousCommand.h"

class Robot : public IterativeRobot {
public:
	std::unique_ptr<Command> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

    static std::shared_ptr<DriveTrain> driveTrain;
    static std::shared_ptr<GearPCM> gearPCM;
    static std::shared_ptr<GearArm> gearArm;
    static std::shared_ptr<Climber> climber;



	virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();

	void ChangeCamera();

private:
    std::shared_ptr<cs::UsbCamera> cam0;
    std::shared_ptr<cs::UsbCamera> cam1;
    cs::UsbCamera gearCam;
    cs::UsbCamera backCam;
    std::shared_ptr<cs::MjpegServer> mjpegServer;
};
#endif
