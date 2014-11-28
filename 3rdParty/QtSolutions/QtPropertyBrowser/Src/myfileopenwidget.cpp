#include "myfileopenwidget.h"


myFileOpenWidget::myFileOpenWidget(QWidget *parent):QWidget(parent)
{
    button = new QToolButton(this);
    pathEdit = new QLineEdit(this);
    button->setFixedWidth(20);
    button->setText("...");
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(getFileOpenDialog()));
    QObject::connect(pathEdit,SIGNAL(textChanged(QString)),this,SIGNAL(textChanged(QString)));
    hbox = new QHBoxLayout(this);
    hbox->addWidget(pathEdit);
    hbox->addWidget(button);
    hbox->setMargin(0);
    hbox->setSpacing(1);
    setLayout(hbox);

    setFilter("");
}

void myFileOpenWidget::getFileOpenDialog()
{
    QString str = QFileDialog::getOpenFileName(this, tr("Open File"), m_startDir, m_filter);
    if (!str.isNull() && !str.isEmpty())
        pathEdit->setText(str);
}

void myFileOpenWidget::setFilter(const QString &f)
{
    if (f.isEmpty())
        m_filter = tr("Files (*.*)");
    else
        m_filter = f;
}

void myFileOpenWidget::setStartDir(const QString &d)
{
    m_startDir = d;
}

QString myFileOpenWidget::text()
{
    return pathEdit->text();
}

void myFileOpenWidget::setText(const QString &str)
{
    if (str != pathEdit->text())
        pathEdit->setText(str);
}

QString myFileOpenWidget::displayText() const
{
    return pathEdit->displayText();
}
