// INCLUDES
//
#include <random>
#include <vector>
#include <time.h>
#include <SDL2/SDL.h>
#include <algorithm>
#include <fstream>
#include <string.h>

#include "sortAlgorithms.hpp"
#include "sdl2Functions.hpp"
// SINGLE FUNCTIONS
//
bool readFromFile(unsigned int* algorithm,
    unsigned int* numberOfElements,
    unsigned int* windowWidth,
    unsigned int* WindowHeight,
    unsigned int* delayTime,
    char* typeOfVisualization);

// MAIN
//
int main(int argc, char *argv[])
{
    // Variables that are loaded from init_data.txt
    unsigned int algorithm;
    unsigned int numberOfElements;
    unsigned int windowWidth;
    unsigned int windowHeight;
    unsigned int delayTime;
    char typeOfVisualization = ' ';

    if(readFromFile(
        &algorithm, &numberOfElements, &windowWidth, 
        &windowHeight, &delayTime, &typeOfVisualization))
    {
        // Delcarating vector which will be populated with random numbers
        std::vector<int> vectorToSort;
        
        // Populating vector
        srand(time(0));
        for (int i = 0; i < numberOfElements; i++)
            vectorToSort.push_back(10 + (rand() % windowHeight - 10));
        
        
        // Setup window
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Window* window = nullptr; // Identify window pointer
        SDL_Renderer* renderer = nullptr; // Identify render pointer
        SDL_CreateWindowAndRenderer(windowWidth, windowHeight, 0, 
                                    &window, &renderer);
        SDL_RenderSetScale(renderer, 1, 1);

        // Sort
        switch (algorithm)
        {
            case 1:
                bubbleSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 2:
                bucketSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 3:
                countingSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 4:
                gnomeSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;
            
            case 5:
                heapSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 6:
                insertionSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 7:
                mergeSort(
                    vectorToSort, 0, vectorToSort.size()-1, 
                    renderer, windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;  

            case 8:
                quickSort(
                    vectorToSort, 0, vectorToSort.size() - 1,
                    renderer, windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 9:
                radixSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;

            case 10:
                selectionSort(
                    vectorToSort, renderer, 
                    windowWidth, windowHeight, 
                    delayTime, typeOfVisualization);
                break;
        }
        
        // Check if all elements are sorted and visualise it with green color
        if (std::is_sorted(std::begin(vectorToSort), std::end(vectorToSort)))
        {
            for(int i = 0; i < vectorToSort.size(); i++)
            {
                drawFinalState(vectorToSort, renderer, 
                windowWidth, windowHeight, 
                i, typeOfVisualization, 2);
            }
        }
        else printf("ERROR\n");

        // Exit
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        return EXIT_SUCCESS;
    }
    else
    {
        SDL_ShowSimpleMessageBox(
        SDL_MESSAGEBOX_ERROR, 
        "ERROR SETTINGS.TXT", 
        "There was a problem with the settings.txt file. Make sure that such a file exists and that all parameters are correct.", 
        NULL);

        return EXIT_FAILURE;
    }
}

bool readFromFile( unsigned int* algorithm,
    unsigned int* numberOfElements,
    unsigned int* windowWidth,
    unsigned int* windowHeight,
    unsigned int* delayTime,
    char* typeOfVisualization)
{
    // Initialization of the file
    std::fstream initDataFile;
    // Opening file
    initDataFile.open("settings.txt", std::ios::in);
    // Trying to read data from file
    if(initDataFile.is_open())
    {
        // Line - current line of txt file
        // Which choice - which line of choice:
        //  0 - algorithm
        //  1 - resolution
        //  etc...
        // numberString - number entered by the user after "choice" 
        std::string line;
        unsigned int whichChoice = 0;
        std::string numberString = "";

        // Reading file
        while(getline(initDataFile, line))
        {
            // Finding word choice for setting up variables
            //
            // Algorithm
            if (line.substr(0,6) == "Choice" && whichChoice == 0)
            {
                for (char c : line)
                {
                    if ((int)c >= 48 && (int)c <= 57)
                    {
                        numberString.push_back(c);
                    }
                }
                // Check if number is correct
                if(numberString == "") goto terminate;
                *algorithm = std::stoi(numberString);
                ++whichChoice;
            }
            // Resolution
            else if (line.substr(0,6) == "Choice" && whichChoice == 1)
            {
                // allowX variable checks if there is a number before or behind 'x'
                bool allowX = false;
                for (char c : line)
                {
                    if(c == 'x' || c == 'X')
                    {
                        if(numberString == "" || allowX == false) goto terminate;
                        *windowWidth = std::stoi(numberString);
                        numberString = "";
                        continue;
                    }
                    if ((int)c >= 48 && (int)c <= 57)
                    {
                        allowX = true;
                        numberString.push_back(c);
                    }
                }
                // Check if number is correct
                if(numberString == "" || allowX == true) goto terminate;
                *windowHeight = std::stoi(numberString);
                ++whichChoice;
            }
            // Number of elements
            else if (line.substr(0,6) == "Choice" && whichChoice == 2)
            {
                for (char c : line)
                {
                    if ((int)c >= 48 && (int)c <= 57)
                    {
                        numberString.push_back(c);
                    }
                }
                // Check if number is correct
                if (numberString == "") goto terminate;
                *numberOfElements = std::stoi(numberString);
                ++whichChoice;
            }
            // Delay time
            else if (line.substr(0,6) == "Choice" && whichChoice == 3)
            {
                for (char c : line)
                {
                    if ((int)c >= 48 && (int)c <= 57)
                    {
                        numberString.push_back(c);
                    }
                }
                // Check if number is correct
                if(numberString == "") goto terminate;
                *delayTime = std::stoi(numberString);
                ++whichChoice;
            }
            // Type of visualization
            else if (line.substr(0,6) == "Choice" && whichChoice == 4)
            {
                for (char c : line)
                {
                    if (c == 'L' || c == 'l')
                    
                        *typeOfVisualization = 'L';
                    
                    else if (c == 'D' || c == 'd')
                        *typeOfVisualization = 'D';
                    
                }
                // Check if type of visualization is correct
                if(*typeOfVisualization == ' ') goto terminate;
                ++whichChoice;
            }
            numberString = "";
        }
        // Check whether all settings have been entered
        if (whichChoice == 5)
        {
            initDataFile.close();
            return true;
        }
        else goto terminate;
    }
    else
    {
        terminate:
        initDataFile.close();
        return false;
    }
}