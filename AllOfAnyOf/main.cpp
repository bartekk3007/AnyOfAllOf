#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm> // std::all_of, std::any_of

class Neighbours
{
public:
    Neighbours(std::initializer_list<int> g0, std::initializer_list<int> gX, std::initializer_list<int> gY) : group0(g0), groupX(gX), groupY(gY)
    {

    }

    std::vector<int> group0;
    std::vector<int> groupX;
    std::vector<int> groupY;
};

bool checkNeighbours(const Neighbours& neighbours, const std::vector<int>& values)
{
    // Sprawdzanie, czy wszystkie elementy group0 s¹ równe 255
    bool allGroup0Equal255 = std::all_of(neighbours.group0.begin(), neighbours.group0.end(), [&values](int index) 
    { 
        return values[index] == 255;
    });

    // Sprawdzanie, czy w groupX wystêpuje co najmniej jeden element ró¿ny od 255
    bool anyGroupXNot255 = std::any_of(neighbours.groupX.begin(), neighbours.groupX.end(), [&values](int index) 
    { 
        return values[index] != 255;
    });

    // Sprawdzanie, czy w groupY wystêpuje co najmniej jeden element ró¿ny od 255
    bool anyGroupYNot255 = std::any_of(neighbours.groupY.begin(), neighbours.groupY.end(), [&values](int index) 
    { 
        return values[index] != 255;
    });

    // Warunki: wszystkie z group0 == 255 i przynajmniej jeden z groupX lub groupY != 255
    return allGroup0Equal255 && anyGroupXNot255 && anyGroupYNot255;
}

int main()
{
    // Przyk³adowe dane
    Neighbours neighbours({0, 1}, {2, 3, 4}, {5, 6, 7});
    std::vector<int> values = {255, 255, 253, 255, 255, 253, 255, 255};

    if (checkNeighbours(neighbours, values)) 
    {
        std::cout << "Tests passed\n";
    } 
    else 
    {
        std::cout << "Tests not passed\n";
    }

    return 0;
}
