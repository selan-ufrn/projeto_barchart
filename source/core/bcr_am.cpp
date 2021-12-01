#include <algorithm>
using std::transform;
#include <string>
using std::string;
#include <sstream>
using std::istringstream;

#include "bcr_am.h"
#include "../libs/coms.h"


namespace bcra {
    // Instantiation of the global configuration variable.
    const Cfg global_cfg;

    auto STR_LOWERCASE = [](const char * t)->std::string{
        std::string str{ t };
        std::transform( str.begin(), str.end(), str.begin(), ::tolower );
        return str;
    };

    /// Lambda expression that transform the string to lowercase.
    auto STR_UPPERCASE = [](const std::string & s )->std::string{
        std::string str{ s };
        std::transform( str.begin(), str.end(), str.begin(), ::toupper );
        return str;
    };

    /// Tokenize a string
    /*!
     * @param input_str The input string.
     * @param delimiter The delimiter symbol.
     * @return A list of tokenized strings.
     */
    std::vector<std::string> split(const std::string & input_str, char delimiter){
        // Store the tokens.
        std::vector<std::string> tokens;

        // read file line by line
        std::istringstream iss;
        iss.str(input_str);
        std::string token;
        while ( std::getline( iss >> std::ws, token, delimiter ) )
            tokens.push_back( token );

        return tokens;
    }

    BCRAnimation::BCRAnimation(){
        m_opt.input_filename = "";
        m_opt.fps            = global_cfg.default_fps;
        m_opt.n_bars         = global_cfg.default_bars;
    }

    /// Initializes the animation engine.
    void BCRAnimation::initialize( int argc, char ** argv ){
        // TODO: Process CLI here.

        // Set the initial animation state.
        m_animation_state = ani_state_e::START;
    }
    bool BCRAnimation::is_over(void) const{
        return m_animation_state == ani_state_e::END;
    }

    void BCRAnimation::process_events(){
        // TODO
    }

    void BCRAnimation::update(){
        // TODO
    }

    void BCRAnimation::render(void) const{
        // TODO
    }
};
