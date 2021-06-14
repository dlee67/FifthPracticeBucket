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

% Notice how it prints out three numbers
% The first two are the eight and width
% the third one is the number of color planes and channels in the image.
disp("CrayOne image size: " + size(img));

waitforbuttonpress;

img_red = img(:, :, 1);
% Portions with higher red values will be displayed brighter.
imshow(img_red);
% This in itself is a channel.
disp(size(img_red))

waitforbuttonpress;

cropped = img(110:310, 10:160);
imshow(cropped);
% Notice how the height and width are one off from the ranges we've
% selected, that is because ranges are inclusive in Matlab.
disp("CrayOne's cropped image size: " + size(cropped));