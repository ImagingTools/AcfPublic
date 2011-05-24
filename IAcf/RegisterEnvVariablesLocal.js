/********************************************************************************
**
**	Copyright (C) 2007-2010 Witold Gantzke & Kirill Lepskiy
**	All rights reserved.
**
**	This file is part of the IACF Toolkit.
**
**	Licensees holding valid IACF Commercial licenses may use this file in
**	accordance with the IACF Commercial License Agreement provided with the
**	Software and appearing in the file License.txt or,
**	alternatively, in accordance with the terms contained in
**	a written agreement between you and Witold Gantzke & Kirill Lepskiy.
**
**	If you are unsure which license is appropriate for your use, please
**	contact us at info@imagingtools.de.
**
** 	See http://www.imagingtools.de or email info@imagingtools.de for further
** 	information about the IACF.
**
********************************************************************************/


var variableExt = "envVariable"
var variableExp = new RegExp(".*\." + variableExt + "$");
var scriptExp = new RegExp(".*\.autoregister\.js$");
var registryPath = "HKEY_CURRENT_USER\\Environment\\";


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

