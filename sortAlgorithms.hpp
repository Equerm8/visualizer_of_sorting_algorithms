#include <vector>
#include <SDL2/SDL.h>

void bubbleSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void bucketSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void countingSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void gnomeSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void heapify(
    std::vector<int>& vector, int n, int i,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void heapSort(
    std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void insertionSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void merge(
    std::vector<int>& vector, int l, int m, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void mergeSort(
    std::vector<int>& vector, int l, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void quickSort(
    std::vector<int>& vector, int l, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void countingSort(
    std::vector<int>& vector, int exp,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

int getMaxValue(std::vector<int>& vector);

void radixSort(std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);

void selectionSort(std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization);