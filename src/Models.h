#ifndef MODELS_H
#define MODELS_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsObject>
#include <QRegion>
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QtMath>
#include <QLabel>
#include <QGraphicsTextItem>
#include <QGraphicsSvgItem>
#include <QSvgRenderer>
#include <QIcon>
#include <QTextItem>


class Ship : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Ship(QGraphicsObject *parent = nullptr) :
        QGraphicsObject(parent)
    {

    }
    void setCourse(double course);


signals:

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

class Viko : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Viko(QGraphicsObject *parent = nullptr);

signals:

    // QGraphicsItem interface
public:
    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void setCourse(double course);

private:
    double currentCourse;
    QGraphicsTextItem *text1;
    QFont font;

};

#endif // MODELS_H
