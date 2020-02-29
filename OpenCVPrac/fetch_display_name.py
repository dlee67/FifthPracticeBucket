import argparse
import cv2

# Following OpenCV Computer Vision Examples with Python: A Complete Guide for Dummies
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required=True, help="Enter path to the image")
args = vars(ap.parse_args())

print("Passed in: ", str(args))
print("Image member assigned with: ", str(args["image"]))

image = cv2.imread(args["image"])
print("width of the image: ".format(image.shape[1]))
print("height of the image in pixels is: ".format(image.shape[0]))
print("channels present the image is: ".format(image.shape[2]))

cv2.imshow("Image Title", image)
cv2.waitKey(5000)