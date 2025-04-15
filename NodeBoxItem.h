// NodeBoxItem.h
#pragma once
#include <QGraphicsItemGroup>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsTextItem>
#include <QColor>
#include <QPen>
#include <QFont>
#include <QGraphicsScene>

class NodeBoxItem : public QGraphicsItemGroup {
public:
    NodeBoxItem(QGraphicsScene *scene, QPointF position, const QString& nodeTitle, const QPixmap& image) {
        // Outer box
        QGraphicsRectItem* box = new QGraphicsRectItem(0, 0, 280, 350);
        box->setBrush(QColor(25, 25, 25));
        box->setPen(QPen(Qt::black));
        this->addToGroup(box);

        // Title
        QGraphicsTextItem* title = new QGraphicsTextItem(nodeTitle);
        title->setFont(QFont("Arial", 14, QFont::Bold));
        title->setDefaultTextColor(Qt::white);
        title->setPos(15, 10);
        this->addToGroup(title);

        // Image
        QGraphicsPixmapItem* imageItem = new QGraphicsPixmapItem(image.scaled(250, 130, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        imageItem->setPos(15, 40);
        this->addToGroup(imageItem);

        // Buttons
        QStringList buttonLabels = {"Edit Image", "Delete", "Download"};
        for (int i = 0; i < buttonLabels.size(); ++i) {
            int btnY = 190 + i * 50;

            QGraphicsRectItem* btn = new QGraphicsRectItem(15, btnY, 250, 40);
            btn->setBrush(QColor(200, 200, 255));
            btn->setPen(QPen(Qt::black));
            this->addToGroup(btn);

            QGraphicsTextItem* btnText = new QGraphicsTextItem(buttonLabels[i]);
            btnText->setFont(QFont("Arial", 11));
            btnText->setPos(25, btnY + 10);
            this->addToGroup(btnText);
        }

        this->setPos(position);
        scene->addItem(this);
    }
};
