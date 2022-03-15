#include <iostream>
#include <fstream>

static const int MAX_SIZE = 50;

int main()
{
    double array[MAX_SIZE][MAX_SIZE];
    std::ifstream inputfile ("output.txt");
    int width, height;
    inputfile >> width;
    inputfile >> height;
    if (width > MAX_SIZE || height > MAX_SIZE)
    {
        std::cout << "Error: width or height more than max size";
        return 1;
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (inputfile.peek() == EOF)
            {
                std::cout << "ERROR: not enough elements in file";
                return 1;
            }
            inputfile >> array[i][j];
        }
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    inputfile.close();
    return 0;
}