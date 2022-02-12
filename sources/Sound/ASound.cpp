#include "pch.hpp"
#include "ASound.hpp"

rts::sound::ASound::ASound(::std::unique_ptr<::sf::SoundSource> source)
    : s_isPlaying(false)
    , s_pos(0, 0, 0)
    , s_source(std::move(source))
{
}

void rts::sound::ASound::play() const
{
    s_source->play();
}

void rts::sound::ASound::stop() const
{
    s_source->stop();
}

void rts::sound::ASound::pause() const
{
    s_source->pause();
}

void rts::sound::ASound::setPosition(float x, float y, float z)
{
    s_source->setPosition(x, y, z);
}

void rts::sound::ASound::setVolume(float volume)
{
    s_source->setVolume(volume);
}

auto rts::sound::ASound::getPosition() const
    -> const ::sf::Vector3f&
{
    return s_pos;
}

auto rts::sound::ASound::getSource() const
    -> const ::std::unique_ptr<::sf::SoundSource>&
{
    return s_source;
}
