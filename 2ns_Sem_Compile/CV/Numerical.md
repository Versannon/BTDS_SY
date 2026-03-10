# Image Processing Numericals - Unit 1 & Unit 2

## Section 1: Illumination, Reflectance & Image Intensity (10 Numericals)

### 1. Basic Illumination-Reflectance Calculation
If Illumination $L = 150$ and Reflectance $R = 0.8$, find the image intensity $I$.

**Formula**: $I(x,y) = L(x,y) \times R(x,y)$

**Solution**: $I = 150 \times 0.8 = 120$

---

### 2. Finding Reflectance
If Pixel intensity $I = 90$ and Illumination $L = 180$, find the Reflectance $R$.

**Solution**: $R = \frac{I}{L} = \frac{90}{180} = 0.5$

---

### 3. Variable Illumination - Minimum and Maximum Intensity
If Illumination varies from 100 to 200 and Reflectance $R = 0.6$, find the minimum and maximum pixel intensity.

**Solution**:
- Minimum: $I_{min} = 100 \times 0.6 = 60$
- Maximum: $I_{max} = 200 \times 0.6 = 120$

---

### 4. Multiple Objects - Illumination Calculation
An object under illumination $L = 250$ with reflectance $R_1 = 0.7$ and another with $R_2 = 0.4$ under the same illumination. Find both pixel intensities.

**Solution**:
- Object 1: $I_1 = 250 \times 0.7 = 175$
- Object 2: $I_2 = 250 \times 0.4 = 100$

---

### 5. Finding Illumination from Intensity
If pixel intensity $I = 144$ and reflectance $R = 0.6$, find the illumination $L$.

**Solution**: $L = \frac{I}{R} = \frac{144}{0.6} = 240$

---

### 6. Varying Reflectance - Range Calculation
If illumination $L = 300$ and reflectance varies from $0.3$ to $0.9$, find the range of pixel intensities.

**Solution**:
- Minimum: $I_{min} = 300 \times 0.3 = 90$
- Maximum: $I_{max} = 300 \times 0.9 = 270$

---

### 7. Three Objects Comparison
Three objects have reflectances $R_1 = 0.2$, $R_2 = 0.5$, and $R_3 = 0.9$ under illumination $L = 200$. Find all intensities.

**Solution**:
- $I_1 = 200 \times 0.2 = 40$
- $I_2 = 200 \times 0.5 = 100$
- $I_3 = 200 \times 0.9 = 180$

---

### 8. Intensity Ratio Calculation
Two objects under the same illumination have pixel intensities $I_1 = 180$ and $I_2 = 90$. Find the ratio of their reflectances.

**Solution**: $\frac{R_1}{R_2} = \frac{I_1}{I_2} = \frac{180}{90} = 2$

---

### 9. Dual Illumination Problem
An object with reflectance $R = 0.75$ is illuminated by two lights with intensities $L_1 = 120$ and $L_2 = 80$. Find the resulting pixel intensity.

**Solution**: $I = (L_1 + L_2) \times R = (120 + 80) \times 0.75 = 200 \times 0.75 = 150$

---

### 10. Inverse Problem - Finding Both Parameters
An image has pixel intensity $I = 200$. If the illumination is twice the reflectance value, find both $L$ and $R$.

**Solution**: Let $L = 2R$. Then $I = L \times R = 2R \times R = 2R^2 = 200$
- $R^2 = 100 \Rightarrow R = 0.316$
- $L = 2 \times 0.316 = 0.632$

---

## Section 2: Histogram Analysis & Pixel Distribution (10 Numericals)

### 11. Histogram from Intensity Matrix
Draw the histogram for the image matrix:
$$\begin{bmatrix} 10 & 20 & 30 & 40 & 50 \\ 20 & 30 & 40 & 50 & 60 \\ 30 & 40 & 50 & 60 & 70 \\ 40 & 50 & 60 & 70 & 80 \\ 50 & 60 & 70 & 80 & 90 \end{bmatrix}$$

**Solution**: Count frequency of each intensity:
| Intensity | 10 | 20 | 30 | 40 | 50 | 60 | 70 | 80 | 90 |
|-----------|----|----|----|----|----|----|----|----|-----|
| Frequency | 1  | 2  | 3  | 4  | 5  | 4  | 3  | 2  | 1   |

---

### 12. Histogram - Dark vs Bright Image
For a dark image with most pixel values between 0-85, and a bright image with most values between 170-255, explain the histogram distribution.

**Solution**: 
- Dark image: Values clustered on the left side (0-85 range)
- Bright image: Values clustered on the right side (170-255 range)

---

### 13. Contrast Analysis from Histogram
An image has pixel values distributed only in the range 100-150. Comment on the image contrast.

**Solution**: The image has **low contrast** because the values are squeezed into a narrow range (100-150 out of 0-255). A high contrast image would have values spread across the entire 0-255 range.

---

### 14. Histogram Normalization
An image has frequency distribution:
| Intensity | Frequency |
|-----------|-----------|
| 50        | 100       |
| 100       | 200       |
| 150       | 150       |
| 200       | 50        |

Calculate the normalized histogram (probability distribution).

**Solution**: Total pixels = 100 + 200 + 150 + 50 = 500
| Intensity | Frequency | Normalized Probability |
|-----------|-----------|------------------------|
| 50        | 100       | 0.20                   |
| 100       | 200       | 0.40                   |
| 150       | 150       | 0.30                   |
| 200       | 50        | 0.10                   |

---

### 15. Cumulative Distribution Function (CDF)
Using the normalized histogram from Problem 14, calculate the CDF.

**Solution**: 
| Intensity | Probability | CDF   |
|-----------|-------------|-------|
| 50        | 0.20        | 0.20  |
| 100       | 0.40        | 0.60  |
| 150       | 0.30        | 0.90  |
| 200       | 0.10        | 1.00  |

---

### 16. Histogram Equalization - Mapping Function
For an 8-bit image with the CDF from Problem 15, calculate the histogram equalization mapping for each intensity.

**Solution**: $s_k = (L-1) \times CDF(r_k)$ where $L = 256$
| Intensity | CDF   | Mapped Value (s) |
|-----------|-------|------------------|
| 50        | 0.20  | 51               |
| 100       | 0.60  | 153              |
| 150       | 0.90  | 230              |
| 200       | 1.00  | 255              |

---

### 17. Contrast Stretching - Linear Scaling
An image has min intensity 30 and max intensity 200. Apply contrast stretching to map the range to [0, 255].

**Formula**: $S = \frac{(r - r_{min}) \times (s_{max} - s_{min})}{(r_{max} - r_{min})} + s_{min}$

**Solution**: For pixel $r = 100$:
$$S = \frac{(100 - 30) \times (255 - 0)}{(200 - 30)} + 0 = \frac{70 \times 255}{170} = \frac{17850}{170} \approx 105$$

---

### 18. Histogram Specification - Target Equalization
An image has the histogram from Problem 14. Specify the equalized histogram for uniform distribution.

**Solution**: For uniform distribution with 4 intensities and 500 pixels:
Each intensity should have frequency = 500 / 4 = 125
Target histogram: [125, 125, 125, 125]

---

### 19. Multi-Channel Histogram
For an RGB image with R=[50,100], G=[75,125], B=[100,150], calculate the combined histogram for a 3×3 pixel image.

**Solution**: Count frequency of each R, G, B value separately or combine to create 3D histogram showing the distribution of colors.

---

### 20. Histogram Comparison
Two images have histograms:
- Image 1: Values concentrated around 128
- Image 2: Values spread across 0-255

Which image has higher contrast?

**Solution**: Image 2 has **higher contrast** because its values are spread across the entire range, while Image 1's values are concentrated around a single intensity level (128).

---

## Section 3: Grayscale Conversion, Color Spaces & Pixel Operations (10 Numericals)

### 21. RGB to Grayscale Conversion
Find the gray value of a color pixel with $R = 255$, $G = 10$, $B = 100$.

**Formula**: $Gray = 0.299R + 0.587G + 0.114B$

**Solution**: 
$$Gray = (0.299 \times 255) + (0.587 \times 10) + (0.114 \times 100)$$
$$Gray = 76.245 + 5.87 + 11.4 = 93.515 \approx 94$$

---

### 22. Multiple RGB to Grayscale
Convert the following RGB pixels to grayscale:
- Pixel 1: $R = 100$, $G = 100$, $B = 100$ (Gray)
- Pixel 2: $R = 255$, $G = 0$, $B = 0$ (Red)
- Pixel 3: $R = 0$, $G = 255$, $B = 0$ (Green)

**Solution**:
- Pixel 1: $Gray = 0.299(100) + 0.587(100) + 0.114(100) = 100$
- Pixel 2: $Gray = 0.299(255) + 0 + 0 = 76.245 \approx 76$
- Pixel 3: $Gray = 0 + 0.587(255) + 0 = 149.685 \approx 150$

---

### 23. Color Space - HSV Analysis
An RGB pixel $(255, 128, 0)$ (orange) is converted to HSV. Explain the expected H, S, V values qualitatively.

**Solution**: 
- **Hue (H)**: ~30° (orange hue in the color wheel)
- **Saturation (S)**: High (~100%) because it's a pure orange color
- **Value (V)**: High (~100%) because it's a bright color

---

### 24. Inverse Grayscale Problem
A grayscale image has a pixel value of 128. If this came from an equally red and green pixel (G = R) with $B = 60$, find the R and G values.

**Formula**: $128 = 0.299R + 0.587R + 0.114(60)$

**Solution**: 
$$128 = 0.886R + 6.84$$
$$121.16 = 0.886R$$
$$R = G \approx 137$$

---

### 25. Blue Channel Dominance
Find the RGB values for a pixel that appears blue (R = x, G = x, B = 200) with grayscale value 100.

**Solution**: $100 = 0.299x + 0.587x + 0.114(200)$
$$100 = 0.886x + 22.8$$
$$77.2 = 0.886x$$
$$x \approx 87$$

So RGB = (87, 87, 200)

---

### 26. Additive Color Mixing
Three pixels are:
- Pixel 1: R = 250, G = 0, B = 0 (Red)
- Pixel 2: R = 0, G = 250, B = 0 (Green)
- Pixel 3: R = 0, G = 0, B = 250 (Blue)

Find their grayscale values and explain the relationship.

**Solution**:
- Red: $Gray = 0.299(250) = 74.75$
- Green: $Gray = 0.587(250) = 146.75$
- Blue: $Gray = 0.114(250) = 28.5$

Green appears brightest, followed by red, then blue (matches human eye sensitivity).

---

### 27. White and Black Balance
Find grayscale values for:
- White: RGB = (255, 255, 255)
- Black: RGB = (0, 0, 0)
- Gray: RGB = (128, 128, 128)

**Solution**:
- White: $Gray = 255$
- Black: $Gray = 0$
- Gray: $Gray = 128$

---

### 28. Complementary Color Analysis
A cyan pixel (R = 0, G = 255, B = 255) and a red pixel (R = 255, G = 0, B = 0) are complementary colors. Compare their grayscale values.

**Solution**:
- Cyan: $Gray = 0 + 0.587(255) + 0.114(255) = 178.905$
- Red: $Gray = 0.299(255) = 76.245$

Cyan appears brighter in grayscale.

---

### 29. Color Image Filtering
An image has RGB pixels in a 2×2 grid. Convert to grayscale:
$$\begin{bmatrix} (100, 50, 200) & (200, 100, 50) \\ (50, 150, 100) & (150, 200, 75) \end{bmatrix}$$

**Solution**: Apply the formula to each pixel to get grayscale matrix.

---

### 30. Intensity Range Verification
Verify that for any valid RGB pixel (0≤R,G,B≤255), the grayscale value is also within [0, 255].

**Solution**: Maximum: $0.299(255) + 0.587(255) + 0.114(255) = 255$. Minimum: $0 + 0 + 0 = 0$. ✓ Grayscale is always in valid range.

---

## Section 4: Morphological Operations - Erosion, Dilation, Opening & Closing (20 Numericals)

### 31. Basic Erosion Operation
Apply erosion with a 3×3 structuring element (all 1s) to the 5×5 binary image:
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

**Solution**: Only the center pixel survives erosion (where the kernel fits entirely within foreground):
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

---

### 32. Basic Dilation Operation
Apply dilation with a 3×3 structuring element (all 1s) to the 5×5 image from Problem 31:
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

**Solution**: Foreground expands to all neighbors:
$$\begin{bmatrix} 0 & 1 & 1 & 1 & 0 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 0 & 1 & 1 & 1 & 0 \end{bmatrix}$$

---

### 33. Opening Operation (Erosion → Dilation)
Apply opening to the 5×5 image with salt-and-pepper noise:
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 0 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

**Solution**: 
- After Erosion: Center 3×3 survives
- After Dilation: Restored with small noise removed

Final Result:
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

---

### 34. Closing Operation (Dilation → Erosion)
Apply closing to fill the hole in the 5×5 image:
$$\begin{bmatrix} 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 0 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \end{bmatrix}$$

**Solution**: 
- After Dilation: Hole is filled
- After Erosion: Size is restored

Final Result:
$$\begin{bmatrix} 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \end{bmatrix}$$

---

### 35. Erosion with Different Structuring Elements
Compare erosion of a 5×5 square with:
- (a) 3×3 square SE
- (b) Implementation with 5×5 square SE

**Solution**: 
- (a) With 3×3 SE: Reduces size significantly
- (b) With 5×5 SE: Eliminates the entire object (too large)

---

### 36. Multiple Erosions
Apply erosion twice to the 5×5 image:
$$\begin{bmatrix} 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 \end{bmatrix}$$

**Solution**: 
- After 1st Erosion: 3×3 center of 1s
- After 2nd Erosion: Single center pixel remains

---

### 37. Multiple Dilations
Apply dilation twice to:
$$\begin{bmatrix} 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \\ 0 & 0 & 0 & 0 & 0 \end{bmatrix}$$

**Solution**: 
- After 1st Dilation: 3×3 center region becomes 1
- After 2nd Dilation: 5×5 region becomes 1 (entire image)

---

### 38. Opening for Object Cleaning
An image has two objects: a 4×4 foreground region and isolated 1-pixel noise. Apply opening with 3×3 SE to remove noise.

**Solution**: Opening removes isolated pixels (noise) while preserving larger connected components (objects).

---

### 39. Closing for Boundary Smoothing
Apply closing to smooth an irregular boundary:
$$\begin{bmatrix} 0 & 1 & 1 & 1 & 0 \\ 0 & 1 & 0 & 1 & 0 \\ 0 & 1 & 1 & 1 & 0 \end{bmatrix}$$

**Solution**: Closing fills the internal hole and smooths the boundary.

---

### 40. Combined Morphological Sequence
For noise reduction, apply: Erosion → Dilation → Closing on the noisy 6×6 image:
$$\begin{bmatrix} 1 & 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 0 & 0 & 1 & 1 \\ 1 & 1 & 0 & 0 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 & 1 \\ 1 & 1 & 1 & 1 & 1 & 1 \end{bmatrix}$$

**Solution**: Apply each operation sequentially with 3×3 SE:
- **Erosion**: Removes boundaries
- **Dilation**: Restores object size
- **Closing**: Fills remaining holes for clean final result

The combined effect provides robust noise removal while preserving object structure.

---
