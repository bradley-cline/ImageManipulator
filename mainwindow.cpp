#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QFileDialog"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up button connections
    connect(ui->btnAverage, &QPushButton::released, this, &MainWindow::Average);
    connect(ui->btnBrowse, &QPushButton::released, this, &MainWindow::Browse);
    connect(ui->btnFlip, &QPushButton::released, this, &MainWindow::Flip);
    connect(ui->btnGreyscale, &QPushButton::released, this, &MainWindow::Greyscale);
    connect(ui->btnProcess, &QPushButton::released, this, &MainWindow::Process);
    connect(ui->btnReset, &QPushButton::released, this, &MainWindow::Reset);

    // Set up button tooltips
    ui->btnAverage->setToolTip("Calculate the mean pixel value if image is greyscale");
    ui->btnBrowse->setToolTip("Select an image to manipulate");
    ui->btnFlip->setToolTip("Vertically mirror the image");
    ui->btnGreyscale->setToolTip("Convert image to greyscale");
    ui->btnProcess->setToolTip("Flip, greyscale, and average the ORIGINAL image");
    ui->btnReset->setToolTip("Clears all processing done on the image");

    // Color process and reset buttons
    ui->btnReset->setStyleSheet("QPushButton {background-color: rgb(213, 184, 184); color: rgb(119, 118, 123);}\n"
                                "QPushButton:enabled {background-color: rgb(192, 28, 40); color: white;}");
    ui->btnProcess->setStyleSheet("QPushButton {background-color: rgb(148, 164, 206); color: rgb(119, 118, 123);}\n"
                                  "QPushButton:enabled {background-color: rgb(26, 95, 180); color: white;}");
}


MainWindow::~MainWindow()
{
    delete ui;
}


/*
 * Calculates average pixel value for greyscaled image, rounded down to nearest integer
 */
void MainWindow::Average()
{
    int sum = 0;
    int totalPixels = m_processedImage.width() * m_processedImage.height();

    for (int x = 0; x < m_processedImage.width(); x++)
    {
        for (int y = 0; y < m_processedImage.height(); y++)
        {
            sum += QColor(m_processedImage.pixel(x, y)).value();
        }
    }

    // Set average pixel value
    ui->lblAverage->setText(QString::number(sum/totalPixels));
    ui->lblAverage->setEnabled(true);

    if (m_processing)
        return;

    // Set recent command label and button states
    ui->lblLastCommand->setText("Calculated average pixel value");
    ui->btnAverage->setEnabled(false);
    ui->btnReset->setEnabled(true);
}


// Opens file browser to allow image file selection
void MainWindow::Browse()
{
    m_imageFile = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Image Files (*.jpeg *.jpg *.png)"));

    // Return if no file is selected
    if (m_imageFile.isEmpty())
    {
        qDebug("No image file selected");
        return;
    }


    // Return if selected file can't be loaded as a QImage
    if (!m_originalImage.load(m_imageFile) || !m_processedImage.load(m_imageFile))
    {
        QMessageBox warning;
        warning.setText(QString("%1 is not a valid image file. Please select a different file.").arg(m_imageFile));
        warning.exec();
        return;
    }

    ui->lblImageFile->setText(m_imageFile);

    // Set original image and processed image initially to the loaded image file
    ui->lblOriginalImage->setPixmap(QPixmap::fromImage(m_originalImage));
    ui->lblOriginalImage->setScaledContents(true);
    RefreshImages();

    // Set recent command label and button states
    ui->lblLastCommand->setText("New image file loaded");
    ui->btnFlip->setEnabled(true);
    ui->btnGreyscale->setEnabled(true);
    ui->btnProcess->setEnabled(true);
}


/*
 * Vertically mirrors image (flips image upside down)
 */
void MainWindow::Flip()
{
    // If calling Flip from the processing command, start with original image, as processed image might already be altered
    if (m_processing)
    {
        m_processedImage = QImage(m_originalImage.mirrored(false, true));
        RefreshImages();
        return;
    }

    m_processedImage = QImage(m_processedImage.mirrored(false, true));
    RefreshImages();

    // Set recent command label and button states
    ui->lblLastCommand->setText("Vertically mirrored image");
    ui->btnReset->setEnabled(true);
}


/*
 * Converts 'processed image' from color to 16 bit greyscale
 */
void MainWindow::Greyscale()
{
    m_processedImage = m_processedImage.convertToFormat(QImage::Format_Grayscale16);
    RefreshImages();

    if (m_processing)
        return;

    // Set recent command label and button states
    ui->lblLastCommand->setText("Converted image to greyscale");
    ui->btnAverage->setEnabled(true);
    ui->btnGreyscale->setEnabled(false);
    ui->btnReset->setEnabled(true);
}


/*
 * Works on original image, not on current state of processed image
 * 1. Flips original image
 * 2. Greyscales flipped original image
 * 3. Calculates average of flipped, greyscaled original image
 */
void MainWindow::Process()
{
    // Perform all manipulations
    m_processing = true;
    Flip();
    Greyscale();
    Average();
    m_processing = false;

    // Set recent command label and button states
    ui->lblLastCommand->setText("Flipped image, converted to greyscale, and calculated average pixel value");
    ui->btnAverage->setEnabled(false);
    ui->btnGreyscale->setEnabled(false);
    ui->btnProcess->setEnabled(false);
    ui->btnReset->setEnabled(true);
}


/*
 * Resets 'processed image' to 'original image'
 * Resets all button enable states.
 */
void MainWindow::Reset()
{
    // Reset 'processed image'
    m_processedImage = m_originalImage;
    RefreshImages();

    // Reset average label
    ui->lblAverage->setText("Not calculated yet");
    ui->lblAverage->setEnabled(false);

    // Set recent command label and button states
    ui->lblLastCommand->setText("Reset - removed processing from 'processed image'");
    ui->btnAverage->setEnabled(false);
    ui->btnFlip->setEnabled(true);
    ui->btnGreyscale->setEnabled(true);
    ui->btnProcess->setEnabled(true);
    ui->btnReset->setEnabled(false);
}


/*
 *  Loads the displayed images.
 *  Run on initialized loading and on all reloads.
 *  Could ultimately just reload the processed image, but this makes the code visually cleaner.
 */
void MainWindow::RefreshImages()
{
    ui->lblOriginalImage->setPixmap(QPixmap::fromImage(m_originalImage));
    ui->lblOriginalImage->setScaledContents(true);
    ui->lblProcessedImage->setPixmap(QPixmap::fromImage(m_processedImage));
    ui->lblProcessedImage->setScaledContents(true);
}
