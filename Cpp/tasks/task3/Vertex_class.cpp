#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

class Vertex {
private:
    int x;
    int y;

public:
    void setRandom() {
        x = (std::rand() % 201) - 100;
        y = (std::rand() % 201) - 100;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    std::string toString() const {
        return "Vertex: (" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
};

int main() {
    std::srand(std::time(0));
    Vertex vertices[5];
    for (int i = 0; i < 5; ++i) {
        vertices[i].setRandom();
    }
    for (int i = 0; i < 5; ++i) {
        std::cout << vertices[i].toString() << "\n";
    }
    return 0;
}
