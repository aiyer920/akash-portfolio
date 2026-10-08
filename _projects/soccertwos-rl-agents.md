---
layout: project
title: "SoccerTwos RL Agents"
description: "In this project, I trained a striker and goalie agent using a curriculum-based reinforcement learning architecture in the physics-based SoccerTwos environment."
categories: [Reinforcement Learning, PyTorch, Python]
filter_categories: [Machine Learning]
featured_image: "/assets/images/projects/soccer-bot/featured.jpg"
github_url: "https://github.com/aiyer920/soccertwos_finalproject"
github_below_content: true
github_label: "SoccerTwos Project GitHub"

gallery:
  - type: "video"
    file: "/assets/images/projects/soccer-bot/Model Based FC Agent vs Baseline Agent.mp4"
    description: "Model Based FC Agent vs Baseline Agent"
  - type: "image"
    file: "/assets/images/projects/soccer-bot/Bootstrapped_training.png"
    description: "Bootstrapped training architecture"
---

## Overview

In this project, I trained a goalie and striker agent with reinforcement learning in SoccerTwos. The environment's sparse goal rewards make it difficult for agents to discover useful behavior through exploration alone. I combined Proximal Policy Optimization (PPO), role-specific reward shaping, and a five-lesson curriculum to develop complementary striker and goalie policies.

## Key Features

Our SoccerTwos agents had specialized team roles. Each agent had separate rewards that encouraged the goalie to defend its own half and remain behind the ball, while encouraging the striker to advance and create scoring opportunities. Our architecture featured a five-lesson curriculum that moved from simplified ball-handling and defensive scenarios to randomized adversarial play. Agents were trained from scratch and fine-tuned from a baseline policy, exploring different starting points for learning the same team roles.

## Architecture

The learning system used PPO with separate striker and goalie policies. The actor and critic networks each used two fully connected hidden layers with 256 units per layer and ReLU activations. PPO's clipped objective limited the incentive for large policy changes during an update, helping stabilize learning from noisy and infrequent scoring events.

A reward wrapper added role-specific signals to the environment rewards. The goalie received a small reward for occupying a defensive zone and a penalty when positioned ahead of the ball. The striker received a reward for occupying the offensive half and a potential-based scoring reward when within five units of the ball. Both agents received an action-change penalty whose strength depended on the current curriculum lesson.

The curriculum controlled the initial positions of the ball and players, the difficulty of the opening scenario, and the action-change penalty. This connected the training task to the behaviors the agents needed to learn: first handling simple scoring and blocking situations, then adapting those skills to opponents and randomized starts.

## Training and Evaluation

Training progressed through five lessons:

1. **Simplified defense and scoring:** The ball rolled slowly toward the team's goal, the goalie started centrally, and the striker began near the opposing goal. Opponents were positioned far away to simplify the task.
2. **Faster defensive play:** Opponents were introduced into play and the ball rolled toward the goal more quickly, increasing the demands on the goalie.
3. **Randomized opposition:** The goalie started in goal and the striker in midfield, while the ball and opponents spawned at random positions.
4. **General play:** All players and the ball spawned at random positions.
5. **Stricter general play:** Randomized play continued with stronger penalties and a higher lesson-completion threshold.

The results show that role-specific reward shaping combined with curriculum learning accelerates convergence, increases reward, and encourages structured team behaviors in the SoccerTwos environment. The agent trained from scratch converged rapidly against the random agent, which demonstrates that our dense reward signal provided sufficient learning signal to overcome the sparse goal reward.

For the bootstrapped agents, the reward drop between lessons shows that transitioning to a new task can temporarily destabilize learning as the agent learns to adapt previously learned skills to a more difficult scenario. The continued improvement between lessons suggests that earlier curricula successfully scaffolded the foundational behaviors needed to succeed in later stages.
