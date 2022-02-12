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
        explicit ASound(::std::unique_ptr<::sf::SoundSource> source);

        ///////////////////////////////////////////////////////////////////////////
        /// \brief Destructor
        ///
        ///////////////////////////////////////////////////////////////////////////
        virtual ~ASound() {};

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
        virtual void play() const = 0;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief stops the sound
        ///
        ///////////////////////////////////////////////////////////////////////////
        void stop() const;

        ///////////////////////////////////////////////////////////////////////////
        /// \brief pauses the sound
        ///
        ///////////////////////////////////////////////////////////////////////////
        void pause() const;

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
            -> const ::std::unique_ptr<sf::SoundSource>&;

    protected:
        bool s_isPlaying;
        ::sf::Vector3f s_pos;
        ::std::unique_ptr<::sf::SoundSource> s_source;
};
}