---
layout: project
title: "TurtleBot Autonomous Navigation"
description: "In this project, I developed object detection, path planning, and control algorithms to get a TurtleBot to navigate a maze."
categories: [ROS 2, Kinematics, Path Planning, SLAM, Sensors, Computer Vision]
filter_categories: [Robotics, Mechatronics, Machine Learning, Perception]
featured_image: "/assets/images/projects/turtlebot/featured.jpg"
github_url: "https://github.com/aiyer920/final"
github_below_content: true
github_label: "TurtleBot Project GitHub"

gallery:
  - type: "video"
    file: "/assets/images/projects/turtlebot/maze-navigation.mp4"
    description: "TurtleBot maze navigation with camera and map views (3x speed)"
  - type: "video"
    file: "/assets/images/projects/turtlebot/lab-demonstration.mp4"
    description: "TurtleBot lab demonstration (3x speed)"
  - type: "image"
    file: "/assets/images/projects/turtlebot/featured.jpg"
    description: "TurtleBot navigating around obstacles in the lab"
---

## Overview

The goal of this project is to develop an algorithm to get a TurtleBot3 robot to navigate a maze through computer vision using a camera and LiDAR sensor. Each wall segment of the maze was marked with signs indicating the direction of the goal, which required computer vision to identify the correct sign. I also implemented a controller that processed sensor data to avoid obstacles and navigate to the goal. Through this project, I explored perception, localization, control, and ROS 2 fundamentals, implementing my algorithm on a physical robot and in simulation.
## Key Features

The maze navigation algorithm involved a two-state controller that blends odometry and LiDAR data for obstacle avoidance. The computer vision pipeline used a KNN approach to identify signs from images that were cropped, filtered and centered on the sign in front of the robot. The maze environment was also mapped to provide localization and global navigation for the robot through the ROS 2 navigation stack. The algorithm was also tested in a Gazebo maze environment before being transferred to the physical robot.

## Path Planning

The maze environment was first mapped out with global waypoints being placed throughout the map to turn it into a grid. Based on the detected sign, the robot would turn and travel through waypoints until it reached the next wall, where it would read the sign in front of the robot and continue navigating through the maze until reaching the goal sign. I set up AMCL for pose estimation and tuned costmap and controller parameters until the robot was able to accurately map the environment. Traveling through waypoints, the robot would follow a path that would avoid obstacles like walls and end facing a wall to read the sign to get directions to the goal.

## Object Detection

I implemented a KNN algorithm that ran locally on the robot to process images and identify signs. The image dataset used to train the algorithm included a provided sign image dataset and additional images of signs collected in the maze. Images are processed by filtering signs, dynamically cropping the area around the sign, and centering the image on the sign. In training, the images are further processed using random crops, rotations, noise, and color jittering to help make the algorithm more robust. The algorithm extracts a feature vector of both pixel intensities and color features which provides more detail for classification. The KNN algorithm achieved a 95% accuracy on a test dataset of separate sign images.

## Control

Low-level control uses a PID controller to provide velocity commands to the motors. For obstacle avoidance, I implemented a Go to Goal controller that used odometry and LiDAR data to avoid obstacles while travelling towards the goal. The robot was able to move towards arbitrary goal positions while avoiding obstacle vectors detected from LiDAR data. Using the ROS 2 navigation stack the robot added full mapping, localization, and global navigation while still avoiding obstacles as the robot travelled between waypoints.
