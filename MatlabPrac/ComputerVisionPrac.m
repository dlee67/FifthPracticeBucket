img = imread('Ramen.png');
imshow(img);
disp(size(img));

% Gets the slice of an image from the row 101 to 103 
% and the column 201 to 203
disp("Grabbing the slice of Ramen.");
disp(img(101:103, 201:203));

waitforbuttonpress;

img = imread('CrayOne.jpg');
imshow(img);
disp("CrayOne image size: " + size(img));

waitforbuttonpress;

cropped = img(110:310, 10:160);
imshow(cropped);
% Notice how the height and width are one off from the ranges we've
% selected, that is because ranges are inclusive in Matlab.
disp("CrayOne's cropped image size: " + size(cropped));