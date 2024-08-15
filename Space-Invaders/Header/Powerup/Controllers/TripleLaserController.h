#pragma once
#include"../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class TripleLaserController : public PowerupController
		{
		public:
			TripleLaserController(PowerupType type);
			virtual ~TripleLaserController();

			void applyPowerup()override;

		};
	}
}