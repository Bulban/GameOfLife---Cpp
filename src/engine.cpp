#include "engine.hpp"
#include <tuple>
#include <unordered_map>
#include <utility>

Engine::Engine() : pause{true}, grid() {}

void Engine::update() {
  // update logic
  if (pause)
    return;
}

//bool Engine::checkNeighour() {
//  // neighbor check logic
//}

const std::unordered_map<std::pair<int, int>, bool, pair_hash>&
Engine::getCells() const {
  return grid;
}

void Engine::addCell(int x, int y) { grid[std::pair<int, int>{x, y}] = true; }

void Engine::removeCell(int x, int y) { grid.erase({x, y}); }

void Engine::setPause() {
  if (pause)
    pause = false;
  else
    pause = true;
}
