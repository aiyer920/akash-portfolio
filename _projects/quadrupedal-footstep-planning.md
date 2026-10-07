---
layout: project
title: "Graph Search and Trajectory Optimization for Quadrupedal Footstep Planning"
description: "This project will expand on the QuadPIPs planning architecture and investigate faster planning approaches such as receding horizon and investigate methods to evaluate dynamic feasibility."
overview_citation:
  url: "https://quadpips.github.io/"
  title: "QuadPiPS: A Perception-informed Footstep Planner for Quadrupeds With Semantic Affordance Prediction"
date: 2026-10-06
categories: [ROS, Gazebo, Kinematics, Path Planning, C++, Linux]
featured_image: "/assets/images/projects/quadpips/Go2.png"

gallery:
  - type: "image"
    file: "/assets/images/projects/quadpips/Go2.png"
    description: "The real Go2 quadruped"
  - type: "video"
    file: "/assets/images/projects/quadpips/Screencast 2026-02-28 13_49_54.mp4"
    description: "QuadPIPs demonstration"
    tall: true
  - type: "image"
    file: "/assets/images/projects/quadpips/perception.png"
    description: "Quadruped perception visualization"
---

## Overview 
This project focuses on two aspects of the QuadPIPs footstep planner. One focus is exploring approaches to increasing the planning/replanning speed of the QuadPIPs footstep planner to provide real time performance. Another focus is implementing methods to evaluate dynamic feasibility in the graph search. These methods are implemented in a simulation environment and tested on a real quadrupedal robot. This project gives opportunities to investigate robot motion planning, kinematics, dynamics, and environment representation. We expect to develop comparisons of various search and dynamics evaluation methods, as well as implementations of these algorithms.

## Key Features

This project revolves around improving planning speed for the QuadPips footstep planner, including Weighted A*, anytime search, Multi-Heuristic A*, and receding-horizon approaches, to evaluate their impact on planning latency and path quality. It also investifates checks that identify difficult or unstable foothold transitions before they reach trajectory optimization, combining kinematic reasoning with candidate dynamic-feasibility methods. Planned simulation comparisons cover stairs, stepping stones, and open maps, measuring search effort, trajectory-optimization success, and the robot's ability to reach its goal. The most promising search and feasibility methods will be combined and evaluated on the Unitree Go2 after simulation screening, with attention to replanning stability and failure modes.

## Planning Speed

The starting point for this investigation is the QuadPiPS graph-search stage, which uses vanilla A* with a Euclidean-distance heuristic and kinematic reachability checks. My goal is to determine whether alternative search and replanning strategies can reduce the delay between receiving an environment representation and producing a usable footstep plan.

Candidate approaches include Weighted A*, anytime methods such as ARA* and ANA*, Multi-Heuristic A*, receding-horizon planning, and delay-tolerant planning. I will compare these methods against the original search across multiple simulation maps. The evaluation will measure time to the first path, total search time, node expansions, and replanning frequency, alongside path quality and goal success.

The comparison will also examine where any speedup comes from: expanding fewer nodes, reducing the cost of each expansion, or changing how often replanning is needed. Faster search is only useful if it continues to produce plans that the downstream trajectory optimizer and robot can execute. Search overhead and the tradeoff between speed and solution quality will therefore guide which approaches move forward to integrated testing.

## Planning Fidelity

Planning fidelity focuses on whether the selected footsteps can lead to stable, executable motion. Kinematic reachability alone does not establish dynamic feasibility, so a contact sequence that passes graph-search checks can still produce a difficult configuration for trajectory optimization. I am investigating ways to evaluate these transitions earlier in the planning pipeline.

Candidate methods include transition inverse-kinematics checks between graph search and trajectory optimization, differential inverse kinematics, centroidal or other reduced-order dynamic checks, and stronger stance and transition constraints. An additional direction is an experience-based heuristic informed by previous trajectory-optimization failures, so the search can use information about configurations that have been difficult to execute.

I will evaluate these methods using trajectory-optimization success, unstable configurations, goal success, and the computational cost of feasibility checks. The evaluation will also consider reference-trajectory smoothness, since valid footholds alone may not eliminate abrupt motion references. A key tradeoff is avoiding overly conservative checks that reject useful footsteps while still filtering out problematic transitions.

After evaluating the methods individually, I plan to combine the most promising feasibility checks with the selected search strategy and compare the integrated planner against the original QuadPiPS baseline. Simulation results will guide subsequent Unitree Go2 testing, where sensing noise, contact uncertainty, latency, and controller limits may affect performance.
