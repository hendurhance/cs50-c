#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // variable to store the grayscale value
    float rgbaGray; 
    
    // loop through the rows
    for (int i = 0; i < height; i++) 
    {
        // loop through the columns
        for (int j = 0; j < width; j++) 
        {
            // calculate the grayscale value
            rgbaGray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0); 
            // set the red value to the grayscale value
            image[i][j].rgbtRed = rgbaGray; 
            // set the green value to the grayscale value
            image[i][j].rgbtGreen = rgbaGray; 
            // set the blue value to the grayscale value
            image[i][j].rgbtBlue = rgbaGray; 
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{   
    // variable to store the sepia red value
    float sepiaRed; 
    // variable to store the sepia green value
    float sepiaGreen; 
    // variable to store the sepia blue value
    float sepiaBlue; 

    // loop through the rows
    for (int i = 0; i < height; i++)
    {
        // loop through the columns
        for (int j = 0; j < width; j++)
        {
            // calculate the sepia red value
            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            // calculate the sepia green value
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            // calculate the sepia blue value
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            // check if the sepia red value is greater than 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            // check if the sepia green value is greater than 255
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // check if the sepia blue value is greater than 255
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // set the sepia red value to the image
            image[i][j].rgbtRed = sepiaRed;
            // set the sepia green value to the image
            image[i][j].rgbtGreen = sepiaGreen;
            // set the sepia blue value to the image
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{   
    // variable to store the temporary pixel
    int temp[3];

    // loop through the rows
    for (int i = 0; i < height; i++)
    {
        // loop through the columns
        for (int j = 0; j < width / 2; j++)
        {   
            // store the temporary pixel
            // store the red value
            temp[0] = image[i][j].rgbtRed; 
            // store the green value
            temp[1] = image[i][j].rgbtGreen;
            // store the blue value
            temp[2] = image[i][j].rgbtBlue;

            // set the red value to the pixel on the other side of the image
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            // set the green value to the pixel on the other side of the image
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            // set the blue value to the pixel on the other side of the image
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // set the red value to the temporary pixel
            image[i][width - j - 1].rgbtRed = temp[0];
            // set the green value to the temporary pixel
            image[i][width - j - 1].rgbtGreen = temp[1];
            // set the blue value to the temporary pixel
            image[i][width - j - 1].rgbtBlue = temp[2];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{   
    // variable to store the temporary pixel
    // variable to store the sum of the red values
    float sumRed; 
    // variable to store the sum of the green values
    float sumGreen;
    // variable to store the sum of the blue values
    float sumBlue;
    // variable to store the number of pixels
    int count;

    // create a temporary image
    RGBTRIPLE temp[height][width]; 

    // loop through the rows
    for (int i = 0; i < height; i++)
    {
        // loop through the columns
        for (int j = 0; j < width; j++)
        {   
            // reset the sum of the red values
            sumRed = 0; 
            // reset the sum of the green values
            sumGreen = 0;
            // reset the sum of the blue values
            sumBlue = 0;
            // reset the number of pixels
            count = 0;

            // loop through the rows
            for (int k = -1; k < 2; k++)
            {
                // loop through the columns
                for (int l = -1; l < 2; l++)
                {
                    // check if the pixel is within the image
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width)
                    {
                        // add the red value to the sum of the red values
                        sumRed += image[i + k][j + l].rgbtRed;
                        // add the green value to the sum of the green values
                        sumGreen += image[i + k][j + l].rgbtGreen;
                        // add the blue value to the sum of the blue values
                        sumBlue += image[i + k][j + l].rgbtBlue;
                        // increment the number of pixels
                        count++;
                    }
                }
            }

            // set the red value to the average of the red values
            temp[i][j].rgbtRed = round(sumRed / count);
            // set the green value to the average of the green values
            temp[i][j].rgbtGreen = round(sumGreen / count);
            // set the blue value to the average of the blue values
            temp[i][j].rgbtBlue = round(sumBlue / count);
        }
    }

    // loop through the rows
    for (int i = 0; i < height; i++)
    {
        // loop through the columns
        for (int j = 0; j < width; j++)
        {
            // set the red value to the temporary image
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            // set the green value to the temporary image
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            // set the blue value to the temporary image
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
