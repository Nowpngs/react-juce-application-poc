# React JUCE Application POC

## Setup

### Prerequisites

Before starting, ensure you have the following installed:

- **CMake**: Required for generating the build system. [Download CMake here](https://cmake.org/download/).

### Build & Install

Follow these steps to build and install your plugin:

1. **Clone the repository:**

   Start by cloning the repository to your local machine:

   ```bash
   git clone <your-repo-url>
   cd <your-repo-folder>
   ```

2. **Configure the project:**

   ```bash
   cmake -S . -B build
   ```

   This command will create a build directory where all the build files and dependencies will be placed.

3. **Build this plugin:**
   After configuring, build the plugin using:

   ```bash
   cmake --build build
   ```

   This will compile your plugin and create the necessary binaries.
