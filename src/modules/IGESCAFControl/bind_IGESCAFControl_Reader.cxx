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
#include <IGESControl_Reader.hxx>
#include <Standard.hxx>
#include <Standard_Handle.hxx>
#include <XSControl_WorkSession.hxx>
#include <Standard_TypeDef.hxx>
#include <TDocStd_Document.hxx>
#include <TCollection_AsciiString.hxx>
#include <IGESCAFControl_Reader.hxx>

void bind_IGESCAFControl_Reader(py::module &mod){

py::class_<IGESCAFControl_Reader, std::unique_ptr<IGESCAFControl_Reader>, IGESControl_Reader> cls_IGESCAFControl_Reader(mod, "IGESCAFControl_Reader", "Provides a tool to read IGES file and put it into DECAF document. Besides transfer of shapes (including assemblies) provided by IGESControl, supports also colors and part names IGESCAFControl_Reader reader; Methods for translation of an IGES file: reader.ReadFile('filename'); reader.Transfer(Document); or reader.Perform('filename',doc); Methods for managing reading attributes. Colors reader.SetColorMode(colormode); Standard_Boolean colormode = reader.GetColorMode(); Layers reader.SetLayerMode(layermode); Standard_Boolean layermode = reader.GetLayerMode(); Names reader.SetNameMode(namemode); Standard_Boolean namemode = reader.GetNameMode();");

// Constructors
cls_IGESCAFControl_Reader.def(py::init<>());
cls_IGESCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &>(), py::arg("theWS"));
cls_IGESCAFControl_Reader.def(py::init<const opencascade::handle<XSControl_WorkSession> &, const Standard_Boolean>(), py::arg("theWS"), py::arg("FromScratch"));

// Fields

// Methods
// cls_IGESCAFControl_Reader.def_static("operator new_", (void * (*)(size_t)) &IGESCAFControl_Reader::operator new, "None", py::arg("theSize"));
// cls_IGESCAFControl_Reader.def_static("operator delete_", (void (*)(void *)) &IGESCAFControl_Reader::operator delete, "None", py::arg("theAddress"));
// cls_IGESCAFControl_Reader.def_static("operator new[]_", (void * (*)(size_t)) &IGESCAFControl_Reader::operator new[], "None", py::arg("theSize"));
// cls_IGESCAFControl_Reader.def_static("operator delete[]_", (void (*)(void *)) &IGESCAFControl_Reader::operator delete[], "None", py::arg("theAddress"));
// cls_IGESCAFControl_Reader.def_static("operator new_", (void * (*)(size_t, void *)) &IGESCAFControl_Reader::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_IGESCAFControl_Reader.def_static("operator delete_", (void (*)(void *, void *)) &IGESCAFControl_Reader::operator delete, "None", py::arg(""), py::arg(""));
cls_IGESCAFControl_Reader.def("Transfer", (Standard_Boolean (IGESCAFControl_Reader::*)(opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Transfer, "Translates currently loaded IGES file into the document Returns True if succeeded, and False in case of fail", py::arg("theDoc"));
cls_IGESCAFControl_Reader.def("Perform", (Standard_Boolean (IGESCAFControl_Reader::*)(const TCollection_AsciiString &, opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Perform, "None", py::arg("theFileName"), py::arg("theDoc"));
cls_IGESCAFControl_Reader.def("Perform", (Standard_Boolean (IGESCAFControl_Reader::*)(const Standard_CString, opencascade::handle<TDocStd_Document> &)) &IGESCAFControl_Reader::Perform, "Translate IGES file given by filename into the document Return True if succeeded, and False in case of fail", py::arg("theFileName"), py::arg("theDoc"));
cls_IGESCAFControl_Reader.def("SetColorMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetColorMode, "Set ColorMode for indicate read Colors or not.", py::arg("theMode"));
cls_IGESCAFControl_Reader.def("GetColorMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const) &IGESCAFControl_Reader::GetColorMode, "None");
cls_IGESCAFControl_Reader.def("SetNameMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetNameMode, "Set NameMode for indicate read Name or not.", py::arg("theMode"));
cls_IGESCAFControl_Reader.def("GetNameMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const) &IGESCAFControl_Reader::GetNameMode, "None");
cls_IGESCAFControl_Reader.def("SetLayerMode", (void (IGESCAFControl_Reader::*)(const Standard_Boolean)) &IGESCAFControl_Reader::SetLayerMode, "Set LayerMode for indicate read Layers or not.", py::arg("theMode"));
cls_IGESCAFControl_Reader.def("GetLayerMode", (Standard_Boolean (IGESCAFControl_Reader::*)() const) &IGESCAFControl_Reader::GetLayerMode, "None");

// Enums

}