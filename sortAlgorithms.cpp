#include <algorithm>
#include <vector>
#include <SDL2/SDL.h>
#include <iostream>

#include "sdl2Functions.hpp"

void bubbleSort(
    std::vector<int>& vectorToSort,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    for (int i = 0; i < vectorToSort.size(); i++)
    {
        for (int j = 0; j < vectorToSort.size() - i - 1; j++)
        {
            if(vectorToSort[j] > vectorToSort[j+1])
            {
                std::swap(vectorToSort[j], vectorToSort[j+1]);
                drawBubbleSortState(
                vectorToSort, renderer,
                windowWidth, windowHeight,
                j+1, j, vectorToSort.size() - i,
                speed, typeOfVisualization);
            }
            else
            {
            drawBubbleSortState(
                vectorToSort, renderer,
                windowWidth, windowHeight,
                j, j+1, vectorToSort.size() - i, 
                speed, typeOfVisualization);
            }
        }
    }
}

void insertionSort(
    std::vector<int>& vector, 
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    for (unsigned int i = 1; i < vector.size(); i++)
    {
        unsigned int j = i;
        while(j > 0 && vector[j-1] > vector[j])
        {
            std::swap(vector[j-1], vector[j]);
            j--;
            drawInsertionSortState(
                vector, renderer, 
                windowWidth, windowHeight,
                i, j, speed, typeOfVisualization);
        }   
    }
}

void bucketSort(
    std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    int max = 0, min = INT32_MAX, numberOfBuckets = 10;
    
    for (int i = 0; i < vector.size(); i++) 
    {
        if (vector[i] > max) max = vector[i];
        if (vector[i] < min) min = vector[i];
    }
    
    int range = (max - min) / numberOfBuckets + 1;

    // Create the bucket as a vector of vectors
    std::vector<std::vector<int>> bucket(numberOfBuckets);

    // Fill the buckets
    for (int i = 0; i < vector.size(); i++) 
    {
        int bucketIndex = (vector[i] - min) / range;
        bucket[bucketIndex].push_back(vector[i]);
    }
    // Visualize buckets
    int index = 0;
    for (int i = 0; i < numberOfBuckets; i++)
    {
        for (int j = 0; j < bucket[i].size(); j++)
        {
            vector[index] = bucket[i][j];
            int bucketIndex = (vector[i] - min) / range;
            drawInsertionSortState(
                vector, renderer,
                windowWidth, windowHeight,
                index, bucketIndex,
                speed, typeOfVisualization);
            ++index;
        }
    }
    // Sort buckets
    insertionSort(
        vector, renderer,
        windowWidth, windowHeight,
        0, typeOfVisualization);
}

void countingSort(
    std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    int vectorSize = vector.size();
    // Range of the unique elements
    int range = -1;
    for(int i = 0; i < vectorSize; i++)
    {
        if (vector[i] > range) range = vector[i];
    }
    ++range;
    int* rangeArray = new int[range]();
    // Occurrence of a unique number
    for (int i = 0; i < vectorSize; i++)
    {
        ++rangeArray[vector[i]];
    }
    // Prefix sum
    for (int i = 1; i < range; i++)
    {
        rangeArray[i] += rangeArray[i-1];
    }
    // Sorting
    int* buffer = new int[vectorSize]();
    for (int i = vectorSize-1; i >= 0; i--)
    {
        buffer[(rangeArray[vector[i]])-1] = vector[i];
        --rangeArray[vector[i]];
    }
    // Chaning vector to sorted
    for (int i = 0; i < vectorSize; i++)
    {
        vector[i] = buffer[i];
        drawCountingSortState(
            vector, renderer,
            windowWidth, windowHeight,
            i, i, speed, typeOfVisualization);
    }

    delete[] buffer;
    delete[] rangeArray;
}

void gnomeSort(
    std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    unsigned int i = 0;
    unsigned int j = 0;
    while (i < vector.size())
    {
        if (i == 0) i++;
        if (vector[i] >= vector[i - 1]) i++;
        else
        {
            std::swap(vector[i], vector[i - 1]);
            i--;
        }
        if (i > j) j = i;
        
        drawInsertionSortState(
            vector, renderer, 
            windowWidth, windowHeight, 
            j, i, speed, typeOfVisualization);
    }
}

//
// HEAP SORT
void heapify(
    std::vector<int>& vector, int n, int i,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    int maxIndex = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && vector[l] > vector[maxIndex])
    {
        maxIndex = l;
    }
    if (r < n && vector[r] > vector[maxIndex])
    {
        maxIndex = r;
    }
    if (maxIndex != i)
    {
        std::swap(vector[i], vector[maxIndex]);
        heapify(
            vector, n, maxIndex, renderer,
            windowWidth, windowHeight,
            speed, typeOfVisualization);
    }

    drawInsertionSortState(
            vector, renderer, 
            windowWidth, windowHeight,
            l, r, speed, typeOfVisualization);
}

void heapSort(
    std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    int n = vector.size();
    
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(
            vector, n, i, renderer,
            windowWidth, windowHeight,
            speed, typeOfVisualization);
    }

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(vector[0], vector[i]);
        heapify(vector, i, 0, renderer,
            windowWidth, windowHeight,
            speed, typeOfVisualization);
    }
}
// END OF HEAP SORT
//

// MERGE SORT
//
void merge(
    std::vector<int>& vector, int l, int m, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization) 
{
    int i = l;
    int j = m + 1;
    int k = l;

    std::vector<int> temp(vector.size(), 0);

    while (i <= m && j <= r) 
    {
        if (vector[i] <= vector[j]) 
        {
            temp[k] = vector[i];
            i++;
        } 
        else 
        {
            temp[k] = vector[j];
            j++;
        }
        k++;
    }

    while (i <= m) 
    {
        temp[k] = vector[i];
        i++;
        k++;
    }
    while (j <= r) 
    {
        temp[k] = vector[j];
        j++;
        k++;
    }

    for (int s = l; s <= r; s++) 
    {
        vector[s] = temp[s];
        drawInsertionSortState(
            vector, renderer,
            windowWidth, windowHeight,
            0, 0, speed, typeOfVisualization);
    }
}

void mergeSort(
    std::vector<int>& vector, int l, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization) 
{
    if (l < r) 
    {
        int m = l + (r - l) / 2;

        mergeSort(
            vector, l, m,
            renderer, windowWidth, windowHeight,
            speed, typeOfVisualization);

        mergeSort(
            vector, m + 1, r,
            renderer, windowWidth, windowHeight,
            speed, typeOfVisualization);

        merge(
            vector, l, m, r,
            renderer, windowWidth, windowHeight,
            speed, typeOfVisualization);
    }
}
// END OF MERGE SORT
//

void quickSort(
    std::vector<int>& vector, int l, int r,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    if (l >= r) return;

    int p = l;
    int q = r;
    int pivot = vector[(l + r) / 2];

    while (p <= q) {
        while (vector[p] < pivot) p++;
        while (vector[q] > pivot) q--;
        if (p <= q) 
        {
            std::swap(vector[p], vector[q]);
            p++;
            q--;
        }
    }
    drawInsertionSortState(
        vector, renderer,
        windowWidth, windowHeight,
        p, q, speed, typeOfVisualization);

    quickSort(
        vector, l, q,
        renderer, windowWidth, windowHeight,
        speed, typeOfVisualization);
    
    quickSort(
        vector, p, r,
        renderer, windowWidth, windowHeight,
        speed, typeOfVisualization);
}

//
// RADIX SORT + CUSTOM COUNTING SORT
void countingSort(
    std::vector<int>& vector, int exp,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization) 
{
    int n = vector.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);

    for (int i = 0; i < n; i++) {
        count[(vector[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(vector[i] / exp) % 10] - 1] = vector[i];
        count[(vector[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        vector[i] = output[i];
        drawInsertionSortState(
            vector, renderer,
            windowWidth, windowHeight,
            0, 0, speed, typeOfVisualization);
    }
}

int getMaxValue(std::vector<int>& vector) 
{
    int maxVal = vector[0];
    for (int num : vector) {
        if (num > maxVal) {
            maxVal = num;
        }
    }
    return maxVal;
}

void radixSort(std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization) 
{
    int maxVal = getMaxValue(vector);

    for (int exp = 1; maxVal / exp > 0; exp *= 10) 
    {
        countingSort(
            vector, exp, renderer,
            windowWidth, windowHeight,
            speed, typeOfVisualization);

        drawInsertionSortState(
            vector, renderer,
            windowWidth, windowHeight,
            exp, 0, speed, typeOfVisualization);
    }
}
//
// END OF RADIX SORT

void selectionSort(std::vector<int>& vector,
    SDL_Renderer* renderer,
    unsigned int windowWidth,
    unsigned int windowHeight,
    unsigned int speed,
    char typeOfVisualization)
{
    for (int i = 0; i < vector.size() - 1; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < vector.size(); j++)
        {
            if (vector[j] < vector[minPos])
            {
                minPos = j;
            }
            drawSelectionSortState(
            vector, renderer, 
            windowWidth, windowHeight, 
            j, minPos, i, speed, typeOfVisualization);
        }
        if (minPos != i) std::swap(vector[i], vector[minPos]);
    }
}