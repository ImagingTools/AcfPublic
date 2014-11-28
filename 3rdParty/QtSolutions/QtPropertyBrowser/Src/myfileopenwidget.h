#ifndef MYFILEOPENWIDGET_H
#define MYFILEOPENWIDGET_H

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QToolButton>
#include <QLineEdit>
#include <QFileDialog>

class myFileOpenWidget: public QWidget
{
    Q_OBJECT

    QString m_filter, m_startDir;
    QLineEdit *pathEdit;
    QToolButton *button;
    QHBoxLayout *hbox;

public:
    myFileOpenWidget(QWidget *parent = 0);

public slots:
    QString text();
    void setText(const QString &);
    QString displayText() const;
    void getFileOpenDialog();
    void setFilter(const QString &);
    void setStartDir(const QString &);

signals:
    void textChanged(const QString &);
};


#endif // MYFILEOPENWIDGET_H
