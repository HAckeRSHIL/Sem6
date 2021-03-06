# -*- coding: utf-8 -*-
"""
Created on Tue Jan 21 21:48:19 2020

@author: HAckeRSHIL
"""
import cv2 
# capture frames from a video 
cap = cv2.VideoCapture('video.avi') 
  
# Trained XML classifiers describes some features of some object we want to detect 
car_cascade = cv2.CascadeClassifier('cars.xml') 
cnt = 0
# loop runs if capturing has been initialized. 
while True: 
    # reads frames from a video 
    ret, frames = cap.read() 
      
    # convert to gray scale of each frames 
    gray = cv2.cvtColor(frames, cv2.COLOR_BGR2GRAY) 
    # gray = cv2.cvtColor(frames, cv2.COLOR_BGR2GRAY)
  
    # Detects cars of different sizes in the input image 
    cars = car_cascade.detectMultiScale(gray, 1.1, 1) 
      
    # To draw a rectangle in each cars 
    for (x,y,w,h) in cars: 
        cv2.rectangle(frames,(x,y),(x+w,y+h),(0,0,255),2) 
        
    
   # Display frames in a window  
    # cv2_imshow(frames) 
    



    height, width, layers = frames.shape   
    if cnt == 0:
      vvideo = cv2.VideoWriter("FHAD.avi", 0, 60, (width, height))  
  
    # Appending the images to the video one by one 
    # for image in frames:  
    #     vvideo.write(image)  
    
    vvideo.write(frames)
    
    # Deallocating memories taken for window creation 


    # Wait for Esc key to stop 
    if cv2.waitKey(33) == 27: 
      break
    if cnt>= 500:
      break
    cnt = cnt + 1
# De-allocate any associated memory usage 
cv2.destroyAllWindows()
vvideo.release() 
