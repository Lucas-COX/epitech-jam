#include <pch.hpp>
#include <Sound/Sound.hpp>

rts::sound::Sound::Sound(::std::unique_ptr<::sf::SoundSource> source)
    : ASound(::std::move(source))
{
}
