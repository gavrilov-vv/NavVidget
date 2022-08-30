#include "Models.h"

void Ship::setCourse(double course)
{
    qreal currentAngle = rotation();
    qreal angle = course - currentAngle;

    setRotation(currentAngle + angle);
    update();
}

QRectF Ship::boundingRect() const
{
    return QRectF(-300, -300, 600, 600);
}

void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    painter->setRenderHint(QPainter::Antialiasing);

    QPen pen =  QPen(QColor("FireBrick"));
    pen.setWidth(3);
    pen.setStyle(Qt::DashDotLine);
    painter->setPen(pen);
    painter->setBrush(QBrush(QColor("FireBrick")));
    painter->setPen(pen);
    setZValue(5);
    QPixmap p = QPixmap(":/drawing.svg");

    painter->drawPixmap(-64, -64, 128, 128, p);

    painter->drawLine(0, -25, 0, -280);

//    QPen pen1 = QPen(QColor("FireBrick"));
//    pen1.setWidth(8);
//    painter->setOpacity(1);
//    painter->setPen(pen1);
//    painter->drawPoint(0, -280);


}

Viko::Viko(QGraphicsObject *parent) : QGraphicsObject(parent),
    currentCourse{0.0},
    text1{new QGraphicsTextItem("")}
{
    font.setPixelSize(18);
    font.setBold(true);
    font.setFamily("Arial");

    text1->setPos(200, -300);
    text1->setFont(font);
    text1->setDefaultTextColor(Qt::blue);
}

QRectF Viko::boundingRect() const
{
    return QRectF(-300, -300, 600, 600);
}

void Viko::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)


    painter->setFont(font);

    QPixmap p = QPixmap(":/compas_29082022.png");
    painter->drawPixmap(-300, -300, 600, 600, p);

    painter->drawText(-300,
                      -300,
                      QString("К:    %1°").arg(currentCourse));

    painter->drawText(-300,
                      -270,
                      QString("V:    %1 уз.").arg(12));

    painter->drawText(200,
                      -300,
                      QString("Ш:    %1").arg("60°42'34\""));

    painter->drawText(200,
                      -270,
                      QString("Д:    %1").arg("30°23'42\""));


}

void Viko::setCourse(double course)
{
    currentCourse = course;
    update();
}
