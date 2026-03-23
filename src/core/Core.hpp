#ifndef ARCADE_CORE_HPP_
#define ARCADE_CORE_HPP_

#include <vector>
#include <string>
#include "../../include/IDisplayModule.hpp"
#include "../../include/IGameModule.hpp"
#include "../../include/Types.hpp"
#include "../DLLoader.hpp"

namespace Arcade {

    class Core {
    public:
        Core(const std::string &initialGraphicsLib);
        ~Core();
        void run();

    private:
        void scanLibraries();
        void loadGraphics(std::size_t index);
        void loadGame(std::size_t index);
        void unloadGraphics();
        void unloadGame();
        void menuLoop();
        void gameLoop();
        void handleSystemKeys(Key key);
        RenderData buildMenuRenderData() const;
        void loadScores();
        void saveScore(const std::string &playerName,
                       const std::string &gameName, int score);

        enum class State { MENU, GAME, QUIT };
        State _state;
        std::string _playerName;
        int _menuSelection;

        std::vector<std::string> _graphicsLibPaths;
        std::vector<std::string> _gameLibPaths;
        std::size_t _currentGraphicsIdx;
        std::size_t _currentGameIdx;
        std::string _initialGraphicsLib;

        DLLoader<IDisplayModule> *_displayLoader;
        DLLoader<IGameModule> *_gameLoader;
        IDisplayModule *_display;
        IGameModule *_game;

        std::vector<ScoreEntry> _scores;
    };

}

#endif
