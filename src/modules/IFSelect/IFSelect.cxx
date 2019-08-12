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

void bind_IFSelect_EditValue(py::module &);
void bind_IFSelect_ReturnStatus(py::module &);
void bind_IFSelect_PrintCount(py::module &);
void bind_IFSelect_PrintFail(py::module &);
void bind_IFSelect_RemainMode(py::module &);
void bind_IFSelect_Editor(py::module &);
void bind_IFSelect(py::module &);
void bind_IFSelect_Activator(py::module &);
void bind_IFSelect_SessionPilot(py::module &);
void bind_IFSelect_ActFunc(py::module &);
void bind_IFSelect_Act(py::module &);
void bind_IFSelect_GeneralModifier(py::module &);
void bind_IFSelect_SequenceOfGeneralModifier(py::module &);
void bind_IFSelect_AppliedModifiers(py::module &);
void bind_IFSelect_SessionDumper(py::module &);
void bind_IFSelect_BasicDumper(py::module &);
void bind_IFSelect_SignatureList(py::module &);
void bind_IFSelect_CheckCounter(py::module &);
void bind_IFSelect_ContextModif(py::module &);
void bind_IFSelect_ContextWrite(py::module &);
void bind_IFSelect_Dispatch(py::module &);
void bind_IFSelect_DispGlobal(py::module &);
void bind_IFSelect_DispPerCount(py::module &);
void bind_IFSelect_DispPerFiles(py::module &);
void bind_IFSelect_DispPerOne(py::module &);
void bind_IFSelect_DispPerSignature(py::module &);
void bind_IFSelect_EditForm(py::module &);
void bind_IFSelect_Functions(py::module &);
void bind_IFSelect_SignCounter(py::module &);
void bind_IFSelect_GraphCounter(py::module &);
void bind_IFSelect_Selection(py::module &);
void bind_IFSelect_TSeqOfSelection(py::module &);
void bind_IFSelect_HSeqOfSelection(py::module &);
void bind_IFSelect_IntParam(py::module &);
void bind_IFSelect_ListEditor(py::module &);
void bind_IFSelect_SequenceOfInterfaceModel(py::module &);
void bind_IFSelect_SequenceOfAppliedModifiers(py::module &);
void bind_IFSelect_ModelCopier(py::module &);
void bind_IFSelect_Modifier(py::module &);
void bind_IFSelect_ModifEditForm(py::module &);
void bind_IFSelect_ModifReorder(py::module &);
void bind_IFSelect_PacketList(py::module &);
void bind_IFSelect_ParamEditor(py::module &);
void bind_IFSelect_SelectDeduct(py::module &);
void bind_IFSelect_SelectAnyList(py::module &);
void bind_IFSelect_SelectExtract(py::module &);
void bind_IFSelect_SelectAnyType(py::module &);
void bind_IFSelect_SelectBase(py::module &);
void bind_IFSelect_SelectCombine(py::module &);
void bind_IFSelect_SelectControl(py::module &);
void bind_IFSelect_SelectDiff(py::module &);
void bind_IFSelect_SelectEntityNumber(py::module &);
void bind_IFSelect_SelectErrorEntities(py::module &);
void bind_IFSelect_SelectExplore(py::module &);
void bind_IFSelect_SelectFlag(py::module &);
void bind_IFSelect_SelectIncorrectEntities(py::module &);
void bind_IFSelect_SelectInList(py::module &);
void bind_IFSelect_SelectIntersection(py::module &);
void bind_IFSelect_SelectionIterator(py::module &);
void bind_IFSelect_SelectModelEntities(py::module &);
void bind_IFSelect_SelectModelRoots(py::module &);
void bind_IFSelect_SelectPointed(py::module &);
void bind_IFSelect_SelectRange(py::module &);
void bind_IFSelect_SelectRootComps(py::module &);
void bind_IFSelect_SelectRoots(py::module &);
void bind_IFSelect_SelectSent(py::module &);
void bind_IFSelect_SelectShared(py::module &);
void bind_IFSelect_SelectSharing(py::module &);
void bind_IFSelect_SelectSignature(py::module &);
void bind_IFSelect_SelectSignedShared(py::module &);
void bind_IFSelect_SelectSignedSharing(py::module &);
void bind_IFSelect_SelectSuite(py::module &);
void bind_IFSelect_SelectType(py::module &);
void bind_IFSelect_SelectUnion(py::module &);
void bind_IFSelect_SelectUnknownEntities(py::module &);
void bind_IFSelect_SessionFile(py::module &);
void bind_IFSelect_TSeqOfDispatch(py::module &);
void bind_IFSelect_ShareOut(py::module &);
void bind_IFSelect_ShareOutResult(py::module &);
void bind_IFSelect_Signature(py::module &);
void bind_IFSelect_SignType(py::module &);
void bind_IFSelect_SignAncestor(py::module &);
void bind_IFSelect_SignCategory(py::module &);
void bind_IFSelect_SignMultiple(py::module &);
void bind_IFSelect_SignValidity(py::module &);
void bind_IFSelect_Transformer(py::module &);
void bind_IFSelect_TransformStandard(py::module &);
void bind_IFSelect_WorkLibrary(py::module &);
void bind_IFSelect_WorkSession(py::module &);

PYBIND11_MODULE(IFSelect, mod) {

py::module::import("OCCT.Standard");
py::module::import("OCCT.Interface");
py::module::import("OCCT.Message");
py::module::import("OCCT.TCollection");
py::module::import("OCCT.TColStd");
py::module::import("OCCT.NCollection");
py::module::import("OCCT.MoniTool");
py::module::import("OCCT.IFGraph");

bind_IFSelect_EditValue(mod);
bind_IFSelect_ReturnStatus(mod);
bind_IFSelect_PrintCount(mod);
bind_IFSelect_PrintFail(mod);
bind_IFSelect_RemainMode(mod);
bind_IFSelect_Editor(mod);
bind_IFSelect(mod);
bind_IFSelect_Activator(mod);
bind_IFSelect_SessionPilot(mod);
bind_IFSelect_ActFunc(mod);
bind_IFSelect_Act(mod);
bind_IFSelect_GeneralModifier(mod);
bind_IFSelect_SequenceOfGeneralModifier(mod);
bind_IFSelect_AppliedModifiers(mod);
bind_IFSelect_SessionDumper(mod);
bind_IFSelect_BasicDumper(mod);
bind_IFSelect_SignatureList(mod);
bind_IFSelect_CheckCounter(mod);
bind_IFSelect_ContextModif(mod);
bind_IFSelect_ContextWrite(mod);
bind_IFSelect_Dispatch(mod);
bind_IFSelect_DispGlobal(mod);
bind_IFSelect_DispPerCount(mod);
bind_IFSelect_DispPerFiles(mod);
bind_IFSelect_DispPerOne(mod);
bind_IFSelect_DispPerSignature(mod);
bind_IFSelect_EditForm(mod);
bind_IFSelect_Functions(mod);
bind_IFSelect_SignCounter(mod);
bind_IFSelect_GraphCounter(mod);
bind_IFSelect_Selection(mod);
bind_IFSelect_TSeqOfSelection(mod);
bind_IFSelect_HSeqOfSelection(mod);
bind_IFSelect_IntParam(mod);
bind_IFSelect_ListEditor(mod);
bind_IFSelect_SequenceOfInterfaceModel(mod);
bind_IFSelect_SequenceOfAppliedModifiers(mod);
bind_IFSelect_ModelCopier(mod);
bind_IFSelect_Modifier(mod);
bind_IFSelect_ModifEditForm(mod);
bind_IFSelect_ModifReorder(mod);
bind_IFSelect_PacketList(mod);
bind_IFSelect_ParamEditor(mod);
bind_IFSelect_SelectDeduct(mod);
bind_IFSelect_SelectAnyList(mod);
bind_IFSelect_SelectExtract(mod);
bind_IFSelect_SelectAnyType(mod);
bind_IFSelect_SelectBase(mod);
bind_IFSelect_SelectCombine(mod);
bind_IFSelect_SelectControl(mod);
bind_IFSelect_SelectDiff(mod);
bind_IFSelect_SelectEntityNumber(mod);
bind_IFSelect_SelectErrorEntities(mod);
bind_IFSelect_SelectExplore(mod);
bind_IFSelect_SelectFlag(mod);
bind_IFSelect_SelectIncorrectEntities(mod);
bind_IFSelect_SelectInList(mod);
bind_IFSelect_SelectIntersection(mod);
bind_IFSelect_SelectionIterator(mod);
bind_IFSelect_SelectModelEntities(mod);
bind_IFSelect_SelectModelRoots(mod);
bind_IFSelect_SelectPointed(mod);
bind_IFSelect_SelectRange(mod);
bind_IFSelect_SelectRootComps(mod);
bind_IFSelect_SelectRoots(mod);
bind_IFSelect_SelectSent(mod);
bind_IFSelect_SelectShared(mod);
bind_IFSelect_SelectSharing(mod);
bind_IFSelect_SelectSignature(mod);
bind_IFSelect_SelectSignedShared(mod);
bind_IFSelect_SelectSignedSharing(mod);
bind_IFSelect_SelectSuite(mod);
bind_IFSelect_SelectType(mod);
bind_IFSelect_SelectUnion(mod);
bind_IFSelect_SelectUnknownEntities(mod);
bind_IFSelect_SessionFile(mod);
bind_IFSelect_TSeqOfDispatch(mod);
bind_IFSelect_ShareOut(mod);
bind_IFSelect_ShareOutResult(mod);
bind_IFSelect_Signature(mod);
bind_IFSelect_SignType(mod);
bind_IFSelect_SignAncestor(mod);
bind_IFSelect_SignCategory(mod);
bind_IFSelect_SignMultiple(mod);
bind_IFSelect_SignValidity(mod);
bind_IFSelect_Transformer(mod);
bind_IFSelect_TransformStandard(mod);
bind_IFSelect_WorkLibrary(mod);
bind_IFSelect_WorkSession(mod);

}
