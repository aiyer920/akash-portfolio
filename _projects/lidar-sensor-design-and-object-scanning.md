---
layout: project
title: "Lidar Sensor Design and Object Scanning"
description: "In this project I designed, built, and deployed a custom LiDAR sensor to develop a point cloud of a structure on campus."
date: 2026-09-29
categories: [LiDAR, Computer Vision, 3D Printing, Sensors, Raspberry Pi]
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

gallery:
  - type: "image"
    file: "/assets/images/projects/lidar/sensor.png"
    description: "Custom LiDAR sensor holder design"
  - type: "image"
    file: "/assets/images/projects/lidar/pointcloudfinal.png"
    description: "Point cloud generated from the campus structure scan"
---

## Overview

I designed a custom LiDAR sensor and mount and developed a data processing pipeline for my final project in my remote sensing class. I used my sensor to scan and collect data on a structure on campus, in this project a large composting bin and then reconstructed a point cloud representation of this structure. This project involved the design and manufacturing of the physical sensor, developing the code for the data processing system and then calibrating the sensor, collecting data, and fine tuning the resulting point cloud. I gained valuable experience in sensor design, working with a Raspberry Pi and Arduino, and computer vision. 

## Key Features

This project included the physical lidar sensor and mount, data collection of a compositing bin on campus, and data processing pipeline to transform collected measurements into a pointcloud representing the structure. 

## Design and Manufacturing

<!-- Add details about the design and manufacturing process here. -->

## Data Collection and Processing

<!-- Add details about data collection and point-cloud processing here. -->
