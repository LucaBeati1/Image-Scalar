#include "raylib.h"
#include "iostream"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Image Scalar");

    Image image = LoadImage("Stein.png");

    Image* newImage = new Image();
    newImage->width = 350;
    newImage->height = 248;
    newImage->format = image.format;
    newImage->mipmaps = 1;
    float factorW = image.width / newImage->width;
    float factorH = image.height / newImage->height;

    unsigned char* dataW = new unsigned char[newImage->width * image.height * 4];

    for (int i = 0; i < newImage->width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            
            int index = (j * image.width + (i * factorW)) * 4 ;
            int index1 = (j * image.width + ((int)((i + 0.25) * factorW))) * 4 ;
            int index2 = (j * image.width + ((int)((i + 0.75) * factorW))) * 4 ;
            int indexO = (j * newImage->width + i) * 4;

            unsigned char r = (((unsigned char*)image.data)[index1] + ((unsigned char*)image.data)[index2]) / 2;
            unsigned char g = (((unsigned char*)image.data)[index1 + 1] + ((unsigned char*)image.data)[index2 + 1]) / 2;
            unsigned char b = (((unsigned char*)image.data)[index1 + 2] + ((unsigned char*)image.data)[index2 + 2]) / 2;
            unsigned char a = (((unsigned char*)image.data)[index1 + 3] + ((unsigned char*)image.data)[index2 + 3]) / 2; 

            dataW[indexO] = r;
            dataW[indexO + 1] = g;
            dataW[indexO + 2] = b;
            dataW[indexO + 3] = a;
        }
        
    }

    unsigned char* data = new unsigned char[newImage->width * newImage->height * 4];

    for (int i = 0; i < newImage->width; i++)
    {
        for (int j = 0; j < newImage->height; j++)
        {
            
            int index = (j * newImage->width * factorH + i) * 4;
            int index1 = (j * newImage->width * factorH + (int)(0.25 * factorH) * newImage->width + i) * 4;
            int index2 = (j * newImage->width * factorH + (int)(0.75 * factorH) * newImage->width + i) * 4;
            int indexO = (j * newImage->width + i) * 4;

            unsigned char r = (((unsigned char*)dataW)[index1] + ((unsigned char*)dataW)[index2]) / 2;
            unsigned char g = (((unsigned char*)dataW)[index1 + 1] + ((unsigned char*)dataW)[index2 + 1]) / 2;
            unsigned char b = (((unsigned char*)dataW)[index1 + 2] + ((unsigned char*)dataW)[index2 + 2]) / 2;
            unsigned char a = (((unsigned char*)dataW)[index1 + 3] + ((unsigned char*)dataW)[index2 + 3]) / 2; 

            data[indexO] = r;
            data[indexO + 1] = g;
            data[indexO + 2] = b;
            data[indexO + 3] = a;
        }
        
    }
    
    newImage->data = data;
    ExportImage(*newImage, "test.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}