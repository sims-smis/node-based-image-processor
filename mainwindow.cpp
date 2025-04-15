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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

}

