#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels, 1st loop for rows
    for (int i = 0; i < height; i++)
    {
        // Second loop for columns
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue for each pixel and round it to next integer
            int average =
                round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            // Update pixel values to average
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take red, green, and blue values of each pixel and apply sepia algorithm to them
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                 .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                   .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue);

            // Cap every value at maximum 255 | Alternative new syntax -> image[i][j].rgbtRed =
            // (sepiaRed > 255) ? 255 : sepiaRed;
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        // Notice we want to stay in the same row image[i] does not change
        for (int j = 0; j < width / 2; j++)
        {
            // Declare a RGBTRIPLE type array as temporary value for the swap
            // Note [width-1-j] corresponds to image[i] position on opposite side
            RGBTRIPLE temp_image;
            temp_image = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp_image;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Declare array that is going to contain a copy of the image
    RGBTRIPLE image2[height][width];

    // Loop through every pixel to create copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }

    // Loop through every pixel for blurring
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // initialize totals for every color and count variable (used to keep track of how many
            // pixels surround target pixel)
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            // Loop through the pixels around including center pixel
            // First loop range: index -1(row above target pixel), index 0 (row of target pixel)
            // index 1 (row below target)
            for (int k = -1; k <= 1; k++)
            {
                // Second loop range: index -1(column above target pixel), index 0 (column of target
                // pixel) index 1 (column below target)
                for (int l = -1; l <= 1; l++)
                {
                    // Make new index adding the shift of rows/columns to the original index
                    // Allows to check area of 3x3 around target pixel
                    int newi = i + k;
                    int newj = j + l;

                    // Check if pixels are within the bounds of the image
                    if (newi >= 0 && newi < height && newj >= 0 && newj < width)
                    {
                        // Calculate total values of each color for every VALID pixel and assign to
                        // image2
                        totalRed += image2[newi][newj].rgbtRed;
                        totalGreen += image2[newi][newj].rgbtGreen;
                        totalBlue += image2[newi][newj].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average color value and assign to original image
            // `count` is the number of pixels that were actually considered in this sum (valid
            // pixels)
            image[i][j].rgbtRed = round((float) totalRed / count);
            image[i][j].rgbtGreen = round((float) totalGreen / count);
            image[i][j].rgbtBlue = round((float) totalBlue / count);
        }
    }
    return;
}