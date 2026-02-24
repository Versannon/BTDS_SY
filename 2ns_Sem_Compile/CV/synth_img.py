import cv2
import numpy as np
import matplotlib.pyplot as plt

matrix = np.random.randint(0,256,(900,900))
print(matrix,type(matrix),"\n")

img = np.array(matrix, dtype=np.uint8)
print(img,type(img),"\n")

cv2.imwrite("sythn_img.jpg", img)

plt.imshow(img, cmap='gray')
plt.title('Synthetic Grayscale Image')
plt.show()

cv2.imshow("Synthetic Image", img)
cv2.waitKey(0)
cv2.destroyAllWindows()