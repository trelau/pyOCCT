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
#include <BRepLib_MakeShape.hxx>
#include <Standard.hxx>
#include <TopoDS_CompSolid.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepLib_ShapeModification.hxx>
#include <TopoDS_Face.hxx>
#include <TopTools_ListOfShape.hxx>
#include <BRepLib_MakeSolid.hxx>

void bind_BRepLib_MakeSolid(py::module &mod){

py::class_<BRepLib_MakeSolid, BRepLib_MakeShape> cls_BRepLib_MakeSolid(mod, "BRepLib_MakeSolid", "Makes a solid from compsolid or shells.");

// Constructors
cls_BRepLib_MakeSolid.def(py::init<>());
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_CompSolid &>(), py::arg("S"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &>(), py::arg("S"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Shell &, const TopoDS_Shell &, const TopoDS_Shell &>(), py::arg("S1"), py::arg("S2"), py::arg("S3"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &>(), py::arg("So"));
cls_BRepLib_MakeSolid.def(py::init<const TopoDS_Solid &, const TopoDS_Shell &>(), py::arg("So"), py::arg("S"));

// Fields

// Methods
// cls_BRepLib_MakeSolid.def_static("operator new_", (void * (*)(size_t)) &BRepLib_MakeSolid::operator new, "None", py::arg("theSize"));
// cls_BRepLib_MakeSolid.def_static("operator delete_", (void (*)(void *)) &BRepLib_MakeSolid::operator delete, "None", py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator new[]_", (void * (*)(size_t)) &BRepLib_MakeSolid::operator new[], "None", py::arg("theSize"));
// cls_BRepLib_MakeSolid.def_static("operator delete[]_", (void (*)(void *)) &BRepLib_MakeSolid::operator delete[], "None", py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator new_", (void * (*)(size_t, void *)) &BRepLib_MakeSolid::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepLib_MakeSolid.def_static("operator delete_", (void (*)(void *, void *)) &BRepLib_MakeSolid::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepLib_MakeSolid.def("Add", (void (BRepLib_MakeSolid::*)(const TopoDS_Shell &)) &BRepLib_MakeSolid::Add, "Add the shell to the current solid.", py::arg("S"));
cls_BRepLib_MakeSolid.def("Solid", (const TopoDS_Solid & (BRepLib_MakeSolid::*)()) &BRepLib_MakeSolid::Solid, "Returns the new Solid.");
cls_BRepLib_MakeSolid.def("FaceStatus", (BRepLib_ShapeModification (BRepLib_MakeSolid::*)(const TopoDS_Face &) const) &BRepLib_MakeSolid::FaceStatus, "returns the status of the Face after the shape creation.", py::arg("F"));

// Enums

}