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
#include <XmlMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <XmlMXCAFDoc_AreaDriver.hxx>
#include <XmlMXCAFDoc_CentroidDriver.hxx>
#include <XmlMXCAFDoc_ColorDriver.hxx>
#include <XmlMXCAFDoc_GraphNodeDriver.hxx>
#include <XmlMXCAFDoc_LocationDriver.hxx>
#include <XmlMXCAFDoc_VolumeDriver.hxx>
#include <XmlMXCAFDoc_DatumDriver.hxx>
#include <XmlMXCAFDoc_DimTolDriver.hxx>
#include <XmlMXCAFDoc_MaterialDriver.hxx>
#include <XmlMXCAFDoc_ClippingPlaneToolDriver.hxx>
#include <XmlMXCAFDoc_ColorToolDriver.hxx>
#include <XmlMXCAFDoc_DocumentToolDriver.hxx>
#include <XmlMXCAFDoc_LayerToolDriver.hxx>
#include <XmlMXCAFDoc_ShapeToolDriver.hxx>
#include <XmlMXCAFDoc_DimTolToolDriver.hxx>
#include <XmlMXCAFDoc_MaterialToolDriver.hxx>
#include <XmlMXCAFDoc_ViewToolDriver.hxx>
#include <XmlMXCAFDoc.hxx>

void bind_XmlMXCAFDoc(py::module &mod){

py::class_<XmlMXCAFDoc, std::unique_ptr<XmlMXCAFDoc>> cls_XmlMXCAFDoc(mod, "XmlMXCAFDoc", "Storage and Retrieval drivers for modelling attributes. Transient attributes are defined in package XCAFDoc");

// Constructors

// Fields

// Methods
// cls_XmlMXCAFDoc.def_static("operator new_", (void * (*)(size_t)) &XmlMXCAFDoc::operator new, "None", py::arg("theSize"));
// cls_XmlMXCAFDoc.def_static("operator delete_", (void (*)(void *)) &XmlMXCAFDoc::operator delete, "None", py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator new[]_", (void * (*)(size_t)) &XmlMXCAFDoc::operator new[], "None", py::arg("theSize"));
// cls_XmlMXCAFDoc.def_static("operator delete[]_", (void (*)(void *)) &XmlMXCAFDoc::operator delete[], "None", py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator new_", (void * (*)(size_t, void *)) &XmlMXCAFDoc::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_XmlMXCAFDoc.def_static("operator delete_", (void (*)(void *, void *)) &XmlMXCAFDoc::operator delete, "None", py::arg(""), py::arg(""));
cls_XmlMXCAFDoc.def_static("AddDrivers_", (void (*)(const opencascade::handle<XmlMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &XmlMXCAFDoc::AddDrivers, "Adds the attribute drivers to <aDriverTable>.", py::arg("aDriverTable"), py::arg("anMsgDrv"));

// Enums

}