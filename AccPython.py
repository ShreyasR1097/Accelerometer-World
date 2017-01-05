
from visual import *
import serial
import time

sensorData = serial.Serial('com11',9600)
time.sleep(2)


AccScene=display(title='Accelerometer World') #Create your scene and give it a title.
 
AccScene.width=800  #We can set the dimension of your visual box. 800X800 pixels works well on my screen
AccScene.height= 800
AccScene.autoscale=True #We want to set the range of the scene manually for better control. Turn autoscale off
AccScene.range = (12,12,12) #Set range of your scene to be 12 inches by 12 inches by 12 inches.

accbox = box(pos=(2.5,2.5,2.5), length = 6, height = 0.5, width = 6, color = color.red)

while True:

    rate(25)
    textline = sensorData.readline()     # read the entire line of text
    dataNums=textline.split(',')
    x = float(dataNums[0])
    xaxis = 0.08*x-10
    
    accbox.axis = (1,xaxis,0)
