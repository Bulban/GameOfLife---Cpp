#include "view.hpp"
#include "engine.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <sys/_types/_u_int32_t.h>
#include <unordered_map>
#include <utility>

void View::drawGrid() {
  const float numberColumns{m_screenWidth / m_squareSize};
  const float numberRows{m_screenHeight / m_squareSize};

  for (int i = 0; i < numberColumns; ++i) {
    for (int j = 0; j < numberRows; ++j) {
      sf::RectangleShape gridCell;
      gridCell.setSize(sf::Vector2f(m_squareSize, m_squareSize));
      gridCell.setOutlineColor(sf::Color::Blue);
      gridCell.setOutlineThickness(1);
      gridCell.setPosition({m_squareSize * j, m_squareSize * i});
      gridCell.setFillColor(sf::Color::Transparent);
      m_window.draw(gridCell);
    }
  }
}

void View::drawCells(
    const std::unordered_map<std::pair<int, int>, bool, pair_hash> &grid) {

  for (const auto &cell : grid) {
    sf::RectangleShape square;
    square.setSize(sf::Vector2f(m_squareSize, m_squareSize));
    square.setFillColor(sf::Color::White);

    square.setPosition({static_cast<float>(cell.first.first * m_squareSize),
                        static_cast<float>(cell.first.second * m_squareSize)});
    m_window.draw(square);
  }
}

View::View()
    : m_screenHeight(800), m_screenWidth(600), m_open(true), m_engine(),
      m_squareSize(50),
      m_window(sf::VideoMode({static_cast<u_int32_t>(m_screenHeight),
                              static_cast<u_int32_t>(m_screenWidth)}),
               "Game Of Life") {

  while (m_window.isOpen()) {

    while (const std::optional event = m_window.pollEvent()) {

      if (event->is<sf::Event::Closed>()) {

        m_window.close();
        m_open = false;

      } else if (const auto *keyPressed =
                     event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scan::Space) {

          m_engine.setPause();
        }
      } else if (const auto *mouseButtonPressed =
                     event->getIf<sf::Event::MouseButtonPressed>()) {

        if (mouseButtonPressed->button == sf::Mouse::Button::Left) {
            std::cout << mouseButtonPressed->position.x << " " << mouseButtonPressed->position.y << std::endl;

            int x_value {static_cast<int>(mouseButtonPressed->position.x / m_squareSize)};
            int y_value {static_cast<int>(mouseButtonPressed->position.y / m_squareSize)};

          m_engine.addCell(x_value, y_value);
        } else if (mouseButtonPressed->button == sf::Mouse::Button::Right) {

          m_engine.removeCell(mouseButtonPressed->position.x,
                              mouseButtonPressed->position.y);
        }
      }
    }

    m_window.clear();

    drawCells(m_engine.getCells());

    drawGrid();

    m_window.display();
  }
}
