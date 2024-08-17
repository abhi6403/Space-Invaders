#include"../../Header/Sound/SoundService.h"
#include"../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
			printf("error loading background music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("error loading background music file");
		else
			if (!buffer_explosion_sound.loadFromFile(Config::explosion_sound_path))
				printf("error loading bakground music file");
			else
				if (!buffer_powerup_enabled.loadFromFile(Config::powerup_enabled_sound_path))
					printf("error loading powerup music file");
				else
					if (!buffer_powerup_disabled.loadFromFile(Config::powerup_disabled_sound_path))
						printf("error loading powerup music file");
					else
						if (!buffer_bullet_fire.loadFromFile(Config::bulletfire_sound_path))
							printf("error loading bulletfire music file");
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			sound_effect.play();
			break;

		case SoundType::EXPLOSION:
			sound_effect.setBuffer(buffer_explosion_sound);
			sound_effect.play();
			break;

		case SoundType::POWERUP_ENABLED:
			sound_effect.setBuffer(buffer_powerup_enabled);
			sound_effect.play();
			break;

		case SoundType::POWERUP_DISABLED:
			sound_effect.setBuffer(buffer_powerup_disabled);
			sound_effect.play();
			break;

		case SoundType::BULLET_FIRE:
			sound_effect.setBuffer(buffer_bullet_fire);
			sound_effect.play();
			break;

		default:
			printf("invaild sound type");
			return;
		}

		
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
}