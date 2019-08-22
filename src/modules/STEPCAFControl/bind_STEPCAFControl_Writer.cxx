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
#include <STEPControl_StepModelType.hxx>
#include <TDF_Label.hxx>
#include <TCollection_AsciiString.hxx>
#include <NCollection_DataMap.hxx>
#include <STEPCAFControl_ExternFile.hxx>
#include <STEPControl_Writer.hxx>
#include <TDF_LabelSequence.hxx>
#include <TopoDS_Shape.hxx>
#include <StepRepr_ShapeAspect.hxx>
#include <StepRepr_RepresentationContext.hxx>
#include <StepAP242_GeometricItemSpecificUsage.hxx>
#include <TCollection_HAsciiString.hxx>
#include <gp_Ax2.hxx>
#include <gp_Pnt.hxx>
#include <Standard_Transient.hxx>
#include <StepDimTol_Datum.hxx>
#include <XCAFDimTolObjects_GeomToleranceObject.hxx>
#include <StepDimTol_GeometricTolerance.hxx>
#include <StepDimTol_HArray1OfDatumSystemOrReference.hxx>
#include <STEPCAFControl_DataMapOfLabelShape.hxx>
#include <STEPCAFControl_DataMapOfLabelExternFile.hxx>
#include <MoniTool_DataMapOfShapeTransient.hxx>
#include <NCollection_Vector.hxx>
#include <StepRepr_RepresentationItem.hxx>
#include <StepVisual_DraughtingModel.hxx>
#include <StepVisual_HArray1OfPresentationStyleAssignment.hxx>
#include <StepRepr_ProductDefinitionShape.hxx>
#include <STEPCAFControl_Writer.hxx>

void bind_STEPCAFControl_Writer(py::module &mod){

py::class_<STEPCAFControl_Writer> cls_STEPCAFControl_Writer(mod, "STEPCAFControl_Writer", "Provides a tool to write DECAF document to the STEP file. Besides transfer of shapes (including assemblies) provided by STEPControl, supports also colors and part names");

// Constructors
cls_STEPCAFControl_Writer.def(py::init<>());
cls_STEPCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_STEPCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_STEPCAFControl_Writer.def_static("operator new_", (void * (*)(size_t)) &STEPCAFControl_Writer::operator new, "None", py::arg("theSize"));
// cls_STEPCAFControl_Writer.def_static("operator delete_", (void (*)(void *)) &STEPCAFControl_Writer::operator delete, "None", py::arg("theAddress"));
// cls_STEPCAFControl_Writer.def_static("operator new[]_", (void * (*)(size_t)) &STEPCAFControl_Writer::operator new[], "None", py::arg("theSize"));
// cls_STEPCAFControl_Writer.def_static("operator delete[]_", (void (*)(void *)) &STEPCAFControl_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_STEPCAFControl_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &STEPCAFControl_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_STEPCAFControl_Writer.def_static("operator delete_", (void (*)(void *, void *)) &STEPCAFControl_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_STEPCAFControl_Writer.def("Init", [](STEPCAFControl_Writer &self, const opencascade::handle<XSControl_WorkSession> & a0) -> void { return self.Init(a0); });
cls_STEPCAFControl_Writer.def("Init", (void (STEPCAFControl_Writer::*)(const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean)) &STEPCAFControl_Writer::Init, "Clears the internal data structures and attaches to a new session Clears the session if it was not yet set for STEP", py::arg("WS"), py::arg("scratch"));
cls_STEPCAFControl_Writer.def("Write", (IFSelect_ReturnStatus (STEPCAFControl_Writer::*)(const Standard_CString)) &STEPCAFControl_Writer::Write, "Writes all the produced models into file In case of multimodel with extern references, filename will be a name of root file, all other files have names of corresponding parts Provided for use like single-file writer", py::arg("filename"));
cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const opencascade::handle<TDocStd_Document> & a0) -> Standard_Boolean { return self.Transfer(a0); });
cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const opencascade::handle<TDocStd_Document> & a0, const STEPControl_StepModelType a1) -> Standard_Boolean { return self.Transfer(a0, a1); });
cls_STEPCAFControl_Writer.def("Transfer", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const STEPControl_StepModelType, const Standard_CString)) &STEPCAFControl_Writer::Transfer, "Transfers a document (or single label) to a STEP model The mode of translation of shape is AsIs If multi is not null pointer, it switches to multifile mode (with external refs), and string pointed by <multi> gives prefix for names of extern files (can be empty string) Returns True if translation is OK", py::arg("doc"), py::arg("mode"), py::arg("multi"));
cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const TDF_Label & a0) -> Standard_Boolean { return self.Transfer(a0); });
cls_STEPCAFControl_Writer.def("Transfer", [](STEPCAFControl_Writer &self, const TDF_Label & a0, const STEPControl_StepModelType a1) -> Standard_Boolean { return self.Transfer(a0, a1); });
cls_STEPCAFControl_Writer.def("Transfer", (Standard_Boolean (STEPCAFControl_Writer::*)(const TDF_Label &, const STEPControl_StepModelType, const Standard_CString)) &STEPCAFControl_Writer::Transfer, "Method to transfer part of the document specified by label", py::arg("L"), py::arg("mode"), py::arg("multi"));
cls_STEPCAFControl_Writer.def("Perform", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &)) &STEPCAFControl_Writer::Perform, "None", py::arg("doc"), py::arg("filename"));
cls_STEPCAFControl_Writer.def("Perform", (Standard_Boolean (STEPCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const Standard_CString)) &STEPCAFControl_Writer::Perform, "Transfers a document and writes it to a STEP file Returns True if translation is OK", py::arg("doc"), py::arg("filename"));
cls_STEPCAFControl_Writer.def("ExternFiles", (const NCollection_DataMap<TCollection_AsciiString, opencascade::handle<STEPCAFControl_ExternFile> > & (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::ExternFiles, "Returns data on external files Returns Null handle if no external files are read");
cls_STEPCAFControl_Writer.def("ExternFile", (Standard_Boolean (STEPCAFControl_Writer::*)(const TDF_Label &, opencascade::handle<STEPCAFControl_ExternFile> &) const) &STEPCAFControl_Writer::ExternFile, "Returns data on external file by its original label Returns False if no external file with given name is read", py::arg("L"), py::arg("ef"));
cls_STEPCAFControl_Writer.def("ExternFile", (Standard_Boolean (STEPCAFControl_Writer::*)(const Standard_CString, opencascade::handle<STEPCAFControl_ExternFile> &) const) &STEPCAFControl_Writer::ExternFile, "Returns data on external file by its name Returns False if no external file with given name is read", py::arg("name"), py::arg("ef"));
cls_STEPCAFControl_Writer.def("ChangeWriter", (STEPControl_Writer & (STEPCAFControl_Writer::*)()) &STEPCAFControl_Writer::ChangeWriter, "Returns basic reader for root file");
cls_STEPCAFControl_Writer.def("Writer", (const STEPControl_Writer & (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::Writer, "Returns basic reader as const");
cls_STEPCAFControl_Writer.def("SetColorMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetColorMode, "Set ColorMode for indicate write Colors or not.", py::arg("colormode"));
cls_STEPCAFControl_Writer.def("GetColorMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetColorMode, "None");
cls_STEPCAFControl_Writer.def("SetNameMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetNameMode, "Set NameMode for indicate write Name or not.", py::arg("namemode"));
cls_STEPCAFControl_Writer.def("GetNameMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetNameMode, "None");
cls_STEPCAFControl_Writer.def("SetLayerMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetLayerMode, "Set LayerMode for indicate write Layers or not.", py::arg("layermode"));
cls_STEPCAFControl_Writer.def("GetLayerMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetLayerMode, "None");
cls_STEPCAFControl_Writer.def("SetPropsMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetPropsMode, "PropsMode for indicate write Validation properties or not.", py::arg("propsmode"));
cls_STEPCAFControl_Writer.def("GetPropsMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetPropsMode, "None");
cls_STEPCAFControl_Writer.def("SetSHUOMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetSHUOMode, "Set SHUO mode for indicate write SHUO or not.", py::arg("shuomode"));
cls_STEPCAFControl_Writer.def("GetSHUOMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetSHUOMode, "None");
cls_STEPCAFControl_Writer.def("SetDimTolMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetDimTolMode, "Set dimtolmode for indicate write D&GTs or not.", py::arg("dimtolmode"));
cls_STEPCAFControl_Writer.def("GetDimTolMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetDimTolMode, "None");
cls_STEPCAFControl_Writer.def("SetMaterialMode", (void (STEPCAFControl_Writer::*)(const Standard_Boolean)) &STEPCAFControl_Writer::SetMaterialMode, "Set dimtolmode for indicate write D&GTs or not.", py::arg("matmode"));
cls_STEPCAFControl_Writer.def("GetMaterialMode", (Standard_Boolean (STEPCAFControl_Writer::*)() const) &STEPCAFControl_Writer::GetMaterialMode, "None");

// Enums

}