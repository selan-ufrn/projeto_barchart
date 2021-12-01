#ifndef BCR_ANIMATION_H
#define BCR_ANIMATION_H

/*!
 *  The Bar Char Race animation manager.
 */

#include <fstream>
#include <thread>
#include <memory>
#include <algorithm>
#include <vector>
using std::vector;
#include <iterator>
#include <sstream>
using std::ostringstream;
#include <numeric>
#include <string>
using std::string;

#include <thread>

#include "../libs/text_color.h"
#include "barchart.h"

namespace bcra {
    //== Helper functions
    std::vector<std::string> split(const std::string & input_str, char delimiter = ' ');

    // TODO: Future feature: read this configuration from a file.
    /// This struct holds some defaults values.
    struct Cfg {
        static constexpr short default_bars = 5;      //!< Default value for # of bars.
        static constexpr short max_bars = 15;         //!< Max number of bars allowed in the animation.
        static constexpr short default_fps = 12;      //!< Default fps.
        static constexpr short max_fps = 45;          //!< Max fps allowed.

        static constexpr short max_bar_length = 50;   //!< Max bar length in characters units.
        static constexpr short n_ticks = 5;           //!< Number of ticks on the X axis.
        static constexpr short height = 30;           //!< How many lines total one screen have.
        static constexpr short width = 60;            //!< How many columns total one screen have.
        static constexpr Color::value_t default_color = Color::GREEN;

        static constexpr short input_label_idx = 1;   //!< Label is located at tokens[1].
        static constexpr short input_value_idx = 3;   //!< Value is located at tokens[3].
        static constexpr short input_date_idx  = 0;   //!< Time is located at tokens[0].
        static constexpr short input_categoy_idx = 4; //!< Category is located at tokens[4].
    };

    /// Class representing an animation manager
    class BCRAnimation {
        private:
            //=== Nested types

            //!< The animation states (Finite State Machine).
            enum class ani_state_e : uint {
                START = 0,   //!< Initial animation state.
                END,         //!< Final animation state.
                ERROR,       //!< Error mode.
                WELCOME,     //!< Initial message.
                READING_INPUT,//!< Reading input file.
                RACING        //!< Displaying bar chart race.
            };

            /// Internal animation options
            struct Options {
                std::string input_filename; //!< Input data file.
                short n_bars;               //!< Requested # of bars per chart.
                short fps;                  //!< Animation speed in frames per second.
            };

            //=== Data members
            Options m_opt;                 //!< Overall options to set up the animation configuration.
            static Cfg m_cfg;              //!< Overall default values for the options and other stuff.
            ani_state_e m_animation_state; //!< Current animation state.
            std::string m_error_msg;       //!< Current error message.

            // TODO: Add your own stuff here

        public:
            BCRAnimation();
            BCRAnimation( const BCRAnimation & _clone) = delete;
            BCRAnimation( BCRAnimation && ) = delete;
            BCRAnimation & operator=( const BCRAnimation & _rhs ) = delete;
            BCRAnimation & operator=( BCRAnimation&& ) = delete;
            ~BCRAnimation() = default;

            //=== Common methods for the animation Loop design pattern.
            void initialize( int, char ** );
            /// Renders the animation to the user.
            void render() const;
            /// Update the animation based on the current animation state.
            void update();
            /// Process user input events, depending on the current animation state.
            void process_events();
            /// Returns true when the user wants to quit the animation.
            bool is_over( void ) const;

        private:
            /// Print out the usage instructions.
            void usage( std::string = std::string{} );

    }; // BCRAnimation class.
}
#endif
