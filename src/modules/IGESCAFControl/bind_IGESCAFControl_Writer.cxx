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
#include <IGESControl_Writer.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TDF_LabelSequence.hxx>
#include <TDF_Label.hxx>
#include <TCollection_AsciiString.hxx>
#include <TopoDS_Shape.hxx>
#include <XCAFPrs_IndexedDataMapOfShapeStyle.hxx>
#include <XCAFPrs_DataMapOfStyleTransient.hxx>
#include <TopTools_MapOfShape.hxx>
#include <XCAFPrs_Style.hxx>
#include <IGESCAFControl_Writer.hxx>

void bind_IGESCAFControl_Writer(py::module &mod){

py::class_<IGESCAFControl_Writer, IGESControl_Writer> cls_IGESCAFControl_Writer(mod, "IGESCAFControl_Writer", "Provides a tool to write DECAF document to the IGES file. Besides transfer of shapes (including assemblies) provided by IGESControl, supports also colors and part names IGESCAFControl_Writer writer(); Methods for writing IGES file: writer.Transfer (Document); writer.Write('filename') or writer.Write(OStream) or writer.Perform(Document,'filename'); Methods for managing the writing of attributes. Colors writer.SetColorMode(colormode); Standard_Boolean colormode = writer.GetColorMode(); Layers writer.SetLayerMode(layermode); Standard_Boolean layermode = writer.GetLayerMode(); Names writer.SetNameMode(namemode); Standard_Boolean namemode = writer.GetNameMode();");

// Constructors
cls_IGESCAFControl_Writer.def(py::init<>());
cls_IGESCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("WS"));
cls_IGESCAFControl_Writer.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("WS"), py::arg("scratch"));

// Fields

// Methods
// cls_IGESCAFControl_Writer.def_static("operator new_", (void * (*)(size_t)) &IGESCAFControl_Writer::operator new, "None", py::arg("theSize"));
// cls_IGESCAFControl_Writer.def_static("operator delete_", (void (*)(void *)) &IGESCAFControl_Writer::operator delete, "None", py::arg("theAddress"));
// cls_IGESCAFControl_Writer.def_static("operator new[]_", (void * (*)(size_t)) &IGESCAFControl_Writer::operator new[], "None", py::arg("theSize"));
// cls_IGESCAFControl_Writer.def_static("operator delete[]_", (void (*)(void *)) &IGESCAFControl_Writer::operator delete[], "None", py::arg("theAddress"));
// cls_IGESCAFControl_Writer.def_static("operator new_", (void * (*)(size_t, void *)) &IGESCAFControl_Writer::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESCAFControl_Writer.def_static("operator delete_", (void (*)(void *, void *)) &IGESCAFControl_Writer::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Writer::Transfer, "Transfers a document to a IGES model Returns True if translation is OK", py::arg("doc"));
cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const TDF_LabelSequence &)) &IGESCAFControl_Writer::Transfer, "Transfers labels to a IGES model Returns True if translation is OK", py::arg("labels"));
cls_IGESCAFControl_Writer.def("Transfer", (Standard_Boolean (IGESCAFControl_Writer::*)(const TDF_Label &)) &IGESCAFControl_Writer::Transfer, "Transfers label to a IGES model Returns True if translation is OK", py::arg("label"));
cls_IGESCAFControl_Writer.def("Perform", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const TCollection_AsciiString &)) &IGESCAFControl_Writer::Perform, "None", py::arg("doc"), py::arg("filename"));
cls_IGESCAFControl_Writer.def("Perform", (Standard_Boolean (IGESCAFControl_Writer::*)(const opencascade::handle<TDocStd_Document> &, const Standard_CString)) &IGESCAFControl_Writer::Perform, "Transfers a document and writes it to a IGES file Returns True if translation is OK", py::arg("doc"), py::arg("filename"));
cls_IGESCAFControl_Writer.def("SetColorMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetColorMode, "Set ColorMode for indicate write Colors or not.", py::arg("colormode"));
cls_IGESCAFControl_Writer.def("GetColorMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const) &IGESCAFControl_Writer::GetColorMode, "None");
cls_IGESCAFControl_Writer.def("SetNameMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetNameMode, "Set NameMode for indicate write Name or not.", py::arg("namemode"));
cls_IGESCAFControl_Writer.def("GetNameMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const) &IGESCAFControl_Writer::GetNameMode, "None");
cls_IGESCAFControl_Writer.def("SetLayerMode", (void (IGESCAFControl_Writer::*)(const Standard_Boolean)) &IGESCAFControl_Writer::SetLayerMode, "Set LayerMode for indicate write Layers or not.", py::arg("layermode"));
cls_IGESCAFControl_Writer.def("GetLayerMode", (Standard_Boolean (IGESCAFControl_Writer::*)() const) &IGESCAFControl_Writer::GetLayerMode, "None");

// Enums

}