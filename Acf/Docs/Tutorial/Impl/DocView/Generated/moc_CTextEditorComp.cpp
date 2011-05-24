/********************************************************************************
**
**	Copyright (c) 2007-2010 Witold Gantzke & Kirill Lepskiy
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
** 	See http://www.imagingtools.de, write info@imagingtools.de or contact
**  by Skype to ACF_infoline for further information about the ACF.
**
********************************************************************************/


/****************************************************************************
** Meta object code from reading C++ file 'CTextEditorComp.h'
**
** Created: Mon 28. Mar 22:23:59 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CTextEditorComp.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CTextEditorComp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CTextEditorComp[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   16,   16,   16, 0x09,
      38,   16,   16,   16, 0x09,
      54,   16,   16,   16, 0x09,
      70,   16,   16,   16, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_CTextEditorComp[] = {
    "CTextEditorComp\0\0OnSelectionChanged()\0"
    "OnTextChanged()\0OnToLowercase()\0"
    "OnToUppercase()\0"
};

const QMetaObject CTextEditorComp::staticMetaObject = {
    { &iqtgui::TGuiObserverWrap<iqtgui::TGuiComponentBase<QTextEdit>,imod::TSingleModelObserverBase<ibase::ITextDocument> >::staticMetaObject, qt_meta_stringdata_CTextEditorComp,
      qt_meta_data_CTextEditorComp, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CTextEditorComp::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CTextEditorComp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CTextEditorComp::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CTextEditorComp))
        return static_cast<void*>(const_cast< CTextEditorComp*>(this));
    if (!strcmp(_clname, "ibase::ICommandsProvider"))
        return static_cast< ibase::ICommandsProvider*>(const_cast< CTextEditorComp*>(this));
    typedef iqtgui::TGuiObserverWrap<iqtgui::TGuiComponentBase<QTextEdit>,imod::TSingleModelObserverBase<ibase::ITextDocument> > QMocSuperClass;
    return QMocSuperClass::qt_metacast(_clname);
}

int CTextEditorComp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    typedef iqtgui::TGuiObserverWrap<iqtgui::TGuiComponentBase<QTextEdit>,imod::TSingleModelObserverBase<ibase::ITextDocument> > QMocSuperClass;
    _id = QMocSuperClass::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: OnSelectionChanged(); break;
        case 1: OnTextChanged(); break;
        case 2: OnToLowercase(); break;
        case 3: OnToUppercase(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
