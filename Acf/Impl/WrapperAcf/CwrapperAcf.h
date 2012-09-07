#ifndef CwrapperAcf_H
#define CwrapperAcf_H
 

#include "generated/ui_CwrapperAcf.h"


namespace wrapper
{
 
class CwrapperAcf : public QWidget, public Ui::CwrapperAcf
{
    Q_OBJECT
 
public:
	CwrapperAcf(char **argv);
	CwrapperAcf();
	
 
 
public slots:
    void GetPath();	
    void RunACF();   
	void RunACF(int msec);
	void GetRegistryPath(QListWidgetItem *);
	



private:
	QString acfDir;
	QString configFilePath;
	QString activeRegistryFilePath;
	QStringList applicationRegistriesList;
	bool InitApplicationRegistriesList();
	void SetProperty();
	QTimer *timer;
	
	
};
 
} // namespace wraperACF
 
#endif