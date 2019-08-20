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
#include <BRepBuilderAPI_MakeShape.hxx>
#include <Standard.hxx>
#include <Standard_TypeDef.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepPrimAPI_MakeOneAxis.hxx>

void bind_BRepPrimAPI_MakeOneAxis(py::module &mod){

py::class_<BRepPrimAPI_MakeOneAxis, std::unique_ptr<BRepPrimAPI_MakeOneAxis>, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeOneAxis(mod, "BRepPrimAPI_MakeOneAxis", "The abstract class MakeOneAxis is the root class of algorithms used to construct rotational primitives.");

// Fields

// Methods
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeOneAxis::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeOneAxis::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeOneAxis::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeOneAxis::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeOneAxis::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeOneAxis.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeOneAxis::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeOneAxis.def("OneAxis", (Standard_Address (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::OneAxis, "The inherited commands should provide the algorithm. Returned as a pointer.");
cls_BRepPrimAPI_MakeOneAxis.def("Build", (void (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Build, "Stores the solid in myShape.");
cls_BRepPrimAPI_MakeOneAxis.def("Face", (const TopoDS_Face & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Face, "Returns the lateral face of the rotational primitive.");
cls_BRepPrimAPI_MakeOneAxis.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Shell, "Returns the constructed rotational primitive as a shell.");
cls_BRepPrimAPI_MakeOneAxis.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeOneAxis::*)()) &BRepPrimAPI_MakeOneAxis::Solid, "Returns the constructed rotational primitive as a solid.");

// Enums

}