Task 3 - OpenCV Video Capture with Multithreading and Screenshot Feature
=======================================================================

This application captures video from the webcam, displays it in a window,
saves the video to a file, and allows the user to take a screenshot of the current frame
by pressing a key. It uses OpenCV and multithreading to ensure smooth performance.

--------------------------------------------------------------------------------
Requirements:
--------------------------------------------------------------------------------
- OpenCV installed and properly configured for C++
- C++ compiler (g++, Visual Studio, etc.)
- Webcam or external camera connected

--------------------------------------------------------------------------------
How to Install OpenCV (Windows - via vcpkg):
--------------------------------------------------------------------------------
1. Download vcpkg from GitHub: https://github.com/microsoft/vcpkg
2. Open PowerShell and run:
   git clone https://github.com/microsoft/vcpkg
   .\vcpkg\bootstrap-vcpkg.bat
3. Install OpenCV:
   .\vcpkg\vcpkg install opencv4
4. Integrate with your compiler if needed:
   .\vcpkg\vcpkg integrate install

--------------------------------------------------------------------------------
How to Compile:
--------------------------------------------------------------------------------
Example g++ command for Linux:
   g++ main.cpp -o VideoApp `pkg-config --cflags --libs opencv4`

Example for Windows (adjust paths accordingly):
   g++ main.cpp -o VideoApp.exe -I"path\to\opencv\include" -L"path\to\opencv\lib" -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs

Make sure your system paths are correctly set if you use OpenCV globally.

--------------------------------------------------------------------------------
How to Run:
--------------------------------------------------------------------------------
1. Run the compiled file:
   ./VideoApp   (Linux or terminal)
   VideoApp.exe (Windows)

2. Controls:
   - Press 's' to take a snapshot (image will be saved in the same folder)
   - Press 'q' to quit the video window

--------------------------------------------------------------------------------
Output:
--------------------------------------------------------------------------------
- Video is saved as `output.avi`
- Snapshots are saved as `snapshot_<timestamp>.png`

--------------------------------------------------------------------------------
Notes:
--------------------------------------------------------------------------------
- Make sure no other application is using the webcam
- If OpenCV is not found, check your include/lib paths
- Tested on OpenCV 4.x

--------------------------------------------------------------------------------
