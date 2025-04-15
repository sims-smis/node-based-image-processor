#ifndef ZOOMABLEGRAPHICSVIEW_H
#define ZOOMABLEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QPointF>

class ZoomableGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    explicit ZoomableGraphicsView(QWidget *parent = nullptr);
    QGraphicsScene* customScene;

protected:
    void wheelEvent(QWheelEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint lastMousePos;
    bool isPanning = false;
    const qreal zoomStep = 1.15;
    const int zoomClampMin = -20;
    const int zoomClampMax = 20;
    int zoomLevel = 0;
};

#endif // ZOOMABLEGRAPHICSVIEW_H
