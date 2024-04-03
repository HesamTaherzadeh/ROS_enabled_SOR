#ifndef DENOISING_NODE_H
#define DENOISING_NODE_H

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/statistical_outlier_removal.h>

class DenoisingNode {
public:
    DenoisingNode();
    void run();

private:
    ros::NodeHandle nh;
    ros::Publisher cloud_pub;

    void removeOutliers(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr& input_cloud,
                        pcl::PointCloud<pcl::PointXYZRGB>::Ptr& output_cloud);
};

#endif // DENOISING_NODE_H
