
# Vulkan and OpenGL under WSL with GLFW and GLAD

### Work in Progress - This repository serves as a personal reference.

## 1. Enable GUI Applications on WSL

### Requirements:
- Windows 10 Build 19044+ or Windows 11.
- Latest GPU driver update (NVIDIA, AMD, or Intel).

### 1.1 Install WSL using PowerShell with administrator privileges:
```shell
    wsl --install
```

### 1.2 Update WSL:
```shell
    wsl --update
```

### 1.3 Reboot WSL:
```shell
    wsl --shutdown
```

## 2. Update and Install Dependencies
First, update the package list:
```shell
    sudo apt update
```
Then, install necessary applications:
```shell
    sudo apt install x11-apps nautilus gnome-text-editor -y
```

### Test Installation:
To verify that everything is set up correctly, run:
```shell
    gedit test.txt
```

## 3. Install GLFW
You can either build GLFW from source or use the binaries from the [GLFW website](https://www.glfw.org/).

### 4. Download GLFW Source
Clone the GLFW repository and place it in the project folder under `libs/`:
```shell
    git clone https://github.com/glfw/glfw
```

## 5. Obtain OpenGL Loaders (GLAD)
Download GLAD from [GLAD's Generator](https://gen.glad.sh/) and copy the files to the `libs/` directory.

## 6. Create a CMake File
Ensure you have a CMake file set up to manage your project.

## 7. Build and Run the Project
Follow these steps to compile and execute your application:
```shell
# Create a build folder
mkdir build
cd build

# Run CMake from inside the build folder
cmake ..

# Build the project
make

# Execute the compiled program
./ProjectName
```

## Additional Resources
For a detailed guide -> [Microsoft WSL GUI Applications Walkthrough](https://learn.microsoft.com/pt-br/windows/wsl/tutorials/gui-apps).

### Using XMing or XServer
If you are using XMing or XServer, when lauching the app do this:

- Disable the "Native OpenGL" option.
- Check "Disable Access Control."

then, add the following to your `.bashrc` or `.zshrc`

```shell
export DISPLAY=$(ip route list default | awk '{print $3}'):0
export LIBGL_ALWAYS_SOFTWARE=1
```
