#pragma once
#include"SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		EXPLOSION,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
		BULLET_FIRE,
	};

	class SoundService
	{
	private:
		const int background_music_volume = 30;

		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer buffer_button_click;
		sf::SoundBuffer buffer_explosion_sound;
		sf::SoundBuffer buffer_powerup_enabled;
		sf::SoundBuffer buffer_powerup_disabled;
		sf::SoundBuffer buffer_bullet_fire;


		void loadBackgroundMusicFromFile();
		void loadSoundFromFile();

	public:
		void initialize();

		void playSound(SoundType soundType);
		void playBackgroundMusic();
	};
}