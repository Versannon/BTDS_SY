# Computer Vision - Unit 1: Image Fundamentals

## 📚 Unit Overview
Unit 1 provides the foundation for understanding digital images, including image formation, color spaces, pixel representation, and basic image properties. This is essential knowledge for all advanced Computer Vision topics.

---

## 1. Introduction to Computer Vision

### 1.1 Definition
**Computer Vision (CV)** is a field of Artificial Intelligence that enables machines to capture, process, understand, and make decisions based on images or videos. It bridges the gap between human visual perception and machine understanding.

### 1.2 Goals of Computer Vision
- **Image Understanding**: Extract meaningful information from images
- **Object Recognition**: Identify and classify objects in images
- **Scene Reconstruction**: Create 3D models from 2D images
- **Image Enhancement**: Improve image quality and visibility
- **Motion Analysis**: Track and analyze movement in videos
- **Pattern Detection**: Find recurring patterns or features

---

## 2. Computer Vision Pipelines

### 2.1 Common CV Pipeline

The typical workflow for computer vision applications follows these steps:

```
Input → Preprocessing → Feature Extraction → Model Inference → Post-processing → Output
```

#### Step 1: **Image Acquisition**
- Capture images using cameras or sensors
- Various formats: RGB, Grayscale, Infrared, Depth, etc.
- Resolution and quality depend on application

#### Step 2: **Preprocessing**
- **Resizing**: Adjust image dimensions
- **Normalization**: Scale pixel values to standard range
- **Denoising**: Remove noise
- **Color conversion**: Transform between color spaces
- **Augmentation**: Generate variations for training

#### Step 3: **Feature Extraction / Representation**
- **Edge detection**: Find object boundaries
- **Corner detection**: Identify key interest points
- **Texture analysis**: Extract texture patterns
- **Deep features**: Learn from neural networks
- **Descriptors**: Create feature vectors

#### Step 4: **Model Inference**
- **Classification**: Assign labels to images
- **Detection**: Localize objects with bounding boxes
- **Segmentation**: Pixel-level classification
- **Tracking**: Follow objects across frames

#### Step 5: **Post-processing**
- **Filtering**: Smooth results using spatial filters
- **NMS** (Non-Maximum Suppression): Remove duplicate detections
- **Thresholding**: Convert to binary decisions
- **Morphological operations**: Clean up results

#### Step 6: **Decision / Output**
- **Labels** for classification tasks
- **Bounding boxes** for object detection
- **Segmentation masks** for semantic understanding
- **Alerts** for monitoring applications
- **Visualizations** for human interpretation

### 2.2 Real-World Pipeline Example: Face Detection

```
Input Image
    ↓
Preprocessing (resize, normalize)
    ↓
Feature Extraction (CNN features)
    ↓
Face Detection Model (Cascade/YOLO/R-CNN)
    ↓
Post-processing (NMS, filtering)
    ↓
Output (bounding boxes, confidence scores)
    ↓
Visualization (draw boxes on image)
```

---

## 3. How Images Are Formed

### 3.1 Physics of Image Formation

An image is created through the following process:

```
Light Source → Object Surface → Reflection → Camera Lens → Image Sensor → Digital Image
```

#### Components:

1. **Light Source (L)**
   - Natural (sunlight) or artificial light
   - Provides illumination to the scene

2. **Object Surface (R)**
   - Different materials reflect light differently
   - Characterized by reflectance (0 to 1)
   - Determines how much light is reflected

3. **Camera Lens**
   - Focuses reflected light onto image sensor
   - Aperture controls light amount
   - Focal length determines field of view

4. **Image Sensor**
   - Converts light energy to electrical signals
   - Discrete sampling creates pixels
   - Each pixel stores intensity value(s)

5. **ADC (Analog-to-Digital Converter)**
   - Quantizes continuous signals to discrete values
   - Typical range: 0-255 (8-bit) or 0-1023 (10-bit)

### 3.2 Mathematical Model

The intensity at a pixel (x,y) is given by:

$$I(x,y) = L(x,y) \times R(x,y)$$

Where:
- **I(x,y)** = Pixel intensity at position (x,y)
- **L(x,y)** = Illumination (incident light intensity)
- **R(x,y)** = Reflectance (0 ≤ R ≤ 1)

### 3.3 Example Calculations

**Problem 1**: If Illumination = 200 and Reflectance = 0.6
$$I = 200 \times 0.6 = 120$$
**Answer: Pixel Value = 120**

**Problem 2**: If Illumination varies from 100 to 200, and Reflectance = 0.6
$$I_{min} = 100 \times 0.6 = 60$$
$$I_{max} = 200 \times 0.6 = 120$$
**Answer: Pixel range = 60 to 120**

---

## 4. Digital Images and Pixels

### 4.1 Pixel Representation

A **pixel** (picture element) is the smallest unit of an image.

- **2D representation**: Image[x, y]
- **Intensity (Grayscale)**: Single value (0-255)
- **Color (RGB)**: Three values (R, G, B) each 0-255
- **Memory**: Each pixel typically 1-4 bytes

### 4.2 Image Properties

| Property | Description | Example |
|----------|-------------|---------|
| **Width** | Number of columns (pixels) | 1920 |
| **Height** | Number of rows (pixels) | 1080 |
| **Size** | Width × Height | 2,073,600 pixels |
| **Channels** | Color components | 1 (gray), 3 (RGB), 4 (RGBA) |
| **Bit Depth** | Bits per pixel | 8 (gray), 24 (RGB) |
| **Data Type** | Storage format | uint8, uint16, float32 |

### 4.3 Image Coordinate System

```
(0,0) ---|--→ x
         |
         ↓
         y
         
Origin at top-left corner
x increases rightward
y increases downward
```

---

## 5. Color Spaces

A **color space** is a mathematical representation of how to describe colors. Different spaces have different advantages.

### 5.1 RGB (Red, Green, Blue)

**Most common color space**

- **Components**: R, G, B (each 0-255)
- **Model**: Additive color mixing
- **Use Case**: Cameras, displays, web
- **Formula**: Color = R × Red + G × Green + B × Blue
- **Advantages**: Hardware native, intuitive
- **Disadvantages**: Not perceptually uniform

```
Pure Red:   (255, 0, 0)
Pure Green: (0, 255, 0)
Pure Blue:  (0, 0, 255)
White:      (255, 255, 255)
Black:      (0, 0, 0)
Yellow:     (255, 255, 0)
```

### 5.2 Grayscale (G)

**Single intensity channel**

- **Formula (Standard)**: $G = 0.299R + 0.587G + 0.114B$
- **Formula (Simplified)**: $G = (R + G + B) / 3$
- **Use Case**: Medical imaging, edge detection, simplification
- **Advantages**: Reduced storage, faster processing
- **Disadvantages**: Loss of color information

**Example**:
```
If R=255, G=10, B=100
G = 0.299(255) + 0.587(10) + 0.114(100)
G = 76.245 + 5.87 + 11.4 = 93.515 ≈ 94
```

### 5.3 HSV/HSI (Hue, Saturation, Value/Intensity)

**Perceptually-oriented color space**

| Component | Range | Meaning |
|-----------|-------|---------|
| **Hue (H)** | 0-360° | Color type (red, green, blue, etc.) |
| **Saturation (S)** | 0-100% | Color purity (0=gray, 100=pure color) |
| **Value/Intensity (V/I)** | 0-100% | Brightness (0=black, 100=bright) |

**Advantages**:
- Separates color information from brightness
- Intuitive for color-based detection
- Robust to lighting changes

**Applications**:
- Color-based object tracking
- Skin tone detection
- Color segmentation

### 5.4 YCbCr/YUV

**Luminance-Chrominance color space**

- **Y**: Luminance (brightness)
- **Cb/U**: Blue chrominance
- **Cr/V**: Red chrominance

**Advantages**:
- Efficiently separates intensity from color
- Used in video compression (JPEG, MPEG)
- Exploits human visual sensitivity

### 5.5 LAB Color Space

**Perceptually uniform color space**

- **L**: Lightness (0-100)
- **A**: Green-red axis (-127 to 127)
- **B**: Blue-yellow axis (-127 to 127)

**Advantages**:
- Perceptually uniform (equal distances = equal perceived differences)
- Used in image processing algorithms
- Good for color-based analysis

### 5.6 CMYK

**Subtractive color mixing**

- **C**: Cyan, **M**: Magenta, **Y**: Yellow, **K**: Key (black)
- **Use**: Printing color model
- **Opposite of RGB**: More pigment = darker color

---

## 6. Pixel Value Calculations

### 6.1 Grayscale Conversion Example

**Given**: R=255, G=10, B=100

Using the standard formula:
$$Gray = 0.299R + 0.587G + 0.114B$$

$$Gray = 0.299(255) + 0.587(10) + 0.114(100)$$
$$Gray = 76.245 + 5.87 + 11.4$$
$$Gray = 93.515 ≈ 94$$

**Answer: Gray value = 94**

### 6.2 Intensity Range Calculation

**Given**: Illumination from 100-200, Reflectance varies per pixel

For a pixel with reflectance R(x,y) = 0.8:
- Minimum: $I_{min} = 100 \times 0.8 = 80$
- Maximum: $I_{max} = 200 \times 0.8 = 160$

For a pixel with reflectance R(x,y) = 0.3:
- Minimum: $I_{min} = 100 \times 0.3 = 30$
- Maximum: $I_{max} = 200 \times 0.3 = 60$

---

## 7. Color Space Conversion Summary

| Conversion | Formula | Uses |
|-----------|---------|------|
| **RGB → Gray** | $G = 0.299R + 0.587G + 0.114B$ | Simplification, edge detection |
| **RGB → HSV** | Complex transformation | Color-based detection |
| **RGB → YCbCr** | $Y = 0.299R + 0.587G + 0.114B$ | Video compression |
| **RGB → LAB** | Complex transformation | Perceptually uniform analysis |
| **Gray → RGB** | $R = G = B$ | Reverse conversion |

---

## 8. Practical Considerations

### 8.1 Image Storage

| Format | Channels | Bits/Pixel | Use Case |
|--------|----------|-----------|----------|
| Grayscale | 1 | 8 | Medical, edge detection |
| RGB | 3 | 24 | Natural images, web |
| RGBA | 4 | 32 | Images with transparency |
| HSV | 3 | 24 | Color-based analysis |

### 8.2 Common Bit Depths

- **8-bit (uint8)**: 0-255, most common
- **16-bit (uint16)**: 0-65535, medical imaging
- **32-bit (float32)**: 0.0-1.0, high precision processing
- **64-bit (float64)**: Maximum precision

### 8.3 Image Quality Factors

| Factor | Impact | Solution |
|--------|--------|----------|
| **Noise** | Degrades quality | Filtering, denoising |
| **Blur** | Loss of detail | Sharpening |
| **Compression** | Artifacts | Use lossless formats |
| **Dynamic range** | Over/under exposure | Histogram equalization |
| **Color space** | Information loss | Choose appropriate space |

---

## 9. Key Formulas Summary

| Concept | Formula | Purpose |
|---------|---------|---------|
| Image Formation | $I(x,y) = L(x,y) \times R(x,y)$ | Model pixel intensity |
| Grayscale Conversion | $G = 0.299R + 0.587G + 0.114B$ | Convert RGB to gray |
| Simple Average | $G = (R + G + B) / 3$ | Approximate grayscale |
| Pixel Range | $[L_min \times R, L_max \times R]$ | Calculate intensity bounds |

---

## 10. Common Image Formats

| Format | Type | Compression | Extension |
|--------|------|-------------|-----------|
| JPEG | Raster | Lossy | .jpg, .jpeg |
| PNG | Raster | Lossless | .png |
| BMP | Raster | None | .bmp |
| TIFF | Raster | Lossless/Lossy | .tif, .tiff |
| GIF | Raster | Lossless | .gif |
| OpenEXR | Raster | Lossless | .exr |

---

## 11. Questions for Self-Assessment

1. Explain the image formation process from light source to digital image.
2. Given L=150 and R=0.7, what is the pixel value?
3. What are the advantages of using HSV color space over RGB?
4. Calculate the grayscale value for RGB(100, 150, 200).
5. Which color space is used in JPEG compression?
6. Explain why LAB color space is perceptually uniform.
7. What is the relationship between bit depth and maximum pixel value?
8. Why is the grayscale conversion formula weighted (not equal weights)?

---

## 12. References & Further Reading

- **Books**:
  - "Digital Image Processing" - Gonzalez & Woods
  - "Computer Vision: Algorithms and Applications" - Szeliski
  - "Digital Image Fundamentals" - Various authors

- **Online Resources**:
  - OpenCV Documentation: https://docs.opencv.org/
  - Scikit-image: https://scikit-image.org/
  - NumPy: https://numpy.org/

---

**Last Updated**: 2026-03-05  
**Assessment Pattern**: Theory quiz + Practical exercises + Color space conversions
