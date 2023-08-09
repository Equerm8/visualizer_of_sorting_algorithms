#include <vector>
#include <SDl2/SDL.h>

#include "sdl2Functions.hpp"
//
// Visualization for state when all elements are sorted
void drawFinalState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1,
    char typeOfVisualization,
    unsigned int speed)
{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if (i <= color1)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        // Lines
        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }

    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}

void drawBubbleSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization)
{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if(i == color1)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        else if(i == color2)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        
        else if(i >= color3)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }
    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}

void drawBucketSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization)
{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if(i == color1)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        else if(i == color2)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        
        else if(i >= color3)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }
    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}

void drawInsertionSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1,
    unsigned int color2,
    unsigned int speed,
    char typeOfVisualization)
{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if(i == color1)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        else if(i == color2)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }
    
    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}

void drawCountingSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1,
    unsigned int color2,
    unsigned int speed,
    char typeOfVisualization)
{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if(i == color1)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        else if(i <= color2)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }
    
    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}

void drawSelectionSortState(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int color1, 
    unsigned int color2,
    unsigned int color3,
    unsigned int speed,
    char typeOfVisualization)

{
    unsigned int width = windowWidth / vector.size();

    // Clear window
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < vector.size(); i++)
    {
        if(i == color1)
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        
        else if(i == color2)
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
        
        else if(i < color3)
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

        else
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        if (typeOfVisualization == 'L')
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight);
        }
        // Dots
        else
        {
            SDL_RenderDrawLine(
                renderer, 
                i*width, 
                windowHeight-vector[i], 
                i*width, 
                windowHeight-vector[i]);
        }
    }
    
    // Show to window
    SDL_RenderPresent(renderer);
    // Slow down visualization
    SDL_Delay(speed);
}