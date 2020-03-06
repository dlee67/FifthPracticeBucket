from PIL import Image
import face_recognition
import numpy as np
import argparse
import cv2

ap = argparse.ArgumentParser()
ap.add_argument("-t", "--image", required = False, help = "Enter path to the image")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])

face_locations = face_recognition.face_locations(image)
print("I found {} face(s) in this photograph".format(len(face_locations)))

for face_location in face_locations:
    top, right, bottom, left = face_location
    print("A face is located at pixel location Top: {}, Left: {}, Bottom: {}, Right: {}".format(top, left, bottom, right))

    face_image = image[top:bottom, left:right]
    pil_image = Image.fromarray(face_image)
    pil_image.show()