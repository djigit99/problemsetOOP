#include "database.h"

DataBase::DataBase(QObject *parent) :
    QObject(parent) {

}

DataBase::~DataBase() {
    db.close();
}

void DataBase::connectToDataBase() {
    if(QFile(DATABASE_NAME).exists()) {
        this->restoreDataBase();
    } else {
        this->openDataBase();
    }
}

bool DataBase::restoreDataBase() {
    if(this->openDataBase()){
        if(!this->createDeviceTable()){
            return false;
        } else {
            return true;
        }
    }
    qDebug() << "Can not restore database";
    return false;
}

bool DataBase::openDataBase() {

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    qDebug() << db.databaseName();
    if ( db.open() ) {
        return true;
    }
    return false;
}

void DataBase::closeDataBase() {
    db.close();
}

bool DataBase::createDeviceTable() {

    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " SHAPE_TABLE " ( "
                            SCENE_ID            " INTEGER(4)     NOT NULL,"
                            SHAPE_TYPE          " VARCHAR(8)     NOT NULL,"
                            SHAPE_COLOR_R       " INTEGER(4)     NOT NULL,"
                            SHAPE_COLOR_G       " INTEGER(4)     NOT NULL,"
                            SHAPE_COLOR_B       " INTEGER(4)     NOT NULL,"
                            SHAPE_ANGLE_X       " FLOAT(5,5)     NOT NULL,"
                            SHAPE_ANGLE_Y       " FLOAT(5,5)     NOT NULL,"
                            SHAPE_ANGLE_Z       " FLOAT(5,5)     NOT NULL,"
                            SHAPE_XCORD         " FLOAT(5,5)     NOT NULL,"
                            SHAPE_YCORD         " FLOAT(5,5)     NOT NULL,"
                            SHAPE_ZCORD         " FLOAT(5,5)     NOT NULL,"
                            SHAPE_WIDTH         " FLOAT(5,5)     NOT NULL,"
                            SHAPE_HEIGHT        " FLOAT(5,5)     NOT NULL );"
                    )) {
        qDebug() << "DataBase: error of create " << SHAPE_TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        qDebug() << "Good";
    }
    return true;
}

bool DataBase::insertIntoDeviceTable(const QVariantList &data) {

    QSqlQuery query;

    query.prepare("INSERT INTO " SHAPE_TABLE " ( "
                            SCENE_ID ", "
                            SHAPE_TYPE ", "
                            SHAPE_COLOR_R ", "
                            SHAPE_COLOR_G ", "
                            SHAPE_COLOR_B ", "
                            SHAPE_ANGLE_X ", "
                            SHAPE_ANGLE_Y ", "
                            SHAPE_ANGLE_Z ", "
                            SHAPE_XCORD ", "
                            SHAPE_YCORD ", "
                            SHAPE_ZCORD ", "
                            SHAPE_WIDTH ", "
                            SHAPE_HEIGHT
                  " ) "
                  "VALUES (:SceneId, :ShapeType, :ShapeColorX, :ShapeColorY, :ShapeColorZ, "
                           ":ShapeAngleX, :ShapeAngleY, :ShapeAngleZ, "
                           ":ShapeXCord, :ShapeYCord, :ShapeZCord, :ShapeWidth, :ShapeHeight"
                  " )" );

    query.bindValue(":SceneId",             data[0].toInt());
    query.bindValue(":ShapeType",           data[1].toString());
    query.bindValue(":ShapeColorX",         data[2].toInt());
    query.bindValue(":ShapeColorY",         data[3].toInt());
    query.bindValue(":ShapeColorZ",         data[4].toInt());
    query.bindValue(":ShapeAngleX",         data[5].toFloat());
    query.bindValue(":ShapeAngleY",         data[6].toFloat());
    query.bindValue(":ShapeAngleZ",         data[7].toFloat());
    query.bindValue(":ShapeXCord",          data[8].toFloat());
    query.bindValue(":ShapeYCord",          data[9].toFloat());
    query.bindValue(":ShapeZCord",          data[10].toFloat());
    query.bindValue(":ShapeWidth",          data[11].toFloat());
    query.bindValue(":ShapeHeight",         data[12].toFloat());

    if( !query.exec() ) {
        qDebug() << "error insert into " << SHAPE_TABLE;
        qDebug() << query.lastError().text();
        return false;
    }
    return true;
}

void DataBase::clearData(int id) {
    QSqlQuery query;

    QString idStr = QString::number(id);
    if( !query.exec("DELETE FROM " SHAPE_TABLE " WHERE " SCENE_ID "= " + idStr) ) {
        qDebug() << "error delete from " << SHAPE_TABLE ;
        qDebug() << query.lastError().text();
        return ;
    } else {
        qDebug() << "Deleted successful " << SHAPE_TABLE;
        return ;
    }
}

QVariantList DataBase::getData(int id) {
    QSqlQuery query;

    QVariantList varL;
    QString idStr = QString::number(id);
    if( !query.exec("SELECT * FROM " SHAPE_TABLE " WHERE " SCENE_ID "= " + idStr) ) {
        qDebug() << "error select from " << SHAPE_TABLE;
        qDebug() << query.lastError().text();
        return varL;
    } else {
        while (query.next()) {
            for (int i = 1; i < 13; i++) {
                qDebug() << query.value(i);
                varL.append(query.value(i));
            }
        }
    }
    return varL;
}

int DataBase::getMaxSceneId() {
    QSqlQuery query;

    if( !query.exec("SELECT MAX( " SCENE_ID " ) FROM " SHAPE_TABLE) ) {
        qDebug() << "error select max from " << SHAPE_TABLE;
        qDebug() << query.lastError().text();
        return 0;
    }
    if (query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

void DataBase::showData() {
    QSqlQuery query;

    if( !query.exec("SELECT * FROM " SHAPE_TABLE) ) {
        qDebug() << "error select from " << SHAPE_TABLE;
        qDebug() << query.lastError().text();
        return ;
    } else {
        while (query.next()) {
            qDebug() <<query.value(0).toString() << query.value(1).toString() << query.value(2).toString()
                    << query.value(3).toString();
        }
    }
}
