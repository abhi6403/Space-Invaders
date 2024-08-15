#pragma once
#include"../../Header/Powerup/PowerupController.h"

namespace Powerup
{
	namespace Controller
	{
		class RapidFireController :public PowerupController
		{
		public:
			RapidFireController(PowerupType type);
			virtual ~RapidFireController();

			void applyPowerup()override;
		};
	}
}
