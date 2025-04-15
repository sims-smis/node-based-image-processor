#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QGraphicsRectItem>
#include "../node-based-image-processor/GraphicsView/ZoomableGraphicsView.h"
#include <QDrag>
#include <QMimeData>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QListWidgetItem>
#include "NodeBoxItem.h"
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    // Cast your promoted QGraphicsView to ZoomableGraphicsView
    ZoomableGraphicsView* view = qobject_cast<ZoomableGraphicsView*>(ui->graphicsView);
    if (!view) {
        qWarning("Failed to cast graphicsView to ZoomableGraphicsView");
        return;
    }

    // Create and assign scene if not already
    QGraphicsScene* scene = new QGraphicsScene(this);
    view->setScene(scene);

    // Add test rectangle to see zoom working
    QGraphicsRectItem* testRect = new QGraphicsRectItem(0, 0, 100, 100);
    testRect->setBrush(Qt::blue);
    scene->addItem(testRect);



    // Initialize the scene for graphics view
    // QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);


    // Manually connect all buttons to the same slot
    connect(ui->imageInputButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->outputButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->brightnessButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->colorChannelButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->blurButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->thresholdButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->edgeDetectionButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->blendButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->noiseGenerationButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
    connect(ui->convFilterButton, &QPushButton::clicked, this, &MainWindow::onNodeButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNodeButtonClicked() {
    // Get the sender of the signal (the button that was clicked)
    QPushButton* senderBtn = qobject_cast<QPushButton*>(sender());
    if (!senderBtn) return;

    QString nodeTitle = senderBtn->text();

    if (lastPos == QPointF(0, 0)) {
        QPointF center = ui->graphicsView->mapToScene(ui->graphicsView->viewport()->rect().center());
        lastPos = QPointF(center.x() - ui->graphicsView->width() / 2 + 50, center.y() - 150);
    }

    // Create your pixmap here if needed
    QPixmap image(":/assets/" + senderBtn->text().toLower() + ".png");  // optional
    auto nodeItem = new NodeBoxItem(ui->graphicsView->scene(), lastPos, nodeTitle, image);
    lastPos.setX(lastPos.x() + 300);  // move to next pos
}




void MainWindow::on_brightnessButton_clicked()
{
    cout<<"hheheheh"<<endl;
}

