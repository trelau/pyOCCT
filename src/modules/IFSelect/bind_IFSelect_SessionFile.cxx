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
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Standard_Transient.hxx>
#include <TColStd_HArray1OfInteger.hxx>
#include <NCollection_DataMap.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <IFSelect_SessionFile.hxx>

void bind_IFSelect_SessionFile(py::module &mod){

py::class_<IFSelect_SessionFile, std::unique_ptr<IFSelect_SessionFile, Deleter<IFSelect_SessionFile>>> cls_IFSelect_SessionFile(mod, "IFSelect_SessionFile", "A SessionFile is intended to manage access between a WorkSession and an Ascii Form, to be considered as a Dump. It allows to write the File from the WorkSession, and later read the File to the WorkSession, by keeping required descriptions (such as dependances).");

// Constructors
cls_IFSelect_SessionFile.def(py::init<const opencascade::handle<IFSelect_WorkSession> &>(), py::arg("WS"));
cls_IFSelect_SessionFile.def(py::init<const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString>(), py::arg("WS"), py::arg("filename"));

// Fields

// Methods
// cls_IFSelect_SessionFile.def_static("operator new_", (void * (*)(size_t)) &IFSelect_SessionFile::operator new, "None", py::arg("theSize"));
// cls_IFSelect_SessionFile.def_static("operator delete_", (void (*)(void *)) &IFSelect_SessionFile::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect_SessionFile::operator new[], "None", py::arg("theSize"));
// cls_IFSelect_SessionFile.def_static("operator delete[]_", (void (*)(void *)) &IFSelect_SessionFile::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect_SessionFile::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect_SessionFile.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect_SessionFile::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect_SessionFile.def("ClearLines", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ClearLines, "Clears the lines recorded whatever for writing or for reading");
cls_IFSelect_SessionFile.def("NbLines", (Standard_Integer (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::NbLines, "Returns the count of recorded lines");
cls_IFSelect_SessionFile.def("Line", (const TCollection_AsciiString & (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::Line, "Returns a line given its rank in the list of recorded lines", py::arg("num"));
cls_IFSelect_SessionFile.def("AddLine", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::AddLine, "Adds a line to the list of recorded lines", py::arg("line"));
cls_IFSelect_SessionFile.def("RemoveLastLine", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::RemoveLastLine, "Removes the last line. Can be called recursively. Does nothing if the list is empty");
cls_IFSelect_SessionFile.def("WriteFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::WriteFile, "Writes the recorded lines to a file named <name> then clears the list of lines. Returns False (with no clearing) if the file could not be created", py::arg("name"));
cls_IFSelect_SessionFile.def("ReadFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::ReadFile, "Reads the recorded lines from a file named <name>, after having cleared the list (stops if RecognizeFile fails) Returns False (with no clearing) if the file could not be read", py::arg("name"));
cls_IFSelect_SessionFile.def("RecognizeFile", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::RecognizeFile, "Recognizes the header line. returns True if OK, False else", py::arg("headerline"));
cls_IFSelect_SessionFile.def("Write", (Standard_Integer (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::Write, "Performs a Write Operation from a WorkSession to a File i.e. calls WriteSession then WriteEnd, and WriteFile Returned Value is : 0 for OK, -1 File could not be created, >0 Error during Write (see WriteSession) IsDone can be called too (will return True for OK)", py::arg("filename"));
cls_IFSelect_SessionFile.def("Read", (Standard_Integer (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::Read, "Performs a Read Operation from a file to a WorkSession i.e. calls ReadFile, then ReadSession and ReadEnd Returned Value is : 0 for OK, -1 File could not be opened, >0 Error during Read (see WriteSession) IsDone can be called too (will return True for OK)", py::arg("filename"));
cls_IFSelect_SessionFile.def("WriteSession", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::WriteSession, "Prepares the Write operation from a WorkSession (IFSelect) to a File, i.e. fills the list of lines (the file itself remains to be written; or NbLines/Line may be called) Important Remark : this excludes the reading of the last line, which is performed by WriteEnd Returns 0 if OK, status > 0 in case of error");
cls_IFSelect_SessionFile.def("WriteEnd", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::WriteEnd, "Writes the trailing line. It is separate from WriteSession, in order to allow to redefine WriteSession without touching WriteEnd (WriteSession defines the body of the file) WriteEnd fills the list of lines. Returns a status of error, 0 if OK, >0 else");
cls_IFSelect_SessionFile.def("WriteLine", [](IFSelect_SessionFile &self, const Standard_CString a0) -> void { return self.WriteLine(a0); });
cls_IFSelect_SessionFile.def("WriteLine", (void (IFSelect_SessionFile::*)(const Standard_CString, const Standard_Character)) &IFSelect_SessionFile::WriteLine, "Writes a line to the File. If <follow> is given, it is added at the following of the line. '' must be added for the end.", py::arg("line"), py::arg("follow"));
cls_IFSelect_SessionFile.def("WriteOwn", (Standard_Boolean (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::WriteOwn, "Writes the Parameters own to each type of Item. Uses the Library of SessionDumpers Returns True if Done, False if <item> could not be treated (hence it remains written with no Own Parameter)", py::arg("item"));
cls_IFSelect_SessionFile.def("ReadSession", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadSession, "Performs a Read Operation from a File to a WorkSession, i.e. reads the list of line (which must have already been loaded, by ReadFile or by calls to AddLine) Important Remark : this excludes the reading of the last line, which is performed by ReadEnd Returns 0 for OK, >0 status for Read Error (not a suitable File, or WorkSession given as Immutable at Creation Time) IsDone can be called too (will return True for OK)");
cls_IFSelect_SessionFile.def("ReadEnd", (Standard_Integer (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadEnd, "Reads the end of a file (its last line). Returns 0 if OK, status >0 in case of error (not a suitable end line).");
cls_IFSelect_SessionFile.def("ReadLine", (Standard_Boolean (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::ReadLine, "Reads a Line and splits it into a set of alphanumeric items, which can then be queried by NbParams/ParamValue ...");
cls_IFSelect_SessionFile.def("SplitLine", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::SplitLine, "Internal routine which processes a line into words and prepares its exploration", py::arg("line"));
cls_IFSelect_SessionFile.def("ReadOwn", (Standard_Boolean (IFSelect_SessionFile::*)(opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::ReadOwn, "Tries to Read an Item, by calling the Library of Dumpers Sets the list of parameters of the line to be read from the first own one", py::arg("item"));
cls_IFSelect_SessionFile.def("AddItem", [](IFSelect_SessionFile &self, const opencascade::handle<Standard_Transient> & a0) -> void { return self.AddItem(a0); });
cls_IFSelect_SessionFile.def("AddItem", (void (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &, const Standard_Boolean)) &IFSelect_SessionFile::AddItem, "Adds an Item to the WorkSession, taken as Name the first item of the read Line. If this Name is not a Name but a Number or if this Name is already recorded in the WorkSession, it adds the Item but with no Name. Then the Name is recorded in order to be used by the method ItemValue <active> commands to make <item> active or not in the session", py::arg("item"), py::arg("active"));
cls_IFSelect_SessionFile.def("IsDone", (Standard_Boolean (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::IsDone, "Returns True if the last Read or Write operation has been corectly performed. ELse returns False.");
cls_IFSelect_SessionFile.def("WorkSession", (opencascade::handle<IFSelect_WorkSession> (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::WorkSession, "Returns the WorkSession on which a SessionFile works. Remark that it is returned as Immutable.");
cls_IFSelect_SessionFile.def("NewItem", (void (IFSelect_SessionFile::*)(const Standard_Integer, const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::NewItem, "At beginning of writing an Item, writes its basics : - either its name in the session if it has one - or its relative number of item in the file, else (preceeded by a '_') - then, its Dynamic Type (in the sense of cdl : pk_class) This basic description can be followed by the parameters which are used in the definition of the item.", py::arg("ident"), py::arg("par"));
cls_IFSelect_SessionFile.def("SetOwn", (void (IFSelect_SessionFile::*)(const Standard_Boolean)) &IFSelect_SessionFile::SetOwn, "Sets Parameters to be sent as Own if <mode> is True (their Name or Number or Void Mark or Text Value is preceeded by a Column sign ':') else they are sent normally Hence, the Own Parameter are clearly identified in the File", py::arg("mode"));
cls_IFSelect_SessionFile.def("SendVoid", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::SendVoid, "During a Write action, commands to send a Void Parameter i.e. a Parameter which is present but undefined Its form will be the dollar sign : $");
cls_IFSelect_SessionFile.def("SendItem", (void (IFSelect_SessionFile::*)(const opencascade::handle<Standard_Transient> &)) &IFSelect_SessionFile::SendItem, "During a Write action, commands to send the identification of a Parameter : if it is Null (undefined) it is send as Void ($) if it is Named in the WorkSession, its Name is sent preceeded by ':', else a relative Ident Number is sent preceeded by '#' (relative to the present Write, i.e. starting at one, without skip, and counted part from Named Items)", py::arg("par"));
cls_IFSelect_SessionFile.def("SendText", (void (IFSelect_SessionFile::*)(const Standard_CString)) &IFSelect_SessionFile::SendText, "During a Write action, commands to send a Text without interpretation. It will be sent as well", py::arg("text"));
cls_IFSelect_SessionFile.def("SetLastGeneral", (void (IFSelect_SessionFile::*)(const Standard_Integer)) &IFSelect_SessionFile::SetLastGeneral, "Sets the rank of Last General Parameter to a new value. It is followed by the Fist Own Parameter of the item. Used by SessionFile after reading general parameters.", py::arg("lastgen"));
cls_IFSelect_SessionFile.def("NbParams", (Standard_Integer (IFSelect_SessionFile::*)() const) &IFSelect_SessionFile::NbParams, "During a Read operation, SessionFile processes sequencially the Items to read. For each one, it gives access to the list of its Parameters : they were defined by calls to SendVoid/SendParam/SendText during Writing the File. NbParams returns the count of Parameters for the line currently read.");
cls_IFSelect_SessionFile.def("IsVoid", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::IsVoid, "Returns True if a Parameter, given its rank in the Own List (see NbOwnParams), is Void. Returns also True if <num> is out of range (undefined parameters)", py::arg("num"));
cls_IFSelect_SessionFile.def("IsText", (Standard_Boolean (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::IsText, "Returns True if a Parameter, in the Own List (see NbOwnParams) is a Text (between '...'). Else it is an Item (Parameter, Selection, Dispatch ...), which can be Void.", py::arg("num"));
cls_IFSelect_SessionFile.def("ParamValue", (const TCollection_AsciiString & (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::ParamValue, "Returns a Parameter (alphanumeric item of a line) as it has been read", py::arg("num"));
cls_IFSelect_SessionFile.def("TextValue", (TCollection_AsciiString (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::TextValue, "Returns the content of a Text Parameter (without the quotes). Returns an empty string if the Parameter is not a Text.", py::arg("num"));
cls_IFSelect_SessionFile.def("ItemValue", (opencascade::handle<Standard_Transient> (IFSelect_SessionFile::*)(const Standard_Integer) const) &IFSelect_SessionFile::ItemValue, "Returns a Parameter as an Item. Returns a Null Handle if the Parameter is a Text, or if it is defined as Void", py::arg("num"));
cls_IFSelect_SessionFile.def("Destroy", (void (IFSelect_SessionFile::*)()) &IFSelect_SessionFile::Destroy, "Specific Destructor (closes the File if not yet done)");

// Enums

}