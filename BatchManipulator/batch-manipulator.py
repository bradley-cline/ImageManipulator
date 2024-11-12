import cv2 as cv # type: ignore
import sys
import os
import shutil


# Intermediate results directories constants
FLIPPED = './Images_Flipped/'
GREYSCALE = './Images_Greyscale/'
FINAL = './Images_Final/'


def flip_image(image, imageName):
	image = cv.flip(image, 0)
	success = cv.imwrite((FLIPPED + "flipped_" + imageName), image)
	if success:
		print("Succesfully flipped image and saved the output to " + FLIPPED + "flipped_" + imageName)
	
	return image


def to_greyscale(image, imageName):
	image = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
	success = cv.imwrite((GREYSCALE + "grey_" + imageName), image)
	if success:
		print("Succesfully greyscaled the image and saved the output to " + GREYSCALE + "grey_" + imageName)
	
	return image


def find_average(image, imageName):
	mean = int(cv.mean(image)[0])
	success = cv.imwrite((FINAL + str(mean) + "_" + imageName), image)
	if success:
		print("The mean pixel value of the image is " + str(mean))
		print("The final image has been saved to " + FINAL + str(mean) + "_" + imageName)

	return success


def cleanup_directory(directoryPath):
	if os.path.exists(directoryPath):
		try:
			shutil.rmtree(directoryPath)
		except OSError:
			print("Error trying to remove output in folder " + directoryPath + "from a previous run")


def main():
	# Check for proper arguments
	if len(sys.argv) < 2 or len(sys.argv) > 2:
		print("usage: batch-manipulator.py <directory of images>")
		exit(1)
	elif not os.path.isdir(sys.argv[1]):
		print("usage: batch-manipulator.py <directory of images>")
		print("argument must be a directory")
		exit(1)

	# Save directory
	directory = sys.argv[1]

	# Get a list of all files in the specified directory with the following
	# file extensions: .jpeg, .jpg, .png, and .tiff
	# expand support for more file types by adding more types below. 
	files = [file for file in os.listdir(directory) if \
		  file.endswith('.jpeg') or \
		  file.endswith('.jpg') or \
		  file.endswith('.png') or \
		  file.endswith('.tiff')]
	
	# If no supported image files are found in the given directory
	if not files:
		print("Provided directory does not contain any supported image files.")
		print("Supported file types: .jpeg .jpg .png .tiff")

	# If there are intermediate folders in the run location from previous runs, empty them
	# Maybe overkill this way, but will guarantee only results from current run will be in
	# the run directory
	cleanup_directory(FLIPPED)
	cleanup_directory(GREYSCALE)
	cleanup_directory(FINAL)
	
	# Create intermediate folders to hold image results
	try:
		os.mkdir(FLIPPED)
		os.mkdir(GREYSCALE)
		os.mkdir(FINAL)
	except OSError:
		print("Error trying to create folders for output images")
		exit(1)

	# If there is a valid directory with valid image types, start image manipulation
	workingDirectory = os.getcwd()

	for file in files:
		# Open image with opencv
		fullPath = directory + file
		image = cv.imread(fullPath, -1)

		# Separator
		print("----------------")
		if image is None:
			print("Tried to load file " + fullPath + " and failed. Moving on.")
			continue
		else:
			print("Processing " + fullPath)

			# Flip the image
			image = flip_image(image, file)
			if image is None:
				print("Failed to flip " + fullPath + ". Moving on.")
				continue

			# Convert image to greyscale
			image = to_greyscale(image, file)
			if image is None:
				print("Failed to greyscale " + fullPath + ". Moving on.")
				continue
			
			# Find the mean pixel value of each image (I'm truncating any decimals here for simplicity)
			if not find_average(image, file):
				print("Failed to find or save averaged image. Moving on.")
				continue
			

if __name__ == "__main__":
	main()