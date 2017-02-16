#ifndef GearPCM_H
#define GearPCM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include <string>

enum class PCMStatus
{
	OPENED,
	CLOSED
};

/**
 *
 *
 * @author Garrick Craft
 */
class GearPCM : public Subsystem {
private:

	std::shared_ptr<Compressor> compressor;
	std::shared_ptr<Solenoid> solenoid;

	inline bool SolenoidP();
	inline bool CompressorP();

public:
	GearPCM();
	void InitDefaultCommand();

	void SetGearPCM(PCMStatus status);

	bool GetPCMStatus();

	std::string GetPCMStatusS();

	void StartCompressor();

	void StopCompressor();
};

#endif
