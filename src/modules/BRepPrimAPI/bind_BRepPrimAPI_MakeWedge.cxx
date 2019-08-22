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
#include <gp_Ax2.hxx>
#include <BRepPrim_Wedge.hxx>
#include <TopoDS_Shell.hxx>
#include <TopoDS_Solid.hxx>
#include <BRepPrimAPI_MakeWedge.hxx>

void bind_BRepPrimAPI_MakeWedge(py::module &mod){

py::class_<BRepPrimAPI_MakeWedge, BRepBuilderAPI_MakeShape> cls_BRepPrimAPI_MakeWedge(mod, "BRepPrimAPI_MakeWedge", "Describes functions to build wedges, i.e. boxes with inclined faces. A MakeWedge object provides a framework for: - defining the construction of a wedge, - implementing the construction algorithm, and - consulting the result.");

// Constructors
cls_BRepPrimAPI_MakeWedge.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
cls_BRepPrimAPI_MakeWedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("ltx"));
cls_BRepPrimAPI_MakeWedge.def(py::init<const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("xmin"), py::arg("zmin"), py::arg("xmax"), py::arg("zmax"));
cls_BRepPrimAPI_MakeWedge.def(py::init<const gp_Ax2 &, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real, const Standard_Real>(), py::arg("Axes"), py::arg("dx"), py::arg("dy"), py::arg("dz"), py::arg("xmin"), py::arg("zmin"), py::arg("xmax"), py::arg("zmax"));

// Fields

// Methods
// cls_BRepPrimAPI_MakeWedge.def_static("operator new_", (void * (*)(size_t)) &BRepPrimAPI_MakeWedge::operator new, "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeWedge.def_static("operator delete_", (void (*)(void *)) &BRepPrimAPI_MakeWedge::operator delete, "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeWedge.def_static("operator new[]_", (void * (*)(size_t)) &BRepPrimAPI_MakeWedge::operator new[], "None", py::arg("theSize"));
// cls_BRepPrimAPI_MakeWedge.def_static("operator delete[]_", (void (*)(void *)) &BRepPrimAPI_MakeWedge::operator delete[], "None", py::arg("theAddress"));
// cls_BRepPrimAPI_MakeWedge.def_static("operator new_", (void * (*)(size_t, void *)) &BRepPrimAPI_MakeWedge::operator new, "None", py::arg(""), py::arg("theAddress"));
// cls_BRepPrimAPI_MakeWedge.def_static("operator delete_", (void (*)(void *, void *)) &BRepPrimAPI_MakeWedge::operator delete, "None", py::arg(""), py::arg(""));
cls_BRepPrimAPI_MakeWedge.def("Wedge", (BRepPrim_Wedge & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Wedge, "Returns the internal algorithm.");
cls_BRepPrimAPI_MakeWedge.def("Build", (void (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Build, "Stores the solid in myShape.");
cls_BRepPrimAPI_MakeWedge.def("Shell", (const TopoDS_Shell & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Shell, "Returns the constructed box in the form of a shell.");
cls_BRepPrimAPI_MakeWedge.def("Solid", (const TopoDS_Solid & (BRepPrimAPI_MakeWedge::*)()) &BRepPrimAPI_MakeWedge::Solid, "Returns the constructed box in the form of a solid.");

// Enums

}