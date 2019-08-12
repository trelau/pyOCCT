/*
This file is part of pyOCCT which provides Python bindings to the OpenCASCADE
geometry kernel.

Copyright (C) 2016-2018  Laughlin Research, LLC
Copyright (C) 2019 Trevor Laughlin and the pyOCCT contributors

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <pyOCCT_Common.hxx>
#include <OSD_FileNode.hxx>
#include <OSD_Path.hxx>
#include <OSD_OpenMode.hxx>
#include <OSD_Protection.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_TypeDef.hxx>
#include <OSD_FromWhere.hxx>
#include <OSD_KindFile.hxx>
#include <OSD_LockType.hxx>
#include <NCollection_SparseArrayBase.hxx>
#include <OSD_File.hxx>

void bind_OSD_File(py::module &mod){

py::class_<OSD_File, std::unique_ptr<OSD_File, Deleter<OSD_File>>, OSD_FileNode> cls_OSD_File(mod, "OSD_File", "Basic tools to manage files Warning: 'ProgramError' is raised when somebody wants to use the methods Read, Write, Seek, Close when File is not open.");

// Constructors
cls_OSD_File.def(py::init<>());
cls_OSD_File.def(py::init<const OSD_Path &>(), py::arg("Name"));

// Fields

// Methods
cls_OSD_File.def("Build", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Build, "CREATES a file if it doesn't already exists or empties an existing file. After 'Build', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Open", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Open, "Opens a File with specific attributes This works only on already existing file. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Append", (void (OSD_File::*)(const OSD_OpenMode, const OSD_Protection &)) &OSD_File::Append, "Appends data to an existing file. If file doesn't exist, creates it first. After 'Append', the file is open. If no name was given, ProgramError is raised.", py::arg("Mode"), py::arg("Protect"));
cls_OSD_File.def("Read", (void (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Read, "Attempts to read Nbyte bytes from the file associated with the object file. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. In this case only number of read bytes will be placed in the buffer.", py::arg("Buffer"), py::arg("Nbyte"));
cls_OSD_File.def("ReadLine", [](OSD_File &self, TCollection_AsciiString & Buffer, const Standard_Integer NByte, Standard_Integer & NbyteRead){ self.ReadLine(Buffer, NByte, NbyteRead); return NbyteRead; }, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read into <NByteRead> and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"), py::arg("NbyteRead"));
cls_OSD_File.def("ReadLine", (Standard_Integer (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer)) &OSD_File::ReadLine, "Reads bytes from the data pointed to by the object file into the buffer <Buffer>. Data is read until <NByte-1> bytes have been read, until a newline character is read and transferred into <Buffer>, or until an EOF (End-of-File) condition is encountered. Upon successful completion, Read returns the number of bytes actually read and placed into the Buffer <Buffer>.", py::arg("Buffer"), py::arg("NByte"));
cls_OSD_File.def("Read", [](OSD_File &self, const Standard_Address Buffer, const Standard_Integer Nbyte, Standard_Integer & Readbyte){ self.Read(Buffer, Nbyte, Readbyte); return Readbyte; }, "Attempts to read Nbyte bytes from the files associated with the object File. Upon successful completion, Read returns the number of bytes actually read and placed in the Buffer. This number may be less than Nbyte if the number of bytes left in the file is less than Nbyte bytes. For this reason the output parameter Readbyte will contain the number of read bytes.", py::arg("Buffer"), py::arg("Nbyte"), py::arg("Readbyte"));
cls_OSD_File.def("Write", (void (OSD_File::*)(const TCollection_AsciiString &, const Standard_Integer)) &OSD_File::Write, "Attempts to write theNbBytes bytes from the AsciiString to the file.", py::arg("theBuffer"), py::arg("theNbBytes"));
cls_OSD_File.def("Write", (void (OSD_File::*)(const Standard_Address, const Standard_Integer)) &OSD_File::Write, "Attempts to write theNbBytes bytes from the buffer pointed to by theBuffer to the file associated to the object File.", py::arg("theBuffer"), py::arg("theNbBytes"));
cls_OSD_File.def("Seek", (void (OSD_File::*)(const Standard_Integer, const OSD_FromWhere)) &OSD_File::Seek, "Sets the seek pointer associated with the open file", py::arg("Offset"), py::arg("Whence"));
cls_OSD_File.def("Close", (void (OSD_File::*)()) &OSD_File::Close, "Closes the file (and deletes a descriptor)");
cls_OSD_File.def("IsAtEnd", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsAtEnd, "Returns TRUE if the seek pointer is at end of file.");
cls_OSD_File.def("KindOfFile", (OSD_KindFile (OSD_File::*)() const) &OSD_File::KindOfFile, "Returns the kind of file. A file can be a file, a directory or a link.");
cls_OSD_File.def("BuildTemporary", (void (OSD_File::*)()) &OSD_File::BuildTemporary, "Makes a temporary File This temporary file is already open !");
cls_OSD_File.def("SetLock", (void (OSD_File::*)(const OSD_LockType)) &OSD_File::SetLock, "Locks current file", py::arg("Lock"));
cls_OSD_File.def("UnLock", (void (OSD_File::*)()) &OSD_File::UnLock, "Unlocks current file");
cls_OSD_File.def("GetLock", (OSD_LockType (OSD_File::*)() const) &OSD_File::GetLock, "Returns the current lock state");
cls_OSD_File.def("IsLocked", (Standard_Boolean (OSD_File::*)() const) &OSD_File::IsLocked, "Returns TRUE if this file is locked.");
cls_OSD_File.def("Size", (Standard_Size (OSD_File::*)()) &OSD_File::Size, "Returns actual number of bytes of <me>.");
cls_OSD_File.def("IsOpen", (Standard_Boolean (OSD_File::*)() const) &OSD_File::IsOpen, "Returns TRUE if <me> is open.");
cls_OSD_File.def("IsReadable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsReadable, "returns TRUE if the file exists and if the user has the autorization to read it.");
cls_OSD_File.def("IsWriteable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsWriteable, "returns TRUE if the file can be read and overwritten.");
cls_OSD_File.def("IsExecutable", (Standard_Boolean (OSD_File::*)()) &OSD_File::IsExecutable, "returns TRUE if the file can be executed.");
cls_OSD_File.def("ReadLastLine", (Standard_Boolean (OSD_File::*)(TCollection_AsciiString &, const Standard_Integer, const Standard_Integer)) &OSD_File::ReadLastLine, "Enables to emulate unix 'tail -f' command. If a line is available in the file <me> returns it. Otherwise attemps to read again aNbTries times in the file waiting aDelay seconds between each read. If meanwhile the file increases returns the next line, otherwise returns FALSE.", py::arg("aLine"), py::arg("aDelay"), py::arg("aNbTries"));
cls_OSD_File.def("Edit", (Standard_Boolean (OSD_File::*)()) &OSD_File::Edit, "find an editor on the system and edit the given file");
cls_OSD_File.def("Rewind", (void (OSD_File::*)()) &OSD_File::Rewind, "Set file pointer position to the beginning of the file");
cls_OSD_File.def("Capture", (int (OSD_File::*)(int)) &OSD_File::Capture, "Redirect a standard handle (fileno(stdout), fileno(stdin) or fileno(stderr) to this OSD_File and return the copy of the original standard handle. Example: OSD_File aTmp; aTmp.BuildTemporary(); int stdfd = _fileno(stdout);", py::arg("theDescr"));

// Enums

}