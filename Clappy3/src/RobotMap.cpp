#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "WPILib.h"

std::shared_ptr<SpeedController> RobotMap::driveTrainTopLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainTopRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomLeft;
std::shared_ptr<SpeedController> RobotMap::driveTrainBottomRight;
std::shared_ptr<SpeedController> RobotMap::driveTrainCenter;

std::shared_ptr<Compressor> RobotMap::gearPCMCompressor;
std::shared_ptr<Solenoid> RobotMap::gearPCMSolenoid;

std::shared_ptr<SpeedController> RobotMap::gearArmMotor;
std::shared_ptr<Encoder> RobotMap::gearArmEncoder;
std::shared_ptr<DigitalInput> RobotMap::gearArmSwitch;
std::shared_ptr<SpeedController> RobotMap::shootMotor;
std::shared_ptr<DigitalInput> RobotMap::shootLowerLimit;
std::shared_ptr<DigitalInput> RobotMap::shootUpperLimit;

void RobotMap::init() {

    LiveWindow *lw = LiveWindow::GetInstance();

    driveTrainTopLeft.reset(new TalonSRX(0));
    lw->AddActuator("DriveTrain", "TopLeft", std::static_pointer_cast<TalonSRX>(driveTrainTopLeft));

    driveTrainTopRight.reset(new TalonSRX(1));
    lw->AddActuator("DriveTrain", "TopRight", std::static_pointer_cast<TalonSRX>(driveTrainTopRight));
    
    driveTrainBottomLeft.reset(new TalonSRX(2));
    lw->AddActuator("DriveTrain", "BottomLeft", std::static_pointer_cast<TalonSRX>(driveTrainBottomLeft));
    
    driveTrainBottomRight.reset(new TalonSRX(3));
    lw->AddActuator("DriveTrain", "BottomRight", std::static_pointer_cast<TalonSRX>(driveTrainBottomRight));
    
    driveTrainCenter.reset(new TalonSRX(4));
    lw->AddActuator("DriveTrain", "Center", std::static_pointer_cast<TalonSRX>(driveTrainCenter));



    gearPCMCompressor.reset(new Compressor());
    lw->AddActuator("GearPCM", "Compressor", std::static_pointer_cast<Compressor>(gearPCMCompressor));

    gearPCMSolenoid.reset(new Solenoid(0));
    lw->AddActuator("GearPCM", "Solenoid", std::static_pointer_cast<Solenoid>(gearPCMSolenoid));



    gearArmMotor.reset(new TalonSRX(5));
    lw->AddActuator("GearArm", "Motor", std::static_pointer_cast<TalonSRX>(gearArmMotor));

    gearArmEncoder.reset(new Encoder(0, 1, true));
    lw->AddSensor("GearArm", "Encoder", std::static_pointer_cast<Encoder>(gearArmEncoder));

    gearArmSwitch.reset(new DigitalInput(2));
    lw->AddSensor("GearArm", "HomeSwitch", std::static_pointer_cast<DigitalInput>(gearArmSwitch));

    shootMotor.reset(new TalonSRX(6));
    lw->AddActuator("GearArm", "ShootMotor", std::static_pointer_cast<TalonSRX>(shootMotor));

    shootLowerLimit.reset(new DigitalInput(3));
    lw->AddSensor("GearArm", "LowerLimit", std::static_pointer_cast<DigitalInput>(shootLowerLimit));

    shootUpperLimit.reset(new DigitalInput(4));
    lw->AddSensor("GearArm", "UpperLimit", std::static_pointer_cast<DigitalInput>(shootUpperLimit));



}
