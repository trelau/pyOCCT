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
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <IFSelect_ReturnStatus.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_DataMap.hxx>
#include <STEPCAFControl_ExternFile.hxx>
#include <STEPControl_Reader.hxx>
#include <TDF_Label.hxx>
#include <StepRepr_NextAssemblyUsageOccurrence.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <STEPConstruct_Tool.hxx>
#include <STEPCAFControl_DataMapOfPDExternFile.hxx>
#include <XCAFDoc_DataMapOfShapeLabel.hxx>
#include <TDF_LabelSequence.hxx>
#include <TopoDS_Shape.hxx>
#include <TopTools_MapOfShape.hxx>
#include <STEPCAFControl_DataMapOfShapePD.hxx>
#include <TColStd_HSequenceOfTransient.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <Transfer_TransientProcess.hxx>
#include <StepShape_ConnectedFaceSet.hxx>
#include <StepDimTol_Datum.hxx>
#include <XCAFDimTolObjects_DatumModifiersSequence.hxx>
#include <XCAFDimTolObjects_DatumModifWithValue.hxx>
#include <Standard_Transient.hxx>
#include <STEPCAFControl_Reader.hxx>

void bind_STEPCAFControl_Reader(py::module &mod){

py::class_<STEPCAFControl_Reader, std::unique_ptr<STEPCAFControl_Reader>> cls_STEPCAFControl_Reader(mod, "STEPCAFControl_Reader", "Provides a tool to read STEP file and put it into DECAF document. Besides transfer of shapes (including assemblies) provided by STEPControl, supports also colors and part names");

// Constructors
cls_STEPCAFControl_Reader.def(py::init<>());
cls_STEPCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_STEPCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_STEPCAFControl_Reader.def_static("operator new_", (void * (*)(size_t)) &STEPCAFControl_Reader::operator new, "None", py::arg("theSize"));
// cls_STEPCAFControl_Reader.def_static("operator delete_", (void (*)(void *)) &STEPCAFControl_Reader::operator delete, "None", py::arg("theAddress"));
// cls_STEPCAFControl_Reader.def_static("operator new[]_", (void * (*)(size_t)) &STEPCAFControl_Reader::operator new[], "None", py::arg("theSize"));
// cls_STEPCAFControl_Reader.def_static("operator delete[]_", (void (*)(void *)) &STEPCAFControl_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_STEPCAFControl_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &STEPCAFControl_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPCAFControl_Reader.def_static("operator delete_", (void (*)(void *, void *)) &STEPCAFControl_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPCAFControl_Reader.def("Init", [](STEPCAFControl_Reader &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.Init(a0); });
cls_STEPCAFControl_Reader.def("Init", (void (STEPCAFControl_Reader::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPCAFControl_Reader::Init, "Clears the internal data structures and attaches to a new session Clears the session if it was not yet set for STEP", py::arg("WS"), py::arg("scratch"));
cls_STEPCAFControl_Reader.def("ReadFile", (IFSelect_ReturnStatus (STEPCAFControl_Reader::*)(const Standard_CString)) &STEPCAFControl_Reader::ReadFile, "Loads a file and returns the read status Provided for use like single-file reader", py::arg("filename"));
cls_STEPCAFControl_Reader.def("NbRootsForTransfer", (Standard_Integer (STEPCAFControl_Reader::*)()) &STEPCAFControl_Reader::NbRootsForTransfer, "Returns number of roots recognized for transfer Shortcut for Reader().NbRootsForTransfer()");
cls_STEPCAFControl_Reader.def("TransferOneRoot", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_Integer, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::TransferOneRoot, "Translates currently loaded STEP file into the document Returns True if succeeded, and False in case of fail Provided for use like single-file reader", py::arg("num"), py::arg("doc"));
cls_STEPCAFControl_Reader.def("Transfer", (Standard_Boolean (STEPCAFControl_Reader::*)(opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Transfer, "Translates currently loaded STEP file into the document Returns True if succeeded, and False in case of fail Provided for use like single-file reader", py::arg("doc"));
cls_STEPCAFControl_Reader.def("Perform", (Standard_Boolean (STEPCAFControl_Reader::*)(const TCollection_AsciiString &, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Perform, "None", py::arg("filename"), py::arg("doc"));
cls_STEPCAFControl_Reader.def("Perform", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_CString, opencascade::handle<TDocStd_Document> &)) &STEPCAFControl_Reader::Perform, "Translate STEP file given by filename into the document Return True if succeeded, and False in case of fail", py::arg("filename"), py::arg("doc"));
cls_STEPCAFControl_Reader.def("ExternFiles", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<STEPCAFControl_ExternFile> > & (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::ExternFiles, "Returns data on external files Returns Null handle if no external files are read");
cls_STEPCAFControl_Reader.def("ExternFile", (Standard_Boolean (STEPCAFControl_Reader::*)(const Standard_CString, opencascade::handle<STEPCAFControl_ExternFile> &) const) &STEPCAFControl_Reader::ExternFile, "Returns data on external file by its name Returns False if no external file with given name is read", py::arg("name"), py::arg("ef"));
cls_STEPCAFControl_Reader.def("ChangeReader", (STEPControl_Reader & (STEPCAFControl_Reader::*)()) &STEPCAFControl_Reader::ChangeReader, "Returns basic reader");
cls_STEPCAFControl_Reader.def("Reader", (const STEPControl_Reader & (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::Reader, "Returns basic reader as const");
cls_STEPCAFControl_Reader.def_static("FindInstance_", (TDF_Label (*)(const opencascade::handle<StepRepr_NextAssemblyUsageOccurrence> &, const opencascade::handle<XCAFDoc_ShapeTool> &, const STEPConstruct_Tool &, const STEPCAFControl_DataMapOfPDExternFile &, const XCAFDoc_DataMapOfShapeLabel &)) &STEPCAFControl_Reader::FindInstance, "Returns label of instance of an assembly component corresponding to a given NAUO", py::arg("NAUO"), py::arg("STool"), py::arg("Tool"), py::arg("PDRFileMap"), py::arg("ShapeLabelMap"));
cls_STEPCAFControl_Reader.def("SetColorMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetColorMode, "Set ColorMode for indicate read Colors or not.", py::arg("colormode"));
cls_STEPCAFControl_Reader.def("GetColorMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetColorMode, "None");
cls_STEPCAFControl_Reader.def("SetNameMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetNameMode, "Set NameMode for indicate read Name or not.", py::arg("namemode"));
cls_STEPCAFControl_Reader.def("GetNameMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetNameMode, "None");
cls_STEPCAFControl_Reader.def("SetLayerMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetLayerMode, "Set LayerMode for indicate read Layers or not.", py::arg("layermode"));
cls_STEPCAFControl_Reader.def("GetLayerMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetLayerMode, "None");
cls_STEPCAFControl_Reader.def("SetPropsMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetPropsMode, "PropsMode for indicate read Validation properties or not.", py::arg("propsmode"));
cls_STEPCAFControl_Reader.def("GetPropsMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetPropsMode, "None");
cls_STEPCAFControl_Reader.def("SetSHUOMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetSHUOMode, "Set SHUO mode for indicate write SHUO or not.", py::arg("shuomode"));
cls_STEPCAFControl_Reader.def("GetSHUOMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetSHUOMode, "None");
cls_STEPCAFControl_Reader.def("SetGDTMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetGDTMode, "Set GDT mode for indicate write GDT or not.", py::arg("gdtmode"));
cls_STEPCAFControl_Reader.def("GetGDTMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetGDTMode, "None");
cls_STEPCAFControl_Reader.def("SetMatMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetMatMode, "Set Material mode", py::arg("matmode"));
cls_STEPCAFControl_Reader.def("GetMatMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetMatMode, "None");
cls_STEPCAFControl_Reader.def("SetViewMode", (void (STEPCAFControl_Reader::*)(const Standard_Boolean)) &STEPCAFControl_Reader::SetViewMode, "Set View mode", py::arg("viewmode"));
cls_STEPCAFControl_Reader.def("GetViewMode", (Standard_Boolean (STEPCAFControl_Reader::*)() const) &STEPCAFControl_Reader::GetViewMode, "Get View mode");

// Enums

}