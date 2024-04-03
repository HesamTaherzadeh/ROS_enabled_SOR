#include "denoising.hpp"

DenoisingNode::DenoisingNode() : nh("~") {
    std::string pcd_file_path;
    nh.getParam("pcd_file_path", pcd_file_path);

    cloud_pub = nh.advertise<sensor_msgs::PointCloud2>("denoised_pointcloud", 1);

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGB>);
    if (pcl::io::loadPCDFile<pcl::PointXYZRGB>(pcd_file_path, *cloud) == -1) {
        ROS_ERROR("Couldn't read PCD file.");
        ros::shutdown();
    }

    pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud_filtered(new pcl::PointCloud<pcl::PointXYZRGB>);
    removeOutliers(cloud, cloud_filtered);

    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(*cloud_filtered, output);
    output.header.frame_id = "map";
    cloud_pub.publish(output);
}

void DenoisingNode::removeOutliers(const pcl::PointCloud<pcl::PointXYZRGB>::Ptr& input_cloud,
                                   pcl::PointCloud<pcl::PointXYZRGB>::Ptr& output_cloud) {
    pcl::StatisticalOutlierRemoval<pcl::PointXYZRGB> sor;
    sor.setInputCloud(input_cloud);
    sor.setMeanK(50);
    sor.setStddevMulThresh(1.0);
    sor.filter(*output_cloud);
}

void DenoisingNode::run() {
    ros::spin();
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "denoising");
    DenoisingNode denoising_node;
    denoising_node.run();
    return 0;
}
