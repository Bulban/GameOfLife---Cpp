#pragma once

#include <unordered_map>
#include <utility>
#include <vector>

struct pair_hash {
    std::size_t operator()(const std::pair<int, int>& p) const noexcept {
        return std::hash<int>()(p.first) ^ (std::hash<int>()(p.second) << 1);
    }
};

class Engine{
    
    private:

    std::unordered_map<std::pair<int, int>, bool, pair_hash> grid;
    bool pause;

    void update();
    bool checkNeighour(int, int);

    public:

    const std::unordered_map<std::pair<int, int>, bool, pair_hash>& getCells() const;

    void setPause();
    void addCell(int, int);
    void removeCell(int, int);
        
    Engine(); 
};
