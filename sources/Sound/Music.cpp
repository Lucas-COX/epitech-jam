#include "pch.hpp"
#include "Music.hpp"

rts::sound::Music::Music(::std::unique_ptr<::sf::SoundSource> source, bool loop)
    : ASound(::std::move(source))
    , s_isLoop(loop)
{
    static_cast<::sf::Music*>(s_source.get())->setLoop(loop);
}

void rts::sound::Music::Music::setLoop(bool loop)
{
    s_isLoop = loop;
    static_cast<::sf::Music*>(s_source.get())->setLoop(loop);
}
