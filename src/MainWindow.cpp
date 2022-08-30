#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(-300, -300, 600, 600);

    Ship *ship = new Ship();
    Viko *viko = new Viko();

    scene->addItem(viko);
    scene->addItem(ship);

    double course = 33;
    ship->setCourse(course);
    viko->setCourse(course);
}

MainWindow::~MainWindow()
{
    delete ui;
}

