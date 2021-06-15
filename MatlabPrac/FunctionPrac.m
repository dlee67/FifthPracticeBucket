ramen = imread('Ramen.png');
imshow(scale(ramen, 1.5)); % Doing this will make the image brighter
                           % because the intensity is increased.
waitforbuttonpress;

ramenResized = imresize(ramen, [500, 500]);
cray = imread('CrayOne.png');
crayResized = imresize(cray, [500, 500]);

% Ensuring the "weight" to equal 1 is called blending two images.
% This is the bases of "alpha-blending."
result = blend(ramenResized, crayResized, 0.5);
imshow(result);

function result = scale(img, value)
    result = value .* img; % .* ensures an element-wise multiplecation
    % meaning, a regular scalar multiplecation.
end

function output = blend(a, b, alpha)
    output = alpha * a + (1 - alpha) * b;
end