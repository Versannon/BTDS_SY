# Computer Vision - Unit 2: Image Filtering, Edge Detection & Enhancement

## 📚 Unit Overview
Unit 2 focuses on fundamental image processing techniques that transform raw images into forms suitable for analysis. This includes filtering operations, edge detection methods, and image enhancement techniques.

---

## 1. Image Filtering & Convolution

### 1.1 What is Image Filtering?
Image filtering is a technique used to enhance or modify images by applying mathematical operations to pixel values. It helps in:
- Noise reduction
- Image smoothing and blurring
- Feature extraction
- Unsharp masking (sharpening)

### 1.2 Convolution Operation
**Definition**: Convolution is a mathematical operation that combines an image with a kernel (filter) to produce a modified image.

**Mathematical Formula**:
$$G(i,j) = \sum_{m=-k}^{k} \sum_{n=-k}^{k} F(i+m, j+n) \times K(m,n)$$

Where:
- G(i,j) = Output pixel value
- F = Input image
- K = Kernel/Filter
- (i,j) = Pixel coordinates

### 1.3 Common Filters

#### A. **Smoothing Filters**

**Moving Average Filter (Box Filter)**
- Reduces noise by averaging neighboring pixels
- Kernel: All values = 1/(kernel_size)
```
[1 1 1]     [1/9 1/9 1/9]
[1 1 1]  →  [1/9 1/9 1/9]
[1 1 1]     [1/9 1/9 1/9]
```

**Gaussian Filter**
- More effective smoothing with weighted average
- Gives more importance to central pixels
- Formula: $G(x,y) = \frac{1}{2\pi\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}$
- Better for noise reduction than box filter

**Median Filter**
- Non-linear filter that replaces pixel with median of neighborhood
- Excellent for salt-and-pepper noise removal
- Kernel: 3×3, 5×5, 7×7, etc.

#### B. **Sharpening Filters**

**Unsharp Mask**
- Formula: Sharpened = Original + (Original - Blurred) × α
- Enhances edges and fine details

**Laplacian Filter**
- Uses second derivative to detect edges
- Kernel:
```
[0  1  0]    [-1 -1 -1]    [1 -2  1]
[1 -4  1]  or [-1  8 -1] or [-2 4 -2]
[0  1  0]    [-1 -1 -1]    [1 -2  1]
```

### 1.4 Padding Strategies
When applying filters, edge pixels need special handling:
- **Zero Padding**: Add zeros around image border
- **Reflection Padding**: Mirror pixels from adjacent area
- **Edge Padding**: Replicate edge pixels
- **Periodic Padding**: Wrap around image

---

## 2. Edge Detection

### 2.1 What are Edges?
Edges are regions where intensity changes abruptly. They represent:
- Object boundaries
- Transitions between regions
- Important structural features

### 2.2 Edge Detection Methods

#### A. **Sobel Operator**
- Uses first-order derivatives in x and y directions
- More robust to noise than simple difference

**Sobel Kernel (X-direction)**:
```
[-1  0  1]
[-2  0  2]
[-1  0  1]
```

**Sobel Kernel (Y-direction)**:
```
[-1 -2 -1]
[ 0  0  0]
[ 1  2  1]
```

**Edge Magnitude**: $E = \sqrt{G_x^2 + G_y^2}$

**Edge Direction**: $\theta = \arctan(G_y / G_x)$

#### B. **Canny Edge Detection**
**Steps**:
1. Apply Gaussian filter to reduce noise
2. Calculate gradient magnitude and direction
3. Apply Non-Maximum Suppression
4. Apply Double Thresholding
5. Edge Tracking by Hysteresis

**Advantages**:
- Accurate edge localization
- Minimal response
- Only one edge per actual edge (no multiple responses)

#### C. **Laplacian Edge Detection**
- Uses second derivative
- Detects all types of edges
- More sensitive to noise
- Kernel:
```
[0  1  0]
[1 -4  1]
[0  1  0]
```

#### D. **Prewitt Operator**
Similar to Sobel but with different kernel weights

**Prewitt X-direction**:
```
[-1  0  1]
[-1  0  1]
[-1  0  1]
```

### 2.3 Edge Detection Comparison

| Method | Gradient Type | Noise Sensitivity | Edge Quality |
|--------|---------------|-------------------|--------------|
| Sobel  | 1st Derivative| Moderate          | Good         |
| Canny  | 1st Derivative| Low               | Excellent    |
| Laplacian | 2nd Derivative | High | Moderate |
| Prewitt | 1st Derivative | Moderate | Good |

---

## 3. Image Enhancement Techniques

### 3.1 Contrast Enhancement

#### A. **Histogram Equalization**
- Redistributes pixel intensities to improve contrast
- Formula: $s = \frac{(\text{no. of pixels} \leq r)}{M \times N} \times 255$
- Works: Spreads out most frequent intensity values

**Advantages**:
- Better visibility of details
- Improved contrast for medical imaging

**Disadvantages**:
- May amplify noise
- Can produce unnatural images

#### B. **Contrast Limited Adaptive Histogram Equalization (CLAHE)**
- Divides image into tiles
- Applies histogram equalization to each tile
- Avoids over-amplification of noise
- Clip limit prevents excessive amplification

#### C. **Gamma Correction**
- Formula: $O = I^{(1/\gamma)}$
- γ > 1: Darkens image
- γ < 1: Brightens image
- Useful for correcting non-linear sensor response

### 3.2 Noise Reduction

#### A. **Types of Noise**
- **Gaussian Noise**: Normal distribution, random
- **Salt & Pepper Noise**: Black and white pixels
- **Poisson Noise**: Quantum fluctuations
- **Speckle Noise**: Multiplicative noise

#### B. **Denoising Methods**
- **Gaussian Blur**: Simple but blurs edges
- **Bilateral Filter**: Preserves edges while smoothing
- **Non-Local Means (NLM)**: Uses similarity patches
- **Morphological Operations**: Uses shape structure

### 3.3 Image Sharpening & Unsharp Masking

**Unsharp Mask Process**:
1. Create blurred version of image
2. Subtract blurred from original
3. Add this difference back to original (scaled by α)

Formula: $Output = Original + \alpha \times (Original - Blurred)$

Where α controls sharpening strength (typically 0.5 - 2.0)

---

## 4. Morphological Operations

### 4.1 Basic Operations

#### A. **Erosion**
- Removes small objects and noise
- Formula: $E = \min\{A(x+i, y+j) : (i,j) \in B\}$
- Shrinks white objects

#### B. **Dilation**
- Fills small holes in objects
- Formula: $D = \max\{A(x-i, y-j) : (i,j) \in B\}$
- Expands white objects

#### C. **Opening**
- Erosion followed by Dilation
- Removes small objects and noise
- Smooths object boundaries

#### D. **Closing**
- Dilation followed by Erosion
- Fills small holes
- Connects nearby objects

### 4.2 Structuring Elements
Common kernels for morphological operations:
- **Rectangular**: 3×3, 5×5, etc.
- **Circular**: Circular shape
- **Cross**: Plus-shaped kernel

---

## 5. Frequency Domain Processing (Introduction)

### 5.1 Fourier Transform
- Converts spatial domain to frequency domain
- Formula: $F(u,v) = \sum_{x=0}^{M-1}\sum_{y=0}^{N-1} f(x,y) e^{-j2\pi(ux/M + vy/N)}$
- Shows frequency content of image

### 5.2 Types of Filters in Frequency Domain

#### A. **Low-Pass Filter**
- Keeps low frequencies
- Reduces noise and high-frequency details
- Causes blurring effect

#### B. **High-Pass Filter**
- Keeps high frequencies
- Enhances edges and details
- Sharpens image

#### C. **Band-Pass Filter**
- Keeps frequencies within a range
- Removes very high and very low frequencies

---

## 6. Key Formulas Summary

| Operation | Formula |
|-----------|---------|
| Convolution | $G(i,j) = \sum_{m,n} F(i+m,j+n) \times K(m,n)$ |
| Sobel Magnitude | $E = \sqrt{G_x^2 + G_y^2}$ |
| Sobel Direction | $\theta = \arctan(G_y/G_x)$ |
| Gamma Correction | $O = I^{(1/\gamma)}$ |
| Unsharp Mask | $Output = Original + \alpha(Original - Blurred)$ |
| Gaussian | $G(x,y) = \frac{1}{2\pi\sigma^2} e^{-\frac{x^2+y^2}{2\sigma^2}}$ |

---

## 7. Practical Applications

### Image Filtering:
- Medical image preprocessing
- Satellite image analysis
- Autonomous vehicle percetion

### Edge Detection:
- Object detection
- Document scanning
- Industrial inspection

### Enhancement:
- Medical imaging (X-ray, MRI)
- Surveillance enhancement
- Underwater image processing

### Morphological Operations:
- Binary image analysis
- Cell counting
- Fingerprint processing

---

## 8. Learning Resources & Code Files

### Associated Jupyter Notebooks:
1. **02_Image_Filtering.ipynb** - Hands-on filtering techniques
2. **03_Edge_Detection.ipynb** - Edge detection methods
3. **04_Image_Enhancement.ipynb** - Enhancement techniques
4. **05_Morphological_Operations.ipynb** - Morphological operations

### Libraries Used:
- OpenCV (cv2)
- NumPy
- Matplotlib
- SciPy (for advanced operations)

---

## 9. Questions for Self-Assessment

1. What is the difference between convolution and correlation?
2. Why is Canny edge detection better than simple Sobel?
3. Explain when to use erosion vs. dilation.
4. How does CLAHE improve over standard histogram equalization?
5. What is the purpose of padding strategies in convolution?
6. Implement a custom 3×3 Gaussian kernel.
7. Compare frequency domain vs. spatial domain filtering.
8. How does bilateral filtering preserve edges?

---

## 10. References & Further Reading

- OpenCV Documentation: https://docs.opencv.org/
- 'Computer Vision: Algorithms and Applications' - Richard Szeliski
- 'Digital Image Processing' - Gonzalez & Woods
- Scikit-image Documentation: https://scikit-image.org/

---

**Last Updated**: 2026-03-05  
**Assessment Pattern**: Practical assignments + Theory questions + Mini-project
