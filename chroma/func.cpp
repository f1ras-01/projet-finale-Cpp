#include <vector>
#include <ctime>
#include <SFML/Graphics.hpp>
#include <utility> // For std::move

#include "global.h"

// Function to remove the first sf::RectangleShape with the same position as toRemove
void removeRectangle(std::vector<sf::RectangleShape>& vec, const sf::RectangleShape& toRemove)
{
    for (size_t i = 0; i < vec.size(); ++i) {
        // Compare based on position (adjust criteria as needed)
        if (vec[i].getPosition() == toRemove.getPosition()) {
            // Shift all subsequent elements left
            for (size_t j = i; j < vec.size() - 1; ++j) {
                vec[j] = std::move(vec[j + 1]);
            }
            vec.pop_back(); // Remove the last element
            break; // Remove only the first occurrence
        }
    }
}

void bombsplaced(std::vector<sf::RectangleShape>& bombs, std::vector<sf::RectangleShape>& placements, sf::Texture& bombT)
{
    int s = 0;
    for (auto& place : placements)
    {
        if (place.getTexture() == &bombT)
            s += 1;
    }
    if (bombs.empty() && s == placements.size())
    {
        bombsPlaced = true;

    }
}
