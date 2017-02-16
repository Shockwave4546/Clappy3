#include "GearPCM.h"
#include "../RobotMap.h"

GearPCM::GearPCM() : Subsystem("GearPCM") {

	compressor = RobotMap::gearPCMCompressor;
	solenoid = RobotMap::gearPCMSolenoid;

	StartCompressor();

}

void GearPCM::InitDefaultCommand() {

}

void GearPCM::SetGearPCM(PCMStatus status)
{
	if (SolenoidP())
		solenoid->Set(static_cast<bool>(status));
}

bool GearPCM::GetPCMStatus()
{
	if (SolenoidP())
		return solenoid->Get();
	else
		return false;
}

std::string GearPCM::GetPCMStatusS()
{
	if (!SolenoidP())
		return "null";
	else if (solenoid->Get() == static_cast<bool>(PCMStatus::OPENED))
		return "Opened";
	else
		return "Closed";
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
