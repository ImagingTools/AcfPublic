#include <iqt/CConsoleReader.h>


#ifdef Q_OS_WIN
// STD includes
#include <stdio.h>
#include <conio.h>
#else
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

extern "C" void kbhit()
{
	static struct termios oldt, newt;
	tcgetattr( STDIN_FILENO, &oldt);
	newt = oldt;

	newt.c_lflag &= ~(ICANON | ECHO);

	tcsetattr( STDIN_FILENO, TCSANOW, &newt);

	int retVal = getchar();

	tcsetattr( STDIN_FILENO, TCSANOW, &oldt);

	return retVal;
}
#endif


namespace iqt
{


// public methods

CConsoleReader::CConsoleReader(QObject* parentPtr)
	:BaseClass(parentPtr),
	m_inputObserver(*this)
{
}


void CConsoleReader::Start()
{
	m_inputObserver.start();
}


void CConsoleReader::Stop()
{
	m_inputObserver.Stop();
}


bool CConsoleReader::IsRunning() const
{
	return m_inputObserver.isRunning();
}


// public methods of the embedded class InputObserver

CConsoleReader::InputObserver::InputObserver(CConsoleReader& parent)
	:m_parent(parent),
	m_shouldBeFinished(false)
{
}


void CConsoleReader::InputObserver::Stop()
{
	m_shouldBeFinished = true;

	wait();
}


// protected methods of the embedded class InputObserver

// reimplemented (QThread)

void CConsoleReader::InputObserver::run()
{
	while (!m_shouldBeFinished){
		if (kbhit() != 0){
			emit m_parent.KeyPressedSignal(getch());

			msleep(100);
		}
	}
}


} // namespace iqt


