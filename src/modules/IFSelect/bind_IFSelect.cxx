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
#include <Standard_TypeDef.hxx>
#include <Standard_Handle.hxx>
#include <IFSelect_WorkSession.hxx>
#include <IFSelect_Signature.hxx>
#include <IFSelect_SignMultiple.hxx>
#include <IFSelect_SignType.hxx>
#include <IFSelect_SignCategory.hxx>
#include <IFSelect_SignValidity.hxx>
#include <IFSelect_SignAncestor.hxx>
#include <IFSelect_ShareOut.hxx>
#include <IFSelect_AppliedModifiers.hxx>
#include <IFSelect_ShareOutResult.hxx>
#include <IFSelect_PacketList.hxx>
#include <IFSelect_Dispatch.hxx>
#include <IFSelect_DispGlobal.hxx>
#include <IFSelect_DispPerOne.hxx>
#include <IFSelect_DispPerCount.hxx>
#include <IFSelect_DispPerSignature.hxx>
#include <IFSelect_DispPerFiles.hxx>
#include <IFSelect_SelectionIterator.hxx>
#include <IFSelect_Selection.hxx>
#include <IFSelect_SelectBase.hxx>
#include <IFSelect_SelectModelRoots.hxx>
#include <IFSelect_SelectModelEntities.hxx>
#include <IFSelect_SelectEntityNumber.hxx>
#include <IFSelect_SelectPointed.hxx>
#include <IFSelect_SelectCombine.hxx>
#include <IFSelect_SelectUnion.hxx>
#include <IFSelect_SelectIntersection.hxx>
#include <IFSelect_SelectControl.hxx>
#include <IFSelect_SelectDiff.hxx>
#include <IFSelect_SelectDeduct.hxx>
#include <IFSelect_SelectShared.hxx>
#include <IFSelect_SelectSharing.hxx>
#include <IFSelect_SelectAnyList.hxx>
#include <IFSelect_SelectInList.hxx>
#include <IFSelect_SelectSuite.hxx>
#include <IFSelect_SelectExtract.hxx>
#include <IFSelect_SelectUnknownEntities.hxx>
#include <IFSelect_SelectErrorEntities.hxx>
#include <IFSelect_SelectIncorrectEntities.hxx>
#include <IFSelect_SelectRoots.hxx>
#include <IFSelect_SelectRootComps.hxx>
#include <IFSelect_SelectRange.hxx>
#include <IFSelect_SelectAnyType.hxx>
#include <IFSelect_SelectType.hxx>
#include <IFSelect_SelectSignature.hxx>
#include <IFSelect_SelectFlag.hxx>
#include <IFSelect_SelectSent.hxx>
#include <IFSelect_SelectExplore.hxx>
#include <IFSelect_SelectSignedShared.hxx>
#include <IFSelect_SelectSignedSharing.hxx>
#include <IFSelect_IntParam.hxx>
#include <IFSelect_SignatureList.hxx>
#include <IFSelect_CheckCounter.hxx>
#include <IFSelect_SignCounter.hxx>
#include <IFSelect_GraphCounter.hxx>
#include <IFSelect_Editor.hxx>
#include <IFSelect_ParamEditor.hxx>
#include <IFSelect_EditForm.hxx>
#include <IFSelect_ListEditor.hxx>
#include <IFSelect_ContextModif.hxx>
#include <IFSelect_ContextWrite.hxx>
#include <IFSelect_Transformer.hxx>
#include <IFSelect_TransformStandard.hxx>
#include <IFSelect_ModelCopier.hxx>
#include <IFSelect_GeneralModifier.hxx>
#include <IFSelect_Modifier.hxx>
#include <IFSelect_ModifReorder.hxx>
#include <IFSelect_ModifEditForm.hxx>
#include <IFSelect_WorkLibrary.hxx>
#include <IFSelect_SessionFile.hxx>
#include <IFSelect_SessionDumper.hxx>
#include <IFSelect_BasicDumper.hxx>
#include <IFSelect_Activator.hxx>
#include <IFSelect_SessionPilot.hxx>
#include <IFSelect_Act.hxx>
#include <IFSelect_Functions.hxx>
#include <IFSelect.hxx>

void bind_IFSelect(py::module &mod){

py::class_<IFSelect> cls_IFSelect(mod, "IFSelect", "Gives tools to manage Selecting a group of Entities processed by an Interface, for instance to divide up an original Model (from a File) to several smaller ones They use description of an Interface Model as a graph");

// Constructors

// Fields

// Methods
// cls_IFSelect.def_static("operator new_", (void * (*)(size_t)) &IFSelect::operator new, "None", py::arg("theSize"));
// cls_IFSelect.def_static("operator delete_", (void (*)(void *)) &IFSelect::operator delete, "None", py::arg("theAddress"));
// cls_IFSelect.def_static("operator new[]_", (void * (*)(size_t)) &IFSelect::operator new[], "None", py::arg("theSize"));
// cls_IFSelect.def_static("operator delete[]_", (void (*)(void *)) &IFSelect::operator delete[], "None", py::arg("theAddress"));
// cls_IFSelect.def_static("operator new_", (void * (*)(size_t, void *)) &IFSelect::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IFSelect.def_static("operator delete_", (void (*)(void *, void *)) &IFSelect::operator delete, "None", py::arg(""), py::arg(""));
cls_IFSelect.def_static("SaveSession_", (Standard_Boolean (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect::SaveSession, "Saves the state of a WorkSession from IFSelect, by using a SessionFile from IFSelect. Returns True if Done, False in case of Error on Writing. <file> gives the name of the File to be produced (this avoids to export the class SessionFile).", py::arg("WS"), py::arg("file"));
cls_IFSelect.def_static("RestoreSession_", (Standard_Boolean (*)(const opencascade::handle<IFSelect_WorkSession> &, const Standard_CString)) &IFSelect::RestoreSession, "Restore the state of a WorkSession from IFSelect, by using a SessionFile from IFSelect. Returns True if Done, False in case of Error on Writing. <file> gives the name of the File to be used (this avoids to export the class SessionFile).", py::arg("WS"), py::arg("file"));

// Enums

}