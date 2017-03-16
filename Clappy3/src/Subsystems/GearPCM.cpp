#include "GearPCM.h"
#include "../RobotMap.h"


GearPCM::GearPCM() : Subsystem("GearPCM") {

	compressor = RobotMap::gearPCMCompressor;
	solenoid = RobotMap::gearPCMSolenoid;

}

void GearPCM::InitDefaultCommand() {

}

void GearPCM::SetGearPCM(PCMStatus status)
{
	if (SolenoidP())
	{
		if (status == PCMStatus::OPENED)
			solenoid->Set(frc::DoubleSolenoid::Value::kReverse);
		else
			solenoid->Set(frc::DoubleSolenoid::Value::kForward);
	}
}

PCMStatus GearPCM::GetPCMStatus()
{
	if (solenoid->Get() == frc::DoubleSolenoid::Value::kForward)
		return PCMStatus::CLOSED;
	else
		return PCMStatus::OPENED;
}

std::string GearPCM::GetPCMStatusS()
{
	if (SolenoidP())
	{
		if (solenoid->Get() == frc::DoubleSolenoid::Value::kForward)
			return "Opened";
		else if(solenoid->Get() == frc::DoubleSolenoid::Value::kReverse)
			return "Closed";
		else
			return "Off";
	}
	else
		return "null";
}

void GearPCM::StartCompressor()
{
	if (CompressorP())
		compressor->Start();
}

void GearPCM::StopCompressor()
{
	if (CompressorP())
		compressor->Stop();
}

inline bool GearPCM::SolenoidP()
{
	return solenoid != nullptr;
}

inline bool GearPCM::CompressorP()
{
	return compressor != nullptr;
}
