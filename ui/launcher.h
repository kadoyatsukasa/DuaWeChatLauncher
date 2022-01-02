#ifndef DUA_WECHAT_LAUNCHER_LAUNCHER_H
#define DUA_WECHAT_LAUNCHER_LAUNCHER_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Launcher; }
QT_END_NAMESPACE

class Launcher : public QWidget {
Q_OBJECT

public:
    explicit Launcher(QWidget *parent = nullptr);

    ~Launcher() override;

private:
    void initialization();

private slots:

    /**
     * @brief  Open Dialog to select .exe file
     */
    void slotOpenFileSelectDialog();

    void slotRunExternalApplication();

private:
    Ui::Launcher *ui;
    QString m_filepath;
};

#endif
