#include <pch.hpp>
#include <Sound/ASound.hpp>

rts::sound::ASound::ASound(::std::shared_ptr<::sf::SoundSource> source)
    : s_isPlaying(false)
    , s_pos(0, 0, 0)
    , s_source(std::move(source))
{
}

rts::sound::ASound::~ASound() = default;

void rts::sound::ASound::play()
{
    s_source->play();
    s_isPlaying = true;
}

void rts::sound::ASound::stop()
{
    s_source->stop();
    s_isPlaying = false;
}

void rts::sound::ASound::pause()
{
    s_source->pause();
    s_isPlaying = false;
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
    -> const ::std::shared_ptr<::sf::SoundSource>&
{
    return s_source;
}

bool ::rts::sound::ASound::isPlaying() const
{
    return s_isPlaying;
}