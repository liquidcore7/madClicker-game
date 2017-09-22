#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QApplication>
#include <QLabel>
#include <chrono>
#include <mutex>
#include <thread>

namespace Ui {
class MadClicker;
}

class MadClicker : public QWidget
{
    Q_OBJECT

public:
    explicit MadClicker(QWidget *parent = 0);
    ~MadClicker();
public slots:
  void currentSpeedRefresh();

private:
    Ui::MadClicker *ui;
    void updateSpeed();
    double  _speed;
    double _hiscore;
    int _cnt;
    std::mutex _m;
    std::chrono::system_clock::time_point _clicked;
};

#endif // MAIN_H
