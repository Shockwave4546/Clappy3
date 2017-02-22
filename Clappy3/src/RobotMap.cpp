#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "WPILib.h"

std::shared_ptr<SpeedController> RobotMap::driveTrainTopLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainTopRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainCenter;

std::shared_ptr<Compressor> RobotMap::gearPCMCompressor;
std::shared_ptr<DoubleSolenoid> RobotMap::gearPCMSolenoid;

std::shared_ptr<SpeedController> RobotMap::gearArmMotor;
std::shared_ptr<Encoder> RobotMap::gearArmEncoder;
std::shared_ptr<DigitalInput> RobotMap::gearArmSwitch;
std::shared_ptr<DoubleSolenoid> RobotMap::gearShootSolenoid;

std::shared_ptr<SpeedController> RobotMap::climbMotor;

void RobotMap::init() {

    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainTopLeft.reset(new VictorSP(0));
    lw->AddActuator("DriveTrain", "TopLeft", std::static_pointer_cast<VictorSP>(driveTrainTopLeft));
    driveTrainTopLeft->StopMotor();

    driveTrainTopRight.reset(new VictorSP(1));
    lw->AddActuator("DriveTrain", "TopRight", std::static_pointer_cast<VictorSP>(driveTrainTopRight));
    driveTrainTopRight->StopMotor();
    
    driveTrainBottomLeft.reset(new VictorSP(2));
    lw->AddActuator("DriveTrain", "BottomLeft", std::static_pointer_cast<VictorSP>(driveTrainBottomLeft));
    driveTrainBottomLeft->StopMotor();
    
    driveTrainBottomRight.reset(new VictorSP(3));
    lw->AddActuator("DriveTrain", "BottomRight", std::static_pointer_cast<VictorSP>(driveTrainBottomRight));
    driveTrainBottomRight->StopMotor();
    
    driveTrainCenter.reset(new VictorSP(4));
    lw->AddActuator("DriveTrain", "Center", std::static_pointer_cast<VictorSP>(driveTrainCenter));
    driveTrainCenter->StopMotor();



    gearPCMCompressor.reset(new Compressor());
    if (gearPCMCompressor != nullptr)
    {
    	lw->AddActuator("GearPCM", "Compressor", gearPCMCompressor);
    	gearPCMCompressor->Start();
    }

    gearPCMSolenoid.reset(new DoubleSolenoid(0, 1));
    if (gearPCMSolenoid != nullptr)
    	lw->AddActuator("GearPCM", "Solenoid", gearPCMSolenoid);



    gearArmMotor.reset(new TalonSRX(5));
    lw->AddActuator("GearArm", "Motor", std::static_pointer_cast<TalonSRX>(gearArmMotor));
    gearArmMotor->StopMotor();

    gearArmEncoder.reset(new Encoder(0, 1, true));
    lw->AddSensor("GearArm", "Encoder", gearArmEncoder);

    gearArmSwitch.reset(new DigitalInput(2));
    lw->AddSensor("GearArm", "HomeSwitch", gearArmSwitch);

    gearShootSolenoid.reset(new DoubleSolenoid(3, 2));
    if (gearShootSolenoid != nullptr)
    	lw->AddActuator("GearArm", "Solenoid", gearShootSolenoid);


    climbMotor.reset(new VictorSP(6));
    lw->AddActuator("Climber", "ClimbMotor", std::static_pointer_cast<VictorSP>(climbMotor));
    climbMotor->StopMotor();



}
