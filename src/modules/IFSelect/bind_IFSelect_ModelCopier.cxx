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
#include <Standard_Transient.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_ShareOut.hxx>
#include <Standard_TypeDef.hxx>
#include <TCollection_AsciiString.hxx>
#include <Interface_InterfaceModel.hxx>
#include <IFSelect_AppliedModifiers.hxx>
#include <Interface_CheckIterator.hxx>
#include <IFSelect_ShareOutResult.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <Interface_Protocol.hxx>
#include <Interface_Graph.hxx>
#include <Interface_EntityIterator.hxx>
#include <Interface_CopyTool.hxx>
#include <TColStd_HSequenceOfHAsciiString.hxx>
#include <IFSelect_ModelCopier.hxx>
#include <Standard_Type.hxx>
#include <IFSelect_SequenceOfInterfaceModel.hxx>
#include <TColStd_SequenceOfAsciiString.hxx>
#include <IFSelect_SequenceOfAppliedModifiers.hxx>
#include <TColStd_HArray1OfInteger.hxx>

void bind_IFSelect_ModelCopier(py::module &mod){

py::class_<IFSelect_ModelCopier, opencascade::handle<IFSelect_ModelCopier>, Standard_Transient> cls_IFSelect_ModelCopier(mod, "IFSelect_ModelCopier", "This class performs the Copy operations involved by the description of a ShareOut (evaluated by a ShareOutResult) plus, if there are, the Modifications on the results, with the help of Modifiers. Each Modifier can work on one or more resulting packets, accoding its criteria : it operates on a Model once copied and filled with the content of the packet.");

// Constructors
cls_IFSelect_ModelCopier.def(py::init<>());

// Fields

// Methods
cls_IFSelect_ModelCopier.def("SetShareOut", (void (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_ShareOut> &)) &IFSelect_ModelCopier::SetShareOut, "Sets the ShareOut, which is used to define Modifiers to apply", py::arg("sho"));
cls_IFSelect_ModelCopier.def("ClearResult", (void (IFSelect_ModelCopier::*)()) &IFSelect_ModelCopier::ClearResult, "Clears the list of produced Models");
cls_IFSelect_ModelCopier.def("AddFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const TCollection_AsciiString &, const opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_ModelCopier::AddFile, "Records a new File to be sent, as a couple (Name as AsciiString, Content as InterfaceModel) Returns True if Done, False if <filename> is already attached to another File", py::arg("filename"), py::arg("content"));
cls_IFSelect_ModelCopier.def("NameFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer, const TCollection_AsciiString &)) &IFSelect_ModelCopier::NameFile, "Changes the Name attached to a File which was formerly defined by a call to AddFile Returns True if Done, False else : if <num> out of range or if the new <filename> is already attached to another File Remark : Giving an empty File Name is equivalent to ClearFile", py::arg("num"), py::arg("filename"));
cls_IFSelect_ModelCopier.def("ClearFile", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer)) &IFSelect_ModelCopier::ClearFile, "Clears the Name attached to a File which was formerly defined by a call to AddFile. This Clearing can be undone by a call to NameFile (with same <num>) Returns True if Done, False else : if <num> is out of range", py::arg("num"));
cls_IFSelect_ModelCopier.def("SetAppliedModifiers", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer, const opencascade::handle<IFSelect_AppliedModifiers> &)) &IFSelect_ModelCopier::SetAppliedModifiers, "Sets a list of File Modifiers to be applied on a file", py::arg("num"), py::arg("applied"));
cls_IFSelect_ModelCopier.def("ClearAppliedModifiers", (Standard_Boolean (IFSelect_ModelCopier::*)(const Standard_Integer)) &IFSelect_ModelCopier::ClearAppliedModifiers, "Clears the list of File Modifiers to be applied on a file", py::arg("num"));
cls_IFSelect_ModelCopier.def("Copy", (Interface_CheckIterator (IFSelect_ModelCopier::*)(IFSelect_ShareOutResult &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::Copy, "Performs the Copy Operations, which include the Modifications defined by the list of Modifiers. Memorizes the result, as a list of InterfaceModels with the corresponding FileNames They can then be sent, by the method Send, or queried Copy calls internal method Copying. Returns the produced CheckList", py::arg("eval"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendCopied", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::SendCopied, "Sends the formerly defined results (see method Copy) to files, then clears it Remark : A Null File Name cause file to be not produced", py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("Send", (Interface_CheckIterator (IFSelect_ModelCopier::*)(IFSelect_ShareOutResult &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::Send, "Performs the Copy Operations (which include the Modifications) and Sends the result on files, without memorizing it. (the memorized result is ignored : neither queried not filled)", py::arg("eval"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendAll", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const Standard_CString, const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &)) &IFSelect_ModelCopier::SendAll, "Sends a model (defined in <G>) into one file, without managing remaining data, already sent files, etc. Applies the Model and File Modifiers. Returns True if well done, False else", py::arg("filename"), py::arg("G"), py::arg("WL"), py::arg("protocol"));
cls_IFSelect_ModelCopier.def("SendSelected", (Interface_CheckIterator (IFSelect_ModelCopier::*)(const Standard_CString, const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, const opencascade::handle<Interface_Protocol> &, const Interface_EntityIterator &)) &IFSelect_ModelCopier::SendSelected, "Sends a part of a model into one file. Model is gotten from <G>, the part is defined in <iter>. Remaining data are managed and can be later be worked on. Returns True if well done, False else", py::arg("filename"), py::arg("G"), py::arg("WL"), py::arg("protocol"), py::arg("iter"));
cls_IFSelect_ModelCopier.def("CopiedRemaining", (void (IFSelect_ModelCopier::*)(const Interface_Graph &, const opencascade::handle<IFSelect_WorkLibrary> &, Interface_CopyTool &, opencascade::handle<Interface_InterfaceModel> &)) &IFSelect_ModelCopier::CopiedRemaining, "Produces a Model copied from the Remaining List as <newmod> <newmod> is a Null Handle if this list is empty <WL> performs the copy by using <TC> <TC> is assumed to have been defined with the starting model same as defined by <G>.", py::arg("G"), py::arg("WL"), py::arg("TC"), py::arg("newmod"));
cls_IFSelect_ModelCopier.def("SetRemaining", (Standard_Boolean (IFSelect_ModelCopier::*)(Interface_Graph &) const) &IFSelect_ModelCopier::SetRemaining, "Updates Graph status for remaining data, for each entity : - Entities just Sent to file or Copied (by CopiedRemaining) have their status set to 1 - the other keep their former status (1 for Send/Copied, 0 for Remaining) These status are computed by Copying/Sending/CopiedRemaining Then, SetRemaining updates graph status, and mustr be called just after one of these method has been called Returns True if done, False if remaining info if not in phase which the Graph (not same counts of items)", py::arg("CG"));
cls_IFSelect_ModelCopier.def("NbFiles", (Standard_Integer (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::NbFiles, "Returns the count of Files produced, i.e. the count of Models memorized (produced by the mmethod Copy) with their file names");
cls_IFSelect_ModelCopier.def("FileName", (TCollection_AsciiString (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::FileName, "Returns the File Name for a file given its rank It is empty after a call to ClearFile on same <num>", py::arg("num"));
cls_IFSelect_ModelCopier.def("FileModel", (opencascade::handle<Interface_InterfaceModel> (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::FileModel, "Returns the content of a file before sending, under the form of an InterfaceModel, given its rank", py::arg("num"));
cls_IFSelect_ModelCopier.def("AppliedModifiers", (opencascade::handle<IFSelect_AppliedModifiers> (IFSelect_ModelCopier::*)(const Standard_Integer) const) &IFSelect_ModelCopier::AppliedModifiers, "Returns the list of File Modifiers to be applied on a file when it will be sent, as computed by CopiedModel : If it is a null handle, no File Modifier has to be applied.", py::arg("num"));
cls_IFSelect_ModelCopier.def("BeginSentFiles", (void (IFSelect_ModelCopier::*)(const opencascade::handle<IFSelect_ShareOut> &, const Standard_Boolean)) &IFSelect_ModelCopier::BeginSentFiles, "Begins a sequence of recording the really sent files <sho> : the default file numbering is cleared If <record> is False, clears the list and stops recording If <record> is True, clears the list and commands recording Creation time corresponds to 'stop recording'", py::arg("sho"), py::arg("record"));
cls_IFSelect_ModelCopier.def("AddSentFile", (void (IFSelect_ModelCopier::*)(const Standard_CString)) &IFSelect_ModelCopier::AddSentFile, "Adds the name of a just sent file, if BeginSentFiles has commanded recording; else does nothing It is called by methods SendCopied Sending", py::arg("filename"));
cls_IFSelect_ModelCopier.def("SentFiles", (opencascade::handle<TColStd_HSequenceOfHAsciiString> (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::SentFiles, "Returns the list of recorded names of sent files. Can be empty (if no file has been sent). Returns a Null Handle if BeginSentFiles has stopped recording.");
cls_IFSelect_ModelCopier.def_static("get_type_name_", (const char * (*)()) &IFSelect_ModelCopier::get_type_name, "None");
cls_IFSelect_ModelCopier.def_static("get_type_descriptor_", (const opencascade::handle<Standard_Type> & (*)()) &IFSelect_ModelCopier::get_type_descriptor, "None");
cls_IFSelect_ModelCopier.def("DynamicType", (const opencascade::handle<Standard_Type> & (IFSelect_ModelCopier::*)() const) &IFSelect_ModelCopier::DynamicType, "None");

// Enums

}