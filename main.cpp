#include <iostream>
#include <random>
#include <stack>
#include <vector>

namespace MazeGenerator {
    struct Cell {
        bool isVisited = true;
        bool walls[4] = {true, true, true, true};
    };

    void build(std::vector<std::vector<Cell>>& maze, int width, int height) {
        std::random_device rd;
        std::mt19937 gen(rd());

        std::stack<std::pair<int, int>> stack;

        int current_x = 0;
        int current_y = 0;

        maze[current_y][current_x].isVisited = true;
        stack.push({current_x, current_y});

        while (!stack.empty()) {
            current_x = stack.top().first;
            current_y = stack.top().second;

            std::vector<std::pair<int, int>> unvisited_neighbors;

            if (current_y > 0 && !maze[current_y - 1][current_x].isVisited) {
                unvisited_neighbors.push_back({current_x, current_y - 1});
            }

            if (current_x < width - 1 && !maze[current_y][current_x + 1].isVisited) {
                unvisited_neighbors.push_back({current_x + 1, current_y});
            }

            if (current_y < height - 1 && !maze[current_y + 1][current_x].isVisited) {
                unvisited_neighbors.push_back({current_x, current_y + 1});
            }

            if (current_x > 0 && !maze[current_y][current_x - 1].isVisited) {
                unvisited_neighbors.push_back({current_x - 1, current_y});
            }

            if (!unvisited_neighbors.empty()) {
                std::uniform_int_distribution<> distrib(0, unvisited_neighbors.size() - 1);
                auto next_coords = unvisited_neighbors[distrib(gen)];

                int next_x = next_coords.first;
                int next_y = next_coords.second;

                if (current_y > next_y) {
                    maze[current_y][current_x].walls[0] = false;
                    maze[next_y][next_x].walls[2] = false;
                } else if (current_y < next_y) {
                    maze[current_y][current_x].walls[2] = false;
                    maze[next_y][next_x].walls[0] = false;
                }

                if (current_x > next_x) {
                    maze[current_y][current_x].walls[3] = false;
                    maze[next_y][next_x].walls[1] = false;
                } else if (current_x < next_x) {
                    maze[current_y][current_x].walls[1] = false;
                    maze[next_y][next_x].walls[3] = false;
                }

                maze[next_y][next_x].isVisited = true;
                stack.push({next_x, next_y});
            } else {
                stack.pop();
            }
        }
    }

    void print(const std::vector<std::vector<Cell>>& maze, int width, int height) {
        for (int x = 0; x < width; ++x) {
            std::cout << "█" << "█";
        }
        std::cout << "█\n";

        for (int y = 0; y < height; ++y) {
            std::cout << "█";

            for (int x = 0; x < width; ++x) {
                std::cout << " ";
                if (maze[y][x].walls[1]) {
                    std::cout << "█";
                } else {
                    std::cout << " ";
                }
            }
            std::cout << "\n";

            std::cout << "█";
            for (int x = 0; x < width; ++x) {
                if (maze[y][x].walls[2]) {
                    std::cout << "█" << "█";
                } else {
                    std::cout << " " << " ";
                }
            }
            std::cout << "\n";
        }
    }
}


int main() {
    const int width = 20;
    const int height = 10;

    std::vector<std::vector<MazeGenerator::Cell>> maze(height, std::vector<MazeGenerator::Cell>(width));
    MazeGenerator::build(maze, width, height);
    MazeGenerator::print(maze, width, height);

    return 0;
}