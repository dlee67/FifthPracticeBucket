import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True, help = "Lol")  
args = vars(ap.parse_args())

image = cv2.imread(args["image"])

image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

blurred = cv2.GaussianBlur(image, (5,5), 0)

cv2.imshow("Gaussian blurr", blurred)
cv2.waitKey(0)

canny = cv2.canny(blurred, 30, 150)
cv2.imshow("Gaussian Blurr", canny)
cv2.waitKey(0)