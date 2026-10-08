---
layout: project
title: "LiDAR Sensor Design and Object Scanning"
description: "In this project, I designed, built, and deployed a custom LiDAR sensor to develop a point cloud of a structure on campus."
categories: [LiDAR, Computer Vision, 3D Printing, Sensors, Raspberry Pi]
filter_categories: [Mechatronics, Design and Manufacturing, Perception]
featured_image: "/assets/images/projects/lidar/sensor.png"

models:
  - file: "/assets/models/lidar/sensor-holder.glb"
    description: "Custom LiDAR sensor holder"

featured_video:
  youtube_id: "yVAGEmn95Cs"
  description: "LiDAR sensor design and object scanning demonstration"

components:
  - name: "Raspberry Pi"
    quantity: 1
    description: "Main computer for image capture and sensor data processing"

  - name: "Raspberry Pi Camera"
    quantity: 1
    description: "Captures the projected laser line for triangulation"

  - name: "Line Laser"
    quantity: 1
    description: "Projects the reference line used to calculate range"

  - name: "3D-Printed Sensor Holder"
    quantity: 1
    description: "Custom mount that maintains the camera and laser geometry"

  - name: "Arduino Uno R3"
    quantity: 1
    description: "Controls line laser"

gallery:
  - type: "image"
    file: "/assets/images/projects/lidar/sensor.png"
    description: "Custom LiDAR sensor holder design"
  - type: "image"
    file: "/assets/images/projects/lidar/pointcloudfinal.png"
    description: "Point cloud generated from the campus structure scan"
---

## Overview

I designed a custom LiDAR sensor and mount and developed a data processing pipeline for my final project in my remote sensing class. I used my sensor to scan and collect data on a structure on campus, which in this project was a large composting bin, and then reconstructed a point cloud representation of this structure. This project involved the design and manufacturing of the physical sensor, developing the code for the data processing system and then calibrating the sensor, collecting data, and fine-tuning the resulting point cloud. I gained valuable experience in sensor design, working with a Raspberry Pi and Arduino, and computer vision.

## Key Features

This project included the physical LiDAR sensor and mount, data collection of a composting bin on campus, and a data processing pipeline to transform collected measurements into a point cloud representing the structure. The LiDAR sensor is made from a line laser and Raspberry Pi Camera. The line laser is shined on the target object and captured by the Pi Camera. The data processing algorithm then uses pre-calibrated geometry to calculate the depth of the line points. A separate algorithm then visualizes the points as a point cloud. An Arduino is also used to power and control the line laser.

## Design and Manufacturing

The LiDAR sensor mount was designed in SolidWorks and then 3D printed. It includes mounts for the line laser, Arduino, Raspberry Pi, and Raspberry Pi Camera and is printed in two pieces to fit printer size constraints. It is also designed to mount easily to a tripod and have space to place a phone/level to measure angle changes when scanning the object.

## Data Collection and Processing

Geometric information about the line laser and camera like the angle between them is used to calibrate the sensor and is used later in the data processing algorithm. To collect data, I scanned my object at a fixed distance from it at fixed angle increments. At each angle increment, the Pi Camera takes an image of the object. This is done with as many sides as possible for the object, and the point clouds of each side of the object are combined in the final point cloud. The data processing algorithm uses OpenCV to mask out the line laser and then averages the height of each point in the line. Calibrated sensor geometry is then used to calculate the depth of the point. This is done for every row in the image. The point cloud points are then passed to CloudCompare, which visualizes the point cloud and allows extraneous points to be removed.
