#include "mainImpl.h"
#include "ui_main.h"

MadClicker::MadClicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MadClicker),
    _speed(0.0),
    _hiscore(0.0),
    _cnt(0),
    _clicked(std::chrono::system_clock::now())
{
    ui->setupUi(this);
    std::thread([this] () {
        while (1)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            updateSpeed();
            _speed = 0.0;
        }
    }).detach();
}

MadClicker::~MadClicker()
{
    delete ui;
}

void MadClicker::currentSpeedRefresh()
{
    auto newClick = std::chrono::system_clock::now();
    this->_m.lock();
    double clicks =1000.0 /  std::chrono::duration_cast<std::chrono::milliseconds>(newClick - _clicked).count();
    if (clicks > _speed)
        _speed = clicks;
    _clicked = newClick;
    this->_m.unlock();
    this->ui->counterLabel->setNum(++_cnt);
}

void MadClicker::updateSpeed()
{
    this->_m.lock();
    this->ui->clickSpeedValue->setNum( _speed);
    if (_speed > _hiscore)
    {
         this->ui->hiScoreValue->setNum( _speed);
        _hiscore = _speed;
    }
    this->_m.unlock();
}
