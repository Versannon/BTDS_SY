# 🖼️ Computer Vision Assignment 1

------------------------------------------------------------------------

## 1) What is Computer Vision? Explain different pipelines in Computer Vision.

**Definition**

Computer Vision (CV) is a field of Artificial Intelligence that enables
machines to capture, process, and understand images or videos in order
to make decisions.

**Common Computer Vision Pipeline**

1.  **Image Acquisition** → Capture image using camera or sensor\
2.  **Preprocessing** → Resize, denoise, normalize image\
3.  **Feature Extraction / Representation** → Detect edges, corners,
    textures or deep features\
4.  **Model Inference** → Perform classification, detection,
    segmentation, tracking\
5.  **Post-processing** → Apply filtering, NMS, thresholding\
6.  **Decision / Output** → Produce labels, bounding boxes, masks or
    alerts

------------------------------------------------------------------------

## 2) How is an image formed?

An image is formed when light from a source falls on an object and
reflects into a camera lens.\
The lens focuses the reflected light onto an image sensor, which
converts the light energy into electrical signals that become pixel
intensities.

**Mathematical Model**

I(x,y) = L(x,y) × R(x,y)

Where

-   I(x,y) = Image intensity at pixel (x,y)\
-   L(x,y) = Illumination (light falling on object)\
-   R(x,y) = Reflectance of object (0--1)

**Image Formation Flow**

Light Source → Object Surface → Camera Lens → Image Sensor → Digital
Image

------------------------------------------------------------------------

## 3) If Illumination = 200 and Reflectance = 0.6

Formula

I = L × R

Calculation

I = 200 × 0.6 = 120

**Pixel Value = 120**

------------------------------------------------------------------------

## 4) Illumination varies from 100 to 200 and Reflectance = 0.6

Minimum Pixel Intensity

I_min = 100 × 0.6 = 60

Maximum Pixel Intensity

I_max = 200 × 0.6 = 120

**Range = 60 to 120**

------------------------------------------------------------------------

## 5) Different color spaces and their uses

  Color Space   Use
  ------------- ---------------------------------------------------
  RGB           Standard model used in cameras and displays
  Grayscale     Single intensity channel for simple processing
  HSV / HSI     Separates hue from brightness for color detection
  YCbCr / YUV   Used in video compression
  LAB           Perceptually uniform color model
  CMYK          Printing color model

------------------------------------------------------------------------

## 6) Gray value of pixel with R=255, G=10, B=100

Formula

Gray = 0.299R + 0.587G + 0.114B

Calculation

Gray = (0.299 × 255) + (0.587 × 10) + (0.114 × 100)

Gray = 76.245 + 5.87 + 11.4 = 93.515 ≈ 94

**Gray value ≈ 94**

------------------------------------------------------------------------

## 7) Histogram

A histogram represents the distribution of pixel intensities in an
image.

-   **X-axis:** intensity values (0--255)\
-   **Y-axis:** number of pixels

**Uses**

-   Shows brightness distribution\
-   Helps determine contrast\
-   Detects overexposed or underexposed images\
-   Helps choose enhancement techniques

------------------------------------------------------------------------

## 8) Histogram based image enhancement

-   **Contrast Stretching** -- Expands intensity range\
-   **Histogram Equalization** -- Improves global contrast\
-   **Adaptive Histogram Equalization (CLAHE)** -- Improves local
    contrast\
-   **Histogram Matching** -- Matches histogram to reference image\
-   **Thresholding** -- Separates foreground and background

------------------------------------------------------------------------

## 9) Why OpenCV is used

OpenCV provides

-   Fast computer vision algorithms\
-   Easy APIs for image/video processing\
-   Real‑time processing capability\
-   Cross‑platform support\
-   Works with Python, C++, Java

------------------------------------------------------------------------

## 10) Functions

**imread()**\
Reads an image file into memory.

**imshow()**\
Displays an image in a window.

**hist()**\
Plots a histogram of pixel values.

**cvtColor()**\
Converts image between color spaces.

------------------------------------------------------------------------

## 11) Pseudocode to plot histogram

    START
    Read image

    If image is color
        Convert to grayscale

    Create histogram array H[0..255] = 0

    For each pixel p
        H[p] = H[p] + 1

    Plot intensity (0..255) vs frequency

    END

------------------------------------------------------------------------

## 12) Algorithm for contrast stretching

Input: grayscale image I\
Output: stretched image S

    1. Find r_min = minimum intensity
    2. Find r_max = maximum intensity

    3. For each pixel r
           If r_max == r_min
                s = 0
           Else
                s = ((r - r_min) / (r_max - r_min)) * (L - 1)

    4. Assign s to output image
    5. Return S

Formula

s = ((r − r_min) / (r_max − r_min)) × (L − 1)
