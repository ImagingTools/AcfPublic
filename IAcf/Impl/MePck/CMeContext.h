/********************************************************************************
**
**	Copyright (C) 2007-2011 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the IACF Toolkit.
**
**	This file may be used under the terms of the GNU Lesser
**	General Public License version 2.1 as published by the Free Software
**	Foundation and appearing in the file LicenseLGPL.txt included in the
**	packaging of this file.  Please review the following information to
**	ensure the GNU Lesser General Public License version 2.1 requirements
**	will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


#ifndef imebase_CMeContext_included
#define imebase_CMeContext_included


#include <QMutex>
#include <QWaitCondition>

#include "imeas/IDataSequence.h"

#include "imebase.h"


namespace imebase
{


/**
	Context for data processing
*/
class CMeContext
{
public:
	CMeContext(const CMeAddr& address, bool isOutput, imeas::IDataSequence* containerPtr);
	~CMeContext();

	/**
		Register this context to MEiDS
	*/
	bool Register(double interval);
	void Unregister();

	int GetId()  const;

	/**
		Check buffer status.
	*/
	int GetCount()  const;
	bool IsDone();
	double GetInterval() const;

	/**
		Wait for task to end. If time out return false.
		\param	timeout	time out in seconds.
	*/
	bool Wait(double timeout);

	void CopyToContainer();
	void CopyFromContainer();

protected:
	bool ConfigInputStream();
	bool ConfigOutputStream();

	bool StartStream();

	// static methods
	static int __stdcall cbAIFunc(int device, int subdevice, int count, void* context, int error);
	static int __stdcall cbAOFunc(int device, int subdevice, int count, void* context, int error);

private:
	QMutex m_activeTaskMutex;
	QWaitCondition m_dataReadyCondition;

	CMeAddr m_address;
	int m_bufferCount;
	std::vector<int> m_hwBuffer;
	bool m_isOutput;
	double m_interval;

	imeas::IDataSequence& m_samplesSequence;
};


} // namespace imebase


#endif // !imebase_CMeContext_included


