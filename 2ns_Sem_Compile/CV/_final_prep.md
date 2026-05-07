# Computer Vision Question Bank – Answers

---

# UNIT 1 – Introduction to Computer Vision

## 1. What is Computer Vision? Explain different pipelines in Computer Vision.

### Definition

Computer Vision (CV) is a branch of Artificial Intelligence (AI) that enables computers to acquire, process, analyze and understand images or videos similar to human vision.

Applications:

* Face recognition
* Self-driving cars
* Medical image analysis
* Object detection
* Robotics
* Surveillance systems

### Computer Vision Pipeline

```text
Image Acquisition
        ↓
Preprocessing
        ↓
Feature Extraction
        ↓
Object Detection / Recognition
        ↓
Decision Making
```

### Explanation of Pipeline

#### 1. Image Acquisition

* Capturing images/videos using cameras or sensors.
* Includes sampling and quantization.

Example:

* CCTV camera capturing frames.

#### 2. Preprocessing

Improves image quality before analysis.

Techniques:

* Noise removal
* Image enhancement
* Resizing
* Thresholding
* Filtering

#### 3. Feature Extraction

Important image features are extracted.

Features include:

* Edges
* Corners
* Texture
* Shapes

#### 4. Object Detection and Recognition

* Detects and classifies objects.
* Uses ML and DL algorithms.

Example:

* Detecting cars in traffic videos.

#### 5. Decision Making

Final interpretation or action.

Example:

* Self-driving car applies brake after detecting obstacle.

---

## 2. How is an image formed? Explain with neat labeled diagram.

### Definition

Image formation is the process by which a real-world scene is converted into a digital image.

### Steps in Image Formation

1. Light source illuminates object
2. Light reflects from object
3. Lens focuses light onto sensor
4. Sensor converts light into electrical signals
5. Signals are digitized into image

### Diagram

```text
Light Source
     ↓
  Object
(reflects light)
     ↓
 Camera Lens
     ↓
 Image Sensor
(CCD/CMOS)
     ↓
Electrical Signal
     ↓
Digital Image
```

### Important Terms

#### Illumination L(x,y)

Amount of light falling on object.

#### Reflectance R(x,y)

Ability of object to reflect light.

### Mathematical Model

genui{"math_block_widget_always_prefetch_v2":{"content":"I(x,y)=L(x,y)\times R(x,y)"}}

Where:

* I(x,y) = Image intensity
* L(x,y) = Illumination
* R(x,y) = Reflectance

---

## 3. Write a note on different color spaces and their uses.

## 1. RGB Color Space

### Definition

RGB represents image using:

* Red
* Green
* Blue

Each pixel contains 3 channels.

### Uses

* Display systems
* Digital cameras
* Computer graphics

### Example

```text
(255,0,0) → Red
(0,255,0) → Green
(0,0,255) → Blue
```

---

## 2. HSV Color Space

HSV =

* Hue
* Saturation
* Value

### Uses

* Color segmentation
* Object tracking
* Color detection

### Advantage

Separates brightness from color.

---

## 3. Grayscale Color Space

Contains only intensity values.

Range:

```text
0 → Black
255 → White
```

### Uses

* Edge detection
* Medical imaging
* Faster processing

### Formula

genui{"math_block_widget_always_prefetch_v2":{"content":"Gray=0.299R+0.587G+0.114B"}}

---

## 4. If Illumination = 200 and Reflectance = 0.6, what will be the pixel value?

Formula:

genui{"math_block_widget_always_prefetch_v2":{"content":"I=L\times R"}}

Given:

* L = 200
* R = 0.6

Calculation:

```text
I = 200 × 0.6
I = 120
```

### Final Answer

Pixel intensity = **120**

---

## 5. If Illumination varies from 100 to 200 and Reflectance = 0.6, find:

### a. Minimum Pixel Intensity

```text
Imin = 100 × 0.6
Imin = 60
```

### b. Maximum Pixel Intensity

```text
Imax = 200 × 0.6
Imax = 120
```

### Final Answer

* Minimum intensity = 60
* Maximum intensity = 120

---

## 6. Find the gray value of a color pixel with R = 255, G = 10, B = 100.

Formula:

```text
Gray = 0.299R + 0.587G + 0.114B
```

Substitute values:

```text
Gray = 0.299(255) + 0.587(10) + 0.114(100)
Gray = 76.245 + 5.87 + 11.4
Gray = 93.515
```

### Final Answer

Gray value ≈ **94**

---

## 7. Explain different point processing methods based on histogram to enhance an image.

Point processing changes pixel intensity values directly.

## Methods

### 1. Image Negative

Transforms bright regions into dark regions.

Formula:

```text
s = L - 1 - r
```

Uses:

* Medical images
* Highlight white details

---

### 2. Log Transformation

Enhances dark regions.

Formula:

```text
s = c log(1+r)
```

Uses:

* Satellite images
* Fourier spectrum display

---

### 3. Power Law (Gamma Transformation)

Controls brightness.

Formula:

```text
s = c r^γ
```

Uses:

* Monitor correction
* Brightness adjustment

---

### 4. Contrast Stretching

Expands intensity range.

Benefits:

* Improves visibility
* Enhances contrast

---

### 5. Thresholding

Converts grayscale image into binary image.

```python
ret, thresh = cv2.threshold(gray,127,255,cv2.THRESH_BINARY)
```

---

### 6. Histogram Equalization

Redistributes intensity values for better contrast.

Benefits:

* Improves low contrast images
* Enhances details

```python
equalized = cv2.equalizeHist(img_gray)
```

---

## 8. Why is OpenCV used?

OpenCV (Open Source Computer Vision Library) is an open-source library used for image processing and computer vision applications.

### Uses of OpenCV

* Image processing
* Object detection
* Face recognition
* Edge detection
* Video processing
* Machine learning support

### Advantages

* Fast processing
* Easy to use
* Supports Python, C++, Java
* Large community support
* Real-time applications

### Example

```python
import cv2
img = cv2.imread("image.jpg")
cv2.imshow("Image", img)
```

---

## 9. Explain the use of following functions.

## a. imread()

Used to load image from storage.

```python
img = cv2.imread("image.jpg")
```

---

## b. imshow()

Displays image in window.

```python
cv2.imshow("Image", img)
cv2.waitKey(0)
```

---

## c. hist()

Plots histogram of image.

```python
plt.hist(img.ravel(),256,[0,256])
```

---

## d. cvtColor()

Converts image from one color space to another.

```python
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
```

---

## e. flatten()

Converts multidimensional array into 1D array.

```python
arr.flatten()
```

---

## f. ravel()

Returns flattened array.

```python
arr.ravel()
```

Difference:

* flatten() creates copy
* ravel() creates view

---

## g. imwrite()

Stores image in storage.

```python
cv2.imwrite("output.jpg", img)
```

---

## 10. Write pseudocode to plot histogram of an image.

```text
START
Read image
Convert image to grayscale
Flatten image matrix
Count frequency of intensity values
Plot histogram
Display histogram
STOP
```

### Python Code

```python
import cv2
import matplotlib.pyplot as plt

img = cv2.imread("image.jpg",0)
plt.hist(img.ravel(), bins=256, range=[0,256])
plt.show()
```

---

## 11. Write algorithm for contrast stretching.

### Algorithm

```text
START
Read grayscale image
Find minimum intensity rmin
Find maximum intensity rmax
For each pixel r:
    s = ((r-rmin)/(rmax-rmin)) × 255
Replace old pixel with s
Display enhanced image
STOP
```

### Python Code

```python
stretched = cv2.normalize(gray, None, 0, 255, cv2.NORM_MINMAX)
```

---

# UNIT 2 – Image Processing Fundamentals

## 1. What are different image enhancement techniques in spatial domain?

Spatial domain enhancement modifies pixel values directly.

## Types

### 1. Point Processing

* Negative transformation
* Log transformation
* Gamma correction
* Contrast stretching
* Thresholding

---

### 2. Histogram Processing

* Histogram equalization
* Histogram stretching

---

### 3. Spatial Filtering

#### Smoothing Filters

* Mean filter
* Median filter

#### Sharpening Filters

* Sobel
* Prewitt
* Laplacian

---

### 4. Arithmetic / Logical Operations

* AND
* OR
* XOR
* Addition
* Subtraction

---

## 2. Explain spatial filtering technique.

Spatial filtering modifies a pixel based on neighboring pixels using a kernel.

### Formula

```text
g(x,y)= ΣΣ w(s,t) f(x+s,y+t)
```

Where:

* f(x,y) = input image
* g(x,y) = output image
* w(s,t) = kernel

### Types

## 1. Smoothing Filters

Used for noise reduction.

### Mean Filter

Replaces pixel with average.

Kernel:

```text
1/9 [1 1 1
     1 1 1
     1 1 1]
```

### Median Filter

Replaces pixel with median value.

Best for salt and pepper noise.

---

## 2. Sharpening Filters

Enhances edges.

Examples:

* Sobel
* Prewitt
* Laplacian

---

## 3. Apply mean filter of size 3x3.

### Formula

```text
Output = Sum of neighboring pixels / 9
```

### Mean Filter Kernel

```text
1/9 [1 1 1
     1 1 1
     1 1 1]
```

### Python Code

```python
mean_filtered = cv2.blur(img,(3,3))
```

---

## 4. Apply median filter of size 3x3.

### Steps

1. Take 3×3 neighborhood
2. Sort values
3. Replace center with median

### Python Code

```python
median_filtered = cv2.medianBlur(img,3)
```

---

## 5. Write first-order derivative and second-order derivative operators.

## First Order Derivative (Gradient Based)

### Sobel Operator

Gx:

```text
[-1 0 1
 -2 0 2
 -1 0 1]
```

Gy:

```text
[-1 -2 -1
  0  0  0
  1  2  1]
```

### Prewitt Operator

Gx:

```text
[-1 0 1
 -1 0 1
 -1 0 1]
```

Gy:

```text
[-1 -1 -1
  0  0  0
  1  1  1]
```

---

## Second Order Derivative

### Laplacian Operator

```text
[ 0 -1  0
 -1  4 -1
 0 -1  0]
```

---

## 6. Explain Edge Detection algorithm.

### Definition

Edge detection identifies sharp intensity changes.

## Canny Edge Detection Steps

### 1. Noise Removal

Apply Gaussian filter.

### 2. Gradient Calculation

Use Sobel operators.

### 3. Gradient Direction

Find edge orientation.

### 4. Non-Maximum Suppression

Thin edges.

### 5. Double Thresholding

Detect strong and weak edges.

### 6. Edge Tracking by Hysteresis

Remove false edges.

### Python Code

```python
edges = cv2.Canny(img,100,200)
```

---

## 7. Define Image transformation.

Image transformation converts image from one domain to another.

Example:

```text
Spatial Domain → Frequency Domain
```

### Types

* Fourier Transform
* Hough Transform

### Applications

* Noise removal
* Compression
* Frequency analysis

---

## 8. Write notes on Image enhancement in frequency domain.

Frequency domain enhancement processes image frequencies instead of pixels.

### Fourier Transform

Converts:

```text
Spatial domain → Frequency domain
```

### Frequency Components

* High frequency → edges, noise
* Low frequency → smooth areas

---

## Types of Frequency Filters

### 1. Low Pass Filter

Removes high frequency.

Uses:

* Smoothing
* Noise removal

---

### 2. High Pass Filter

Removes low frequency.

Uses:

* Sharpening
* Edge enhancement

---

### 3. Band Pass Filter

Keeps selected frequencies.

---

### Python Code

```python
import numpy as np

dft = np.fft.fft2(img)
dft_shift = np.fft.fftshift(dft)
```

---

## 9. Write short notes on Erosion, Dilation, Opening & Closing.

## 1. Erosion

Shrinks objects.

Condition:

* Output pixel = 1 only if all pixels under kernel are 1.

Uses:

* Removes noise
* Separates objects

```python
erosion = cv2.erode(img,kernel)
```

---

## 2. Dilation

Expands objects.

Condition:

* Output pixel = 1 if any pixel under kernel is 1.

Uses:

* Fills holes
* Joins nearby objects

```python
dilation = cv2.dilate(img,kernel)
```

---

## 3. Opening

Formula:

```text
(A⊖B)⊕B
```

Erosion followed by dilation.

Uses:

* Removes small noise

---

## 4. Closing

Formula:

```text
(A⊕B)⊖B
```

Dilation followed by erosion.

Uses:

* Fills holes
* Connects gaps

---

## 10. Explain functions.

## erode()

Performs erosion.

```python
cv2.erode(img,kernel)
```

---

## dilate()

Performs dilation.

```python
cv2.dilate(img,kernel)
```

---

## morphologyEx()

Performs advanced morphology operations.

```python
cv2.morphologyEx(img, cv2.MORPH_OPEN, kernel)
```

---

## filter2D()

Applies custom filter.

```python
cv2.filter2D(img,-1,kernel)
```

---

## blur()

Applies averaging filter.

```python
cv2.blur(img,(3,3))
```

---

## medianBlur()

Applies median filter.

```python
cv2.medianBlur(img,5)
```

---

# UNIT 3 – Hough & Feature Detection

## 1. Detect line using edge points (0,1), (1,1), (2,1).

### Hough Transform Equation

genui{"math_block_widget_always_prefetch_v2":{"content":"\rho = x\cos\theta + y\sin\theta"}}

For θ = 90°:

```text
ρ = y
```

For all points:

```text
(0,1) → ρ = 1
(1,1) → ρ = 1
(2,1) → ρ = 1
```

Maximum votes occur at:

```text
ρ = 1 , θ = 90°
```

Final line equation:

```text
y = 1
```

---

## 2. Explain Hough Transform.

Hough Transform detects geometric shapes.

### Steps

1. Edge detection
2. Parameter space voting
3. Accumulator matrix creation
4. Peak detection

### Applications

* Line detection
* Circle detection
* Lane detection

---

## 3. What is Feature Detection? Explain its types and algorithms.

### Definition

Feature detection identifies important image points.

## Types

### 1. Edge Features

Sudden intensity changes.

Algorithm:

* Canny edge detector

---

### 2. Corner Features

Intensity changes in multiple directions.

Algorithm:

* Harris Corner Detector

---

### 3. Blob Features

Uniform intensity regions.

Algorithm:

* Laplacian of Gaussian (LoG)

---

## 4. What is feature extraction? Explain any 2 types.

### Definition

Feature extraction converts raw image into meaningful numerical features.

## Types

### 1. Shape Based Features

Represents shape of object.

Examples:

* Area
* Perimeter
* Compactness

---

### 2. Texture Based Features

Represents surface texture.

Examples:

* Mean
* Variance
* Entropy

Applications:

* Medical imaging
* Pattern recognition

---

## 5. What are Feature Descriptors? Explain its uses.

Feature descriptors encode local image regions into numerical vectors.

### Uses

* Object recognition
* Image matching
* Panorama stitching
* Face recognition
* Tracking

---

## 6. Write feature descriptor algorithms and their properties.

## 1. SIFT

Scale Invariant Feature Transform.

### Properties

* Rotation invariant
* Scale invariant
* Robust to illumination

---

## 2. SURF

Speeded Up Robust Features.

### Properties

* Faster than SIFT
* Robust to blur
* Uses Hessian detector

---

## 3. ORB

Oriented FAST and Rotated BRIEF.

### Properties

* Fast
* Efficient
* Good for real-time systems

---

## 7. Write applications of feature descriptors and keypoint matching.

### Applications

* Panorama creation
* AR systems
* Object tracking
* Medical imaging
* Robotics navigation
* Face recognition

### Keypoint Matching Methods

* Brute Force Matcher
* Homography Estimation

---

## 8. Name algorithms to detect features.

### Algorithms

* Canny Edge Detector
* Harris Corner Detector
* SIFT
* SURF
* ORB
* FAST
* Laplacian of Gaussian

---

# UNIT 4 & 5 – Machine Learning and Neural Networks

## 1. What is Machine Learning? Explain its process.

### Definition

Machine Learning is a branch of AI that enables systems to learn from data and make predictions without explicit programming.

### Process

```text
Data Input
    ↓
Algorithm Selection
    ↓
Model Training
    ↓
Evaluation
    ↓
Prediction
```

### Explanation

#### 1. Data Input

Collect and preprocess data.

#### 2. Algorithm Selection

Choose algorithm according to task.

#### 3. Model Training

Model learns patterns.

#### 4. Evaluation

Model tested using unseen data.

#### 5. Prediction

Final output generated.

---

## 2. Explain supervised and unsupervised machine learning.

## Supervised Learning

Model is trained on labeled data.

### Applications

* Spam detection
* Price prediction
* Image classification

### Algorithms

* KNN
* SVM
* Linear Regression

---

## Unsupervised Learning

Model learns from unlabeled data.

### Applications

* Clustering
* Customer segmentation
* Pattern discovery

### Algorithms

* K-Means
* PCA
* Hierarchical Clustering

---

## 3. Explain KNN algorithm with advantages and disadvantages.

### Definition

KNN is a supervised learning algorithm based on similarity.

### Working

1. Select K value
2. Calculate distance
3. Select nearest neighbors
4. Perform majority voting

### Distance Formula

genui{"math_block_widget_always_prefetch_v2":{"content":"d=\sqrt{\sum_{i=1}^{n}(x_i-y_i)^2}"}}

### Advantages

* Simple
* Easy to implement
* No training phase
* Works for classification and regression

### Disadvantages

* Slow for large datasets
* Sensitive to noisy data
* High memory usage

### Python Code

```python
from sklearn.neighbors import KNeighborsClassifier

model = KNeighborsClassifier(n_neighbors=3)
model.fit(X,y)
```

---

## 4. What is Artificial Neural Network? Explain structure, process and applications.

### Definition

ANN is a computational model inspired by the human brain.

### Structure

```text
Input Layer → Hidden Layer → Output Layer
```

### Components

* Neurons
* Weights
* Bias
* Activation function

### Process

1. Input computation
2. Output generation
3. Weight adjustment
4. Learning

### Applications

* Image recognition
* NLP
* Speech recognition
* Cybersecurity

---

## 5. What is single layer perceptron? Explain working with diagram.

### Definition

Single Layer Perceptron is the simplest neural network used for binary classification.

### Diagram

```text
x1 ----w1---\
              > Σ → Activation → Output
x2 ----w2---/
             + Bias
```

### Working

1. Multiply inputs with weights
2. Add bias
3. Apply activation function
4. Produce output
5. Update weights

### Equation

genui{"math_block_widget_always_prefetch_v2":{"content":"y=f(\sum wx+b)"}}

---

## 6. Design single-layer perceptron for AND gate.

### Truth Table

```text
x1 x2 Output
0  0   0
0  1   0
1  0   0
1  1   1
```

### Initial Values

```text
w1 = 0
w2 = 0
b = 0
η = 1
```

### Final Weights

```text
w1 = 1
w2 = 1
b = -1.5
```

### Final Equation

```text
y = x1 + x2 - 1.5
```

### Python Code

```python
from sklearn.linear_model import Perceptron

X = [[0,0],[0,1],[1,0],[1,1]]
y = [0,0,0,1]

model = Perceptron()
model.fit(X,y)
```

---

## 7. What is multilayer neural network? Explain working.

### Definition

Multilayer Neural Network contains:

* Input layer
* Hidden layers
* Output layer

### Working

#### 1. Forward Propagation

Data moves from input to output.

#### 2. Activation Function

Introduces non-linearity.

Functions:

* ReLU
* Sigmoid
* Tanh

#### 3. Loss Function

Measures error.

#### 4. Backpropagation

Updates weights.

#### 5. Optimization

Uses gradient descent.

---

## 8. Write short note on CNN.

### Definition

CNN (Convolutional Neural Network) is a deep learning architecture mainly used for image processing.

### CNN Architecture

```text
Input Image
     ↓
Convolution Layer
     ↓
ReLU
     ↓
Pooling Layer
     ↓
Flattening
     ↓
Fully Connected Layer
     ↓
Output
```

### Advantages

* Automatic feature extraction
* Good image classification accuracy
* Robust to spatial variations

### Applications

* Face recognition
* Medical imaging
* Self-driving cars
* Object detection

---

## 9. Case study based on region-based feature classification of object.

# Case Study – Fruit Classification using Region Based Features

## Objective

Classify fruits based on shape and region properties.

## Steps

### 1. Image Acquisition

Capture fruit images.

### 2. Preprocessing

* Resize image
* Convert to grayscale
* Remove noise

### 3. Segmentation

Separate fruit from background.

### 4. Feature Extraction

Extract:

* Area
* Perimeter
* Eccentricity
* Compactness

### 5. Classification

Use ML classifier such as:

* KNN
* SVM
* CNN

### Diagram

```text
Input Image
      ↓
Preprocessing
      ↓
Segmentation
      ↓
Feature Extraction
      ↓
Classification
      ↓
Output Label
```

### Applications

* Fruit sorting
* Industrial automation
* Quality inspection

---

# End of Answers
