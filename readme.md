# Denoising Package

This ROS 1 package provides a node for denoising point cloud data. The node reads a Point Cloud Data (PCD) file, applies a statistical outlier removal filter, and publishes the denoised point cloud.

## Dependencies
- ROS 1 (Robot Operating System)
- PCL (Point Cloud Library)

## Installation
1. Make sure you have ROS 1 installed. If not, follow the [ROS installation instructions](http://wiki.ros.org/ROS/Installation).
2. Install the Point Cloud Library (PCL) by running:
    ```
    sudo apt-get install ros-<distro>-pcl-ros
    ```
    Replace `<distro>` with your ROS distribution (e.g., melodic, noetic).
3. Clone this repository into your ROS workspace:
    ```
    git clone https://github.com/HesamTaherzadeh/ROS_enabled_SOR/tree/main
    ```
4. Build the package using `catkin_make`.

## Usage
1. Launch ROS master if it's not already running:
    ```
    roscore
    ```
2. Launch the denoising node:
    ```
    rosrun pointcloud_denoising_cpp denoising pcd_file_path:=/path/to/pcd
    ```

## Parameters
- `pcd_file_path` (string): Path to the PCD file to be denoised.

### Published Topics
- `/denoised_pointcloud` (sensor_msgs/PointCloud2): Denoised point cloud data.

## How It Works
1. The node reads the path to the PCD file from the ROS parameter server.
2. It loads the point cloud data from the specified PCD file.
3. A statistical outlier removal filter is applied to the point cloud data to remove noise.
4. The denoised point cloud is published on the `/denoised_pointcloud` topic.
