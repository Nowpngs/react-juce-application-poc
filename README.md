# React JUCE Application POC

The **React JUCE Application POC** is a proof-of-concept exploring the integration of a JUCE-based C++ GUI application with a React frontend. It combines JUCE's native GUI capabilities with modern web technologies, showcasing how React-based interfaces can enhance the flexibility and dynamism of traditional C++ desktop apps, enabling a more streamlined and hybrid approach to desktop app development.

## Setup

### Prerequisites

Before starting, ensure you have the following installed:

- **CMake**: Required for generating the build system. [Download CMake here](https://cmake.org/download/).
- **Node.js & npm**: Required for managing frontend dependencies. [Download Node.js here](https://nodejs.org/).

### Build & Install

Follow these steps to build and install both the backend JUCE application and frontend React interface:

#### Backend Setup (JUCE GUI Application)

1. **Install backend dependencies:**

   ```bash
   make install-backend
   ```

   This will configure the backend JUCE application project using CMake and install any necessary dependencies.

2. **Build and run the backend:**
   Build the JUCE application using the following command:

   ```bash
   make run-backend
   ```

   This will compile the application and run it. The executable will be located in the specified build directory.

#### Frontend Setup (React Application)

1. **Install frontend dependencies:**

   ```bash
   make install-frontend
   ```

   This will install all the necessary npm packages for the React application.

2. **Run the frontend:**

   To start the frontend React application, use the following command:

   ```bash
   make run-frontend
   ```

## Coding Standard

#### Backend (C++/JUCE) Code Formatting

This project uses `clang-format` for the backend (JUCE application) and `prettier` for the frontend (React application) to maintain consistent coding standards.

1. **Install clang-format**

   Ensure you have `clang-format` installed on your system. On macOS, you can easily install it using Homebrew:

   ```bash
   brew install clang-format
   ```

2. **Format the backend code**

   Run the following command from the root directory of the project to format all `.cpp` and `.h` files in the backend directories:

   ```bash
   make format-style
   ```

   This will apply `clang-format` to all relevant files according to the style defined in your `.clang-format` file.

#### Frontend (React) Code Formatting

**Note:** Always format your code before committing changes to ensure that your code adheres to the project's coding standards. This helps maintain a consistent style across the codebase.

## License

This project is licensed under the MIT License. See the full license text in the [LICENSE](https://opensource.org/license/mit) file.
