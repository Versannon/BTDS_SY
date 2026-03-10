# Unit 2: Image Processing Fundamentals - Assignment 2

## Theory Questions

### 1. What are different image enhancement techniques in spatial domain?

Image enhancement in the spatial domain refers to techniques that operate directly on the pixels of an image. The main categories include:

- **Point Processing Operations**: Determines a new pixel value based solely on its original intensity using a transfer function.
- **Histogram Processing**: Improves contrast by modifying the distribution of pixel intensity values.
- **Spatial Filtering**: Calculates new pixel values using the neighborhood of pixels and a filter mask (kernel).
- **Arithmetic/Logic Operations**: Enhances images by combining two images or applying logical masks.

### 2. Explain spatial filtering technique.

Spatial filtering is a method where a new pixel value is determined by its neighboring pixel values and a filter mask, also known as a kernel or window.

**Process**: A kernel (typically $3\times3$ or $5\times5$) slides over the image.

**Mathematical Representation**: 
$$g(x,y)=\sum_{s=-a}^{a}\sum_{t=-b}^{b}w(s,t).f(x+s,y+t)$$

**Usage**: It is used to remove noise (smoothing), sharpen images for edge detection, and extract features in computer vision.

### 3. Apply mean filter of size $3\times3$ on given image and compute output image (use padding).

**Given Image**:
$$\begin{bmatrix} 114 & 133 & 122 \\ 93 & 116 & 95 \\ 123 & 153 & 141 \end{bmatrix}$$

**Note**: A standard mean filter replaces the center pixel with the average of its neighbors.

**Calculation for center pixel (116)**: 
- Sum = 114+133+122+93+116+95+123+153+141 = 1090
- Mean = 1090 / 9 ≈ 121.1

**Result**: The center pixel 116 is replaced by 121. (Full output image calculation requires applying this to all pixels using zero-padding).

### 4. Apply median filter of size $3\times3$ on given image using padding.

**Given Image**:
$$\begin{bmatrix} 117 & 117 & 117 \\ 117 & 0 & 117 \\ 1 & 117 & 117 \end{bmatrix}$$

**Process**: Replaces the pixel with the median of neighborhood values.

**Calculation for center pixel (0)**:
- Sort the 9 values: $1, 117, 117, 117, 117, 117, 117, 117, 117$
- The median (middle value) is **117**

**Result**: The noise (0) is removed and replaced by 117.

### 5. Write first-order derivative (gradient based) & second order derivative operators.

**First-Order Derivative (Gradient)**: Measures intensity changes in $x$ and $y$ directions.

**Sobel Operator** ($3\times3$):
$$Gx = \begin{bmatrix} -1 & 0 & 1 \\ -2 & 0 & 2 \\ -1 & 0 & 1 \end{bmatrix}, \quad Gy = \begin{bmatrix} -1 & -2 & -1 \\ 0 & 0 & 0 \\ 1 & 2 & 1 \end{bmatrix}$$

**Prewitt Operator** ($3\times3$):
$$Gx = \begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}, \quad Gy = \begin{bmatrix} -1 & -1 & -1 \\ 0 & 0 & 0 \\ 1 & 1 & 1 \end{bmatrix}$$

**Second-Order Derivative (Laplacian)**: Highlights regions of rapid intensity change using derivatives in both directions.

**Standard Laplacian Mask**: 
$$\begin{bmatrix} 0 & -1 & 0 \\ -1 & 4 & -1 \\ 0 & -1 & 0 \end{bmatrix}$$

### 6. Explain Edge detection algorithm?

Edges are detected by finding sharp local changes in intensity, representing object boundaries. The **Canny Edge Detection Algorithm** is the most widely used:

1. **Noise Removal**: Apply Gaussian Smoothing to reduce noise sensitivity.
2. **Gradient Calculation**: Use Sobel operators to find intensity changes and magnitude.
3. **Non-Maximum Suppression**: Look at gradient direction and keep pixels only if they are the local maximum to thin the edges.
4. **Double Thresholding**: Categorize pixels as strong, weak, or non-edge based on high and low thresholds.
5. **Edge Tracking (Hysteresis)**: Keep weak edges only if they are connected to strong edges.

### 7. Define Image transformation.

Image transformations convert an image from one domain to another (e.g., Spatial to Frequency) to make analysis easier.

- **Fourier Transform**: Converts Spatial Domain (pixels) to Frequency Domain (frequencies).
- **Hough Transform**: Converts Image Space to Parameter Space to detect lines, circles, and shapes accurately even with noise.

### 8. Write notes on - Image enhancement in frequency domain.

Enhancement in the frequency domain is performed on the transformed image (Fourier transform) rather than the raw pixels.

- **Low Pass Filter (LPF)**: Smoothens the image by preserving low frequencies (background/smooth parts) and attenuating high frequencies (edges/noise).
- **High Pass Filter (HPF)**: Sharpens the image by preserving high frequencies (edges) and attenuating low frequencies.
- **Filters**: Common types include Ideal, Butterworth, and Gaussian filters.

### 9. Write short notes on - Erosion, Dilation, Opening & Closing.

These are Morphological Operations based on shapes using a structuring element:

- **Erosion** ($A \ominus B$): Reduces the size of objects by removing pixels from boundaries.
- **Dilation** ($A \oplus B$): Increases the size of objects, joins adjacent objects, and fills small holes.
- **Opening** ($A \circ B$): Erosion followed by dilation; used to remove small noise objects.
- **Closing** ($A \bullet B$): Dilation followed by erosion; used to fill small gaps and holes.

### 10. Explain the use of following functions:

- **`erode()`**: Reduces object size by removing boundary pixels based on a kernel.
- **`dilate()`**: Enlarges object size by adding boundary pixels based on a kernel.
- **`morphologyEx()`**: A versatile function for complex morphological operations like opening or closing.
- **`filter2D()`**: Convolves a user-defined kernel (mask) with an image to apply custom spatial filters.
- **`blur()`**: Smoothens an image using a normalized box (mean) filter.
- **`medianBlur()`**: Smoothens an image by replacing pixels with the median of their neighborhood; best for salt-and-pepper noise.

### 11. Perform all numerical on morphological operation.

**Example 1: Erosion/Dilation**

Input Image $A$: $3\times3$ block of 1s in a $5\times5$ field.
Kernel $B$: $3\times3$ block of 1s.

- **Erosion Result**: Only the center pixel remains 1 (where the kernel fits entirely).
- **Dilation Result**: The $3\times3$ block expands to a $5\times5$ block of 1s.

**Example 2: Noise Removal (Opening)**

- **Input Image**: Contains isolated "1" pixels (noise).
- **Process**: Erosion removes the isolated 1s, then Dilation restores the larger objects, effectively cleaning the image.

---

# Unit 1 & Fundamentals (cv_1.pdf Questions)

### 1. What is Computer Vision? Explain different pipelines in Computer Vision.

Computer Vision (CV) is a field of AI that enables machines to process, analyze, and understand visual information from images or videos.

**Pipeline**:
1. **Acquisition**: Sensing image/video data.
2. **Pre-processing**: Enhancement, filtering, or resizing.
3. **Feature Extraction**: Detecting edges, textures, or shapes.
4. **Classification/Detection**: Assigning labels using ML/DL.
5. **Decision Making**: Taking action based on understanding.

### 2. How is an image formed? Explain with a neat labeled diagram.

Image formation is the physical/computational process of converting a 3D scene into a 2D digital image.

**Process**:
1. **Illumination**: A light source shines on an object.
2. **Reflection**: Light reflects based on object properties (reflectance).
3. **Focusing**: The camera lens focuses light onto a sensor.
4. **Sensing**: The sensor (CMOS/CCD) converts light into electrical signals.
5. **Digitization**: Signals are sampled and quantized into pixel values (0-255).

### 3. If Illumination $= 200$ and Reflectance $= 0.6$, what will be the pixel value?

Using the formula $I(x,y) = L(x,y) \times R(x,y)$:
$$I = 200 \times 0.6 = \mathbf{120}$$

### 4. If Illumination varies from 100 to 200 and Reflectance $= 0.6$ find:

a. **Minimum pixel intensity**: $100 \times 0.6 = \mathbf{60}$

b. **Maximum pixel intensity**: $200 \times 0.6 = \mathbf{120}$

### 5. Write a note on different color spaces and their uses.

- **RGB (Red, Green, Blue)**: Default for digital displays; sensitive to lighting changes.
- **HSV (Hue, Saturation, Value)**: Separates color (Hue) from brightness (Value); robust for tracking objects under varying light.
- **Grayscale**: Single intensity channel (0-255); used when color isn't needed (edge detection, face detection) for faster processing.

### 6. Find the gray value of a color pixel with $R=255, G=10, B=100$.

Using the formula $Gray = 0.299R + 0.587G + 0.114B$:
$$Gray = (0.299 \times 255) + (0.587 \times 10) + (0.114 \times 100)$$
$$Gray = 76.245 + 5.87 + 11.4 = \mathbf{93.515}$$

### 7. Write a note on histogram. Also explain how histogram help in image analysis.

An image histogram is a graph showing the frequency of pixel intensity values.

**Analysis**:
- **Dark Image**: Most values clustered on the left (near 0).
- **Bright Image**: Most values clustered on the right (near 255).
- **Low Contrast**: Values are squeezed into a narrow range.
- **High Contrast**: Values are spread across the entire range.

### 8. Explain different point processing methods based on histogram to enhance an image.

- **Contrast Stretching**: Linearly expands the range of intensities to cover the full spectrum (0-255).
- **Histogram Equalization**: Redistributes intensity values to create a uniform distribution using a Cumulative Distribution Function (CDF), improving overall contrast.

### 9. Why is OpenCV used?

OpenCV (Open Source Computer Vision Library) is used because it provides optimized functions for real-time image and video processing, feature detection, object detection, and machine learning support.

### 10. Write algorithm for contrast stretching.

1. Find the minimum intensity ($r_{min}$) and maximum intensity ($r_{max}$) of the input image.
2. Set desired output range ($s_{min}=0, s_{max}=255$).
3. For each pixel value $r$, compute output $S$ using:
$$S = \left( \frac{(r - r_{min}) \times (s_{max} - s_{min})}{(r_{max} - r_{min})} \right) + s_{min}$$
