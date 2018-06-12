#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include <QDate>
#include <QDebug>

#define DATABASE_HOSTNAME   "ShapesDataBase"
#define DATABASE_NAME       "/home/andrii/QtProjects/myfigures/shapes.sqlite"

#define SHAPE_TABLE         "ShapeTable"
#define SCENE_ID            "SceneID"
#define SHAPE_TYPE          "ShapeType"
#define SHAPE_COLOR_R       "ColorRed"
#define SHAPE_COLOR_G       "ColorGreen"
#define SHAPE_COLOR_B       "ColorBlue"
#define SHAPE_ANGLE_X       "AngleX"
#define SHAPE_ANGLE_Y       "AngleY"
#define SHAPE_ANGLE_Z       "AngleZ"
#define SHAPE_XCORD         "Xcord"
#define SHAPE_YCORD         "Ycord"
#define SHAPE_ZCORD         "Zcord"
#define SHAPE_WIDTH         "Width"
#define SHAPE_HEIGHT        "Height"

class DataBase : public QObject {

    Q_OBJECT
public:
    explicit DataBase(QObject *parent = 0);
    ~DataBase();

private:

    QSqlDatabase    db;

public:

    void connectToDataBase();
    bool openDataBase();
    bool restoreDataBase();
    void closeDataBase();
    bool createDeviceTable();
    void showData();

    bool insertIntoDeviceTable(const QVariantList &data);
    void clearData(int);
    QVariantList getData(int);

    int getMaxSceneId();

};

#endif // DATABASE_H
