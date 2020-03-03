import argparse
import cv2

# Following OpenCV Computer Vision Examples with Python: A Complete Guide for Dummies
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required=True, help="Enter path to the image")
args = vars(ap.parse_args())

print("Passed in: ", str(args))
print("Image member assigned with: ", str(args["image"]))

image = cv2.imread(args["image"])
print("width of the image: {}".format(image.shape[1]))
print("height of the image in pixels is: {}".format(image.shape[0]))
print("channels present the image is: {}".format(image.shape[2]))

(b, g, r) = image[0,0]
print("Pixel at (0,0) - Red: {}, Green: {}, Blue: {}".format(r,g,b))

image[0,0] = (0,0,255)
(b, g, r) = image[0,0]
print("Pixel at (0,0) - Red: {}, Green: {}, Blue: {}".format(r, g, b))

# From the top left corner, height, width.
corner = image[0:500, 0:1000]
cv2.imshow("Corner just sliced", corner)
cv2.waitKey(0)

# Changes the color on speicified portion of the image.
corner[0:250, 0:100] = (0, 255, 0)
cv2.imshow("Corner just sliced", corner)
cv2.waitKey(0)

cv2.resize(image, None, fx=0.5, fy=0.5)
cv2.imshow("Resized Optimus Prime", image)
cv2.waitKey(0)

# cv2.resize(image, dim)
# cv2.imshow("Image Title", image)
# cv2.waitKey(0)
# cv2.imwrite("NewOptimusPicture.jpg", image)