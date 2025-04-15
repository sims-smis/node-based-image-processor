#include "GraphicsView/ZoomableGraphicsView.h"
#include <QScrollBar>
// #include "leftSidebarHeader/NodeItem.h"
#include <QMimeData>
#include <QDrag>
#include <QGraphicsScene>

class BaseNode;
ZoomableGraphicsView::ZoomableGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);
    setDragMode(QGraphicsView::NoDrag);  // we'll handle custom drag
    setSceneRect(-5000, -5000, 10000, 10000);  // virtually infinite canvas

    customScene = new QGraphicsScene(this);  // ✅ create your scene here
    setScene(customScene);                                    // ✅ set it to the view

}

void ZoomableGraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0 && zoomLevel < zoomClampMax) {
        scale(zoomStep, zoomStep);
        zoomLevel++;
    } else if (event->angleDelta().y() < 0 && zoomLevel > zoomClampMin) {
        scale(1.0 / zoomStep, 1.0 / zoomStep);
        zoomLevel--;
    }
}

void ZoomableGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::MiddleButton || event->button() == Qt::LeftButton) {
        isPanning = true;
        lastMousePos = event->pos();
        setCursor(Qt::ClosedHandCursor);
    } else {
        QGraphicsView::mousePressEvent(event);
    }
}

void ZoomableGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (isPanning) {
        QPoint delta = event->pos() - lastMousePos;
        lastMousePos = event->pos();
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
    } else {
        QGraphicsView::mouseMoveEvent(event);
    }
}

void ZoomableGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (isPanning && (event->button() == Qt::MiddleButton || event->button() == Qt::LeftButton)) {
        isPanning = false;
        setCursor(Qt::ArrowCursor);
    } else {
        QGraphicsView::mouseReleaseEvent(event);
    }
}
