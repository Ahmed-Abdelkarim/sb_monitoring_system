# SB Monitoring System

![Language](https://img.shields.io/badge/language-C++-blue)

## Table of Contents

1. [About](#about)
2. [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
    - [Docker Usage](#docker-usage)
3. [Project Structure](#project-structure)
4. [Contact](#contact)

---

## About

**SB Monitoring System** is a C++ application is an interview task for C++ developer role at Sonnen GmbH. This project utilizes OOP and C++11 features to implement a monitoring system for sonnenbattries.


## Getting Started

These instructions will help you set up a copy of the project on your local machine for development and testing purposes.

### Prerequisites

- C++14 or later
- CMake version 3.5 or later
- Google Test for unit testing

### Installation

1. **Clone the repository:**
    ```bash
    git clone https://github.com/Ahmed-Abdelkarim/sb_monitoring_system.git
    cd sb_monitoring_system
    ```

2. **Build the project using CMake:**
    ```bash
    mkdir build
    cd build
    cmake ..
    cmake --build .
    ```

3. **Run the executable:**
    ```bash
    ./sb
    ```

### Docker Usage

To run this project using Docker, follow these steps:

1. **Pull the Docker image:**
    ```bash
    docker pull ahmedabdelkarim1/sb_monitoring_system:latest
    ```

2. **Run the Docker container:**
    ```bash
    docker run --rm ahmedabdelkarim1/sb_monitoring_system:latest
    ```

3. **Access the container's terminal (if needed):**
    ```bash
    docker run -it --rm username/project-name:latest /bin/bash
## Project Structure

```
project-name/
│
├── src/                    # Source files
│   ├── main.cpp            # Main entry point
│   ├── HouseOwner.cpp      
│   ├── HouseGrid.cpp
│   ├── Grid.cpp
│   ├── PV.cpp
│   ├── Network.cpp
│   ├── sbStorage.cpp
│   └── installation.cpp
│
├── include/                # Header files
│   ├── PowerEntity.h       # Abstract Class
│   ├── HouseOwner.h              
│   ├── HouseGrid.h
│   ├── Grid.h
│   ├── PV.h
│   ├── Network.h
│   ├── sbStorage.h
│   └── installation.h
│
│
├── CMakeLists.txt          # CMake build script
├── Dockerfile              # Docker file
└── README.md               # Project README
```


## Contact

- **Ahmed Abdelhafez** - [ahmedabdelhafez20111@gmail.com](ahmedabdelhafez20111@gmail.com)
- **Project Link**: [https://github.com/Ahmed-Abdelkarim/sb_monitoring_system.git](https://github.com/Ahmed-Abdelkarim/sb_monitoring_system.git)

---
