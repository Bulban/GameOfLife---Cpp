#pragma once

#include "engine.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Window.hpp>
#include <sys/_types/_u_int32_t.h>
#include <utility>

class View {
    private:

        const float m_screenWidth;
        const float m_screenHeight;
        sf::RenderWindow m_window;
        Engine m_engine;
        const float m_squareSize;

        void drawGrid();
        void drawCells(const std::unordered_map<std::pair<int, int>, bool, pair_hash>&);

    public:

        bool m_open;

        View();

};
