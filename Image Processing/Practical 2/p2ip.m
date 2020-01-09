
clear ;
close all;
img1=imread("C:\CODING\SEM 6 IT\Image Processing\Practical 2\Screenshot (2).png");
expended=imresize(img1,2);
imshow(expended);
figure();
shrinked=imresize(img1,0.5);
imshow(shrinked);