/********************************************************************************
**
**	Copyright (C) 2007-2015 Witold Gantzke & Kirill Lepskiy
**
**	This file is part of the ACF Toolkit.
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
** 	See http://www.ilena.org or write info@imagingtools.de for further
** 	information about the ACF.
**
********************************************************************************/


#pragma once


// Qt includes
#include <QtCore/QThread>


namespace iqt
{


/**
	User-input reader for command line console.
*/
class CConsoleReader: public QObject
{
	Q_OBJECT

public:
	typedef QObject BaseClass;

	CConsoleReader(QObject* parentPtr = NULL);

	/**
		Start reading of the user input on the console.
	*/
	virtual void Start();

	/**
		Stop reading of the user input on the console.
	*/
	virtual void Stop();

	/**
		Check if the reader is running.
	*/
	bool IsRunning() const;

signals:
	/**
		Emit typed character.
	*/
	void KeyPressedSignal(char character);

protected:
	class InputObserver: public QThread
	{
	public:
		InputObserver(CConsoleReader& parent);

		void Stop();

	protected:
		// reimplemented (QThread)
		virtual void run();

	private:
		CConsoleReader& m_parent;
		bool m_shouldBeFinished;
	};

private:
	InputObserver m_inputObserver;
};


} // namespace iqt


