#pragma once

#include <string>
#include <memory>
#include <SFML/Audio.hpp>

namespace rts::sound {

class ASound {
    public:
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        // *structors
        //
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Constructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        explicit ASound(::std::shared_ptr<::sf::SoundSource> source);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        virtual ~ASound();

        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////
        // Basics
        //
        ///////////////////////////////////////////////////////////////////////////////////////////////
        ///////////////////////////////////////////////////////////////////////////////////////////////

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Plays the sound
        ///
        ///////////////////////////////////////////////////////////////////////////
        void play();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief stops the sound
        ///
        ///////////////////////////////////////////////////////////////////////////
        void stop();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief pauses the sound
        ///
        ///////////////////////////////////////////////////////////////////////////
        void pause();

        ///////////////////////////////////////////////////////////////////////////
        /// \brief sets the sound-s position
        ///
        ///////////////////////////////////////////////////////////////////////////
        void setPosition(
            float x,
            float y,
            float z = -1);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief sets the sound's volume
        ///
        ///////////////////////////////////////////////////////////////////////////
        void setVolume(float vol);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Gets the sound's position.
        ///
        ///////////////////////////////////////////////////////////////////////////
        [[nodiscard]] auto getPosition() const
            -> const ::sf::Vector3f&;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Gets the sound's source.
        ///
        ///////////////////////////////////////////////////////////////////////////
        [[nodiscard]] auto getSource() const
            -> const ::std::shared_ptr<sf::SoundSource>&;

        bool isPlaying() const;

    protected:
        ///////////////////////////////////////////////////////////////////////////
        /// \brief true if sound is played, false otherwise.
        ///
        ///////////////////////////////////////////////////////////////////////////
        bool s_isPlaying;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Sound's position.
        ///
        ///////////////////////////////////////////////////////////////////////////
        ::sf::Vector3f s_pos;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief sound's source (sf::Sound or sf::Music)
        ///
        ///////////////////////////////////////////////////////////////////////////
        ::std::shared_ptr<::sf::SoundSource> s_source;
};
}