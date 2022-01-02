#include "launcher.h"
#include "ui_Launcher.h"
#include <QFileDialog>
#include <QProcess>
#include <QMessageBox>

Launcher::Launcher(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Launcher),
        m_filepath(""){
    ui->setupUi(this);
    initialization();
}

Launcher::~Launcher() {
    delete ui;
}

void Launcher::initialization() {

    setFixedSize(800,200);

    connect(ui->btnSelectPath,&QPushButton::clicked,this,&Launcher::slotOpenFileSelectDialog);
    connect(ui->btnCancel,&QPushButton::clicked,[=]{close();});
    connect(ui->btnSubmit,&QPushButton::clicked,this,&Launcher::slotRunExternalApplication);
}

void Launcher::slotOpenFileSelectDialog() {
    std::shared_ptr<QFileDialog> dialog = std::make_shared<QFileDialog>();
    m_filepath = dialog->getOpenFileName(this,"Select file",".exe","application(*.exe)");
    if (!m_filepath.isEmpty())
        ui->lineFilePath->setText(m_filepath);
}

void Launcher::slotRunExternalApplication() {
    if (ui->lineCount->text().toInt() == 0)
    {
        QMessageBox::information(this,"Error","Number of client cannot be 0");
        return;
    }

    m_filepath.replace("/","\\");
    std::shared_ptr<QProcess> process = std::make_shared<QProcess>();

    for (int i = 0; i < ui->lineCount->text().toInt(); i++) {
        process->startDetached(m_filepath);
    }
}

