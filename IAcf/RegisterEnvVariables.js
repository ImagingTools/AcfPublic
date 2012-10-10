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
** 	See http://www.ilena.org, write info@imagingtools.de or contact
**	by Skype to ACF_infoline for further information about the IACF.
**
********************************************************************************/


var variableExt = "envVariable"
var variableExp = new RegExp(".*\." + variableExt + "$");
var scriptExp = new RegExp(".*\.autoregister\.js$");
var registryPath = "HKEY_LOCAL_MACHINE\\SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\\";


function ProcessFolder(shell, folder)
{
	var retVal = new String;

	var fileIter = new Enumerator(folder.files);
	for (; !fileIter.atEnd(); fileIter.moveNext()){
		var file = fileIter.item();

		if (variableExp.exec(file.Name)){
			var folderPath = new String(folder);
			var name = file.Name.substr(0, file.Name.length - variableExt.length  - 1);
			retVal += "- " + name + " = " + folder + "\n";
			shell.RegWrite(registryPath + name, folder);
		}

		if (scriptExp.exec(file.Name)){
			WScript.Echo("Running " + file);
			shell.Run(file);
		}
	}

	var subFolderIter = new Enumerator(folder.SubFolders);
	for (; !subFolderIter.atEnd(); subFolderIter.moveNext()){
		retVal += ProcessFolder(shell, subFolderIter.item());
	}
	
	return retVal;
}


var fileSystem = WScript.CreateObject("Scripting.FileSystemObject");
var fullPath = fileSystem.GetParentFolderName(WScript.ScriptFullName);
var shell = WScript.CreateObject("WScript.Shell");
var message = ProcessFolder(shell, fileSystem.GetFolder(fullPath));
if (message.length > 0){
	WScript.Echo("Following variables was registered:\n\n" + message);
}
else{
	WScript.Echo("No variable was registered");
}

WScript.Quit(0);

