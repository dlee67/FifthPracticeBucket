import numpy as np
import cv2

# Should go learn more about this canvas.
canvas = np.zeros((300, 300, 3), dtype="uint8")
green = (0, 255, 0)
cv2.line(canvas, (0,0), (300, 300), green)
cv2.imshow("The canvas", canvas)
cv2.waitKey(0)

cv2.rectangle(canvas, (10, 10), (60, 60), green)
cv2.imshow("The rectangle", canvas)
cv2.waitKey(0)

red = (0, 0, 255)
cv2.rectangle(canvas, (70, 70), (30, 30), red)
cv2.imshow("Red rectangle", canvas)
cv2.waitKey(0)

canvas = np.zeros((300, 300, 3), dtype="uint8")

green = (0, 255, 0)
cv2.circle(canvas, (100, 100), 10, green)
cv2.imshow("Single circle", canvas)
cv2.waitKey(0)
# To clear the canvas, it seems like I have to re-initialize it.

white = (255, 255, 255)
(centerX, centerY) = (canvas.shape[1]//2, canvas.shape[0]//2)

for r in range(0, 175, 25):
    cv2.circle(canvas, (centerX, centerY), r, white)

cv2.imshow("Single circle", canvas)
cv2.waitKey(0)