# ImageManipulator

## Part 1 - The Image Manipulator Qt App
This application was built on Ubuntu Linux. The bulk of the work is contained inside the `mainwindow.cpp` file. See the `QtAppDemo.mp4` video for a quick demo

## Part 2 - The Batch Manipulator python script
This script `batch-manipulator.py` in the `BatchManipulator` directory takes as input a directory and searches it for supported image files (currently supported file types include .jpg .jpeg .png and .tiff.

If provided with a directory that contains suitable image files, the script will read in each image file in the directory and perform the following actions:

1. Flip the image vertically (upside down)
2. Convert the image to greyscale
3. Compute the average pixel value for each image

After each of the operations above, a copy of the altered image will be saved in a subdirectory of the current working directory as follows, respectively:

1. Images_Flipped
2. Images_Greyscale
3. Imaged_Final
   
#### Usage
`python batch-manipulator.py <some_directory_containing_image_files>`

#### Prereqs
- Must have opencv-python installed and its dependencies
