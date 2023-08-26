#include <vector>
#include <SDL2/SDL.h>

// Draw states of current state of vector
//
// Visualization for state when all elements are sorted

void drawFinalState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1,
    char typeOfVisualization,
    unsigned int speed = 10);

void drawBubbleSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization);

void drawBucketSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization);

void drawInsertionSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int speed,
    char typeOfVisualization);

void drawCountingSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int speed,
    char typeOfVisualization);

void drawSelectionSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization);