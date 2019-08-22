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
#include <BinMDF_ADriverTable.hxx>
#include <Message_Messenger.hxx>
#include <Standard_TypeDef.hxx>
#include <BinMDataXtd_PointDriver.hxx>
#include <BinMDataXtd_AxisDriver.hxx>
#include <BinMDataXtd_PlaneDriver.hxx>
#include <BinMDataXtd_GeometryDriver.hxx>
#include <BinMDataXtd_ConstraintDriver.hxx>
#include <BinMDataXtd_PlacementDriver.hxx>
#include <BinMDataXtd_PatternStdDriver.hxx>
#include <BinMDataXtd_ShapeDriver.hxx>
#include <BinMDataXtd_TriangulationDriver.hxx>
#include <BinMDataXtd.hxx>

void bind_BinMDataXtd(py::module &mod){

py::class_<BinMDataXtd> cls_BinMDataXtd(mod, "BinMDataXtd", "Storage and Retrieval drivers for modelling attributes.");

// Constructors

// Fields

// Methods
// cls_BinMDataXtd.def_static("operator new_", (void * (*)(size_t)) &BinMDataXtd::operator new, "None", py::arg("theSize"));
// cls_BinMDataXtd.def_static("operator delete_", (void (*)(void *)) &BinMDataXtd::operator delete, "None", py::arg("theAddress"));
// cls_BinMDataXtd.def_static("operator new[]_", (void * (*)(size_t)) &BinMDataXtd::operator new[], "None", py::arg("theSize"));
// cls_BinMDataXtd.def_static("operator delete[]_", (void (*)(void *)) &BinMDataXtd::operator delete[], "None", py::arg("theAddress"));
// cls_BinMDataXtd.def_static("operator new_", (void * (*)(size_t, void *)) &BinMDataXtd::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BinMDataXtd.def_static("operator delete_", (void (*)(void *, void *)) &BinMDataXtd::operator delete, "None", py::arg(""), py::arg(""));
cls_BinMDataXtd.def_static("AddDrivers_", (void (*)(const opencascade::handle<BinMDF_ADriverTable> &, const opencascade::handle<Message_Messenger> &)) &BinMDataXtd::AddDrivers, "Adds the attribute drivers to <theDriverTable>.", py::arg("theDriverTable"), py::arg("aMsgDrv"));
cls_BinMDataXtd.def_static("SetDocumentVersion_", (void (*)(const Standard_Integer)) &BinMDataXtd::SetDocumentVersion, "None", py::arg("DocVersion"));
cls_BinMDataXtd.def_static("DocumentVersion_", (Standard_Integer (*)()) &BinMDataXtd::DocumentVersion, "None");

// Enums

}